/*
 * AstPrinter.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: andy
 */

#include "AstPrinter.h"
#include "Ast.h"

namespace py
{


AstPrinter::AstPrinter(std::ostream& os) : os(os)
{
}

AstPrinter::~AstPrinter()
{
	// TODO Auto-generated destructor stub
}

int AstPrinter::Visit(Name* nm)
{
	os << "Name(" << nm->id << ")" << std::endl;
	return 0;
}

int AstPrinter::Visit(Num* num)
{
	os << "Num(" << num->doubleValue << ")" << std::endl;
	return 0;
}

int AstPrinter::Visit(Str*)
{
	return 0;
}

int AstPrinter::Visit(Module* m)
{
	os << "Module(body=[" << std::endl;

	for (AstNodes::const_iterator i = m->body.begin();
			i != m->body.end(); ++i)
	{
		(*i)->Accept(this);
	}

	os << "])" << std::endl;

	return 0;
}

int AstPrinter::Visit(Assign* a)
{
	os << "Assign(targets=[" << std::endl;

	for(AstNodes::const_iterator i = a->targets.begin();
			i != a->targets.end(); ++i)
	{
		(*i)->Accept(this);
	}

	os << "], value=";

	os << a->value->Accept(this);

	os << "]" << std::endl;

	return 0;
}

int AstPrinter::Visit(BinOp*)
{
	return 0;
}

int AstPrinter::Visit(Tuple* t)
{
    os << "Tuple(items=[";
    
    if (t->items.size() > 0)
    {
        os << std::endl;
        for (AstNodes::const_iterator i = t->items.begin();
             i != t->items.end(); ++i)
        {
            (*i)->Accept(this);
        }
    }
    
    os << "])";
    
	return 0;
}

int AstPrinter::Visit(Ast* ast)
{
	return ast->module->Accept(this);
}

} /* namespace py */
