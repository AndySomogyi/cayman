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

private:
	std::ostream &os;
};

} /* namespace py */

#endif /* _INCLUDED_ASTPRINTER_H_ */
