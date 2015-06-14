/*
 * Expression.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#include "Expr.h"
#include "AstVisitor.h"

namespace py
{


// TODO replace these with a table, this is super inefficient
static AstNode add;
static AstNode sub;
static AstNode mult;
static AstNode div;
static AstNode mod;
static AstNode pow;
static AstNode lShift;
static AstNode rShift;
static AstNode bitOr;
static AstNode bitXor;
static AstNode bitAnd;
static AstNode floorDiv;

AstNode *Op::Add = &add;
AstNode *Op::Sub = &sub;
AstNode *Op::Mult = &mult;
AstNode *Op::Div = &div;
AstNode *Op::Mod = &mod;
AstNode *Op::Pow = &pow;
AstNode *Op::LShift = &lShift;
AstNode *Op::RShift = &rShift;
AstNode *Op::BitOr = &bitOr;
AstNode *Op::BitXor = &bitXor;
AstNode *Op::BitAnd = &bitAnd;
AstNode *Op::FloorDiv = &floorDiv;




Expr::~Expr()
{
	AstNode *p = Op::Add;
}

int BinOp::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

OperatorType Op::GetOperatorType(const AstNode* node)
{
	if (node == Op::Add) {
		return py::Add;
	}


    if (node == Op::Sub) {
        return py::Sub;
    }
    
	if (node == Op::Mult) {
        return py::Mult;
    }
    
	if (node == Op::Div) {
        return py::Div;
    }
    
	if (node == Op::Mod) {
        return py::Mod;
    }
    
	if (node == Op::Pow) {
        return py::Pow;
    }
    
	if (node == Op::LShift) {
        return py::LShift;
    }
    
	if (node == Op::RShift) {
        return py::RShift;
    }
    
	if (node == Op::BitOr) {
        return py::BitOr;
    }
    
	if (node == Op::BitXor) {
        return py::BitXor;
    }
    
	if (node == Op::BitAnd) {
        return py::BitAnd;
    }
    
	if (node == Op::FloorDiv) {
        return py::FloorDiv;
    }

    assert(0);

    return py::Add;
}

} /* namespace py */


