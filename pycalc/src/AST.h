/*
 * AST.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef PYCALC_SRC_AST_H_
#define PYCALC_SRC_AST_H_

#include "AstNode.h"
#include "cxx11/memory.h"

namespace py
{

class Ast : public AstNode
{
public:
	Ast();
	virtual ~Ast();


private:
	// memory managment details of AST
	// All ASTNodes are owned by the root AST object.
	// All other objects, includeing ASTNodes themselves
	// may contain pointers to ASTNodes, but these are
	// borrowed references, owned by the root AST object.
	// ASTNodes are created by the ASTFactory, and these
	// are added to the AST object. In the future, we
	// may employ some sort of block memory managment scheme
	// such as that used in Google V8, but currently, nodes
	// will just be standard 'new'ed and a pointer added
	// to the root AST.

	friend class ASTNodeFactory;

};

typedef cxx11_ns::shared_ptr<Ast> AstPtr;

} /* namespace py */

#endif /* PYCALC_SRC_AST_H_ */
