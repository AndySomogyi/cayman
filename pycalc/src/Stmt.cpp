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
		AstNode *r, AstNode* s) :
		Stmt(ast, loc)
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


For::For(Ast* ast, const location& loc, AstNode* _target, AstNode* _iter,
	AstNode* _body, AstNode* _orelse) :
	Stmt(ast, loc), target(NULL), iter(NULL)
{
	if (_target) SetTarget(_target);
	if (_iter) SetIter(_iter);
	if (_body) SetBody(_body);
	if (_orelse) SetOrElse(_orelse);
}

int For::Accept(AstVisitor* v)
{
	return v->Visit(this);
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

	body = tuple->items;
}

void For::SetOrElse(AstNode* _orelse)
{
	Tuple *tuple = dynamic_cast<Tuple*>(_orelse);
	orelse = tuple->items;
}



If::If(class Ast* _ast, const location& _loc,  AstNode *_test,
		AstNode *_body, AstNode *_orelse):
		Stmt(_ast, _loc), test(NULL)
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

int If::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

AugAssign::AugAssign(class Ast* _ast, const location& _loc, AstNode* _target,
		OperatorType _op, AstNode* _value) :
		Stmt(_ast, _loc), target(NULL), op(EndOp), value(NULL)
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

int AugAssign::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

void FunctionDef::AddDecorators(AstNode* tuple)
{
}


Delete::Delete(class Ast* ast, const location& loc, AstNode* _targets) :
		Stmt(ast, loc)
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

int Delete::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}



ImportFrom::ImportFrom(class Ast* ast, const location& loc, AstNode* _module,
		AstNode* _names, int level) :
	Stmt(ast, loc), level(level)
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
		AliasNodes *nodes = dynamic_cast<AliasNodes*>(n);
		assert(nodes);
		names = nodes->names;
	}
}

AliasNodes::AliasNodes(class Ast* ast, const location& loc, AstNode* nm, AstNode* asnm) :
		AstNode(ast, loc)
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


int Return::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int While::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Raise::Accept(class AstVisitor* v)
{
    return v->Visit(this);
}

int Try::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Assert::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

Import::Import(class Ast* ast, const location& loc, AstNode* nm) :
    Stmt(ast, loc)
{
	if (nm) {
		AliasNodes *nodes = dynamic_cast<AliasNodes*>(nm);
		assert(nodes);
		names = nodes->names;
	}
}

int Import::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int ImportFrom::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Global::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int NonLocal::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int ClassDef::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Pass::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Break::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Continue::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

} /* namespace py */


