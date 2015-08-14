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
		module->setDataLayout(jctx.getTarget().createDataLayout());
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

class AstCodegen: public IRGenContext, private AstVisitor<AstCodegen, llvm::Value*, py::ExprContext>
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



	llvm::Value* visit(Name*, py::ExprContext);
	llvm::Value* visit(Num*, py::ExprContext);
	llvm::Value* visit(Str*, py::ExprContext);
	llvm::Value* visit(Module*, py::ExprContext);
	llvm::Value* visit(Assign*, py::ExprContext);
	llvm::Value* visit(BinOp*, py::ExprContext);
	llvm::Value* visit(Tuple*, py::ExprContext);
	llvm::Value* visit(Ast*, py::ExprContext);
	llvm::Value* visit(Arg*, py::ExprContext);
	llvm::Value* visit(FunctionDef*, py::ExprContext);
	llvm::Value* visit(KeywordArg*, py::ExprContext);
	llvm::Value* visit(Call*, py::ExprContext);
	llvm::Value* visit(Starred*, py::ExprContext);
	llvm::Value* visit(For*, py::ExprContext);
	llvm::Value* visit(If*, py::ExprContext);
	llvm::Value* visit(Attribute*, py::ExprContext);
	llvm::Value* visit(IfExpr*, py::ExprContext);
	llvm::Value* visit(UnaryOp*, py::ExprContext);
	llvm::Value* visit(AugAssign*, py::ExprContext);
	llvm::Value* visit(Compare*, py::ExprContext);
	llvm::Value* visit(Delete*, py::ExprContext);
    llvm::Value* visit(Return*, py::ExprContext);
    llvm::Value* visit(Pass*, py::ExprContext);
    llvm::Value* visit(Break*, py::ExprContext);
    llvm::Value* visit(Continue*, py::ExprContext);
    llvm::Value* visit(While*, py::ExprContext);
    llvm::Value* visit(Raise*, py::ExprContext);
    llvm::Value* visit(Try*, py::ExprContext);
    llvm::Value* visit(Assert*, py::ExprContext);
    llvm::Value* visit(Import*, py::ExprContext);
    llvm::Value* visit(ImportFrom*, py::ExprContext);
    llvm::Value* visit(Global*, py::ExprContext);
    llvm::Value* visit(NonLocal*, py::ExprContext);
    llvm::Value* visit(ClassDef*, py::ExprContext);
    llvm::Value* visit(Lambda*, py::ExprContext);
    llvm::Value* visit(Dict*, py::ExprContext);
    llvm::Value* visit(Set*, py::ExprContext);
    llvm::Value* visit(ListComp*, py::ExprContext);
    llvm::Value* visit(SetComp*, py::ExprContext);
    llvm::Value* visit(DictComp*, py::ExprContext);
    llvm::Value* visit(GeneratorExpr*, py::ExprContext);
    llvm::Value* visit(Yield*, py::ExprContext);
    llvm::Value* visit(YieldFrom*, py::ExprContext);
    llvm::Value* visit(Bytes*, py::ExprContext);
    llvm::Value* visit(NameConstant*, py::ExprContext);
    llvm::Value* visit(Subscript*, py::ExprContext);
    llvm::Value* visit(List*, py::ExprContext);


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
	friend AstVisitor<AstCodegen, llvm::Value*, py::ExprContext>;
};

}

using py::AstCodegen;


#endif /* SRC_ASTCODEGEN_H_ */
