/*
 * ASTNode.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_ASTNODE_H_
#define _INCLUDED_ASTNODE_H_

#include <ostream>
#include <vector>
#include <stdint.h>
#include "location.hh"
#include "assert.h"


namespace py
{

/**
 * name or identifier.
 *
 * TODO, it is very inneficient to store ids as std::strings,
 * much duplication, come up with more effecient storage scheme.
 */
typedef std::string Identifier;

typedef std::vector<Identifier> Identifiers;

enum AstNodeType {
	AST_ALIASNODE,
    AST_ARG,
    AST_AST,
	AST_NODE,
    AST_NODESEQ,
    AST_TOKEN,
    AST_DBLSTARRED,
    AST_KEYWORDARG,
    AST_MODULE,
    AST_NAME,
    AST_NUM,
    AST_STARRED,
    AST_STR,
    AST_TMPARGUMENTS,
    AST_TUPLE,

    // All AstStmt derived nodes must follow AST_STMT for llvm RTTI to work correctly.
    AST_STMT,
    AST_ASSERT,
    AST_ASSIGN,
    AST_AUGASSIGN,
    AST_BREAK,
    AST_CLASSDEF,
    AST_CONTINUE,
    AST_DELETE,
    AST_FOR,
    AST_FUNCTIONDEF,
    AST_GLOBAL,
    AST_IF,
    AST_IMPORT,
    AST_IMPORTFROM,
    AST_NONLOCAL,
    AST_PASS,
    AST_RAISE,
    AST_RETURN,
    AST_TRY,
    AST_WHILE,

    // All AstExpr derived nodes must follow AST_EXPR for llvm RTTI
    AST_EXPR,
    AST_ATTRIBUTE,
    AST_BINOP,
    AST_BYTES,
    AST_CALL,
    AST_COMPARE,
    AST_DICT,
    AST_DICTCOMP,
    AST_GENERATOREXPR,
    AST_IFEXPR,
    AST_LAMBDA,
    AST_LIST,
    AST_LISTCOMP,
    AST_NAMECONSTANT,
    AST_SET,
    AST_SETCOMP,
    AST_SUBSCRIPT,
    AST_UNARYOP,
    AST_YIELD,
    AST_YIELDFROM
};


enum ExprContext { Load=1, Store=2, Del=3, AugLoad=4, AugStore=5,
                   Param=6, UnknownCtx=7};


class AstNode
{
public:
    const AstNodeType type;
    

	AstNode(AstNodeType _type, class Ast* _ast, const location &_loc) :
		type(_type), loc(_loc), ast(_ast), flags(0) {};

	AstNode() : type(AST_NODE), ast(0), flags(0) {};

	virtual ~AstNode() {};

	virtual void Print(std::ostream&) const {};

	// region of source code where this syntax item was defined,
	// currently use the bison provided location (it works), but
	// in future, might move to differnt one if we replace bison based
	// parser with something else.
	location loc;

	/**
	 * Is this a terminal node, i.e. a primitive, or surounded by parenthesis,
	 * so (a < b < c) should be atomic.
	 */
	bool IsAtomic() { return flags & ATOMIC; }

	void SetAtomic(bool atomic)
    {
        if (atomic) {
            flags |= ATOMIC;
        } else {
            flags &= ~ATOMIC;
        }
    }

	virtual void setContext(ExprContext)
	{
		assert(0 && "Can not set expression context for node type");
	}
    
    protected:

	AstNode(AstNodeType _type, class Ast* _ast, const location &_loc, uint32_t _flags) :
		type(_type), loc(_loc), ast(_ast), flags(_flags) {};

	enum FlagFields
	{
		ATOMIC = 1,
	};

	/**
	 * the root AST object that ownes this node.
	 */
	class Ast *ast;

	uint32_t flags;
};
    
typedef std::vector<AstNode*> AstNodes;


/**
 * A temp Ast node type that never occurs in a built tree, but is used
 * by the parser to construct the tree.
 *
 * These are only created in internal grammar rules.
 */
class AstNodeSeq : public AstNode
{
public:
	AstNodeSeq(const location& loc) : AstNode(AST_NODESEQ, NULL, loc) {};
	virtual ~AstNodeSeq() {};

	AstNodes seq;

	/**
	 * If seq is an existing sequence, node is added to it, and
	 * the appended sequence is returned. If seq is NULL, a new sequence
	 * is created with node, and returned.
	 */
	static AstNodeSeq *Add(const location& loc, AstNode *seq, AstNode *node);

};

class Tuple : public AstNode
{
public:
	Tuple(class Ast* ast, const location &loc, const AstNodes &items, ExprContext ctx) :
		AstNode(AST_TUPLE, ast, loc, ATOMIC), items(items), ctx(ctx) {};

	Tuple(class Ast* _ast, const location &_loc, ExprContext ctx) :
		AstNode(AST_TUPLE, ast, loc), ctx(ctx) {};

	virtual ~Tuple() {};

	void setContext(ExprContext _ctx) override {
		ctx = _ctx;
	}

	AstNodes items;

	ExprContext ctx;
};

/**
 * A name or identifier. 
 *
 * Names can be dotted, i.e. having multiple hierarchical names, a.b.c.
 *
 * TODO: this storage scheme is horribly inefficient, come up with better
 * system of globally storing unique ids.
 */
class Name : public AstNode
{
public:
	Name(class Ast *ast, const location &loc, const char* begin, const char* end);
	virtual ~Name() {};

    /**
     * The full name, may be dotted
     */
	// TODO, inefficient, need to share names
	std::string id;

	ExprContext ctx;

	void setContext(ExprContext _ctx) override {
		ctx = _ctx;
	}
    
    void AppendName(AstNode *name);
    
    void PrependName(AstNode *name);
    
private:
    /**
     * sequence of dotted names
     */
    std::vector<std::string> ids;
};





class Num : public AstNode
{
public:

	/**
	 * Parse the string of begin -> end for a numeric type.
	 *
	 * Based on the string, either an int, float, double, etc...
	 * is created.
	 */
	Num(class Ast *ast, const location &loc, const char* begin, const char* end);

	/**
	 * the textual value of the numeric literal
	 */
	std::string value;

	virtual ~Num() {};
};


class Str : public AstNode
{
public:
	Str(class Ast *ast, const location &loc, const char* begin, const char* end);
	virtual ~Str() {};

	virtual void Print(std::ostream&) const;

	std::string value;
};


class Module : public AstNode
{
public:
	Module(class Ast *ast, const location& loc, const AstNodes &body) :
		AstNode(AST_MODULE, ast, loc), body(body) {};
	virtual ~Module() {};

	AstNodes body;
};

/**
 * A starred expression, i.e. *a, *(a, b, c)
 */
class Starred : public AstNode
{
public:
	Starred(class Ast* ast, const location &loc, AstNode *_value, ExprContext ctx = UnknownCtx) :
		AstNode(AST_STARRED, ast, loc), value(_value), ctx(ctx) {};

	virtual ~Starred() {};

	AstNode *value;

	ExprContext ctx;

	void setContext(ExprContext _ctx) override {
		ctx = _ctx;
	}
};

/**
 * A double starred expression, i.e. *a, *(a, b, c),
 *
 * Only valid inside of an arglist.
 *
 * This class is NOT meant to be added to a AST tree, this is only
 * used internally by the parser to return a double starred expr
 * in an arglist
 */
class DblStarred : public AstNode
{
public:
	DblStarred(class Ast* ast, const location &loc, AstNode *_value) :
		AstNode(AST_DBLSTARRED, ast, loc), value(_value) {};

	virtual ~DblStarred() {};

	AstNode *value;
};

// typedef enum _unaryop { Invert=1, Not=2, UAdd=3, USub=4 }
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

	// special operations only valid in unary
	Not,

	Invert,

	// comparisons,  comp_op: '<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'

	// comparisons start at the Eq operator.
	Eq,             // "=="
	NotEq,          // "!="
	Lt,             // "<"
	LtEq,           // "<="
	Gt,             // ">"
	GtEq,           // ">="
	Is,             // "is"
	IsNot,          // "is" "not"
	In,             // "in"
	NotIn,          // "not" "in"

	And,
	Or,

	// keep this as the last operator, to know the number of operators
	// we have, this is NOT a valid operator type.
	EndOp
};

} /* namespace py */

// define these in std namespace
namespace std
{
ostream& operator<<(ostream& os, const py::AstNode& node);
ostream& operator<<(ostream& os, const py::AstNode* node);
}



#endif /* _INCLUDED_ASTNODE_H_ */

