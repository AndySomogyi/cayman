/*
 * AstCodegen.h
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_ASTCODEGEN_H_
#define _INCLUDED_ASTCODEGEN_H_

#include "cayman_llvm.h"
#include "JITContext.h"
#include "Ast.h"

#include <memory>
#include <map>

/**
 * temporary storage of items that only live for the durration of a IR codgen
 */
class IRGenContext
{
public:

	IRGenContext(JITContext &jctx) :
		jctx(jctx), module(
		    new llvm::Module(jctx.generateUniqueName("jit_module_"),
				jctx.getLLVMContext())), builder(jctx.getLLVMContext())
	{
		module->setDataLayout(*jctx.getTarget().getDataLayout());
	}

	//SessionContext& getSession() { return Session; }

	llvm::Module& getModule() const
	{
		return *module;
	}

	std::unique_ptr<llvm::Module> TakeModule()
	{
		return std::move(module);
	}

	llvm::IRBuilder<>& getBuilder()
	{
		return builder;
	}

	llvm::LLVMContext& getLLVMContext()
	{
		return jctx.getLLVMContext();
	}

	/**
	 * Get a prototype defined in the currently being built module,
	 * create if necessary.
	 */
	llvm::Function* GetPrototype(const std::string &name);

	std::map<std::string, llvm::AllocaInst*> namedValues;

private:
	JITContext &jctx;
	std::unique_ptr<llvm::Module> module;
	llvm::IRBuilder<> builder;
};

class AstCodegen
{
};

template <typename T>
std::unique_ptr<T> ErrorU(const std::string &Str) {
	std::cerr << "Error: " << Str << "\n";
	return nullptr;
}

template <typename T>
T* ErrorP(const std::string &Str) {
	std::cerr << "Error: " << Str << "\n";
	return nullptr;
}

#endif /* SRC_ASTCODEGEN_H_ */
