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

class AstPrinter: private AstVisitor<AstPrinter, int, int>
{
	typedef AstVisitor<AstPrinter, int, int> Base;
	// mark the template class as friend so it can call the
	// private visitor methods.
	friend Base;


public:
	AstPrinter(std::ostream &os);
	~AstPrinter();
    
    void print(AstNode *node);
    
private:



	int visit(Name*, int);
	int visit(Num*, int);
	int visit(Str*, int);
	int visit(Module*, int);
	int visit(Assign*, int);
	int visit(BinOp*, int);
	int visit(Tuple*, int);
	int visit(Ast*, int);
	int visit(Arg*, int);
	int visit(FunctionDef*, int);
	int visit(KeywordArg*, int);
	int visit(Call*, int);
	int visit(Starred*, int);
	int visit(For*, int);
	int visit(If*, int);
	int visit(Attribute*, int);
	int visit(IfExpr*, int);
	int visit(UnaryOp*, int);
	int visit(AugAssign*, int);
	int visit(Compare*, int);
	int visit(Delete*, int);
    int visit(Return*, int);
    int visit(Pass*, int);
    int visit(Break*, int);
    int visit(Continue*, int);
    int visit(While*, int);
    int visit(Raise*, int);
    int visit(Try*, int);
    int visit(Assert*, int);
    int visit(Import*, int);
    int visit(ImportFrom*, int);
    int visit(Global*, int);
    int visit(NonLocal*, int);
    int visit(ClassDef*, int);
    int visit(Lambda*, int);
    int visit(Dict*, int);
    int visit(Set*, int);
    int visit(ListComp*, int);
    int visit(SetComp*, int);
    int visit(DictComp*, int);
    int visit(GeneratorExpr*, int);
    int visit(Yield*, int);
    int visit(YieldFrom*, int);
    int visit(Bytes*, int);
    int visit(NameConstant*, int);
    int visit(Subscript*, int);
    int visit(List*, int);


	std::ostream &os;
    
    void PrintNodes(AstNodes& nodes);
    void PrintAliases(Aliases&);

    int dispatch(AstNode*);
};

} /* namespace py */

#endif /* _INCLUDED_ASTPRINTER_H_ */
