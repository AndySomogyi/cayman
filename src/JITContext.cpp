/*
 * JITContext.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include "JITContext.h"
#include "AstCodegen.h"
#include "assert.h"

JITContext *JITContext::jitCtx = nullptr;

int JITContext::Initialize()
{
	assert(jitCtx == nullptr);
	jitCtx = new JITContext();
	return 0;
}

int JITContext::Finalize()
{
	delete jitCtx;
	jitCtx = nullptr;
	return 0;
}

void JITContext::addPrototypeAST(std::unique_ptr<PrototypeAST> P)
{
}

PrototypeAST* JITContext::getPrototypeAST(const std::string& nm)
{
	auto i = functions.find(nm);
	if (i != functions.end()) {
		return i->second.functionDef.get();
	}
	return nullptr;
}

JITContext::JITContext() :
    ctx(llvm::getGlobalContext()),
	tm(llvm::EngineBuilder().selectTarget()),
	CompileLayer(ObjectLayer, llvm::orc::SimpleCompiler(this->getTarget())),
	      LazyEmitLayer(CompileLayer)
{
}

FunctionAST *JITContext::GetFunctionAST(const std::string& nm)
{
}

llvm::RuntimeDyld::SymbolInfo JITContext::CompileFunction(const std::string& nm)
{
	auto fi = functions.find(nm);
	if (fi == functions.end())
		return nullptr;

	assert(!fi->second.jitSymbol);

	// IRGen the AST, add it to the JIT, and return the address for it.
	auto h = addModule(IRGen(*fi->second.functionDef.get()));
	auto sym = findSymbolIn(h, nm);

	// the sym.getAddress will actully invoke the JIT compilation.
	return llvm::RuntimeDyld::SymbolInfo(sym.getAddress(), sym.getFlags());
}

std::unique_ptr<llvm::Module> JITContext::IRGen(const FunctionAST& f)
{
	IRGenContext irCtx(*this);

	auto lf = f.IRGen(irCtx);
	if (!lf)
		return nullptr;
#ifndef MINIMAL_STDERR_OUTPUT
	fprintf(stderr, "Read function definition:");
	lf->dump();
#endif
	return irCtx.TakeModule();
}

JITContext::ModuleHandleT JITContext::addModule(std::unique_ptr<llvm::Module> M)
{
	// We need a memory manager to allocate memory and resolve symbols for this
	// new module. Create one that resolves symbols by looking back into the
	// JIT.
	auto Resolver = llvm::orc::createLambdaResolver(
			[&](const std::string &Name) {
		// First try to find 'Name' within the JIT.
		if (auto Symbol = findSymbol(Name))
			return llvm::RuntimeDyld::SymbolInfo(Symbol.getAddress(),
					Symbol.getFlags());

		// If we don't already have a definition of 'Name' then search
		// the ASTs.
		return CompileFunction(Name);
	},
	[](const std::string &S) { return nullptr; } );

	return LazyEmitLayer.addModuleSet(singletonSet(std::move(M)),
			llvm::make_unique<llvm::SectionMemoryManager>(),
			std::move(Resolver));
}
