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

class AstCodegen: public IRGenContext, private AstVisitor
{
public:
	AstCodegen(JITContext &jctx);


	virtual ~AstCodegen();

	/**
	 * Emit a prototype defined in the currently being built llvm module.
	 */
	llvm::Function *FunctionProto(const py::FunctionDef &func);


	/**
	 * Emit the full IR for a function definition, including func body.
	 */
	llvm::Function *Function(const py::FunctionDef &func);

private:

	virtual int Visit(Name*);
	virtual int Visit(Num*);
	virtual int Visit(Str*);
	virtual int Visit(Module*);
	virtual int Visit(Assign*);
	virtual int Visit(BinOp*);
	virtual int Visit(Tuple*);
	virtual int Visit(Ast*);
	virtual int Visit(Arg*);
	virtual int Visit(FunctionDef*);
	virtual int Visit(KeywordArg*);
	virtual int Visit(Call*);
	virtual int Visit(Starred*);
	virtual int Visit(For*);
	virtual int Visit(If*);
	virtual int Visit(Attribute*);
	virtual int Visit(IfExpr*);
	virtual int Visit(UnaryOp*);
	virtual int Visit(AugAssign*);
	virtual int Visit(Compare*);
	virtual int Visit(Delete*);
    virtual int Visit(Return*);
    virtual int Visit(Pass*);
    virtual int Visit(Break*);
    virtual int Visit(Continue*);
    virtual int Visit(While*);
    virtual int Visit(Raise*);
    virtual int Visit(Try*);
    virtual int Visit(Assert*);
    virtual int Visit(Import*);
    virtual int Visit(ImportFrom*);
    virtual int Visit(Global*);
    virtual int Visit(NonLocal*);
    virtual int Visit(ClassDef*);
    virtual int Visit(Lambda*);
    virtual int Visit(Dict*);
    virtual int Visit(Set*);
    virtual int Visit(ListComp*);
    virtual int Visit(SetComp*);
    virtual int Visit(DictComp*);
    virtual int Visit(GeneratorExpr*);
    virtual int Visit(Yield*);
    virtual int Visit(YieldFrom*);
    virtual int Visit(Bytes*);
    virtual int Visit(NameConstant*);
    virtual int Visit(Subscript*);
    virtual int Visit(List*);


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

    llvm::Value *_result;

    /**
     * Wrapper for calling Accept --- Visit and grabing the resulting llvm value
     */
    llvm::Value *Create(AstNode *node);
};

}

using py::AstCodegen;


#endif /* SRC_ASTCODEGEN_H_ */
