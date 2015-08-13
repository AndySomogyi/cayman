/*
 * AstInterpreter.h
 *
 *  Created on: Aug 3, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_ASTINTERPRETER_H_
#define _INCLUDED_ASTINTERPRETER_H_

#include "Ast.h"
#include "AstVisitor.h"
#include <iostream>
#include "cayman.h"

namespace py {



class AstInterpreterContext {
public:

	AstInterpreterContext() {};

};


/**
 * Interpret and evaluate the AST directly.
 */
class AstInterpreter: private AstVisitor<AstInterpreter, CaObject*,  AstInterpreterContext&>
{
public:
	// mark the template class as friend so it can call the
	// private visitor methods.
	friend AstVisitor<AstInterpreter, CaObject*, AstInterpreterContext&>;

	CaObject *eval(AstNode *node);

private:

	typedef AstInterpreterContext Ctx;



	CaObject *visit(Name*, Ctx&);
	CaObject *visit(Num*, Ctx&);
	CaObject *visit(Str*, Ctx&);
	CaObject *visit(Module*, Ctx&);
	CaObject *visit(Assign*, Ctx&);
	CaObject *visit(BinOp*, Ctx&);
	CaObject *visit(Tuple*, Ctx&);
	CaObject *visit(Ast*, Ctx&);
	CaObject *visit(Arg*, Ctx&);
	CaObject *visit(FunctionDef*, Ctx&);
	CaObject *visit(KeywordArg*, Ctx&);
	CaObject *visit(Call*, Ctx&);
	CaObject *visit(Starred*, Ctx&);
	CaObject *visit(For*, Ctx&);
	CaObject *visit(If*, Ctx&);
	CaObject *visit(Attribute*, Ctx&);
	CaObject *visit(IfExpr*, Ctx&);
	CaObject *visit(UnaryOp*, Ctx&);
	CaObject *visit(AugAssign*, Ctx&);
	CaObject *visit(Compare*, Ctx&);
	CaObject *visit(Delete*, Ctx&);
    CaObject *visit(Return*, Ctx&);
    CaObject *visit(Pass*, Ctx&);
    CaObject *visit(Break*, Ctx&);
    CaObject *visit(Continue*, Ctx&);
    CaObject *visit(While*, Ctx&);
    CaObject *visit(Raise*, Ctx&);
    CaObject *visit(Try*, Ctx&);
    CaObject *visit(Assert*, Ctx&);
    CaObject *visit(Import*, Ctx&);
    CaObject *visit(ImportFrom*, Ctx&);
    CaObject *visit(Global*, Ctx&);
    CaObject *visit(NonLocal*, Ctx&);
    CaObject *visit(ClassDef*, Ctx&);
    CaObject *visit(Lambda*, Ctx&);
    CaObject *visit(Dict*, Ctx&);
    CaObject *visit(Set*, Ctx&);
    CaObject *visit(ListComp*, Ctx&);
    CaObject *visit(SetComp*, Ctx&);
    CaObject *visit(DictComp*, Ctx&);
    CaObject *visit(GeneratorExpr*, Ctx&);
    CaObject *visit(Yield*, Ctx&);
    CaObject *visit(YieldFrom*, Ctx&);
    CaObject *visit(Bytes*, Ctx&);
    CaObject *visit(NameConstant*, Ctx&);
    CaObject *visit(Subscript*, Ctx&);
    CaObject *visit(List*, Ctx&);
};

}

#endif /* _INCLUDED_ASTINTERPRETER_H_ */
