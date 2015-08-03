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
#include "AstVisitor.h"

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
				jctx.getLLVMContext())), builder(jctx.getLLVMContext()),
				llvmCtx(jctx.getLLVMContext())
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



	std::map<std::string, llvm::AllocaInst*> namedValues;

protected:
	JITContext &jctx;
	std::unique_ptr<llvm::Module> module;
	llvm::IRBuilder<> builder;

	llvm::LLVMContext &llvmCtx;
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

namespace py {

class AstCodegen: public IRGenContext, private AstVisitor<AstCodegen, llvm::Value*>
{
public:
	AstCodegen(JITContext &jctx);


	virtual ~AstCodegen();

	/**
	 * Emit a prototype defined in the currently being built llvm module.
	 */
	llvm::Function *emitFunctionProto(const py::FunctionDef &func);


	/**
	 * Emit the full IR for a function definition, including func body.
	 */
	llvm::Function *emitFunction(const py::FunctionDef &func);

private:



	llvm::Value* visit(Name*);
	llvm::Value* visit(Num*);
	llvm::Value* visit(Str*);
	llvm::Value* visit(Module*);
	llvm::Value* visit(Assign*);
	llvm::Value* visit(BinOp*);
	llvm::Value* visit(Tuple*);
	llvm::Value* visit(Ast*);
	llvm::Value* visit(Arg*);
	llvm::Value* visit(FunctionDef*);
	llvm::Value* visit(KeywordArg*);
	llvm::Value* visit(Call*);
	llvm::Value* visit(Starred*);
	llvm::Value* visit(For*);
	llvm::Value* visit(If*);
	llvm::Value* visit(Attribute*);
	llvm::Value* visit(IfExpr*);
	llvm::Value* visit(UnaryOp*);
	llvm::Value* visit(AugAssign*);
	llvm::Value* visit(Compare*);
	llvm::Value* visit(Delete*);
    llvm::Value* visit(Return*);
    llvm::Value* visit(Pass*);
    llvm::Value* visit(Break*);
    llvm::Value* visit(Continue*);
    llvm::Value* visit(While*);
    llvm::Value* visit(Raise*);
    llvm::Value* visit(Try*);
    llvm::Value* visit(Assert*);
    llvm::Value* visit(Import*);
    llvm::Value* visit(ImportFrom*);
    llvm::Value* visit(Global*);
    llvm::Value* visit(NonLocal*);
    llvm::Value* visit(ClassDef*);
    llvm::Value* visit(Lambda*);
    llvm::Value* visit(Dict*);
    llvm::Value* visit(Set*);
    llvm::Value* visit(ListComp*);
    llvm::Value* visit(SetComp*);
    llvm::Value* visit(DictComp*);
    llvm::Value* visit(GeneratorExpr*);
    llvm::Value* visit(Yield*);
    llvm::Value* visit(YieldFrom*);
    llvm::Value* visit(Bytes*);
    llvm::Value* visit(NameConstant*);
    llvm::Value* visit(Subscript*);
    llvm::Value* visit(List*);


    /// CreateArgumentAllocas - Create an alloca for each argument and register the
    /// argument in the symbol table so that references to it will succeed.
    void CreateArgumentAllocas(const py::FunctionDef& funcAst, llvm::Function *f);

    /// CreateEntryBlockAlloca - Create an alloca instruction in the entry block of
    /// the function.  This is used for mutable variables etc.
    llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function *TheFunction,
    		const std::string &VarName);


    /**
     * iterate through a sequence of nodes untill a return statement is found,
     * all statements after a return are ignored.
     */
    llvm::Value* CreateBody(const py::AstNodes& body);


    llvm::Value *create(AstNode *node);

	// mark the template class as friend so it can call the
	// private visitor methods.
	friend AstVisitor<AstCodegen, llvm::Value*>;
};

}

using py::AstCodegen;


#endif /* SRC_ASTCODEGEN_H_ */
