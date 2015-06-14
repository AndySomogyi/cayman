/*
 * Expression.h
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_EXPRESSION_H_
#define _INCLUDED_EXPRESSION_H_

#include "Stmt.h"

namespace py
{

class Expr : public Stmt
{
public:
	Expr(class Ast* _ast, const location &_loc) : Stmt(_ast, _loc) {};
	virtual ~Expr();
};

enum OperatorType
{
	Add = 1,
	Sub = 2,
	Mult = 3,
	Div = 4,
	Mod = 5,
	Pow = 6,
	LShift = 7,
	RShift = 8,
	BitOr = 9,
	BitXor = 10,
	BitAnd = 11,
	FloorDiv = 12
};

/**
 * internal class, map token values to AstNodes, lets us keep a single
 * data type in the parser instead of the more complex variant or union.
 */
class Op
{
public:
	static AstNode *Add;
	static AstNode *Sub;
	static AstNode *Mult;
	static AstNode *Div;
	static AstNode *Mod;
	static AstNode *Pow;
	static AstNode *LShift;
	static AstNode *RShift;
	static AstNode *BitOr;
	static AstNode *BitXor;
	static AstNode *BitAnd;
	static AstNode *FloorDiv;

	static OperatorType GetOperatorType(const AstNode *node);
};

class BinOp : public Expr
{
public:
	BinOp(class Ast* _ast, const location& _loc,  OperatorType _op, AstNode* _left,
			AstNode* _right) :
			Expr(_ast, _loc), op(_op), left(_left), right(_right)
	{
	}
	;

	virtual ~BinOp()
	{
	}
	;

	OperatorType op;

	AstNode *left;
	AstNode *right;


	virtual int Accept(class AstVisitor*);
};




} /* namespace py */
#endif /* _INCLUDED_EXPRESSION_H_ */

