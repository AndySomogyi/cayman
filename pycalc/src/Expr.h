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


/**
 * The single line ternary if then else operator,
 * An expression such as a if b else c.
 *
 * Unlike the more general If class, each field holds a single node,
 * as opposed to a block
 */
class IfExpr : public Expr
{
public:
	IfExpr(class Ast* _ast, const location& _loc,  AstNode *_test = NULL,
			AstNode *_body = NULL, AstNode *orelse = NULL);

	virtual ~IfExpr() {};

	AstNode *test;
	AstNode *body;
	AstNode *orelse;

	void SetTest(AstNode *_test);
	void SetBody(AstNode *_body);
	void SetOrElse(AstNode *_orelse);

	virtual int Accept(class AstVisitor*);
};

/**
 * A unary operation
 *
 * Uses the same enum from OperatorType, except here, the
 * operator is applied to the operand.
 */
class UnaryOp : public Expr
{
public:
	UnaryOp(class Ast* _ast, const location& _loc,
			OperatorType op, AstNode *operand);

	virtual ~UnaryOp() {};

	OperatorType op;

	AstNode *operand;


	void SetOp(OperatorType op);
	void SetOperand(AstNode *operand);

	virtual int Accept(class AstVisitor*);
};


typedef std::vector<OperatorType> OperatorTypes;

/**
 * Python has a peculiar syntax where "x < 4 < 5 > 3" is actually
 * a sequence of compares and'ed together, it actually evaluates
 * (x < 4) && (4 < 5) && (5 > 3). So, this node stores a length N 
 * sequence of operands, and a length (N - 1) sequence of compare operators.
 * 
 * The operator list must be >= 2, and the operand list must be >= 1. 
 * 
 * -- need sequences for compare to distinguish between
 * -- x < 4 < 3 and (x < 4) < 3
 */
class Compare : public Expr
{
public:
    /**
     * Creates a Compare node with two operands and a single operator.
     */
	Compare(class Ast* ast, const location& loc, AstNode *lhs, 
            OperatorType op, AstNode *rhs);
			

	virtual ~Compare() {};

    AstNodes operands;

    OperatorTypes operators;

    /**
     * append an operator and operand to the sequence.
     */
    void Append(OperatorType op, AstNode *operand);
    

	virtual int Accept(class AstVisitor*);
};


class Lambda : public Expr
{
public:
	Lambda(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~Lambda() {};

	virtual int Accept(class AstVisitor*);
};

class Dict : public Expr
{
public:
	Dict(class Ast* ast, const location& loc, AstNode *key = NULL, AstNode *value = NULL) ;

	virtual ~Dict() {};

	AstNodes keys;
	AstNodes values;

	void AddKeyValue(AstNode *key, AstNode *value);

	virtual int Accept(class AstVisitor*);
};

class Set : public Expr
{
public:
	Set(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~Set() {};

	virtual int Accept(class AstVisitor*);
};

class ListComp : public Expr
{
public:
	ListComp(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~ListComp() {};

	virtual int Accept(class AstVisitor*);
};

class SetComp : public Expr
{
public:
	SetComp(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~SetComp() {};

	virtual int Accept(class AstVisitor*);
};

class DictComp : public Expr
{
public:
	DictComp(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~DictComp() {};

	virtual int Accept(class AstVisitor*);
};

class GeneratorExpr : public Expr
{
public:
	GeneratorExpr(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~GeneratorExpr() {};

	virtual int Accept(class AstVisitor*);
};

class Yield : public Expr
{
public:
	Yield(class Ast* ast, const location& loc, AstNode *_value) :
        Expr(ast, loc), value(_value) {};

	virtual ~Yield() {};
    
    AstNode *value;

	virtual int Accept(class AstVisitor*);
};

class YieldFrom : public Expr
{
public:
	YieldFrom(class Ast* ast, const location& loc, AstNode *_value) :
        Expr(ast, loc), value(_value) {};

	virtual ~YieldFrom() {};
    
    AstNode *value;

	virtual int Accept(class AstVisitor*);
};


class Bytes : public Expr
{
public:
	Bytes(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~Bytes() {};

	virtual int Accept(class AstVisitor*);
};

class NameConstant : public Expr
{
public:
	NameConstant(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~NameConstant() {};

	virtual int Accept(class AstVisitor*);
};

class Subscript : public Expr
{
public:
	Subscript(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~Subscript() {};

	virtual int Accept(class AstVisitor*);
};

class List : public Expr
{
public:
	List(class Ast* ast, const location& loc) : Expr(ast, loc) {};

	virtual ~List() {};

	virtual int Accept(class AstVisitor*);
};


} /* namespace py */
#endif /* _INCLUDED_EXPRESSION_H_ */

