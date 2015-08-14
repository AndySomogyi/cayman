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
	CompileLayer(ObjectLayer, llvm::orc::SimpleCompiler(this->getTarget())),
    dataLayout(getTarget().createDataLayout())
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

	auto lf = cg.emitFunction(f);
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
			[&](const std::string &name) {

		// look up first in JIT'ed code
		if (auto sym = findMangledSymbol(name)) {
			return RuntimeDyld::SymbolInfo(sym.getAddress(),
					sym.getFlags());
			return RuntimeDyld::SymbolInfo(nullptr);
		}

		// look up in added globals
		if (auto addr = getPointerToGlobalMapping(name)) {
			return RuntimeDyld::SymbolInfo(addr, JITSymbolFlags::Exported);
		}

		// finally try to look up existing process symbols, note
		// this works for symbols loaded in shared libraries, but
		// does NOT seem to find symbols declared in the executable.
		if (auto Addr =
				RTDyldMemoryManager::getSymbolAddressInProcess(name)) {
			return RuntimeDyld::SymbolInfo(Addr, JITSymbolFlags::Exported);
		}
                
                
        // TODO report error
        return RuntimeDyld::SymbolInfo(0, JITSymbolFlags::Exported);
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
			cg.emitFunction(*func);
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
        llvm::Mangler::getNameWithPrefix(MangledNameStream, name, dataLayout);
    }
    return MangledName;
}

uint64_t JITContext::RemoveMapping(llvm::StringRef Name)
{
	  GlobalAddressMapTy::iterator I = GlobalAddressMap.find(Name);
	  uint64_t OldVal;

	  // FIXME: This is silly, we shouldn't end up with a mapping -> 0 in the
	  // GlobalAddressMap.
	  if (I == GlobalAddressMap.end())
	    OldVal = 0;
	  else {
	    GlobalAddressReverseMap.erase(I->second);
	    OldVal = I->second;
	    GlobalAddressMap.erase(I);
	  }

	  return OldVal;
}


std::string JITContext::mangle(const GlobalValue *GV) {

  Mangler Mang;
  SmallString<128> FullName;
  Mang.getNameWithPrefix(FullName, GV, false);
  return FullName.str();
}

void JITContext::addGlobalMapping(const GlobalValue *GV, void *Addr) {

  addGlobalMapping(mangle(GV), (uint64_t) Addr);
}

void JITContext::addGlobalMapping(StringRef Name, uint64_t Addr) {


  assert(!Name.empty() && "Empty GlobalMapping symbol name!");

  //DEBUG(dbgs() << "JIT: Map \'" << Name  << "\' to [" << Addr << "]\n";);
  uint64_t &CurVal = getGlobalAddressMap()[Name];
  assert((!CurVal || !Addr) && "GlobalMapping already established!");
  CurVal = Addr;

  // If we are using the reverse mapping, add it too.
  if (!getGlobalAddressReverseMap().empty()) {
    std::string &V = getGlobalAddressReverseMap()[CurVal];
    assert((!V.empty() || !Name.empty()) &&
           "GlobalMapping already established!");
    V = Name;
  }
}

void JITContext::clearAllGlobalMappings() {


  getGlobalAddressMap().clear();
  getGlobalAddressReverseMap().clear();
}

uint64_t JITContext::updateGlobalMapping(const llvm::GlobalValue* GV,
		void* Addr)
{
	return updateGlobalMapping(mangle(GV), (uint64_t) Addr);
}

uint64_t JITContext::updateGlobalMapping(llvm::StringRef Name, uint64_t Addr)
{
	GlobalAddressMapTy &Map =
			getGlobalAddressMap();

	// Deleting from the mapping?
	if (!Addr)
		return RemoveMapping(Name);

	uint64_t &CurVal = Map[Name];
	uint64_t OldVal = CurVal;

	if (CurVal && !getGlobalAddressReverseMap().empty())
		getGlobalAddressReverseMap().erase(CurVal);
	CurVal = Addr;

	// If we are using the reverse mapping, add it too.
	if (!getGlobalAddressReverseMap().empty()) {
		std::string &V = getGlobalAddressReverseMap()[CurVal];
		assert((!V.empty() || !Name.empty()) &&
				"GlobalMapping already established!");
		V = Name;
	}
	return OldVal;
}

uint64_t JITContext::getPointerToGlobalMapping(llvm::StringRef S)
{
	uint64_t Address = 0;
	GlobalAddressMapTy::iterator I =
			getGlobalAddressMap().find(S);
	if (I != getGlobalAddressMap().end())
		Address = I->second;
	return Address;

}

uint64_t JITContext::getPointerToGlobalMapping(const llvm::GlobalValue* GV)
{
	return getPointerToGlobalMapping(mangle(GV));
}
