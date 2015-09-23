/*
 * Statement.h
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_STATEMENT_H_
#define _INCLUDED_STATEMENT_H_

#include "AstNode.h"
#include "cayman_llvm.h"
#include <vector>

class IRGenContext;

namespace py
{

class Stmt: public AstNode
{
public:
	Stmt(AstNodeType _type, class Ast* _ast, const location &_loc) :
    AstNode(_type, _ast, _loc)
	{
	}
	;
	virtual ~Stmt() {};

	static bool classof(const AstNode *node) {
		return node->type >= AST_STMT;
	}

};

class Assign: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned), 
	 * and a single target (what is being assigned to)
	 *
	 * The lhs ctx is set to store, and the rhs is set to load
	 */
	Assign(class Ast *_ast, const location &_loc, AstNode *target,
			AstNode *value);

	Assign(class Ast *_ast, const location &_loc, const AstNodes &_targets,
			AstNode *_value) :
			Stmt(AST_ASSIGN, _ast, _loc), targets(_targets), value(_value)
	{
	}
	;

	virtual ~Assign()
	{
	}
	;

	/**
	 * the lhs(s) of the expression.
	 */
	AstNodes targets;

	/**
	 * the rhs of the expressions
	 */
	AstNode *value;

	/**
	 * Adds a new value to this node, and shifts the previous value 
	 * to a target.
	 *
	 * New values have thier ctx set to load, and the targets get set
	 * to store
	 */
	void addValue(AstNode *_value);

	static bool classof(const AstNode *node) {
		return node->type == AST_ASSIGN;
	}
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

	static bool classof(const AstNode *node) {
		return node->type == AST_AUGASSIGN;
	}
};


class Arg: public AstNode
{
public:
	Arg(class Ast* ast, const location& loc, const std::string& id,
			AstNode *_def = NULL, AstNode *_type = NULL) :
			AstNode(AST_ARG, ast, loc), id(id), def(_def), annotation(_type)
	{
	}
	;

	virtual ~Arg()
	{
	}
	;



	std::string id;

	/**
	 * Default value of argument
	 */
	AstNode *def;

	/**
	 * Type annotation expression.
	 */
	AstNode *annotation;

	static bool classof(const AstNode *node) {
		return node->type == AST_ARG;
	}
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
			Arguments(), AstNode(AST_TMPARGUMENTS, ast, loc)
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

	static bool classof(const AstNode *node) {
		return node->type == AST_TMPARGUMENTS;
	}

};


/**
 * A Funciton definition may be fully specialized if all of the
 * argument annotation expressions evaluate to a valid type. They
 * may be partially specialized of only a subset of annotations
 * evaluate to a type, and fully generalized if there are no annotations
 * or none of them evaluate to a type.
 *
 *
 *
 */
class FunctionDef: public Arguments, public Stmt
{
public:
	FunctionDef(Ast *ast, const location& loc, AstNode *name, AstNode *args,
			AstNode *returns, AstNode *suite, bool _ext = false);

	virtual ~FunctionDef() {};

	/**
	 * copy ctor
	 */
	FunctionDef(const FunctionDef*);
    
    /**
     * Adds a list of decorators from a tuple
     */
    void AddDecorators(AstNode *tuple);

	Identifier name;
    
    AstNodes decorators;

	AstNodes body;

	/**
	 * Is this an external function definition
	 */
	bool ext;
    
    /**
     * The type of the return value
     */
    AstNode *returns;

	static bool classof(const AstNode *node) {
		return node->type == AST_FUNCTIONDEF;
	}
};

class ClassDef: public Stmt
{
public:
	/**
	 * classdef: 'class' NAME ['(' [arglist] ')'] ':' suite
	 *
	 * @param arglist: optional, may be NULL
	 */
	ClassDef(class Ast *ast, const location &loc,
			AstNode *name, AstNode *arglist, AstNode *suite);

	virtual ~ClassDef() {};

	/**
	 * name is a raw string for the class name
	 */
    Identifier name;

	/**
	 * bases is a list of nodes for explicitly specified base classes.
	 */
    AstNodes bases;

    /**
     * keywords is a list of keyword nodes, principally for ‘metaclass’.
     * Other keywords will be passed to the metaclass, as per PEP-3115.
     */
    AstNodes keywords;

    /**
     * starargs and kwargs are each a single node, as in a function call.
     * starargs will be expanded to join the list of base classes.
     */
    AstNode *starargs;

    /**
     * starargs and kwargs are each a single node, as in a function call.
     * kwargs will be passed to the metaclass.
     */
    AstNode *kwargs;

    /**
     * body is a list of nodes representing the code within the class definition.
     */
    AstNodes body;

    /**
     *  a list of nodes, as in FunctionDef.
     */
    AstNodes decorators;

    /**
     * Adds a list of decorators from a tuple
     */
    void AddDecorators(AstNode *tuple);

    /**
     * makes sure the node is a Name and sets the name
     */
	void SetName(AstNode *nm);

	/**
	 * makes sure the node is a tuple, and sets the body.
	 */
	void SetBody(AstNode *suite);

	/**
	 * pulls the required bits out of the arglist
	 */
	void ParseArglist(AstNode *arglist);

	static bool classof(const AstNode *node) {
		return node->type == AST_CLASSDEF;
	}
};


/**
 * A named argument in a function call
 */
class KeywordArg : public AstNode
{
public:
	KeywordArg(class Ast* ast, const location &loc, const std::string& _arg, AstNode *_value) :
		AstNode(AST_KEYWORDARG, ast, loc), arg(_arg), value(_value) {};

	virtual ~KeywordArg() {};

	std::string arg;

	AstNode *value;

	static bool classof(const AstNode *node) {
		return node->type == AST_KEYWORDARG;
	}
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

	static bool classof(const AstNode *node) {
		return node->type == AST_FOR;
	}
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

	static bool classof(const AstNode *node) {
		return node->type == AST_IF;
	}
};


/**
 * Augmented assignment, such as a += 1. In that example, target is a Name node
 * for a (with the Store context), op is Add, and value is a Num node for 1.
 * target can be Name, Subscript or Attribute, but not a Tuple or List
 * (unlike the targets of Assign).
 */
class Delete: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	Delete(class Ast *ast, const location &loc, AstNode *targets);

	virtual ~Delete() {};

	AstNodes targets;

	/**
	 * Add targets to delete. node may be either a simnple node, or a tuple, in which case,
	 * all elements in the tuple are added.
	 */
	void AddTargets(AstNode *node);

	static bool classof(const AstNode *node) {
		return node->type == AST_DELETE;
	}

};


class Return: public Stmt
{
public:

	Return(class Ast *ast, const location &loc, AstNode *_expr) :
		Stmt(AST_RETURN, ast, loc), value(_expr) {};

	virtual ~Return() {};

	AstNode *value;

	static bool classof(const AstNode *node) {
		return node->type == AST_RETURN;
	}
};

class Pass: public Stmt
{
public:

	Pass(class Ast *ast, const location &loc) : Stmt(AST_PASS, ast, loc) {};

	virtual ~Pass() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_PASS;
	}
};

class Break: public Stmt
{
public:

	Break(class Ast *ast, const location &loc) : Stmt(AST_BREAK, ast, loc) {};

	virtual ~Break() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_BREAK;
	}
};

class Continue: public Stmt
{
public:

	Continue(class Ast *ast, const location &loc) : Stmt(AST_CONTINUE, ast, loc) {};

	virtual ~Continue() {};

	static bool classof(const AstNode *node) {
		return node->type == AST_CONTINUE;
	}
};

class While: public Stmt
{
public:

	While(class Ast *ast, const location &loc, AstNode *test, AstNode *body,
			AstNode *orelse=NULL);

	virtual ~While() {};

	/**
	 * The expression that is to be looped over.
	 */
	AstNode *test;

	/**
	 * sequence of nodes that are executed in the loop body
	 */
	AstNodes body;

	/**
	 * Sequence of nodes that are executed if the loop finishes normally,
	 * rather than via a break statement.
	 */
	AstNodes orelse;


	void SetTest(AstNode *_test);

	void SetBody(AstNode *_body);

	void SetOrElse(AstNode *_orelse);

	static bool classof(const AstNode *node) {
		return node->type == AST_WHILE;
	}

};



class Raise: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	Raise(class Ast *ast, const location &loc, AstNode *_exc, AstNode *_cause) :
		Stmt(AST_RAISE, ast, loc), exc(_exc), cause(_cause) {};

	virtual ~Raise() {};

	AstNode *exc;
    AstNode *cause;

	static bool classof(const AstNode *node) {
		return node->type == AST_RAISE;
	}

};


class Try: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	Try(class Ast *ast, const location &loc, AstNode *_expr) : Stmt(AST_TRY, ast, loc), expr(_expr) {};

	virtual ~Try() {};

	AstNode *expr;

	static bool classof(const AstNode *node) {
		return node->type == AST_TRY;
	}

};


class Assert: public Stmt
{
public:

	Assert(class Ast *ast, const location &loc, AstNode *_test, AstNode *_msg=NULL);

	virtual ~Assert() {};

	AstNode *test;

	AstNode *msg;

	static bool classof(const AstNode *node) {
		return node->type == AST_ASSERT;
	}
};

/**
 * mapping of what is imported to what name it should have.
 *
 * Just strings, no need to make a new AstNode here.
 */
struct Alias {
	Alias() {};
	Alias(const Identifier& n, const Identifier& a) : name(n), asname(a) {};
	Identifier name;
	Identifier asname;
};


typedef std::vector<Alias> Aliases;

class Import: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	Import(class Ast *ast, const location &loc, AstNode *names);

	virtual ~Import() {};

	Aliases names;

	static bool classof(const AstNode *node) {
		return node->type == AST_IMPORT;
	}


};

class ImportFrom: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	ImportFrom(class Ast *ast, const location &loc, AstNode *module, AstNode *names, int level);

	virtual ~ImportFrom() {};

	Aliases names;

	Identifier module;
    
    int level;

	void SetModule(AstNode*);

	void SetNames(AstNode*);

	static bool classof(const AstNode *node) {
		return node->type == AST_IMPORTFROM;
	}


};

/**
 * Temprary nodes only used by the parser to build an ImportFrom
 *
 * NOT part of grammar, only used by the parser.
 *
 * TODO, not very effcient, replace with a better way of building the ImportFrom
 * nodes.
 */
class AliasNodes : public AstNode
{
public:
	AliasNodes(class Ast *ast, const location &loc, AstNode *nm, AstNode *asnm);

	virtual ~AliasNodes() {};

	Aliases names;

	void AddAlias(AstNode *name, AstNode *asname);

	/**
	 * not part of grammar, can not be visited.
	 */

	static bool classof(const AstNode *node) {
		return node->type == AST_ALIASNODE;
	}

};


class Global: public Stmt
{
public:
	Global(class Ast *ast, const location &loc, AstNode *names);

	virtual ~Global() {};

	Identifiers names;

	static bool classof(const AstNode *node) {
		return node->type == AST_GLOBAL;
	}


};

class NonLocal: public Stmt
{
public:
	NonLocal(class Ast *ast, const location &loc, AstNode *names);

	virtual ~NonLocal() {};

	Identifiers names;

	static bool classof(const AstNode *node) {
		return node->type == AST_NONLOCAL;
	}
};



} /* namespace py */
#endif /* _INCLUDED_STATEMENT_H_ */

