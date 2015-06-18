/*
 * AstPrinter.h
 *
 *  Created on: Jun 9, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_ASTPRINTER_H_
#define _INCLUDED_ASTPRINTER_H_

#include "AstVisitor.h"
#include <iostream>

namespace py
{

class AstPrinter: public AstVisitor
{
public:
	AstPrinter(std::ostream &os);
	virtual ~AstPrinter();

	virtual int Visit(Name*);
	virtual int Visit(Num*);
	virtual int Visit(Str*);
	virtual int Visit(Module*);
	virtual int Visit(Assign*);
	virtual int Visit(BinOp*);
	virtual int Visit(Tuple*);
	virtual int Visit(Ast*);
	virtual int Visit(Arg*);
	virtual int Visit(FunctionDef*);
	virtual int Visit(KeywordArg*);
	virtual int Visit(Call*);
	virtual int Visit(Starred*);
	virtual int Visit(For*);
	virtual int Visit(If*);
	virtual int Visit(Attribute*);
	virtual int Visit(IfExpr*);
	virtual int Visit(UnaryOp*);
	virtual int Visit(AugAssign*);
	virtual int Visit(Compare*);
	virtual int Visit(Delete*);
    virtual int Visit(Return*);
    virtual int Visit(Pass*);
    virtual int Visit(Break*);
    virtual int Visit(Continue*);
    virtual int Visit(While*);
    virtual int Visit(Raise*);
    virtual int Visit(Try*);
    virtual int Visit(Assert*);
    virtual int Visit(Import*);
    virtual int Visit(ImportFrom*);
    virtual int Visit(Global*);
    virtual int Visit(NonLocal*);
    virtual int Visit(ClassDef*);
    virtual int Visit(Lambda*);
    virtual int Visit(Dict*);
    virtual int Visit(Set*);
    virtual int Visit(ListComp*);
    virtual int Visit(SetComp*);
    virtual int Visit(DictComp*);
    virtual int Visit(GeneratorExpr*);
    virtual int Visit(Yield*);
    virtual int Visit(YieldFrom*);
    virtual int Visit(Bytes*);
    virtual int Visit(NameConstant*);
    virtual int Visit(Subscript*);
    virtual int Visit(List*);

private:
	std::ostream &os;
    
    void PrintNodes(AstNodes& nodes);
};

} /* namespace py */

#endif /* _INCLUDED_ASTPRINTER_H_ */
