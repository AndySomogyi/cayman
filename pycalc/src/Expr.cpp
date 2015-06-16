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


If::If(class Ast* _ast, const location& _loc,  AstNode *_test,
		AstNode *_body, AstNode *_orelse):
		Expr(_ast, _loc), test(NULL)
{
	SetTest(_test);
	SetBody(_body);
	SetOrElse(_orelse);
}

void If::SetTest(AstNode* _test)
{
	test = _test;
}

void If::SetBody(AstNode* _body)
{
	if (_body)
	{
		Tuple *tuple = dynamic_cast<Tuple*>(_body);
		assert(tuple);
		body = tuple->items;
	}
	else
	{
		body.clear();
	}
}

void py::If::SetOrElse(AstNode* _orelse)
{
	orelse.clear();

	if (_orelse)
	{
		If *i = dynamic_cast<If*>(_orelse);
		if (i)
		{
			orelse.push_back(i);
			return;
		}

		Tuple *tuple = dynamic_cast<Tuple*>(_orelse);
		assert(tuple);
		orelse = tuple->items;
	}
}


If* If::GetTerminalElif()
{
	if (orelse.size() == 1)
	{
		If *tail = dynamic_cast<If*>(orelse[0]);
		if (tail)
		{
			return tail->GetTerminalElif();
		}
	}
	return this;
}

int py::If::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}




} /* namespace py */
