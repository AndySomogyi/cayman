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


class Arg : public AstNode
{
public:
	Arg(class Ast* ast, const location& loc, const std::string& id, class Expr *def=NULL, class Expr *type=NULL) :
		AstNode(ast, loc), id(id), def(def), type(type) {};

	virtual ~Arg() {};


	virtual int Accept(AstVisitor *v);

	std::string id;
	class Expr *def;
	class Expr* type;
};

class Arguments
{
public:
	Arguments() :
		vararg(NULL), kwArg(NULL) {};

	/**
	 * list of named arguments
	 */
	AstNodes args;

	/**
	 * default values for args, may be less than size of args,
	 * defaults apply the tail of the args, i.e.
	 *
	 * foo(a, b, c=1, d=2, e=3)
	 * args: a, b, c, d, e
	 * defaults: 1, 2, 3
	 */
	AstNodes defaults;

	/**
	 * keyword only args, named args that appear after a stared arg, i.e.
	 *
	 * foo(a, b, *args, kw1, kw2, kw3, **dargs)
	 */
	AstNodes kwOnlyArgs;

	/**
	 * list of same length as kwOnlyArgs, if a kwOnlyArg does not have
	 * default, then the coresponding item in this list is NULL.
	 */
	AstNodes kwDefaults;

	/**
	 * named of the starred argument.
	 */
	AstNode *vararg;

	/**
	 * name of the double starred argument
	 */
	AstNode *kwArg;
};




/**
 * An internal tmp object used by the parser to build the AST.
 */
class TmpArguments : public Arguments, public AstNode
{
public:

	TmpArguments(class Ast *ast, const location& loc) :
		AstNode(ast, loc), Arguments() {};

	~TmpArguments() {};

	void SetKwOnlyArgs(AstNode *node);

	void SetArgs(AstNode *node);

	void SetVararg(AstNode *node);

	void SetKwArg(AstNode *node);

	virtual int Accept(AstVisitor *)
	{
		assert(0);
		return 0;
	}
};





class FunctionDef : public Arguments, public Stmt
{
public:
	FunctionDef(Ast *ast, const location& loc) :
		Stmt(ast, loc), Arguments(), returns(NULL) {};


	FunctionDef(Ast *ast, const location& loc, AstNode *name, AstNode *args, AstNode *suite);


	virtual ~FunctionDef() {};

	virtual int Accept(AstVisitor *);

	AstNodes body;

	AstNode *returns;
};

} /* namespace py */


#endif /* _INCLUDED_STATEMENT_H_ */

