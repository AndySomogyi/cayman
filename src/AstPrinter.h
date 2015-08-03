/*
 * AstPrinter.h
 *
 *  Created on: Jun 9, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_ASTPRINTER_H_
#define _INCLUDED_ASTPRINTER_H_

#include "Ast.h"
#include "AstVisitor.h"
#include <iostream>

namespace py
{

class AstPrinter: private AstVisitor<AstPrinter, int>
{
	// mark the template class as friend so it can call the
	// private visitor methods.
	friend AstVisitor<AstPrinter, int>;


public:
	AstPrinter(std::ostream &os);
	~AstPrinter();
    
    void print(AstNode *node);
    
private:



	int visit(Name*);
	int visit(Num*);
	int visit(Str*);
	int visit(Module*);
	int visit(Assign*);
	int visit(BinOp*);
	int visit(Tuple*);
	int visit(Ast*);
	int visit(Arg*);
	int visit(FunctionDef*);
	int visit(KeywordArg*);
	int visit(Call*);
	int visit(Starred*);
	int visit(For*);
	int visit(If*);
	int visit(Attribute*);
	int visit(IfExpr*);
	int visit(UnaryOp*);
	int visit(AugAssign*);
	int visit(Compare*);
	int visit(Delete*);
    int visit(Return*);
    int visit(Pass*);
    int visit(Break*);
    int visit(Continue*);
    int visit(While*);
    int visit(Raise*);
    int visit(Try*);
    int visit(Assert*);
    int visit(Import*);
    int visit(ImportFrom*);
    int visit(Global*);
    int visit(NonLocal*);
    int visit(ClassDef*);
    int visit(Lambda*);
    int visit(Dict*);
    int visit(Set*);
    int visit(ListComp*);
    int visit(SetComp*);
    int visit(DictComp*);
    int visit(GeneratorExpr*);
    int visit(Yield*);
    int visit(YieldFrom*);
    int visit(Bytes*);
    int visit(NameConstant*);
    int visit(Subscript*);
    int visit(List*);


	std::ostream &os;
    
    void PrintNodes(AstNodes& nodes);
    void PrintAliases(Aliases&);
};

} /* namespace py */

#endif /* _INCLUDED_ASTPRINTER_H_ */
