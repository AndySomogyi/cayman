/*
 * JITContext.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include "JITContext.h"
#include "AstCodegen.h"
#include "CaModule.h"
#include "assert.h"


JITContext *JITContext::jitCtx = nullptr;

using namespace llvm;
using namespace llvm::orc;


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
	CompileLayer(ObjectLayer, llvm::orc::SimpleCompiler(this->getTarget()))
{

}

FunctionAST *JITContext::getFunctionAST(const std::string& nm) const
{
    return nullptr;
}

llvm::RuntimeDyld::SymbolInfo JITContext::CompileFunction(const std::string& nm)
{
	const FunctionAST *func = nullptr;
	for(auto i = caModules.begin(); i != caModules.end(); ++i)
	{
		func = i->second->GetFunctionAST(nm);
		if(func)
		{
			// IRGen the AST, add it to the JIT, and return the address for it.
			auto h = addModule(CreateModuleWithFunction(*func));
			auto sym = CompileLayer.findSymbolIn(h, nm, true);

			// the sym.getAddress will actully invoke the JIT compilation.
			return llvm::RuntimeDyld::SymbolInfo(sym.getAddress(), sym.getFlags());
		}
		else
		{
			continue;
		}
	}
	return nullptr;
}

void JITContext::removeModule(ModuleHandleT H)
{
	CompileLayer.removeModuleSet(H);
}

JITSymbol JITContext::findMangledSymbol(const std::string& name)
{
	if (auto sym = CompileLayer.findSymbol(name, true))
	{
		return sym;
	}

	if (auto *func = getFunctionAST(name))
	{
		// IRGen the AST, add it to the JIT, and return the address for it.
		auto h = addModule(CreateModuleWithFunction(*func));
		auto sym = CompileLayer.findSymbolIn(h, name, true);

		assert(sym);

		return sym;
	}

	// TODO report error
	return nullptr;
}

std::unique_ptr<llvm::Module> JITContext::CreateModuleWithFunction(const FunctionAST& f)
{
	AstCodegen cg(*this);

	auto lf = cg.Function(f);
	if (!lf)
		return nullptr;
#ifndef MINIMAL_STDERR_OUTPUT
	fprintf(stderr, "Read function definition:");
	lf->dump();
#endif
	return cg.TakeModule();
}

JITContext::ModuleHandleT JITContext::addModule(std::unique_ptr<llvm::Module> M)
{
    // We need a memory manager to allocate memory and resolve symbols for this
    // new module. Create one that resolves symbols by looking back into the
    // JIT.
    auto Resolver = createLambdaResolver(
                      [&](const std::string &Name) {
                        if (auto sym = findMangledSymbol(Name))
                          return RuntimeDyld::SymbolInfo(sym.getAddress(),
                                                         sym.getFlags());
                        return RuntimeDyld::SymbolInfo(nullptr);
                      },
                      [](const std::string &S) { return nullptr; }
                    );
    return CompileLayer.addModuleSet(singletonSet(std::move(M)),
                                     make_unique<SectionMemoryManager>(),
                                     std::move(Resolver));
}

void JITContext::AddCaModule(const CaModule* m)
{
	AstCodegen cg(*this);

	for(py::AstNode *node : m->ast->body)
	{
		if (py::FunctionDef *func = dynamic_cast<py::FunctionDef*>(node))
		{
			cg.Function(*func);
		}
	}

	addModule(cg.TakeModule());
}

JITSymbol JITContext::findSymbol(const std::string& Name)
{
	return findMangledSymbol(mangle(Name));
}

std::string JITContext::mangle(const std::string &name)
{
    std::string MangledName;
    {
      llvm::raw_string_ostream MangledNameStream(MangledName);
      llvm::Mangler::getNameWithPrefix(MangledNameStream, name,
    		  *getTarget().getDataLayout());
    }
    return MangledName;
}


