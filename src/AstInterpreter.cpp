/*
 * AstInterpreter.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: andy
 */

#include "cayman.h"
#include <AstInterpreter.h>




namespace py {

CaObject* AstInterpreter::eval(AstNode* node)
{
	AstInterpreterContext ctx;
	return dispatch(node, ctx);
}

CaObject* AstInterpreter::visit(Name*, AstInterpreter::Ctx &ctx)
{
	CaObject *builtins = CaEval_GetBuiltins();
	return nullptr;
}

CaObject* AstInterpreter::visit(Num* num, AstInterpreter::Ctx &ctx)
{
	return CaNumber_FromString(num->value.c_str());
}

CaObject* AstInterpreter::visit(Str* str, AstInterpreter::Ctx &ctx)
{
	return CaString_FromString(str->value.c_str());
}

CaObject* AstInterpreter::visit(Module*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Assign*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(BinOp*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Tuple*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Ast*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Arg*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(FunctionDef*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(KeywordArg*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Call*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Starred*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(For*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(If*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Attribute*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(IfExpr*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(UnaryOp*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(AugAssign*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Compare*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Delete*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Return*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Pass*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Break*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Continue*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(While*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Raise*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Try*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Assert*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Import*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(ImportFrom*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Global*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(NonLocal*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(ClassDef*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Lambda*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Dict*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Set*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(ListComp*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(SetComp*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(DictComp*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(GeneratorExpr*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Yield*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(YieldFrom*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Bytes*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(NameConstant*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(Subscript*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

CaObject* AstInterpreter::visit(List*, AstInterpreter::Ctx &ctx)
{
	return nullptr;
}

}
