/*
 * AST.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#include <AST.h>
#include <Ast.h>

namespace py
{

Ast::Ast() : AstNode(this, location())
{
	// TODO Auto-generated constructor stub

}

Ast::~Ast()
{

}

Assign* Ast::CreateAssign(const location& loc, const AstNodes& targets,
		class Expr* value)
{
	Assign *n = new Assign(this, loc, targets, value);

	nodes.push_back(n);

	return n;
}

Name* Ast::CreateName(location& loc, const char* begin, const char* end)
{
	Name *n = new Name(this, loc, begin, end);
	nodes.push_back(n);
	return n;
}

Assign* Ast::CreateAssign(const location& loc, AstNode* target, AstNode* value)
{
	Assign *n = new Assign(this, loc, target, value);
	nodes.push_back(n);
	return n;
}

Num* Ast::CreateNum(const location& loc, const char* begin, const char* end)
{
	Num *n = new Num(this, loc, begin, end);
	nodes.push_back(n);
	return n;
}

} /* namespace py */
