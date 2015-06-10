/*
 * ASTNode.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#include "AstNode.h"
#include "AstVisitor.h"
#include "py_parser.hh"


namespace py
{

AstNodeSeq* AstNodeSeq::Add(const location& loc, AstNode* seq, AstNode* node)
{
	AstNodeSeq *nodes = NULL;
	if (seq)
	{
		nodes = dynamic_cast<AstNodeSeq*>(seq);

		if (!nodes) {
			throw syntax_error(location(), "seq must be NULL or an existing AstNodeSeq");
		}
	}
	else
	{
		nodes = new AstNodeSeq(loc);
	}

	nodes->seq.push_back(node);
	return nodes;
}

Name::Name(class Ast* ast, const location& loc, const char* begin,
           const char* end) :
    AstNode(ast, loc)
{
}

Num::Num(class Ast* ast, const location& loc, const char* begin,
         const char* end) :
    AstNode(ast, loc)
{
}


Str::Str()
{
	// TODO Auto-generated constructor stub

}

Str::~Str()
{
	// TODO Auto-generated destructor stub
}

int Name::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Num::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Str::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Module::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

} /* namespace py */


namespace std
{

ostream& operator<<(ostream& os, const py::AstNode& node)
{
	node.Print(os);
	return os;
}

ostream& operator<<(ostream& os, const py::AstNode* node)
{
	if (node)
	{
		node->Print(os);
	}
	else
	{
		os << "AstNode";
	}
	return os;
}

}


