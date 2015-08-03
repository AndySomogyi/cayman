/*
 * AstCodegen.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include <AstCodegen.h>


using namespace llvm;


py::AstCodegen::~AstCodegen()
{
}

llvm::Value *py::AstCodegen::visit(Name* name)
{
	// Look this variable up in the function.
	Value *V = namedValues[name->id];

	if (V == 0)
	{
		//return ErrorP<Value>("Unknown variable name '" + Name + "'");
		return nullptr;
	}

	// Load the value.
	return getBuilder().CreateLoad(V, name->id.c_str());
}

llvm::Value *py::AstCodegen::visit(Num*)
{
}

llvm::Value *py::AstCodegen::visit(Str*)
{
}

llvm::Value *py::AstCodegen::visit(Module*)
{
}

llvm::Value *py::AstCodegen::visit(Assign*)
{
}

llvm::Value *py::AstCodegen::visit(BinOp* op)
{
	Value *L = create(op->left);
	Value *R = create(op->right);
	if (!L || !R)
	{
		return nullptr;
	}

	switch (op->op) {
	case py::OperatorType::Add: return getBuilder().CreateFAdd(L, R, "addtmp");
	case py::OperatorType::Sub: return getBuilder().CreateFSub(L, R, "subtmp");
	case py::OperatorType::Mult: return getBuilder().CreateFMul(L, R, "multmp");
	case py::OperatorType::Div: return getBuilder().CreateFDiv(L, R, "divtmp");
	case py::OperatorType::Lt:
		L = getBuilder().CreateFCmpULT(L, R, "cmptmp");
		// Convert bool 0/1 to double 0.0 or 1.0
		return getBuilder().CreateUIToFP(L, Type::getDoubleTy(llvmCtx),"booltmp");

	default: break;
	}


	return nullptr;
}

llvm::Value *py::AstCodegen::visit(Tuple*)
{
}

llvm::Value *py::AstCodegen::visit(Ast*)
{
}

llvm::Value *py::AstCodegen::visit(Arg*)
{
}

llvm::Value *py::AstCodegen::visit(FunctionDef*)
{
}

llvm::Value *py::AstCodegen::visit(KeywordArg*)
{
}

llvm::Value *py::AstCodegen::visit(Call*)
{
}

llvm::Value *py::AstCodegen::visit(Starred*)
{
}

llvm::Value *py::AstCodegen::visit(For*)
{
}

llvm::Value *py::AstCodegen::visit(If*)
{
}

llvm::Value *py::AstCodegen::visit(Attribute*)
{
}

llvm::Value *py::AstCodegen::visit(IfExpr*)
{
}

llvm::Value *py::AstCodegen::visit(UnaryOp*)
{
}

llvm::Value *py::AstCodegen::visit(AugAssign*)
{
}

llvm::Value *py::AstCodegen::visit(Compare*)
{
}

llvm::Value *py::AstCodegen::visit(Delete*)
{
}

llvm::Value *py::AstCodegen::visit(Return* ret)
{
	Value *retval = create(ret->value);

	// TODO check retval
	return getBuilder().CreateRet(retval);
}

llvm::Value *py::AstCodegen::visit(Pass*)
{
}

llvm::Value *py::AstCodegen::visit(Break*)
{
}

llvm::Value *py::AstCodegen::visit(Continue*)
{
}

llvm::Value *py::AstCodegen::visit(While*)
{
}

llvm::Value *py::AstCodegen::visit(Raise*)
{
}

llvm::Value *py::AstCodegen::visit(Try*)
{
}

llvm::Value *py::AstCodegen::visit(Assert*)
{
}

llvm::Value *py::AstCodegen::visit(Import*)
{
}

llvm::Value *py::AstCodegen::visit(ImportFrom*)
{
}

llvm::Value *py::AstCodegen::visit(Global*)
{
}

llvm::Value *py::AstCodegen::visit(NonLocal*)
{
}

llvm::Value *py::AstCodegen::visit(ClassDef*)
{
}

llvm::Value *py::AstCodegen::visit(Lambda*)
{
}

llvm::Value *py::AstCodegen::visit(Dict*)
{
}

llvm::Value *py::AstCodegen::visit(Set*)
{
}

llvm::Value *py::AstCodegen::visit(ListComp*)
{
}

llvm::Value *py::AstCodegen::visit(SetComp*)
{
}

llvm::Value *py::AstCodegen::visit(DictComp*)
{
}

llvm::Value *py::AstCodegen::visit(GeneratorExpr*)
{
}

llvm::Value *py::AstCodegen::visit(Yield*)
{
}

llvm::Value *py::AstCodegen::visit(YieldFrom*)
{
}

llvm::Value *py::AstCodegen::visit(Bytes*)
{
}

llvm::Value *py::AstCodegen::visit(NameConstant*)
{
}

llvm::Value *py::AstCodegen::visit(Subscript*)
{
}

py::AstCodegen::AstCodegen(JITContext& jctx) : IRGenContext(jctx)
{
}

llvm::Function* py::AstCodegen::emitFunctionProto(const py::FunctionDef &func)
{
	// Make the function type:  double(double,double) etc.
	std::vector<Type*> Doubles(func.args.size(),
			llvm::Type::getDoubleTy(llvmCtx));

	llvm::FunctionType *FT = llvm::FunctionType::get(Type::getDoubleTy(llvmCtx),
			Doubles, false);

	// function names are by definition legal names, parser takes care of this.
	llvm::Function *f = Function::Create(FT, Function::ExternalLinkage, func.name,
			&getModule());


	// If F conflicted, there was already something named 'FnName'.  If it has a
	// body, don't allow redefinition or reextern.
	if (f->getName() != func.name)
	{
		// Delete the one we just made and get the existing one.
		f->eraseFromParent();
		f = getModule().getFunction(func.name);

		// If F already has a body, reject this.
		if (!f->empty()) {

			// TODO report error
			// ErrorP<	Function>("redefinition of function");
			return nullptr;
		}

		// If F took a different number of args, reject.
		if (f->arg_size() != func.args.size()) {
			// TODO: report error
			//ErrorP<Function>("redefinition of function with different # args");
			return nullptr;
		}
	}

	// Set names for all arguments.
	unsigned Idx = 0;
	for (Function::arg_iterator AI = f->arg_begin(); Idx != func.args.size();
			++AI, ++Idx)
		AI->setName(func.args[Idx]->id);

	return f;
}

llvm::Function* py::AstCodegen::emitFunction(const py::FunctionDef& func)
{
	namedValues.clear();

    llvm::Function *TheFunction = emitFunctionProto(func);
	if (!TheFunction)
		return nullptr;

	// If this is an operator, install it.
	//if (Proto->isBinaryOp())
	//	BinopPrecedence[Proto->getOperatorName()] = Proto->Precedence;

	// Create a new basic block to start insertion into.
	BasicBlock *BB = BasicBlock::Create(llvmCtx, "entry", TheFunction);
	getBuilder().SetInsertPoint(BB);



	// Add all arguments to the symbol table and create their allocas.
	CreateArgumentAllocas(func, TheFunction);


	if (CreateBody(func.body))
	{
        TheFunction->dump();
        
		// Validate the generated code, checking for consistency.
		verifyFunction(*TheFunction);

		return TheFunction;
	}

	// Error reading body, remove function.
	TheFunction->eraseFromParent();


	return nullptr;


}

llvm::Value *py::AstCodegen::visit(List*)
{
}

/// CreateEntryBlockAlloca - Create an alloca instruction in the entry block of
/// the function.  This is used for mutable variables etc.
AllocaInst *py::AstCodegen::CreateEntryBlockAlloca(llvm::Function *TheFunction,
		const std::string &VarName)
{
	IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
			TheFunction->getEntryBlock().begin());
	return TmpB.CreateAlloca(Type::getDoubleTy(llvmCtx), 0,
			VarName.c_str());
}


/// CreateArgumentAllocas - Create an alloca for each argument and register the
/// argument in the symbol table so that references to it will succeed.
void py::AstCodegen::CreateArgumentAllocas(const py::FunctionDef& funcAst, llvm::Function *f) {
	llvm::Function::arg_iterator AI = f->arg_begin();

	for (unsigned Idx = 0, e = funcAst.args.size(); Idx != e; ++Idx, ++AI) {
		// Create an alloca for this variable.
		AllocaInst *Alloca = CreateEntryBlockAlloca(f, funcAst.args[Idx]->id);

		// Store the initial value into the alloca.
		getBuilder().CreateStore(AI, Alloca);

		// Add arguments to variable symbol table.
		namedValues[funcAst.args[Idx]->id] = Alloca;
	}
}

llvm::Value* py::AstCodegen::CreateBody(const py::AstNodes& body)
{
	llvm::Value *result = nullptr;

	for(AstNode* node : body)
	{
		result = create(node);

		if(dyn_cast<ReturnInst>(result))
		{
			return result;
		}
	}

	return getBuilder().CreateRetVoid();
}

llvm::Value* py::AstCodegen::create(AstNode* node)
{
	return dispatch(node);
}
