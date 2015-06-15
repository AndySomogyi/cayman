/*
 * Statement.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#include "Stmt.h"
#include "Expr.h"
#include "py_parser.hh"
#include "AstVisitor.h"
#include <Stmt.h>

namespace py
{

Assign::Assign(class Ast* _ast, const location& _loc, AstNode* target,
		AstNode* _value) :
		Stmt(_ast, _loc), value(_value)
{
	targets.push_back(target);

}

void Assign::AddValue(AstNode* _value)
{
	targets.push_back(value);
	value = _value;
}

int Assign::Accept(class AstVisitor* v)
{
	return v->Visit(this);
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

int Arg::Accept(AstVisitor* v)
{
	return v->Visit(this);
}

FunctionDef::FunctionDef(Ast* ast, const location& loc, AstNode* n, AstNode* a,
		AstNode* s) :
		Stmt(ast, loc), returns(NULL)
{
	Tuple *suite = dynamic_cast<Tuple*>(s);

	if (!suite)
	{
		throw syntax_error(loc,
				"function def suite must be a list of statements in a tuple");
	}

	TmpArguments *targs = dynamic_cast<TmpArguments*>(a);

	assert(targs);

	Name *name = dynamic_cast<Name*>(n);

	assert(name);

	id = name->id;
	body = suite->items;

	args = targs->args;
	kwOnlyArgs = targs->kwOnlyArgs;
	vararg = targs->vararg;
	kwarg = targs->kwarg;
}

int FunctionDef::Accept(AstVisitor* v)
{
	return v->Visit(this);
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

int KeywordArg::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

Call::Call(Ast* ast, const location& loc, AstNode* _argsTuple) :
		Stmt(ast, loc), func(NULL), starArg(NULL), kwArg(NULL)
{
	if (!_argsTuple) {
		return;
	}

	Tuple *argsTuple = dynamic_cast<Tuple*>(_argsTuple);

	if(!argsTuple) {
		// this is bad, error in the grammar
		assert(0);
	}

	for(AstNodes::const_iterator i = argsTuple->items.begin();
			i != argsTuple->items.end(); ++i)
	{
		AddArg(*i);
	}
}

void Call::AddArg(AstNode* arg)
{
	assert(arg);

	Starred *starred = dynamic_cast<Starred*>(arg);

	if(starred) {
		if (starArg == NULL) {
			starArg = starred->value;
			return;
		} else {
			throw syntax_error(starred->loc, "star argument already defined");
		}
	}

	KeywordArg *keywordArg = dynamic_cast<KeywordArg*>(arg);
	if(keywordArg) {
		kwArgs.push_back(keywordArg);
		return;
	}

	DblStarred *dblStarred = dynamic_cast<DblStarred*>(arg);
	if(dblStarred) {
		kwArg = dblStarred->value;
		return;
	}

	// its a standard arg
	args.push_back(arg);
}

void Call::SetFunc(AstNode* f)
{
	func = f;
}

int Call::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

} /* namespace py */


