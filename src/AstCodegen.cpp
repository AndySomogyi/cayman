/*
 * AstCodegen.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include <AstCodegen.h>


using namespace llvm;


// wrapper to make using the visitor a bit cleaner
#define Return(__ret) _result = __ret; return 0

py::AstCodegen::~AstCodegen()
{
}

int py::AstCodegen::Visit(Name* name)
{
	// Look this variable up in the function.
	Value *V = namedValues[name->id];

	if (V == 0)
	{
		//return ErrorP<Value>("Unknown variable name '" + Name + "'");
		return -1;
	}

	// Load the value.
	Return(getBuilder().CreateLoad(V, name->id.c_str()));
}

int py::AstCodegen::Visit(Num*)
{
}

int py::AstCodegen::Visit(Str*)
{
}

int py::AstCodegen::Visit(Module*)
{
}

int py::AstCodegen::Visit(Assign*)
{
}

int py::AstCodegen::Visit(BinOp* op)
{
	op->left->Accept(this);


	Value *L = Create(op->left);
	Value *R = Create(op->right);
	if (!L || !R)
	{
		return -1;
	}

	switch (op->op) {
	case py::OperatorType::Add: Return(getBuilder().CreateFAdd(L, R, "addtmp"));
	case py::OperatorType::Sub: Return(getBuilder().CreateFSub(L, R, "subtmp"));
	case py::OperatorType::Mult: Return(getBuilder().CreateFMul(L, R, "multmp"));
	case py::OperatorType::Div: Return(getBuilder().CreateFDiv(L, R, "divtmp"));
	case py::OperatorType::Lt:
		L = getBuilder().CreateFCmpULT(L, R, "cmptmp");
		// Convert bool 0/1 to double 0.0 or 1.0
		Return(getBuilder().CreateUIToFP(L, Type::getDoubleTy(llvmCtx),"booltmp"));

	default: break;
	}


	return -1;
}

int py::AstCodegen::Visit(Tuple*)
{
}

int py::AstCodegen::Visit(Ast*)
{
}

int py::AstCodegen::Visit(Arg*)
{
}

int py::AstCodegen::Visit(FunctionDef*)
{
}

int py::AstCodegen::Visit(KeywordArg*)
{
}

int py::AstCodegen::Visit(Call*)
{
}

int py::AstCodegen::Visit(Starred*)
{
}

int py::AstCodegen::Visit(For*)
{
}

int py::AstCodegen::Visit(If*)
{
}

int py::AstCodegen::Visit(Attribute*)
{
}

int py::AstCodegen::Visit(IfExpr*)
{
}

int py::AstCodegen::Visit(UnaryOp*)
{
}

int py::AstCodegen::Visit(AugAssign*)
{
}

int py::AstCodegen::Visit(Compare*)
{
}

int py::AstCodegen::Visit(Delete*)
{
}

int py::AstCodegen::Visit(Return* ret)
{
	Value *retval = Create(ret->value);

	// TODO check retval
	Return(getBuilder().CreateRet(retval));
}

int py::AstCodegen::Visit(Pass*)
{
}

int py::AstCodegen::Visit(Break*)
{
}

int py::AstCodegen::Visit(Continue*)
{
}

int py::AstCodegen::Visit(While*)
{
}

int py::AstCodegen::Visit(Raise*)
{
}

int py::AstCodegen::Visit(Try*)
{
}

int py::AstCodegen::Visit(Assert*)
{
}

int py::AstCodegen::Visit(Import*)
{
}

int py::AstCodegen::Visit(ImportFrom*)
{
}

int py::AstCodegen::Visit(Global*)
{
}

int py::AstCodegen::Visit(NonLocal*)
{
}

int py::AstCodegen::Visit(ClassDef*)
{
}

int py::AstCodegen::Visit(Lambda*)
{
}

int py::AstCodegen::Visit(Dict*)
{
}

int py::AstCodegen::Visit(Set*)
{
}

int py::AstCodegen::Visit(ListComp*)
{
}

int py::AstCodegen::Visit(SetComp*)
{
}

int py::AstCodegen::Visit(DictComp*)
{
}

int py::AstCodegen::Visit(GeneratorExpr*)
{
}

int py::AstCodegen::Visit(Yield*)
{
}

int py::AstCodegen::Visit(YieldFrom*)
{
}

int py::AstCodegen::Visit(Bytes*)
{
}

int py::AstCodegen::Visit(NameConstant*)
{
}

int py::AstCodegen::Visit(Subscript*)
{
}

py::AstCodegen::AstCodegen(JITContext& jctx) : IRGenContext(jctx)
{
}

llvm::Function* py::AstCodegen::FunctionProto(const py::FunctionDef &func)
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

llvm::Function* py::AstCodegen::Function(const py::FunctionDef& func)
{
	namedValues.clear();

    llvm::Function *TheFunction = FunctionProto(func);
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

int py::AstCodegen::Visit(List*)
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
		result = Create(node);

		if(dyn_cast<ReturnInst>(result))
		{
			return result;
		}
	}

	return getBuilder().CreateRetVoid();
}

llvm::Value* py::AstCodegen::Create(AstNode* node)
{
	_result = nullptr;

	if(node->Accept(this) != 0)
	{
		// TODO handle error conditions
	}
	return _result;
}
