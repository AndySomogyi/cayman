/*
 * AST.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */


#include "Ast.h"
#include "AstPrinter.h"
#include "AstToken.h"
#include "py_parser.hh"
#include "ParserContext.h"

namespace py
{

Ast::Ast() : AstNode(AST_AST, this, location())
{
	// TODO Auto-generated constructor stub

}

Ast::~Ast()
{

}


void Ast::Print(std::ostream& os)
{
	AstPrinter printer(os);

	printer.print(this);
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
    
Str* Ast::CreateStr(const location& loc, const char* begin, const char* end)
{
    Str *s = new Str(this, loc, begin, end);
    nodes.push_back(s);
    return s;
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


List *Ast::CreateList(const location &loc, const AstNodes &items, ExprContext ctx)
{
	List *n = new List(this, loc, items, ctx);
	nodes.push_back(n);
	return n;

}

List *Ast::CreateList(const location &_loc, ExprContext ctx)
{
	List *n = new List(this, loc, ctx);
	nodes.push_back(n);
	return n;

}

List *Ast::CreateList(const location& loc, ExprContext ctx, AstNode *seq, AstNode *item)
{
	List *tuple = NULL;
	if (seq)
	{
		tuple = dynamic_cast<List*>(seq);

        if(!tuple)
        {
            tuple = CreateList(loc, ctx);
            tuple->items.push_back(seq);
        }
	}
	else
	{
		tuple = CreateList(loc, ctx);
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
		AstNode* args, AstNode *returns, AstNode* suite)
{
	return new FunctionDef(this, loc, nm, args, returns, suite);
}


Call* Ast::CreateCall(const location& loc, AstNode *name, AstNode* args)
{
	Call *call = new Call(this, loc, args);
    if (name) {
        call->SetFunc(name);
    }
    return call;
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

Compare* Ast::CreateCompare(const location& loc, AstNode* seq, AstNode* opNode,
		AstNode* expr)
{
	OperatorType op = AstToken::GetOperatorType(opNode);
	Compare *compSeq = dynamic_cast<Compare*>(seq);
	if (compSeq && !compSeq->IsAtomic())
	{
		compSeq->Append(op, expr);
		return compSeq;
	}
	return new Compare(this, loc, seq, op, expr);
}

Delete* Ast::CreateDelete(const location& loc, AstNode* expr)
{
	return new Delete(this, loc, expr);
}

Break* Ast::CreateBreak(const location& loc)
{
    return new Break(this, loc);
}

Continue* Ast::CreateContinue(const location& loc)
{
    return new Continue(this, loc);
}

Return* Ast::CreateReturn(const location& loc, AstNode* expr)
{
    return new Return(this, loc, expr);
}

Pass* Ast::CreatePass(const location& loc)
{
    return new Pass(this, loc);
}

Raise* Ast::CreateRaise(const location& loc, AstNode* expr, AstNode* from)
{
    return new Raise(this, loc, expr, from);
}

Yield* Ast::CreateYield(const location& loc, AstNode* expr)
{
    return new Yield(this, loc, expr);
}

YieldFrom* Ast::CreateYieldFrom(const location& loc, AstNode* from)
{
    return new YieldFrom(this, loc, from);
}

AliasNodes* Ast::CreateAliasNodes(const location& loc, AstNode *prev, AstNode* name, AstNode* asname)
{
    AliasNodes *nodes;
    if (prev) {
        nodes = dynamic_cast<AliasNodes*>(prev);
        assert(nodes);
        nodes->AddAlias(name, asname);
        return nodes;
    }
	return new AliasNodes(this, loc, name, asname);
}

Import* Ast::CreateImport(const location& loc, AstNode* names)
{
	return new Import(this, loc, names);
}

ImportFrom* Ast::CreateImportFrom(const location& loc, AstNode* module,
		AstNode* names, AstNode* level)
{
	ImportFrom *impf = dynamic_cast<ImportFrom*>(level);

	if(level) assert(impf);

	if (impf) {
		impf->SetModule(module);
		impf->SetNames(names);
		return impf;
	}

	return new ImportFrom(this, loc, module, names, 0);
}

ImportFrom* Ast::CreateImportFrom(const location& loc, int level)
{
	return new ImportFrom(this, loc, NULL, NULL, level);
}

ImportFrom* Ast::CreateImportFrom(const location& loc, AstNode* prevLevel,
		int level)
{
	ImportFrom *impf = dynamic_cast<ImportFrom*>(prevLevel);
	assert(impf);
	impf->level += level;
	return impf;
}

TmpArguments* Ast::CreateTmpArguments(const location& loc)
{
	return new TmpArguments(this, loc);
}

BinOp* Ast::CreateBinOp(const location& _loc, AstNode *op, AstNode* _left,
		AstNode* _right)
{
	return new BinOp(this, _loc, AstToken::GetOperatorType(op), _left, _right);
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

UnaryOp* Ast::CreateUnaryOp(const location& loc, AstNode *op,
		AstNode* operand)
{
	return new UnaryOp(this, loc, AstToken::GetOperatorType(op), operand);
}

AugAssign* Ast::CreateAugAssign(const location& loc, AstNode* target,
		AstNode *op, AstNode* value)
{
	return new AugAssign(this, loc, target, AstToken::GetOperatorType(op), value);
}
    
Global *Ast::CreateGlobal(const location &loc, AstNode *names)
{
    return new Global(this, loc, names);
}

NonLocal *Ast::CreateNonLocal(const location &loc, AstNode *names)
{
    return new NonLocal(this, loc, names);
}

Assert* Ast::CreateAssert(const location &loc, AstNode *test, AstNode *msg)
{
	return new Assert(this, loc, test, msg);
}

While* Ast::CreateWhile(const location& loc, AstNode* test, AstNode* body,
		AstNode* orelse)
{
	return new While(this, loc, test, body, orelse);
}
    
AstNode *Ast::CreateDecorated(const location& loc, AstNode *decorators, AstNode *thing)
{
    FunctionDef *func = dynamic_cast<FunctionDef*>(thing);
    
    if (func) {
        func->AddDecorators(decorators);
        return func;
    }
    
    ClassDef *classDef = dynamic_cast<ClassDef*>(thing);
    if (classDef) {
        classDef->AddDecorators(decorators);
        return classDef;
    }
    
    assert(0);
    return 0;
}

ClassDef* Ast::CreateClassDef(const location& loc, AstNode* name,
		AstNode* arglist, AstNode* suite)
{
	return new ClassDef(this, loc, name, arglist, suite);
}

Dict* Ast::CreateDict(const location& loc, AstNode* seq, AstNode* key,
		AstNode* value)
{
	Dict *dict = dynamic_cast<Dict*>(seq);
	if (dict != NULL) {
		dict->AddKeyValue(key, value);
		return dict;
	}

	return new Dict(this, loc, key, value);
}

Tuple* Ast::CreateArgList(const location& loc, AstNode* args,
		AstNode* starredArg, AstNode* dblStarredArg)
{
	Tuple *seq = NULL;


	if (args) {
		seq = dynamic_cast<Tuple*>(args);
		assert(seq);
	} else {
		seq = CreateTuple(loc, NULL, NULL);
	}

	if (starredArg) {
		AstNode *sa = this->CreateStarred(starredArg->loc, starredArg);
		seq->items.push_back(sa);
	}

	if (dblStarredArg) {
		AstNode *dbls = this->CreateDblStarred(dblStarredArg->loc, dblStarredArg);
		seq->items.push_back(dbls);
	}

	return seq;
}

NameConstant* Ast::CreateNameConstant(const location& loc,
		NameConstant::NameConstantType _type)
{
	return new NameConstant(this, loc, _type);
}

Subscript* Ast::CreateSubscript(const location& loc, AstNode* name,
		AstNode* args)
{
	return new Subscript(this, loc, args);
}

} /* namespace py */


