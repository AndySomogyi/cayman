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
#include "ParserContext.h"

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

Arg* Ast::CreateArg(const location& loc, AstNode* nm, AstNode* def,
		AstNode* type)
{
	Name *name = dynamic_cast<Name*>(nm);
	return new Arg(this, loc, name->id, def, type);
}

void Ast::Free(AstNode* node)
{
}

Tuple* Ast::CreateTuple(const location& loc, AstNode* seq, AstNode* item)
{
	return CreateTuple(loc, UnknownCtx, seq, item);
}

FunctionDef* Ast::CreateFunctionDef(const location& loc, AstNode* nm,
		AstNode* args, AstNode* suite)
{
	return new FunctionDef(this, loc, nm, args, suite);
}


Call* Ast::CreateCall(const location& loc, AstNode* args)
{
	return new Call(this, loc, args);
}



If* Ast::CreateElif(const location& loc, AstNode* _elifSeq, AstNode* test,
		AstNode* body)
{
	If *elifSeq = NULL;

	if (_elifSeq) {
		elifSeq = dynamic_cast<If*>(_elifSeq);
		assert(elifSeq);
	}

	If *newIf = new If(this, loc, test, body, NULL);

	if (elifSeq)
	{
		elifSeq->SetOrElse(newIf);
		return elifSeq;
	}

	return newIf;
}

If* Ast::CreateIf(const location& loc, AstNode* test, AstNode* body,
		AstNode* orelse, AstNode* trailingElse)
{
	If *newIf = new If(this, loc, test, body, orelse);

	if(trailingElse)
	{
		newIf->GetTerminalElif()->SetOrElse(trailingElse);
	}

	return newIf;
}

Attribute* Ast::CreateAttribute(const location& loc, ExprContext ctx,
		AstNode* value, AstNode* attr)
{
	return new Attribute(this, loc, ctx, value, attr);
}

TmpArguments* Ast::CreateTmpArguments(const location& loc)
{
	return new TmpArguments(this, loc);
}

BinOp* Ast::CreateBinOp(const location& _loc, AstNode *op, AstNode* _left,
		AstNode* _right)
{
	return new BinOp(this, _loc, TokenAstNodes::GetOperatorType(op), _left, _right);
}

Starred* Ast::CreateStarred(const location& loc, AstNode* _value,
		ExprContext ctx)
{
	return new Starred(this, loc, _value, ctx);
}

DblStarred* Ast::CreateDblStarred(const location& loc, AstNode* _value)
{
	return new DblStarred(this, loc, _value);
}

KeywordArg* Ast::CreateKeywordArg(const location& loc, AstNode * name,
		AstNode* _value)
{
	Name *nm = dynamic_cast<Name*>(name);

	if(!nm) {
		throw syntax_error(loc, "error, name of a keyword argument must be a name");
	}
	return new KeywordArg(this, loc, nm->id, _value);
}

For* Ast::CreateFor(const location& loc, AstNode* _target, AstNode* _iter,
		AstNode* _body, AstNode* _orelse)
{
	return new For(this, loc, _target, _iter, _body, _orelse);
}

} /* namespace py */


