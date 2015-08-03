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

/**
 * Interpret and evaluate the AST directly.
 */
class AstInterpreter: private AstVisitor<AstInterpreter, CaObject*>
{
public:
	// mark the template class as friend so it can call the
	// private visitor methods.
	friend AstVisitor<AstInterpreter, CaObject*>;

	CaObject *eval(AstNode *node);

private:

	CaObject *visit(Name*);
	CaObject *visit(Num*);
	CaObject *visit(Str*);
	CaObject *visit(Module*);
	CaObject *visit(Assign*);
	CaObject *visit(BinOp*);
	CaObject *visit(Tuple*);
	CaObject *visit(Ast*);
	CaObject *visit(Arg*);
	CaObject *visit(FunctionDef*);
	CaObject *visit(KeywordArg*);
	CaObject *visit(Call*);
	CaObject *visit(Starred*);
	CaObject *visit(For*);
	CaObject *visit(If*);
	CaObject *visit(Attribute*);
	CaObject *visit(IfExpr*);
	CaObject *visit(UnaryOp*);
	CaObject *visit(AugAssign*);
	CaObject *visit(Compare*);
	CaObject *visit(Delete*);
    CaObject *visit(Return*);
    CaObject *visit(Pass*);
    CaObject *visit(Break*);
    CaObject *visit(Continue*);
    CaObject *visit(While*);
    CaObject *visit(Raise*);
    CaObject *visit(Try*);
    CaObject *visit(Assert*);
    CaObject *visit(Import*);
    CaObject *visit(ImportFrom*);
    CaObject *visit(Global*);
    CaObject *visit(NonLocal*);
    CaObject *visit(ClassDef*);
    CaObject *visit(Lambda*);
    CaObject *visit(Dict*);
    CaObject *visit(Set*);
    CaObject *visit(ListComp*);
    CaObject *visit(SetComp*);
    CaObject *visit(DictComp*);
    CaObject *visit(GeneratorExpr*);
    CaObject *visit(Yield*);
    CaObject *visit(YieldFrom*);
    CaObject *visit(Bytes*);
    CaObject *visit(NameConstant*);
    CaObject *visit(Subscript*);
    CaObject *visit(List*);
};

}

#endif /* _INCLUDED_ASTINTERPRETER_H_ */
