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
	Add = 1,
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


/**
 * A general binary operation betwen two objects.
 *
 * Note, CPython had a separate tree items for binary ops and boolean ops,
 * presubmably because this allowed some optimization in the interpreter. Here,
 * all code is compiled to native machine types, and any optimization will occur
 * later in the compilation process. We support type inference as well.
 */
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


class If : public Expr
{
public:
	If(class Ast* _ast, const location& _loc,  AstNode *_test = NULL,
			AstNode *_body = NULL, AstNode *orelse = NULL);

	virtual ~If() {};

	AstNode *test;

	// sequence of ops for body
	AstNodes body;

	// sequence of ops for else block
	AstNodes orelse;

	void SetTest(AstNode *_test);
	void SetBody(AstNode *_body);
	void SetOrElse(AstNode *_orelse);

	If *GetTerminalElif();

	virtual int Accept(class AstVisitor*);


};

/**
 * Expressions such as attributes or function calls may be chained, i.e.
 *
 * a.b.c().d, etc...
 *
 * This sequence is represented as
 * attr(
 *   name='d',
 *   value=call(
 *     func=attr(
 *       name='c'
 *       value=attr(
 *         value=attr(
 *         name='b'
 *         value='a'
 *         )
 *       )
 *     )
 *   )
 * )
 *
 * The ExprSeq provides a consistent way for the parser to set the
 * base epxression.
 */
class ExprSeq
{
public:
	/**
	 * Sets the immediate base (parent) expression of the current node
	 */
	virtual void SetBaseExpr(AstNode *base) = 0;

	/**
	 * As these are chained expressions, this gets the terminal, or
	 * inner-most expression.
	 *
	 * The parser first builds the expression sequence from 1:n, then
	 * once the 1:n sequence is built, the 0'th term is added.
	 */
	virtual ExprSeq *GetTerminalExpr() = 0;
	virtual ~ExprSeq() {};
};


/**
 * Function or method call
 */
class Call : public Expr, public ExprSeq
{
public:

	Call(Ast *ast, const location& loc, AstNode *argsTuple = NULL);

	virtual ~Call() {};

	/**
	 * Name expression of function being called.
	 */
	AstNode* func;

	/**
	 * List of standard arguments
	 */
	AstNodes args;

	/**
	 * List of arguments given with keywords, i.e. foo(kw1=5, kw3=3)
	 */
	KeywordArgs kwArgs;

	/**
	 * The single starred argument, treated as a list
	 */
	AstNode *starArg;

	/**
	 * The double starred argunment, treated as a dict
	 */
	AstNode *kwArg;

	/**
	 * catergorize the given argument and add it to the appropriate
	 * arg list.
	 */
	void AddArg(AstNode *arg);

	/**
	 * set the func (or object) this is calling
	 */
	void SetFunc(AstNode *f);

	/**
	 * When the Call expr is first created, the base is not known,
	 * this method allows the parser to set the base once it is known.
	 *
	 * The base for a func call is the func expression.
	 */
	virtual void SetBaseExpr(AstNode *base);

	virtual ExprSeq *GetTerminalExpr();

	virtual int Accept(class AstVisitor*);
};



class Attribute : public Expr, public ExprSeq
{
public:
	Attribute(class Ast* _ast, const location& _loc,  ExprContext _ctx, AstNode* _value,
			AstNode *_attr);

	virtual ~Attribute() {};

	/**
	 * load, store???
	 */
	ExprContext ctx;

	/**
	 * The object from which the attribute is requested
	 */
	AstNode *value;

	/**
	 * name of attribute being requested
	 */
	Identifier attr;

	void SetValue(AstNode *_value);

	void SetAttr(AstNode *_attr);

	/**
	 * When the Attribute expr is first created, the base is not known,
	 * this method allows the parser to set the base once it is known.
	 *
	 * The base for an Attribute expr is the value expression.
	 */
	virtual void SetBaseExpr(AstNode *base);

	virtual ExprSeq *GetTerminalExpr();

	virtual int Accept(class AstVisitor*);
};





} /* namespace py */
#endif /* _INCLUDED_EXPRESSION_H_ */

