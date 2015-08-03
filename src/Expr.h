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
	Expr(AstNodeType _type, class Ast* _ast, const location &_loc) : Stmt(_type, _ast, _loc) {};
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
			Expr(AST_BINOP, _ast, _loc), op(_op), left(_left), right(_right)
	{
	}
	;

	virtual ~BinOp(){};

	OperatorType op;

	AstNode *left;
	AstNode *right;

	static bool classof(const AstNode *node) {
		return node->type == AST_BINOP;
	}

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

	static bool classof(const AstNode *node) {
		return node->type == AST_CALL;
	}
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

	static bool classof(const AstNode *node) {
		return node->type == AST_ATTRIBUTE;
	}
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

	static bool classof(const AstNode *node) {
		return node->type == AST_IFEXPR;
	}


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

	static bool classof(const AstNode *node) {
		return node->type == AST_UNARYOP;
	}

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
    
	static bool classof(const AstNode *node) {
		return node->type == AST_COMPARE;
	}



};


class Lambda : public Expr
{
public:
	Lambda(class Ast* ast, const location& loc) : Expr(AST_LAMBDA, ast, loc) {};

	virtual ~Lambda() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_LAMBDA;
	}


};

class Dict : public Expr
{
public:
	Dict(class Ast* ast, const location& loc, AstNode *key = NULL, AstNode *value = NULL) ;

	virtual ~Dict() {};

	AstNodes keys;
	AstNodes values;

	void AddKeyValue(AstNode *key, AstNode *value);

	static bool classof(const AstNode *node) {
		return node->type == AST_DICT;
	}


};

class Set : public Expr
{
public:
	Set(class Ast* ast, const location& loc) : Expr(AST_SET, ast, loc) {};

	virtual ~Set() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_SET;
	}


};

class ListComp : public Expr
{
public:
	ListComp(class Ast* ast, const location& loc) : Expr(AST_LISTCOMP, ast, loc) {};

	virtual ~ListComp() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_LISTCOMP;
	}


};

class SetComp : public Expr
{
public:
	SetComp(class Ast* ast, const location& loc) : Expr(AST_SETCOMP, ast, loc) {};

	virtual ~SetComp() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_SETCOMP;
	}


};

class DictComp : public Expr
{
public:
	DictComp(class Ast* ast, const location& loc) : Expr(AST_DICTCOMP, ast, loc) {};

	virtual ~DictComp() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_DICTCOMP;
	}


};

class GeneratorExpr : public Expr
{
public:
	GeneratorExpr(class Ast* ast, const location& loc) : Expr(AST_GENERATOREXPR, ast, loc) {};

	virtual ~GeneratorExpr() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_GENERATOREXPR;
	}


};

class Yield : public Expr
{
public:
	Yield(class Ast* ast, const location& loc, AstNode *_value) :
        Expr(AST_YIELD, ast, loc), value(_value) {};

	virtual ~Yield() {};
    
    AstNode *value;

	static bool classof(const AstNode *node) {
		return node->type == AST_YIELD;
	}
};

class YieldFrom : public Expr
{
public:
	YieldFrom(class Ast* ast, const location& loc, AstNode *_value) :
        Expr(AST_YIELDFROM, ast, loc), value(_value) {};

	virtual ~YieldFrom() {};
    
    AstNode *value;

	static bool classof(const AstNode *node) {
		return node->type == AST_YIELDFROM;
	}
};


class Bytes : public Expr
{
public:
	Bytes(class Ast* ast, const location& loc) : Expr(AST_BYTES, ast, loc) {};

	virtual ~Bytes() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_BYTES;
	}
};

class NameConstant : public Expr
{
public:
	enum NameConstantType
	{
		True, False, None
	};

	NameConstant(class Ast* ast, const location& loc,
			NameConstantType _type) : Expr(AST_NAMECONSTANT, ast, loc), value(_type) {};

	virtual ~NameConstant() {};



	NameConstantType value;

	static bool classof(const AstNode *node) {
		return node->type == AST_NAMECONSTANT;
	}
};

class Subscript : public Expr, public ExprSeq
{
public:
	Subscript(class Ast* ast, const location& loc, AstNode *subscript) :
		Expr(AST_SUBSCRIPT, ast, loc) {};

	virtual ~Subscript() {};

	/**
	 * Sets the immediate base (parent) expression of the current node
	 */
	virtual void SetBaseExpr(AstNode *base);

	/**
	 * As these are chained expressions, this gets the terminal, or
	 * inner-most expression.
	 *
	 * The parser first builds the expression sequence from 1:n, then
	 * once the 1:n sequence is built, the 0'th term is added.
	 */
	virtual ExprSeq *GetTerminalExpr();

	static bool classof(const AstNode *node) {
		return node->type == AST_SUBSCRIPT;
	}


};

class List : public Expr
{
public:
	List(class Ast* ast, const location &loc, const AstNodes &items, ExprContext ctx) :
		Expr(AST_LIST, ast, loc), items(items), ctx(ctx) {};

	List(class Ast* _ast, const location &_loc, ExprContext ctx) :
		Expr(AST_LIST, ast, loc), ctx(ctx) {};

	virtual ~List() {};

	AstNodes items;

	ExprContext ctx;

	static bool classof(const AstNode *node) {
		return node->type == AST_LIST;
	}
};


} /* namespace py */
#endif /* _INCLUDED_EXPRESSION_H_ */

