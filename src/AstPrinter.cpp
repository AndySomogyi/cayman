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

int AstPrinter::visit(AugAssign* aug)
{
	os << "AugAssign(target=";

	dispatch(aug->target);

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

	dispatch(aug->value);

	os << ")";


	return 0;


}

int AstPrinter::visit(Pass*)
{
	os << "Pass()";
	return 0;
}


int AstPrinter::visit(Break*)
{
	os << "Break()";
	return 0;
}

int AstPrinter::visit(Continue*)
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
        dispatch((*i));
        
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

int AstPrinter::visit(Name* nm)
{
	os << "Name(" << nm->id << ")";
	return 0;
}

int AstPrinter::visit(Num* num)
{
	os << "Num(" << num->doubleValue << ")";
	return 0;
}

int AstPrinter::visit(Str* s)
{
	os << "Str(s=\"" << s->s << "\")";
	return 0;
}

int AstPrinter::visit(Module* m)
{
	os << "Module(body=[" << std::endl;

	for (AstNodes::const_iterator i = m->body.begin();
			i != m->body.end(); ++i)
	{
		dispatch((*i));
        
        if (i + 1 < m->body.end()) {
            os << ",";
        }
        
        os << std::endl;

	}

	os << "])";

	return 0;
}

int AstPrinter::visit(Assign* a)
{
	os << "Assign(targets=[" << std::endl;

	for(AstNodes::const_iterator i = a->targets.begin();
			i != a->targets.end(); ++i)
	{
		dispatch((*i));
	}

	os << "], value=";

	dispatch(a->value);

	os << ")";

	return 0;
}

int AstPrinter::visit(IfExpr *i)
{
	os << "IfExpr()";
	return 0;
}

int AstPrinter::visit(BinOp* b)
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
	dispatch(b->left);
	os << ", right=";
	dispatch(b->right);
	os << ")";

	return 0;
}

int AstPrinter::visit(Tuple* t)
{
    os << "Tuple(items=[";
    
    if (t->items.size() > 0)
    {
        os << std::endl;
        for (AstNodes::const_iterator i = t->items.begin();
             i != t->items.end(); ++i)
        {
            dispatch((*i));
            if (i + 1 < t->items.end()) {
            	os << ", ";
            }
        }
    }
    
    os << "])";
    
	return 0;
}


int AstPrinter::visit(Ast* ast)
{
    if (ast->module) {
        return dispatch(ast->module);
    }
    else {
        os << "Error, no module" << std::endl;
        return 0;
    }
}

int AstPrinter::visit(Attribute* attr)
{
	os << "Attribute(value=" << std::endl;
    dispatch(attr->value);
    os << "," << std::endl;
    
    os << "attr=" << attr->attr << "," << std::endl;
    os << "ctx=?" << std::endl;
    
    os << ")";
    
	return 0;
}

int AstPrinter::visit(Arg* arg)
{
    os << "Arg(id=" << arg->id << ", defaults=";
    
    if (arg->def) {
        dispatch(arg->def);
    } else {
        os << "Null";
    }
    
    os << ", type=";
    if (arg->typeExpr) {
        dispatch(arg->typeExpr);
    } else {
        os << "Null";
    }
    
    os << ")";
    
    return 0;
}

int AstPrinter::visit(FunctionDef* func)
{
    os << "FunctionDef(id=" << func->name << ", args=[" << std::endl;
    
    for (Args::const_iterator i = func->args.begin(); i != func->args.end(); ++i) {
        dispatch((*i));
        
        if (i + 1 < func->args.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "]," << std::endl;
    
    os << "kwOnlyArgs=[" << std::endl;
    for (Args::const_iterator i = func->kwOnlyArgs.begin(); i != func->kwOnlyArgs.end(); ++i) {
        dispatch((*i));
        
        if (i + 1 < func->args.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "]," << std::endl;
    
    os << "vararg=";
    
    if (func->vararg) {
        dispatch(func->vararg);
    }
    else {
        os << "Null";
    }
    
    os << ", " << std::endl;
    
    os << "kwarg=";
    
    if (func->kwarg) {
        dispatch(func->kwarg);
    }
    else {
        os << "Null";
    }
    
    os << std::endl << "body=[" << std::endl;
    
    for (AstNodes::const_iterator i = func->body.begin(); i < func->body.end(); ++i)
    {
        dispatch((*i));
        
        if (i + 1 < func->body.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "]" << std::endl;
    
    os << ", returns=";
    
    if (func->returns) {
        dispatch(func->returns);
    } else {
        os << "NULL";
    }
    
    os << "," << std::endl << "decorators=" << std::endl;
    PrintNodes(func->decorators);
    
    os << ")";
    
    return 0;
}

int AstPrinter::visit(KeywordArg* k)
{
	os << "KeywordArg(arg=" << k->arg <<
			", value=";

	dispatch(k->value);

	os << ")";

	return 0;
}

int AstPrinter::visit(Call* c)
{
	os << "Call(func=";

	dispatch(c->func);

	os << "," << std::endl << "args=[";


	for (AstNodes::const_iterator i = c->args.begin(); i != c->args.end(); ++i) {
		dispatch((*i));

		if(i + 1 < c->args.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "], keywords=[";


	for (KeywordArgs::const_iterator i = c->kwArgs.begin(); i != c->kwArgs.end(); ++i) {
		dispatch((*i));

		if(i + 1 < c->kwArgs.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "], " << std::endl;


	os << "starargs=";

	if(c->starArg) {
		dispatch(c->starArg);
	} else {
		os << "Null";
	}

	os << ", kwarg=";

	if (c->kwArg) {
		dispatch(c->kwArg);
	} else {
		os << "Null";
	}


	os << ")";

	return 0;
}

int AstPrinter::visit(Starred* s)
{
	os << "Starred(value=";

	if (s->value) {
		dispatch(s->value);
	} else {
		os << "Null";
	}

	os << ")";

	return 0;

}

int AstPrinter::visit(For *f)
{
	os << "For(" << std::endl;
	os << "target=";

	dispatch(f->target);

	os << ", " << std::endl << "iter=";

	dispatch(f->iter);

	os << ", " << std::endl << "body=[" << std::endl;


	for (AstNodes::const_iterator i = f->body.begin(); i != f->body.end(); ++i) {
		dispatch((*i));

		if(i + 1 < f->body.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "] " << std::endl;


	os << ", " << std::endl << "orelse=[" << std::endl;


	for (AstNodes::const_iterator i = f->orelse.begin(); i != f->orelse.end(); ++i) {
		dispatch((*i));

		if(i + 1 < f->orelse.end()) {
			os << ",";
		}

		os << std::endl;
	}

	os << "] " << std::endl;


	os << ")";



	return 0;
}

int AstPrinter::visit(If* i)
{
    os << "If(" << std::endl;
    
    os << "test=";
    dispatch(i->test);
    os << std::endl;
    
    os << "body=";
    PrintNodes(i->body);
    
    os << "else=";
    PrintNodes(i->orelse);
    
    os << ")";
    
    
	return 0;
}

int AstPrinter::visit(UnaryOp* op)
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
    dispatch(op->operand);
    os << ")";
	return 0;
}


/**
 * // comp_op: '<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'
 */
int AstPrinter::visit(Compare* cmp)
{
	os << "Compare(operands=[" << std::endl;

    for (AstNodes::const_iterator i = cmp->operands.begin(); i != cmp->operands.end(); ++i)
    {
        dispatch((*i));
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

int AstPrinter::visit(Delete* d)
{
    os << "Delete(targets=";
    PrintNodes(d->targets);
    os << ")";
    return 0;
}

int AstPrinter::visit(Return *r)
{
    os << "Return(value=";
    
    if (r->value) {
        dispatch(r->value);
    } else {
        os << "NULL";
    }
    
    os << ")";
    return 0;
}

int AstPrinter::visit(While* f)
{
    os << "While(" << std::endl;
    os << "test=";
    
    dispatch(f->test);
    
    os << ", " << std::endl << "body=[" << std::endl;
    
    
    for (AstNodes::const_iterator i = f->body.begin(); i != f->body.end(); ++i) {
        dispatch((*i));
        
        if(i + 1 < f->body.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "] " << std::endl;
    
    
    os << ", " << std::endl << "orelse=[" << std::endl;
    
    
    for (AstNodes::const_iterator i = f->orelse.begin(); i != f->orelse.end(); ++i) {
        dispatch((*i));
        
        if(i + 1 < f->orelse.end()) {
            os << ",";
        }
        
        os << std::endl;
    }
    
    os << "] " << std::endl;
    
    
    os << ")";
    
    
    
    return 0;
}

int AstPrinter::visit(Raise* raise)
{
    os << "Raise(exc=";
    if (raise->exc) {
        dispatch(raise->exc);
    } else {
        os << "NULL";
    }
    os << ", cause=";
    if (raise->cause) {
        dispatch(raise->cause);
    } else {
        os << "NULL";
    }
    os << ")";
    return 0;
}

int AstPrinter::visit(Try*)
{
    os << "Try()";
    return 0;
}

int AstPrinter::visit(Assert *a)
{
    os << "Assert(test=";
    if (a->test) {
        dispatch(a->test);
    } else {
        os << "NULL";
    }
    
    os << ", msg=";
    if (a->msg) {
        dispatch(a->msg);
    } else {
        os << "NULL";
    }
    
    os << ")";
    
    return 0;
}

void AstPrinter::print(AstNode* node)
{
	dispatch(node);
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

int AstPrinter::visit(Import* imp)
{
    os << "Import(";
    PrintAliases(imp->names);
    os << ")";
    return 0;
}

int AstPrinter::visit(ImportFrom* imp)
{
    os << "ImportFrom(module=\"" << imp->module << "\", ";
    PrintAliases(imp->names);
    os << ", level=" << imp->level;
    os << ")";
    return 0;
}

int AstPrinter::visit(Global *g)
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

int AstPrinter::visit(NonLocal *n)
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

int AstPrinter::visit(ClassDef*)
{
    os << "ClassDef()";
    return 0;
}

int AstPrinter::visit(Lambda*)
{
    os << "Lambda()";
    return 0;
}

int AstPrinter::visit(Dict*)
{
    os << "Dict()";
    return 0;
}

int AstPrinter::visit(Set*)
{
    os << "Set()";
    return 0;
}

int AstPrinter::visit(ListComp*)
{
    os << "ListComp()";
    return 0;
}

int AstPrinter::visit(SetComp*)
{
    os << "SetComp()";
    return 0;
}

int AstPrinter::visit(DictComp*)
{
    os << "DictComp()";
    return 0;
}

int AstPrinter::visit(GeneratorExpr*)
{
    os << "GeneratorExpr()";
    return 0;
}

int AstPrinter::visit(Yield* y)
{
    os << "Yield(value=";
    
    if (y->value) {
        dispatch(y->value);
    } else {
        os << "NULL";
    }
    
    os << ")";
        
    
    return 0;
}

int AstPrinter::visit(YieldFrom* y)
{
    os << "YieldFrom(value=";
    
    if (y->value) {
        dispatch(y->value);
    } else {
        os << "NULL";
    }
    
    os << ")";
    
    
    return 0;
}

int AstPrinter::visit(Bytes*)
{
    os << "Bytes()";
    return 0;
}

int AstPrinter::visit(NameConstant* c)
{
    os << "NameConstant(value=";

    switch(c->value) {
    case NameConstant::True:
    	os << "True";
    	break;
    case NameConstant::False:
    	os << "False";
    	break;
    default:
    	os << "None";
    	break;
    }
    os << ")";

    return 0;
}

int AstPrinter::visit(Subscript*)
{
    os << "Subscript()";
    return 0;
}

int AstPrinter::visit(List*)
{
    os << "List()";
    return 0;
}

} /* namespace py */
