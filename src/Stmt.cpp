/*
 * Statement.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#include "Stmt.h"
#include "Expr.h"
#include "py_parser.hh"
#include "Stmt.h"
#include "ParserContext.h"
#include "AstToken.h"


#include "cayman_llvm.h"
#include "AstCodegen.h"

namespace py
{

Assign::Assign(class Ast* _ast, const location& _loc, AstNode* target,
		AstNode* _value) :
		Stmt(AST_ASSIGN, _ast, _loc), value(_value)
{
	targets.push_back(target);

}

void Assign::AddValue(AstNode* _value)
{
	targets.push_back(value);
	value = _value;
}


void TmpArguments::SetKwOnlyArgs(AstNode* node)
{
	ArgsFromTuple(node, kwOnlyArgs);
}

void TmpArguments::SetArgs(AstNode* node)
{
	ArgsFromTuple(node, args);
}

void TmpArguments::SetVararg(AstNode* node)
{
	vararg = dynamic_cast<Arg*>(node);
	assert(vararg);
}

void TmpArguments::SetKwArg(AstNode* node)
{
	kwarg = dynamic_cast<Arg*>(node);
	assert(kwarg);
}


FunctionDef::FunctionDef(Ast* ast, const location& loc, AstNode* n, AstNode* a,
		AstNode *r, AstNode* s) :
		Stmt(AST_FUNCTIONDEF, ast, loc)
{
	Tuple *suite = dynamic_cast<Tuple*>(s);

	if (!suite)
	{
		throw syntax_error(loc,
				"function def suite must be a list of statements in a tuple");
	}

	TmpArguments *targs = dynamic_cast<TmpArguments*>(a);

	assert(targs);

	Name *nm = dynamic_cast<Name*>(n);

	assert(nm);

	name = nm->id;
	body = suite->items;

	args = targs->args;
	kwOnlyArgs = targs->kwOnlyArgs;
	vararg = targs->vararg;
	kwarg = targs->kwarg;
    
    returns = r;
}


void TmpArguments::ArgsFromTuple(AstNode* node, Args& args)
{
	if (node == NULL)
	{
		args.clear();
		return;
	}

	Tuple *tuple = dynamic_cast<Tuple*>(node);

	if (tuple == NULL)
	{
		throw syntax_error(node->loc, "AstNode must be a tuple");
	}

	args.clear();
	args.reserve(tuple->items.size());

	for (AstNodes::const_iterator i = tuple->items.begin();
			i != tuple->items.end(); ++i)
	{
		Arg *arg = dynamic_cast<Arg*>(*i);
		if (arg == NULL)
		{
			throw syntax_error((*i)->loc, "argument must be an arg type");
		}

		args.push_back(arg);
	}
}



For::For(Ast* ast, const location& loc, AstNode* _target, AstNode* _iter,
	AstNode* _body, AstNode* _orelse) :
	Stmt(AST_FOR, ast, loc), target(NULL), iter(NULL)
{
	if (_target) SetTarget(_target);
	if (_iter) SetIter(_iter);
	if (_body) SetBody(_body);
	if (_orelse) SetOrElse(_orelse);
}


void For::SetTarget(AstNode* _target)
{
	target = _target;
}

void For::SetIter(AstNode* _iter)
{
	iter = _iter;
}

void For::SetBody(AstNode* _body)
{
	Tuple *tuple = dynamic_cast<Tuple*>(_body);
	assert(tuple);

	body = tuple->items;
}

void For::SetOrElse(AstNode* _orelse)
{
	Tuple *tuple = dynamic_cast<Tuple*>(_orelse);
	orelse = tuple->items;
}



If::If(class Ast* _ast, const location& _loc,  AstNode *_test,
		AstNode *_body, AstNode *_orelse):
		Stmt(AST_IF, _ast, _loc), test(NULL)
{
	SetTest(_test);
	SetBody(_body);
	SetOrElse(_orelse);
}

void If::SetTest(AstNode* _test)
{
	test = _test;
}

void If::SetBody(AstNode* _body)
{
	if (_body)
	{
		Tuple *tuple = dynamic_cast<Tuple*>(_body);
		assert(tuple);
		body = tuple->items;
	}
	else
	{
		body.clear();
	}
}

void If::SetOrElse(AstNode* _orelse)
{
	orelse.clear();

	if (_orelse)
	{
		If *i = dynamic_cast<If*>(_orelse);
		if (i)
		{
			orelse.push_back(i);
			return;
		}

		Tuple *tuple = dynamic_cast<Tuple*>(_orelse);
		assert(tuple);
		orelse = tuple->items;
	}
}


If* If::GetTerminalElif()
{
	if (orelse.size() == 1)
	{
		If *tail = dynamic_cast<If*>(orelse[0]);
		if (tail)
		{
			return tail->GetTerminalElif();
		}
	}
	return this;
}


AugAssign::AugAssign(class Ast* _ast, const location& _loc, AstNode* _target,
		OperatorType _op, AstNode* _value) :
		Stmt(AST_AUGASSIGN, _ast, _loc), target(NULL), op(EndOp), value(NULL)
{
	SetTarget(_target);
	SetOp(_op);
	SetValue(_value);
}

void AugAssign::SetOp(OperatorType _op)
{
	op = _op;
}

void AugAssign::SetTarget(AstNode* _target)
{
	target = _target;
}

void AugAssign::SetValue(AstNode* _value)
{
	value = _value;
}


void FunctionDef::AddDecorators(AstNode* dec)
{
    Tuple *tuple = dynamic_cast<Tuple*>(dec);
    if (tuple) {
        decorators.insert(decorators.end(), tuple->items.begin(), tuple->items.end());
    }
    else {
        decorators.push_back(dec);
    }
}


Delete::Delete(class Ast* ast, const location& loc, AstNode* _targets) :
		Stmt(AST_DELETE, ast, loc)
{
	AddTargets(_targets);
}

void Delete::AddTargets(AstNode* node)
{
	Tuple *tuple = dynamic_cast<Tuple*>(node);
	if (tuple) {
		targets.insert(targets.end(), tuple->items.begin(), tuple->items.end());
	}
	else {
		targets.push_back(node);
	}
}




ImportFrom::ImportFrom(class Ast* ast, const location& loc, AstNode* _module,
		AstNode* _names, int level) :
	Stmt(AST_IMPORTFROM, ast, loc), level(level)
{
	SetModule(_module);
	SetNames(_names);
}

void ImportFrom::SetModule(AstNode *m)
{
	if (m)
	{
		Name *nm = dynamic_cast<Name*>(m);
		assert(nm);
		module = nm->id;
	}
	else
	{
		module.clear();
	}
}

void ImportFrom::SetNames(AstNode *n)
{
	names.clear();
	if (n)
	{
		// The given name could be a "*" token,
		// TOOO FIX THIS HACK!!!, maybe make a proper Operator Ast Node?
		if (AstToken::GetOperatorType(n) == Mult)
		{
			Alias name("*", "");
			names.push_back(name);
            return;
		}

		AliasNodes *nodes = dynamic_cast<AliasNodes*>(n);
		assert(nodes);
		names = nodes->names;
	}
}

AliasNodes::AliasNodes(class Ast* ast, const location& loc, AstNode* nm, AstNode* asnm) :
		AstNode(AST_ALIASNODE, ast, loc)
{
	AddAlias(nm, asnm);
}

void AliasNodes::AddAlias(AstNode* name, AstNode* asname)
{
	Alias alias;

	Name *n = dynamic_cast<Name*>(name);
	assert(n);
	alias.name = n->id;

	if(asname) {
		Name *a = dynamic_cast<Name*>(asname);
		assert(a);
		alias.asname = a->id;
	}

	names.push_back(alias);
}

Global::Global(class Ast* ast, const location& loc, AstNode* _names) :
    Stmt(AST_GLOBAL, ast, loc)
{
	Tuple *tuple = dynamic_cast<Tuple*>(_names);

	if (tuple) {
		for (AstNodes::const_iterator i = tuple->items.begin();
				i != tuple->items.end(); ++i) {
			Name *name = dynamic_cast<Name*>(*i);
			assert(name);
			names.push_back(name->id);
		}
		return;
	}

	Name *name = dynamic_cast<Name*>(_names);
	assert(name);
	names.push_back(name->id);
}

NonLocal::NonLocal(class Ast* ast, const location& loc, AstNode* _names) :
    Stmt(AST_NONLOCAL, ast, loc)
{
	Tuple *tuple = dynamic_cast<Tuple*>(_names);

	if (tuple) {
		for (AstNodes::const_iterator i = tuple->items.begin();
				i != tuple->items.end(); ++i) {
			Name *name = dynamic_cast<Name*>(*i);
			assert(name);
			names.push_back(name->id);
		}
		return;
	}

	Name *name = dynamic_cast<Name*>(_names);
	assert(name);
	names.push_back(name->id);
}



While::While(class Ast* ast, const location& loc, AstNode* _test, AstNode* _body,
		AstNode* _orelse) :
    Stmt(AST_WHILE, ast, loc), test(NULL)
{
	SetTest(_test);
	SetBody(_body);
	SetOrElse(_orelse);
}

void While::SetTest(AstNode* _test)
{
	test = _test;
}

void While::SetBody(AstNode* _body)
{
	if (_body)
	{
		Tuple *tuple = dynamic_cast<Tuple*>(_body);
		assert(tuple);
		body = tuple->items;
	}
	else
	{
		body.clear();
	}
}

void While::SetOrElse(AstNode* _orelse)
{
	orelse.clear();

	if (_orelse)
	{
		Tuple *tuple = dynamic_cast<Tuple*>(_orelse);
		assert(tuple);
		orelse = tuple->items;
	}
}


Assert::Assert(class Ast* ast, const location& loc, AstNode* _test,
		AstNode* _msg) :
    Stmt(AST_ASSERT, ast, loc)
{
	test = _test;
	msg = _msg;
}


Import::Import(class Ast* ast, const location& loc, AstNode* nm) :
    Stmt(AST_IMPORT, ast, loc)
{
	if (nm) {
		AliasNodes *nodes = dynamic_cast<AliasNodes*>(nm);
		assert(nodes);
		names = nodes->names;
	}
}


ClassDef::ClassDef(class Ast* ast, const location& loc, AstNode* nm,
		AstNode* arglist, AstNode* suite) :
    Stmt(AST_CLASSDEF, ast, loc), starargs(NULL), kwargs(NULL)
{
	SetName(nm);
	SetBody(suite);
	ParseArglist(arglist);
}

void ClassDef::AddDecorators(AstNode* dec)
{
    Tuple *tuple = dynamic_cast<Tuple*>(dec);
    if (tuple) {
        decorators.insert(decorators.end(), tuple->items.begin(), tuple->items.end());
    }
    else {
        decorators.push_back(dec);
    }
}

void ClassDef::SetName(AstNode* nm)
{
	Name *n = dynamic_cast<Name*>(nm);
	assert(n);
	name = n->id;
}

void ClassDef::SetBody(AstNode* suite)
{
	Tuple *tuple = dynamic_cast<Tuple*>(suite);
	assert(tuple);
	body = tuple->items;
}

void ClassDef::ParseArglist(AstNode* arglist)
{
}




} /* namespace py */


