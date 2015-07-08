/*
 * AstVisitor.h
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_ASTVISITOR_H_
#define _INCLUDED_ASTVISITOR_H_

#include "AstNode.h"
#include "Stmt.h"
#include "Expr.h"

namespace py
{

class AstVisitor
{
public:

	virtual int Visit(Name*) = 0;
	virtual int Visit(Num*) = 0;
	virtual int Visit(Str*) = 0;
	virtual int Visit(Module*) = 0;
	virtual int Visit(Assign*) = 0;
	virtual int Visit(BinOp*) = 0;
	virtual int Visit(Tuple*) = 0;
	virtual int Visit(class Ast*) = 0;
	virtual int Visit(Arg*) = 0;
	virtual int Visit(FunctionDef*) = 0;
	virtual int Visit(KeywordArg*) = 0;
	virtual int Visit(Call*) = 0;
	virtual int Visit(Starred*) = 0;
	virtual int Visit(For*) = 0;
	virtual int Visit(If*) = 0;
	virtual int Visit(Attribute*) = 0;
	virtual int Visit(IfExpr*) = 0;
	virtual int Visit(UnaryOp*) = 0;
	virtual int Visit(AugAssign*) = 0;
	virtual int Visit(Compare*) = 0;
	virtual int Visit(Delete*) = 0;
    virtual int Visit(Return*) = 0;
    virtual int Visit(Pass*) = 0;
    virtual int Visit(Break*) = 0;
    virtual int Visit(Continue*) = 0;
    virtual int Visit(While*) = 0;
    virtual int Visit(Raise*) = 0;
    virtual int Visit(Try*) = 0;
    virtual int Visit(Assert*) = 0;
    virtual int Visit(Import*) = 0;
    virtual int Visit(ImportFrom*) = 0;
    virtual int Visit(Global*) = 0;
    virtual int Visit(NonLocal*) = 0;
    virtual int Visit(ClassDef*) = 0;
    virtual int Visit(Lambda*) = 0;
    virtual int Visit(Dict*) = 0;
    virtual int Visit(Set*) = 0;
    virtual int Visit(ListComp*) = 0;
    virtual int Visit(SetComp*) = 0;
    virtual int Visit(DictComp*) = 0;
    virtual int Visit(GeneratorExpr*) = 0;
    virtual int Visit(Yield*) = 0;
    virtual int Visit(YieldFrom*) = 0;
    virtual int Visit(Bytes*) = 0;
    virtual int Visit(NameConstant*) = 0;
    virtual int Visit(Subscript*) = 0;
    virtual int Visit(List*) = 0;

	virtual ~AstVisitor() {};
};

} /* namespace py */

#endif /* _INCLUDED_ASTVISITOR_H_ */
