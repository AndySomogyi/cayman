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

class Name : public AstNode
{
public:
	Name(class Ast *ast, const location &loc, const char* begin, const char* end);
	virtual ~Name() {};
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

	virtual ~Num() {};
};


class Str : public AstNode
{
public:
	Str();
	virtual ~Str();
};

} /* namespace py */

// define these in std namespace
namespace std
{
ostream& operator<<(ostream& os, const py::AstNode& node);
ostream& operator<<(ostream& os, const py::AstNode* node);
}



#endif /* _INCLUDED_ASTNODE_H_ */

