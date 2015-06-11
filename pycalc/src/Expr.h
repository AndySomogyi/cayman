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

class BinOp : public Expr
{
public:
	BinOp(class Ast* _ast, const location& _loc, Expr* _left, OperatorType _op,
			Expr* _right) :
			Expr(_ast, _loc), left(_left), op(_op), right(_right)
	{
	}
	;

	virtual ~BinOp()
	{
	}
	;

	Expr *left;
	Expr *right;
	OperatorType op;

	virtual int Accept(class AstVisitor*);
};




} /* namespace py */
#endif /* _INCLUDED_EXPRESSION_H_ */

