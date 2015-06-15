/*
 * Expression.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#include "Expr.h"
#include "AstVisitor.h"

namespace py
{






Expr::~Expr()
{
	AstNode *p = 0;
}

int BinOp::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}



} /* namespace py */


