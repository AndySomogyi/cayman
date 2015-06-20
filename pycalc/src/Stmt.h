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


	FunctionDef(Ast *ast, const location& loc, AstNode *name, AstNode *args,
			AstNode *returns, AstNode *suite);

	virtual ~FunctionDef() {};

	virtual int Accept(AstVisitor *);
    
    /**
     * Adds a list of decorators from a tuple
     */
    void AddDecorators(AstNode *tuple);

	Identifier name;
    
    AstNodes decorators;

	AstNodes body;
    
    /**
     * The type of the return value
     */
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

	virtual int Accept(class AstVisitor*);
};


class Return: public Stmt
{
public:

	Return(class Ast *ast, const location &loc, AstNode *_expr) : Stmt(ast, loc), value(_expr) {};

	virtual ~Return() {};

	AstNode *value;

	virtual int Accept(class AstVisitor*);
};

class Pass: public Stmt
{
public:

	Pass(class Ast *ast, const location &loc) : Stmt(ast, loc) {};

	virtual ~Pass() {};

	virtual int Accept(class AstVisitor*);
};

class Break: public Stmt
{
public:

	Break(class Ast *ast, const location &loc) : Stmt(ast, loc) {};

	virtual ~Break() {};

	virtual int Accept(class AstVisitor*);
};

class Continue: public Stmt
{
public:

	Continue(class Ast *ast, const location &loc) : Stmt(ast, loc) {};

	virtual ~Continue() {};

	virtual int Accept(class AstVisitor*);
};

class While: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	While(class Ast *ast, const location &loc, AstNode *_expr) : Stmt(ast, loc), expr(_expr) {};

	virtual ~While() {};

	AstNode *expr;

	virtual int Accept(class AstVisitor*);
};



class Raise: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	Raise(class Ast *ast, const location &loc, AstNode *_exc, AstNode *_cause) :
    Stmt(ast, loc), exc(_exc), cause(_cause) {};

	virtual ~Raise() {};

	AstNode *exc;
    AstNode *cause;

	virtual int Accept(class AstVisitor*);
};


class Try: public Stmt
{
public:

	/**
	 * create a basic assignment statement with only a single value (what is being assigned),
	 * and a single target (what is being assigned to)
	 */
	Try(class Ast *ast, const location &loc, AstNode *_expr) : Stmt(ast, loc), expr(_expr) {};

	virtual ~Try() {};

	AstNode *expr;

	virtual int Accept(class AstVisitor*);
};


class Assert: public Stmt
{
public:

	Assert(class Ast *ast, const location &loc, AstNode *_test, AstNode *_msg=NULL);

	virtual ~Assert() {};

	AstNode *test;

	AstNode *msg;

	virtual int Accept(class AstVisitor*);
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

	virtual int Accept(class AstVisitor*);
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

	virtual int Accept(class AstVisitor*);
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
	virtual int Accept(class AstVisitor*) { assert(0); return 0; }
};


class Global: public Stmt
{
public:
	Global(class Ast *ast, const location &loc, AstNode *names);

	virtual ~Global() {};

	Identifiers names;

	virtual int Accept(class AstVisitor*);
};

class NonLocal: public Stmt
{
public:
	NonLocal(class Ast *ast, const location &loc, AstNode *names);

	virtual ~NonLocal() {};

	Identifiers names;

	virtual int Accept(class AstVisitor*);
};

class ClassDef: public Stmt
{
public:
	ClassDef(class Ast *ast, const location &loc, AstNode *names);

	virtual ~ClassDef() {};

	AstNode *expr;

	virtual int Accept(class AstVisitor*);
};


} /* namespace py */
#endif /* _INCLUDED_STATEMENT_H_ */

