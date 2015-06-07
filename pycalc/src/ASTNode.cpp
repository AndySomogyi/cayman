/*
 * ASTNode.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#include <ASTNode.h>

namespace py
{

AstNode::AstNode()
{
	// TODO Auto-generated constructor stub

}

AstNode::~AstNode()
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
	node->Print(os);
	return os;
}

}

