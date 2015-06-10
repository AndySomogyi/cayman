/*
 * Statement.h
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_STATEMENT_H_
#define _INCLUDED_STATEMENT_H_

#include "AstNode.h"
#include <vector>

namespace py
{

class Stmt : public AstNode
{
public:
	Stmt(class Ast* _ast, const location &_loc) : AstNode(_ast, _loc) {};
	virtual ~Stmt() {};
};


class Assign : public Stmt
{
public:

    /**
     * create a basic assignment statement with only a single value (what is being assigned), 
     * and a single target (what is being assigned to)
     */
    Assign(class Ast *_ast, const location &_loc, AstNode *target, AstNode *value);


	Assign(class Ast *_ast, const location &_loc, const AstNodes &_targets, AstNode *_value) :
		Stmt(_ast, _loc), targets(_targets), value(_value) {};

	virtual ~Assign() {};

	AstNodes targets;
	AstNode *value;


    /**
     * Adds a new value to this node, and shifts the previous value 
     * to a target.
     */
    void AddValue(AstNode *_value);

    virtual int Accept(class AstVisitor*);

};

} /* namespace py */
#endif /* _INCLUDED_STATEMENT_H_ */

