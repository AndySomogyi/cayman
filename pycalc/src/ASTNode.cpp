/*
 * ASTNode.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#include <ASTNode.h>


namespace py
{

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

