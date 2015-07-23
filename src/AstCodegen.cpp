/*
 * AstCodegen.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include <AstCodegen.h>

llvm::Function* IRGenContext::GetPrototype(const std::string& name)
{
	if (llvm::Function *ExistingProto = module->getFunction(name))
		return ExistingProto;
	if (FunctionAST *ast = jctx.GetFunctionAST(name))
		return ast->PrototypeIRGen(*this);
	return nullptr;
}

py::AstCodegen::AstCodegen()
{
}

py::AstCodegen::~AstCodegen()
{
}

int py::AstCodegen::Visit(Name*)
{
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

int py::AstCodegen::Visit(BinOp*)
{
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

int py::AstCodegen::Visit(Return*)
{
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

int py::AstCodegen::Visit(List*)
{
}
