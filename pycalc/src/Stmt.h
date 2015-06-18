/*
 * Statement.h
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_STATEMENT_H_
#define _INCLUDED_STATEMENT_H_

#include "AstNode.h"
#include <vector>

namespace py
{

class Stmt: public AstNode
{
public:
	Stmt(class Ast* _ast, const location &_loc) :
			AstNode(_ast, _loc)
	{
	}
	;
	virtual ~Stmt()
	{
	}
	;
};

class Assign: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned), 
	 * and a single target (what is being assigned to)
	 */
	Assign(class Ast *_ast, const location &_loc, AstNode *target,
			AstNode *value);

	Assign(class Ast *_ast, const location &_loc, const AstNodes &_targets,
			AstNode *_value) :
			Stmt(_ast, _loc), targets(_targets), value(_value)
	{
	}
	;

	virtual ~Assign()
	{
	}
	;

	AstNodes targets;
	AstNode *value;

	/**
	 * Adds a new value to this node, and shifts the previous value 
	 * to a target.
	 */
	void AddValue(AstNode *_value);

	virtual int Accept(class AstVisitor*);

};

/**
 * Augmented assignment, such as a += 1. In that example, target is a Name node
 * for a (with the Store context), op is Add, and value is a Num node for 1.
 * target can be Name, Subscript or Attribute, but not a Tuple or List
 * (unlike the targets of Assign).
 */
class AugAssign: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	AugAssign(class Ast *ast, const location &loc, AstNode *target,
			OperatorType op, AstNode *value);



	virtual ~AugAssign() {};

	OperatorType op;
	AstNode *target;
	AstNode *value;

	void SetOp(OperatorType op);
	void SetTarget(AstNode *target);
	void SetValue(AstNode *value);

	virtual int Accept(class AstVisitor*);

};


class Arg: public AstNode
{
public:
	Arg(class Ast* ast, const location& loc, const std::string& id,
			AstNode *_def = NULL, AstNode *_type = NULL) :
			AstNode(ast, loc), id(id), def(_def), type(_type)
	{
	}
	;

	virtual ~Arg()
	{
	}
	;

	virtual int Accept(AstVisitor *v);

	std::string id;
	AstNode *def;
	AstNode *type;
};

/**
 * list of arguments
 */
typedef std::vector<Arg*> Args;

class Arguments
{
public:
	Arguments() :
			vararg(NULL), kwarg(NULL)
	{
	}
	;

	/**
	 * list of named arguments
	 */
	Args args;

	/**
	 * keyword only args, named args that appear after a stared arg, i.e.
	 *
	 * foo(a, b, *args, kw1, kw2, kw3, **dargs)
	 */
	Args kwOnlyArgs;

	/**
	 * named of the starred argument.
	 */
	Arg *vararg;

	/**
	 * name of the double starred argument
	 */
	Arg *kwarg;
};

/**
 * An internal tmp object used by the parser to build the AST.
 */
class TmpArguments: public Arguments, public AstNode
{
public:

	TmpArguments(class Ast *ast, const location& loc) :
			Arguments(), AstNode(ast, loc)
	{
	}
	;

	~TmpArguments()
	{
	}
	;

	void SetKwOnlyArgs(AstNode *node);

	void SetArgs(AstNode *node);

	void SetVararg(AstNode *node);

	void SetKwArg(AstNode *node);

	static void ArgsFromTuple(AstNode *node, Args& args);

	virtual int Accept(AstVisitor *)
	{
		assert(0);
		return 0;
	}
};

class FunctionDef: public Arguments, public Stmt
{
public:
	FunctionDef(Ast *ast, const location& loc) :
			Arguments(), Stmt(ast, loc)
	{
	}
	;

	FunctionDef(Ast *ast, const location& loc, AstNode *name, AstNode *args,
			AstNode *suite);

	virtual ~FunctionDef()
	{
	}
	;

	virtual int Accept(AstVisitor *);
    
    /**
     * Adds a list of decorators from a tuple
     */
    void AddDecorators(AstNode *tuple);

	Identifier name;
    
    AstNodes decorators;

	AstNodes body;
};

/**
 * A named argument in a function call
 */
class KeywordArg : public AstNode
{
public:
	KeywordArg(class Ast* ast, const location &loc, const std::string& _arg, AstNode *_value) :
		AstNode(ast, loc), arg(_arg), value(_value) {};

	virtual ~KeywordArg() {};

	std::string arg;

	AstNode *value;

	virtual int Accept(class AstVisitor*);
};

typedef std::vector<KeywordArg*> KeywordArgs;


/**
 * for loop stmt
 *
 *  "for" target "in" iter ":" body
 *  "for" target "in" iter ":" body "else" ":" orelse
 */
class For: public Stmt
{
public:
	For(Ast *ast, const location& loc, AstNode *_target = NULL,
			AstNode *_iter = NULL, AstNode *_body = NULL,
			AstNode *_orelse = NULL);

	virtual ~For() {};

	virtual int Accept(AstVisitor *);

	/**
	 * The variable(s) that the loop assigns to, may be either a
	 * single Name, Tuple or List.
	 */
	AstNode *target;

	/**
	 * The expression that is to be looped over.
	 */
	AstNode *iter;

	/**
	 * sequence of nodes that are executed in the loop body
	 */
	AstNodes body;

	/**
	 * Sequence of nodes that are executed if the loop finishes normally,
	 * rather than via a break statement.
	 */
	AstNodes orelse;


	void SetTarget(AstNode *_target);

	void SetIter(AstNode *_iter);

	void SetBody(AstNode *_body);

	void SetOrElse(AstNode *_orelse);
};


class If : public Stmt
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



} /* namespace py */
#endif /* _INCLUDED_STATEMENT_H_ */

