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
	// binary operations
	Add = 0,
	Sub,
	Mult,
	Div,
	Mod,
	Pow,
	LShift,
	RShift,
	BitOr,
	BitXor,
	BitAnd,
	FloorDiv,

	// comparisons
	// comparisons start at the Eq operator.
	Eq,
	NotEq,
	Lt,
	LtEq,
	Gt,
	GtEq,
	Is,
	IsNot,
	In,
	NotIn,

	And,
	Or,

	// keep this as the last operator, to know the number of operators
	// we have, this is NOT a valid operator type.
	EndOp
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

