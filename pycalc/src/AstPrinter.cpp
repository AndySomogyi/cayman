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

int AstPrinter::Visit(AugAssign* aug)
{
	os << "AugAssign(target=";

	aug->target->Accept(this);

	os << ", op=";

	switch(aug->op) {
    case Add:
        os << "+=";
        break;
    case Sub:
        os << "-=";
        break;
    case Mult:
        os << "*=";
        break;
    case Div:
        os << "/=";
        break;
    case Mod:
        os << "%=";
        break;
    case Pow:
        os << "**=";
        break;
    case LShift:
        os << "<<=";
        break;
    case RShift:
        os << ">>=";
        break;
    case BitOr:
        os << "|=";
        break;
    case BitXor:
        os << "^=";
        break;
    case BitAnd:
        os << "&=";
        break;
    case FloorDiv:
        os << "//=";
        break;
    default:
        os << "Invalid AugAssign Op";
	}

	os << ", value=";

	aug->value->Accept(this);

	os << ")";


	return 0;


}

int AstPrinter::Visit(Pass*)
{
	os << "Pass()";
	return 0;
}


int AstPrinter::Visit(Break*)
{
	os << "Break()";
	return 0;
}

int AstPrinter::Visit(Continue*)
{
	os << "Continue()";
	return 0;
}

void AstPrinter::PrintNodes(AstNodes& nodes)
{
    os << "[" << std::endl;
    for(AstNodes::const_iterator i = nodes.begin();
        i != nodes.end(); ++i)
    {
        (*i)->Accept(this);
        
        if (i + 1 < nodes.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    os << "]";
}
    
    


AstPrinter::AstPrinter(std::ostream& os) : os(os)
{
}

AstPrinter::~AstPrinter()
{
	// TODO Auto-generated destructor stub
}

int AstPrinter::Visit(Name* nm)
{
	os << "Name(" << nm->id << ")";
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
        
        if (i + 1 < m->body.end()) {
            os << ",";
        }
        
        os << std::endl;

	}

	os << "])";

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

	os << "]";

	return 0;
}

int AstPrinter::Visit(IfExpr *i)
{
	os << "IfExpr()";
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
    case And:
    	os << "and";
    	break;
    case Or:
    	os << "or";
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
            if (i + 1 < t->items.end()) {
            	os << ", ";
            }
        }
    }
    
    os << "])";
    
	return 0;
}


int AstPrinter::Visit(Ast* ast)
{
	return ast->module->Accept(this);
}

int AstPrinter::Visit(Attribute* attr)
{
	os << "Attribute(value=" << std::endl;
    attr->value->Accept(this);
    os << "," << std::endl;
    
    os << "attr=" << attr->attr << "," << std::endl;
    os << "ctx=?" << std::endl;
    
    os << ")";
    
	return 0;
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
    os << "FunctionDef(id=" << func->name << ", args=[" << std::endl;
    
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
    
    os << "]" << std::endl;
    
    os << ", returns=";
    
    if (func->returns) {
        func->returns->Accept(this);
    } else {
        os << "NULL";
    }
    
    os << ")";
    
    return 0;
}

int AstPrinter::Visit(KeywordArg* k)
{
	os << "KeywordArg(arg=" << k->arg <<
			", value=";

	k->value->Accept(this);

	os << ")";

	return 0;
}

int AstPrinter::Visit(Call* c)
{
	os << "Call(func=";

	c->func->Accept(this);

	os << "," << std::endl << "args=[";


	for (AstNodes::const_iterator i = c->args.begin(); i != c->args.end(); ++i) {
		(*i)->Accept(this);

		if(i + 1 < c->args.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "], keywords=[";


	for (KeywordArgs::const_iterator i = c->kwArgs.begin(); i != c->kwArgs.end(); ++i) {
		(*i)->Accept(this);

		if(i + 1 < c->kwArgs.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "], " << std::endl;


	os << "starargs=";

	if(c->starArg) {
		c->starArg->Accept(this);
	} else {
		os << "Null";
	}

	os << ", kwarg=";

	if (c->kwArg) {
		c->kwArg->Accept(this);
	} else {
		os << "Null";
	}


	os << ")";

	return 0;
}

int AstPrinter::Visit(Starred* s)
{
	os << "Starred(value=";

	if (s->value) {
		s->value->Accept(this);
	} else {
		os << "Null";
	}

	os << ")";

	return 0;

}

int AstPrinter::Visit(For *f)
{
	os << "For(" << std::endl;
	os << "target=";

	f->target->Accept(this);

	os << ", " << std::endl << "iter=";

	f->iter->Accept(this);

	os << ", " << std::endl << "body=[" << std::endl;


	for (AstNodes::const_iterator i = f->body.begin(); i != f->body.end(); ++i) {
		(*i)->Accept(this);

		if(i + 1 < f->body.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "] " << std::endl;


	os << ", " << std::endl << "orelse=[" << std::endl;


	for (AstNodes::const_iterator i = f->orelse.begin(); i != f->orelse.end(); ++i) {
		(*i)->Accept(this);

		if(i + 1 < f->orelse.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "] " << std::endl;


	os << ")";



	return 0;
}

int AstPrinter::Visit(If* i)
{
    os << "If(" << std::endl;
    
    os << "test=";
    i->test->Accept(this);
    os << std::endl;
    
    os << "body=";
    PrintNodes(i->body);
    
    os << "else=";
    PrintNodes(i->orelse);
    
    os << ")";
    
    
	return 0;
}

int AstPrinter::Visit(UnaryOp* op)
{
	os << "UnaryOp(op=";
    switch (op->op) {
        case Add:
            os << "UAdd, ";
            break;
        case Sub:
            os << "UMinus, ";
            break;
        case Not:
            os << "Not, ";
            break;
        case Invert:
            os << "Invert, ";
            break;
        default:
            assert(0);
    }
    op->operand->Accept(this);
    os << ")";
	return 0;
}


/**
 * // comp_op: '<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'
 */
int AstPrinter::Visit(Compare* cmp)
{
	os << "Compare(operands=[" << std::endl;

    for (AstNodes::const_iterator i = cmp->operands.begin(); i != cmp->operands.end(); ++i)
    {
        (*i)->Accept(this);
        if (i + 1 < cmp->operands.end())
        {
            os << ",";
        }
        os << std::endl;
    }

    os << "], " << std::endl << "operators=[" << std::endl;

    for (OperatorTypes::const_iterator i = cmp->operators.begin(); i != cmp->operators.end(); ++i)
    {
        switch (*i) {
        case Eq:
            os << "\"==\"";
            break;
        case NotEq: 
            os << "\"!=\"";
            break;
        case Lt: 
            os << "\"<\"";
            break;
        case LtEq: 
            os << "\"<=\"";
            break;
        case Gt: 
            os << "\">\"";
            break;
        case GtEq: 
            os << "\">=\"";
            break;
        case Is: 
            os << "\"is\"";
            break;
        case IsNot: 
            os << "\"is not\"";
            break;
        case In: 
            os << "\"in\"";
            break;
        case NotIn: 
            os << "\"not in\"";
            break;
            
        default:
            os << "\"Unknown Operator\"";
            break;
        }
        
        if (i + 1 < cmp->operators.end())
        {
            os << ",";
        }
        os << std::endl;
    }

    os << "]" << std::endl << ")";

	return 0;
}

int AstPrinter::Visit(Delete* d)
{
    os << "Delete(targets=";
    PrintNodes(d->targets);
    os << ")";
    return 0;
}

int AstPrinter::Visit(Return *r)
{
    os << "Return(value=";
    
    if (r->value) {
        r->value->Accept(this);
    } else {
        os << "NULL";
    }
    
    os << ")";
    return 0;
}

int AstPrinter::Visit(While*)
{
    os << "While()";
    return 0;
}

int AstPrinter::Visit(Raise* raise)
{
    os << "Raise(exc=";
    if (raise->exc) {
        raise->exc->Accept(this);
    } else {
        os << "NULL";
    }
    os << ", cause=";
    if (raise->cause) {
        raise->cause->Accept(this);
    } else {
        os << "NULL";
    }
    os << ")";
    return 0;
}

int AstPrinter::Visit(Try*)
{
    os << "Try()";
    return 0;
}

int AstPrinter::Visit(Assert *a)
{
    os << "Assert(test=";
    if (a->test) {
        a->test->Accept(this);
    } else {
        os << "NULL";
    }
    
    os << ", msg=";
    if (a->msg) {
        a->msg->Accept(this);
    } else {
        os << "NULL";
    }
    
    os << ")";
    
    return 0;
}
    
void AstPrinter::PrintAliases(Aliases& names)
{
    os << "names=[" << std::endl;
    for (Aliases::const_iterator i = names.begin(); i != names.end(); ++i) {
        os << "alias(name=\"" << (*i).name << "\", asname=\"" << (*i).asname << "\")";
        if (i + 1 < names.end()) {
            os << ",";
        }
        os << std::endl;
    }
    os << "]";
}

int AstPrinter::Visit(Import* imp)
{
    os << "Import(";
    PrintAliases(imp->names);
    os << ")";
    return 0;
}

int AstPrinter::Visit(ImportFrom* imp)
{
    os << "ImportFrom(module=\"" << imp->module << "\", ";
    PrintAliases(imp->names);
    os << ", level=" << imp->level;
    os << ")";
    return 0;
}

int AstPrinter::Visit(Global *g)
{
    os << "Global(names=[" << std::endl;
    
    for (Identifiers::const_iterator i = g->names.begin();
         i != g->names.end(); ++i) {
        os << "\"" << *i << "\"";
        if (i + 1 < g->names.end()) {
            os << ",";
        }
        os << std::endl;
    }
    
    os << "])";
    return 0;
}

int AstPrinter::Visit(NonLocal *n)
{
    os << "NonLocal(names=[" << std::endl;
    
    for (Identifiers::const_iterator i = n->names.begin();
         i != n->names.end(); ++i) {
        os << "\"" << *i << "\"";
        if (i + 1 < n->names.end()) {
            os << ",";
        }
        os << std::endl;
    }
    
    os << "])";
    return 0;
}

int AstPrinter::Visit(ClassDef*)
{
    os << "ClassDef()";
    return 0;
}

int AstPrinter::Visit(Lambda*)
{
    os << "Lambda()";
    return 0;
}

int AstPrinter::Visit(Dict*)
{
    os << "Dict()";
    return 0;
}

int AstPrinter::Visit(Set*)
{
    os << "Set()";
    return 0;
}

int AstPrinter::Visit(ListComp*)
{
    os << "ListComp()";
    return 0;
}

int AstPrinter::Visit(SetComp*)
{
    os << "SetComp()";
    return 0;
}

int AstPrinter::Visit(DictComp*)
{
    os << "DictComp()";
    return 0;
}

int AstPrinter::Visit(GeneratorExpr*)
{
    os << "GeneratorExpr()";
    return 0;
}

int AstPrinter::Visit(Yield* y)
{
    os << "Yield(value=";
    
    if (y->value) {
        y->value->Accept(this);
    } else {
        os << "NULL";
    }
    
    os << ")";
        
    
    return 0;
}

int AstPrinter::Visit(YieldFrom* y)
{
    os << "YieldFrom(value=";
    
    if (y->value) {
        y->value->Accept(this);
    } else {
        os << "NULL";
    }
    
    os << ")";
    
    
    return 0;
}

int AstPrinter::Visit(Bytes*)
{
    os << "Bytes()";
    return 0;
}

int AstPrinter::Visit(NameConstant*)
{
    os << "NameConstant()";
    return 0;
}

int AstPrinter::Visit(Subscript*)
{
    os << "Subscript()";
    return 0;
}

int AstPrinter::Visit(List*)
{
    os << "List()";
    return 0;
}

} /* namespace py */
