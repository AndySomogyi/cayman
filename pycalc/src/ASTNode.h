/*
 * ASTNode.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef PY_ASTNODE_H_
#define PY_ASTNODE_H_

#include <ostream>
#include "location.hh"

namespace py
{

class AstNode
{
public:
	AstNode();
	virtual ~AstNode();

	virtual void Print(std::ostream&) const = 0;

protected:

	// region of source code where this syntax item was defined,
	// currently use the bison provided location (it works), but
	// in future, might move to differnt one if we replace bison based
	// parser with something else.
	location loc;
};

} /* namespace py */

// define these in std namespace
namespace std
{
ostream& operator<<(ostream& os, const py::AstNode& node);
ostream& operator<<(ostream& os, const py::AstNode* node);
}

#endif /* PYCALC_SRC_ASTNODE_H_ */
