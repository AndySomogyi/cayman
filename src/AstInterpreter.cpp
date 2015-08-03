/*
 * AstInterpreter.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: andy
 */

#include <AstInterpreter.h>

namespace py {

CaObject* AstInterpreter::eval(AstNode* node)
{
	return dispatch(node);
}

CaObject* AstInterpreter::visit(Name*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Num*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Str*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Module*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Assign*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(BinOp*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Tuple*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Ast*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Arg*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(FunctionDef*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(KeywordArg*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Call*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Starred*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(For*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(If*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Attribute*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(IfExpr*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(UnaryOp*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(AugAssign*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Compare*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Delete*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Return*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Pass*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Break*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Continue*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(While*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Raise*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Try*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Assert*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Import*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(ImportFrom*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Global*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(NonLocal*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(ClassDef*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Lambda*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Dict*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Set*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(ListComp*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(SetComp*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(DictComp*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(GeneratorExpr*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Yield*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(YieldFrom*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Bytes*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(NameConstant*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Subscript*)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(List*)
{
	return nullptr;
}

}
