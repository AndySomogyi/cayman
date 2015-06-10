/*
 * Statement.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#include "Stmt.h"
#include "Expr.h"
#include "py_parser.hh"
#include "AstVisitor.h"

namespace py
{

Assign::Assign(class Ast* _ast, const location& _loc, AstNode* target,
		AstNode* _value) :
    Stmt(_ast, _loc), value(_value)
{
	targets.push_back(target);

}

void Assign::AddValue(AstNode* _value)
{
	targets.push_back(value);
	value = _value;
}

int Assign::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

} /* namespace py */

