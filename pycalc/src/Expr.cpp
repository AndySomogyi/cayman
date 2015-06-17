/*
 * Expression.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#include "Expr.h"
#include "AstVisitor.h"
#include "py_parser.hh"

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

Call::Call(Ast* ast, const location& loc, AstNode* _argsTuple) :
		Expr(ast, loc), func(NULL), starArg(NULL), kwArg(NULL)
{
	if (!_argsTuple) {
		return;
	}

	Tuple *argsTuple = dynamic_cast<Tuple*>(_argsTuple);

	if(!argsTuple) {
		// this is bad, error in the grammar
		assert(0);
	}

	for(AstNodes::const_iterator i = argsTuple->items.begin();
			i != argsTuple->items.end(); ++i)
	{
		AddArg(*i);
	}
}

void Call::AddArg(AstNode* arg)
{
	assert(arg);

	Starred *starred = dynamic_cast<Starred*>(arg);

	if(starred) {
		if (starArg == NULL) {
			starArg = starred->value;
			return;
		} else {
			throw syntax_error(starred->loc, "star argument already defined");
		}
	}

	KeywordArg *keywordArg = dynamic_cast<KeywordArg*>(arg);
	if(keywordArg) {
		kwArgs.push_back(keywordArg);
		return;
	}

	DblStarred *dblStarred = dynamic_cast<DblStarred*>(arg);
	if(dblStarred) {
		kwArg = dblStarred->value;
		return;
	}

	// its a standard arg
	args.push_back(arg);
}

void Call::SetFunc(AstNode* f)
{
	func = f;
}

void Call::SetBaseExpr(AstNode* base)
{
	func = base;
}

ExprSeq* Call::GetTerminalExpr()
{
	ExprSeq *base = dynamic_cast<ExprSeq*>(func);
	return base != NULL ? base->GetTerminalExpr() : this;
}

int Call::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}



Attribute::Attribute(class Ast* _ast, const location& _loc, ExprContext _ctx,
		AstNode* _value, AstNode* _attr) :
		Expr(_ast, _loc), ctx(_ctx), value(NULL)
{
	SetValue(_value);
	SetAttr(_attr);
};

void Attribute::SetValue(AstNode* _value)
{
	value = _value;
}

void Attribute::SetAttr(AstNode* _attr)
{
	if(_attr) {
		Name *name = dynamic_cast<Name*>(_attr);
		if (name == NULL) {
			throw syntax_error(loc, "attribute name must be a name");
		}
		attr = name->id;
	}
}

void Attribute::SetBaseExpr(AstNode* base)
{
	value = base;
}

ExprSeq* Attribute::GetTerminalExpr()
{
	ExprSeq *base = dynamic_cast<ExprSeq*>(value);
	return base != NULL ? base->GetTerminalExpr() : this;
}

int Attribute::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

} /* namespace py */


