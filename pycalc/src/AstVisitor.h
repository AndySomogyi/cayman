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


	virtual ~AstVisitor() {};
};

} /* namespace py */

#endif /* _INCLUDED_ASTVISITOR_H_ */
