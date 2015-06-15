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
	os << "Num(" << num->doubleValue << ")";
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

int AstPrinter::Visit(BinOp* b)
{
	os << "BinOp(op=";
	switch(b->op) {
    case Add:
        os << "+";
        break;
    case Sub:
        os << "-";
        break;
    case Mult:
        os << "*";
        break;
    case Div:
        os << "/";
        break;
    case Mod:
        os << "%";
        break;
    case Pow:
        os << "**";
        break;
    case LShift:
        os << "<<";
        break;
    case RShift:
        os << ">>";
        break;
    case BitOr:
        os << "|";
        break;
    case BitXor:
        os << "^";
        break;
    case BitAnd:
        os << "&";
        break;
    case FloorDiv:
        os << "//";
        break;
    case Eq:
        os << "==";
        break;
    case NotEq:
        os << "!=";
        break;
    case Lt:
        os << "<";
        break;
    case LtEq:
        os << "<=";
        break;
    case Gt:
        os << ">";
        break;
    case GtEq:
        os << ">=";
        break;
    case Is:
        os << "is";
        break;
    case IsNot:
        os << "is not";
        break;
    case In:
        os << "in";
        break;
    case NotIn:
        os << "not in";
        break;
    default:
    	break;
	}

	os << ", left=";
	b->left->Accept(this);
	os << ", right=";
	b->right->Accept(this);
	os << ")";

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

int AstPrinter::Visit(Arg* arg)
{
    os << "Arg(id=" << arg->id << ", defaults=";
    
    if (arg->def) {
        arg->def->Accept(this);
    } else {
        os << "Null";
    }
    
    os << ", type=";
    if (arg->type) {
        arg->type->Accept(this);
    } else {
        os << "Null";
    }
    
    os << ")";
    
    return 0;
}

int AstPrinter::Visit(FunctionDef* func)
{
    os << "FunctionDef(id=" << func->id << ", args=[" << std::endl;
    
    for (Args::const_iterator i = func->args.begin(); i != func->args.end(); ++i) {
        (*i)->Accept(this);
        
        if (i + 1 < func->args.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "]," << std::endl;
    
    os << "kwOnlyArgs=[" << std::endl;
    for (Args::const_iterator i = func->kwOnlyArgs.begin(); i != func->kwOnlyArgs.end(); ++i) {
        (*i)->Accept(this);
        
        if (i + 1 < func->args.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "]," << std::endl;
    
    os << "vararg=";
    
    if (func->vararg) {
        func->vararg->Accept(this);
    }
    else {
        os << "Null";
    }
    
    os << ", " << std::endl;
    
    os << "kwarg=";
    
    if (func->kwarg) {
        func->kwarg->Accept(this);
    }
    else {
        os << "Null";
    }
    
    os << std::endl << "body=[" << std::endl;
    
    for (AstNodes::const_iterator i = func->body.begin(); i < func->body.end(); ++i)
    {
        (*i)->Accept(this);
        
        if (i + 1 < func->body.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "]" << std::endl << ")";
    
    return 0;
}

} /* namespace py */


