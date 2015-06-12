/*
 * AST.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */


#include "Ast.h"
#include "AstVisitor.h"
#include "AstPrinter.h"
#include "py_parser.hh"

namespace py
{

Ast::Ast() : AstNode(this, location())
{
	// TODO Auto-generated constructor stub

}

Ast::~Ast()
{

}

int Ast::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

void Ast::Print(std::ostream& os)
{
	AstPrinter printer(os);

	printer.Visit(this);
}

Module *Ast::CreateModule(const location &loc, const AstNodes &body)
{
	Module *n = new Module(this, loc, body);
	nodes.push_back(n);
	return n;
}

Name* Ast::CreateName(location& loc, const char* begin, const char* end)
{
	Name *n = new Name(this, loc, begin, end);
	nodes.push_back(n);
	return n;
}

Assign* Ast::CreateAssign(const location& loc, AstNode* target, AstNode* value)
{
	Assign *n = new Assign(this, loc, target, value);
	nodes.push_back(n);
	return n;
}

Num* Ast::CreateNum(const location& loc, const char* begin, const char* end)
{
	Num *n = new Num(this, loc, begin, end);
	nodes.push_back(n);
	return n;
}


Tuple *Ast::CreateTuple(const location &loc, const AstNodes &items, ExprContext ctx)
{
    Tuple *n = new Tuple(this, loc, items, ctx);
	nodes.push_back(n);
	return n;

}

Tuple *Ast::CreateTuple(const location &_loc, ExprContext ctx)
{
    Tuple *n = new Tuple(this, loc, ctx);
	nodes.push_back(n);
	return n;

}

Tuple *Ast::CreateTuple(const location& loc, ExprContext ctx, AstNode *seq, AstNode *item)
{
    Tuple *tuple = NULL;
	if (seq)
	{
		tuple = dynamic_cast<Tuple*>(seq);
        
        if(!tuple)
        {
            tuple = CreateTuple(loc, ctx);
            tuple->items.push_back(seq);
        }
	}
	else
	{
		tuple = CreateTuple(loc, ctx);
	}

    if(item)
    {
        tuple->items.push_back(item);
    }

    return tuple;
}

Arg* Ast::CreateArg(const location& loc, AstNode* nm, AstNode* df,
		AstNode* tp)
{
	Name *name = dynamic_cast<Name*>(nm);

	Expr *def = dynamic_cast<Expr*>(df);
	Expr *type = dynamic_cast<Expr*>(tp);



	return new Arg(this, loc, name->id, def, type);
}

void Ast::Free(AstNode* node)
{
}

TmpArguments* Ast::CreateTmpArguments(const location& loc)
{
	return new TmpArguments(this, loc);
}


} /* namespace py */


