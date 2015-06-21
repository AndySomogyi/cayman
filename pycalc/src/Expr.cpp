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


IfExpr::IfExpr(class Ast* _ast, const location& _loc, AstNode* _test,
		AstNode* _body, AstNode* _orelse) :
		Expr(_ast, _loc), test(NULL), body(NULL), orelse(NULL)
{
	SetTest(_test);
	SetBody(_body);
	SetOrElse(_orelse);
}

void IfExpr::SetTest(AstNode* _test)
{
}

void IfExpr::SetBody(AstNode* _body)
{
}

void IfExpr::SetOrElse(AstNode* _orelse)
{
}

int IfExpr::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

UnaryOp::UnaryOp(class Ast* _ast, const location& _loc, OperatorType _op,
		AstNode* _operand) :
    Expr(_ast, _loc), op(EndOp), operand(NULL)
{
	SetOp(_op);
	SetOperand(_operand);
}

void UnaryOp::SetOp(OperatorType _op)
{
	op = _op;
}

void UnaryOp::SetOperand(AstNode* _operand)
{
	operand = _operand;
}

int UnaryOp::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

static void CompareValidOperator(OperatorType op)
{

}

static void CompareValidOperand(AstNode *operand)
{

}

Compare::Compare(class Ast* _ast, const location& _loc, AstNode* lhs,
		OperatorType op, AstNode* rhs) : Expr(_ast, _loc)
{
	CompareValidOperand(lhs);
	operands.push_back(lhs);

	Append(op, rhs);
}

void Compare::Append(OperatorType op, AstNode* operand)
{
	CompareValidOperator(op);
	CompareValidOperand(operand);
	operators.push_back(op);
	operands.push_back(operand);
}

int Compare::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Lambda::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

Dict::Dict(class Ast* ast, const location& loc, AstNode* key, AstNode* value) :
		Expr(ast, loc)
{
	AddKeyValue(key, value);
}

void Dict::AddKeyValue(AstNode* key, AstNode* value)
{
	if (key && value) {
		keys.push_back(key);
		values.push_back(value);
	}
}



int Dict::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int Set::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int ListComp::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int SetComp::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int DictComp::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int GeneratorExpr::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int Yield::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int YieldFrom::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int Bytes::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int NameConstant::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int Subscript::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int List::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

} /* namespace py */


