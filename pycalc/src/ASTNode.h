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

class AstNode
{
public:
	AstNode(class Ast* _ast, const location &_loc) : ast(_ast), loc(_loc) {};

	AstNode() : ast(0) {assert(0);};

	virtual ~AstNode() {};

	virtual void Print(std::ostream&) const {};

	virtual int Accept(class AstVisitor*) = 0;

	// region of source code where this syntax item was defined,
	// currently use the bison provided location (it works), but
	// in future, might move to differnt one if we replace bison based
	// parser with something else.
	location loc;
    
    protected:

	/**
	 * the root AST object that ownes this node.
	 */
	class Ast *ast;
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
	AstNodeSeq(const location& loc) : AstNode(NULL, loc) {};
	virtual ~AstNodeSeq() {};

	AstNodes seq;

	/**
	 * If seq is an existing sequence, node is added to it, and
	 * the appended sequence is returned. If seq is NULL, a new sequence
	 * is created with node, and returned.
	 */
	static AstNodeSeq *Add(const location& loc, AstNode *seq, AstNode *node);

	virtual int Accept(class AstVisitor*)
	{
		assert("AstNodeSeq is not visitable" && 0);
		return 0;
	}
};

enum ExprContext { Load=1, Store=2, Del=3, AugLoad=4, AugStore=5,
                   Param=6, UnknownCtx=7};

class Tuple : public AstNode
{
public:
	Tuple(class Ast* ast, const location &loc, const AstNodes &items, ExprContext ctx) :
		AstNode(ast, loc), items(items), ctx(ctx) {};

	Tuple(class Ast* _ast, const location &_loc, ExprContext ctx) :
		AstNode(ast, loc), ctx(ctx) {};

	virtual ~Tuple() {};

	AstNodes items;

	ExprContext ctx;

	virtual int Accept(class AstVisitor*);
};


class Name : public AstNode
{
public:
	Name(class Ast *ast, const location &loc, const char* begin, const char* end);
	virtual ~Name() {};

	// TODO, ineffecient, need to share names
	std::string id;

	ExprContext ctx;

	virtual int Accept(class AstVisitor*);
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

	enum {Int32, UInt32, Float, Double} type;


	union
	{
		int32_t int32Value;
		uint32_t uint32Value;
		float floatValue;
		double doubleValue;
	};

	virtual ~Num() {};

	virtual int Accept(class AstVisitor*);
};


class Str : public AstNode
{
public:
	Str();
	virtual ~Str();

	virtual int Accept(class AstVisitor*);

	std::string str;
};


class Module : public AstNode
{
public:
	Module(class Ast *ast, const location& loc, const AstNodes &body) :
		AstNode(ast, loc), body(body) {};
	virtual ~Module() {};

	AstNodes body;

	virtual int Accept(class AstVisitor*);


};

} /* namespace py */

// define these in std namespace
namespace std
{
ostream& operator<<(ostream& os, const py::AstNode& node);
ostream& operator<<(ostream& os, const py::AstNode* node);
}



#endif /* _INCLUDED_ASTNODE_H_ */

