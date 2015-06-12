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
#include <Stmt.h>

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

void TmpArguments::SetKwOnlyArgs(AstNode* node)
{
}

void TmpArguments::SetArgs(AstNode* node)
{
}

void TmpArguments::SetVararg(AstNode* node)
{
}

void TmpArguments::SetKwArg(AstNode* node)
{
}

int Arg::Accept(AstVisitor* v)
{
}


} /* namespace py */

