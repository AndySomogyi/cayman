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
			Arguments(), Stmt(ast, loc), returns(NULL)
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

	std::string id;

	AstNodes body;

	AstNode *returns;
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
 * Function or method call
 */
class Call : public Stmt
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


	virtual int Accept(class AstVisitor*);
};



} /* namespace py */
#endif /* _INCLUDED_STATEMENT_H_ */

