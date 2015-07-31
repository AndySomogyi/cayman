/*
 * JITContext.h
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_JITCONTEXT_H_
#define _INCLUDED_JITCONTEXT_H_

#include "cayman_llvm.h"
#include "Ast.h"
#include <sstream>
#include <assert.h>
#include <unordered_map>

using llvm::orc::JITSymbol;

class CaModule;

template <typename T>
static std::vector<T> singletonSet(T t) {
	std::vector<T> Vec;
	Vec.push_back(std::move(t));
	return Vec;
}



typedef std::unique_ptr<FunctionAST> FunctionAstPtr;

/**
 * The fields in the FunctionInfo struct are filled in as needed,
 * first only the AST added, then later when the func is IR'ed and
 * JIT'ed, these values are filled in.
 */
struct FunctionInfo
{
	FunctionAstPtr functionDef;


	JITSymbol jitSymbol;

	/**
	 * LLVM function prototoype, owned by LLVM.
	 */
	llvm::Function *prototype;
};

/**
 * Manage the state of the current JIT runtime, this includes
 * all of the currently defined method definitions.
 *
 * Notes:
 *
 * Currently all functions are compiled into separate object code
 * modules, so need external linkage.
 */
class JITContext
{
public:
	/**
	 * There may at some point be more that one JITContext, say
	 * in sepparate threads, this gets a reference to the
	 * current context.
	 */
	static JITContext &Get()
	{
		assert(jitCtx);
		return *jitCtx;
	}

	/**
	 * Sets up an LLVM context and state.
	 */
	static int Initialize();

	static int Finalize();


public:


	llvm::LLVMContext& getLLVMContext() const { return ctx; }


	llvm::TargetMachine& getTarget() { return *tm; }

	void addPrototypeAST(std::unique_ptr<PrototypeAST> p);

	PrototypeAST* getPrototypeAST(const std::string &name);

	// FIXME: Obviously we can do better than this
	std::string generateUniqueName(const std::string &Root)
	{
		static int i = 0;
		std::ostringstream NameStream;
		NameStream << Root << ++i;
		return NameStream.str();
	}

private:

	// only Initialize allowed create a context.
	JITContext();

	typedef std::map<std::string, std::unique_ptr<PrototypeAST>> PrototypeMap;

	// initial version will jit on the main thread to
	// start off with.
	llvm::LLVMContext &ctx;


	std::unique_ptr<llvm::TargetMachine> tm;

	/**
	 * list of function prototypes (external func definitions)
	 */
	PrototypeMap prototypes;

public:
	typedef llvm::orc::ObjectLinkingLayer<> ObjLayerT;
	typedef llvm::orc::IRCompileLayer<ObjLayerT> CompileLayerT;
	typedef CompileLayerT::ModuleSetHandleT ModuleHandleT;



	std::string mangle(const std::string &name);

	void AddCaModule(const CaModule* m);


	/**
	 * Adds an LLVM module to the lazy emit orc layer.
	 *
	 * symbol references in the new module are resolved to the
	 * existing modules.
	 */
	ModuleHandleT addModule(std::unique_ptr<llvm::Module> M);

	void removeModule(ModuleHandleT H);

	JITSymbol findMangledSymbol(const std::string &name);

	JITSymbol findSymbol(const std::string &name);


	/**
	 * Searches the current set of camodules for a definition ast.
	 */
	FunctionAST *getFunctionAST(const std::string &nm) const;

private:

	/**
	 * Searches for a function with the given name, generates IR, a new module
	 * with the given IR, and finally generates compiled object code are
	 * returns the symbol info of this new object code.
	 *
	 * This method is only called by the AddModule method, which defines a
	 * symbol resolver. The symbol resolver will check to see if there is already
	 * an existing compiled method, if not, it will call this method to
	 * compile and save the object code.
	 *
	 * This method first searches for the function definition ast via
	 * GetFunctionAST, then generates IR, then creates a new llvm module
	 * containing only this func def.
	 */
	llvm::RuntimeDyld::SymbolInfo CompileFunction(const std::string &nm);


	ObjLayerT ObjectLayer;
	CompileLayerT CompileLayer;


	/**
	 *
	 */
	std::unordered_map<std::string, CaModule*> caModules;

	/**
	 * Creates an new LLVM module populated with the single given function.
	 */
	std::unique_ptr<llvm::Module> CreateModuleWithFunction(const FunctionAST &f) ;


	std::map<std::string, FunctionInfo> functions;


	static JITContext* jitCtx;
};

#endif /* SRC_JITCONTEXT_H_ */
