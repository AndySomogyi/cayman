/*
 * AST.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */


#include "Ast.h"
#include "AstVisitor.h"
#include "AstPrinter.h"

namespace py
{

Ast::Ast() : AstNode(this, location())
{
	// TODO Auto-generated constructor stub

}

Ast::~Ast()
{

}

int Ast::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

void Ast::Print(std::ostream& os)
{
	AstPrinter printer(os);

	printer.Visit(this);
}

Module *Ast::CreateModule(const location &loc, const AstNodes &body)
{
	Module *n = new Module(this, loc, body);
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
