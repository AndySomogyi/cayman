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
	// TODO Auto-generated destructor stub
}



Tuple::~Tuple()
{
	// TODO Auto-generated destructor stub
}

int Tuple::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int BinOp::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

} /* namespace py */


