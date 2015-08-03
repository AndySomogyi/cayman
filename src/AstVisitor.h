/*
 * AstVisitor.h
 *
 *  Created on: Jun 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_ASTVISITOR_H_
#define _INCLUDED_ASTVISITOR_H_

#include "AstNode.h"
#include "Stmt.h"
#include "Expr.h"

namespace py
{
    
class Ast;


template<typename Derived, typename RType>
class AstVisitor
{
protected:

	RType visit(Name*) { return RType(); };
	RType visit(Num*) { return RType(); };
	RType visit(Str*) { return RType(); };
	RType visit(Module*) { return RType(); };
	RType visit(Assign*) { return RType(); };
	RType visit(BinOp*) { return RType(); };
	RType visit(Tuple*) { return RType(); };
	RType visit(Ast*) { return RType(); };
	RType visit(Arg*) { return RType(); };
	RType visit(FunctionDef*) { return RType(); };
	RType visit(KeywordArg*) { return RType(); };
	RType visit(Call*) { return RType(); };
	RType visit(Starred*) { return RType(); };
	RType visit(For*) { return RType(); };
	RType visit(If*) { return RType(); };
	RType visit(Attribute*) { return RType(); };
	RType visit(IfExpr*) { return RType(); };
	RType visit(UnaryOp*) { return RType(); };
	RType visit(AugAssign*) { return RType(); };
	RType visit(Compare*) { return RType(); };
	RType visit(Delete*) { return RType(); };
    RType visit(Return*) { return RType(); };
    RType visit(Pass*) { return RType(); };
    RType visit(Break*) { return RType(); };
    RType visit(Continue*) { return RType(); };
    RType visit(While*) { return RType(); };
    RType visit(Raise*) { return RType(); };
    RType visit(Try*) { return RType(); };
    RType visit(Assert*) { return RType(); };
    RType visit(Import*) { return RType(); };
    RType visit(ImportFrom*) { return RType(); };
    RType visit(Global*) { return RType(); };
    RType visit(NonLocal*) { return RType(); };
    RType visit(ClassDef*) { return RType(); };
    RType visit(Lambda*) { return RType(); };
    RType visit(Dict*) { return RType(); };
    RType visit(Set*) { return RType(); };
    RType visit(ListComp*) { return RType(); };
    RType visit(SetComp*) { return RType(); };
    RType visit(DictComp*) { return RType(); };
    RType visit(GeneratorExpr*) { return RType(); };
    RType visit(Yield*) { return RType(); };
    RType visit(YieldFrom*) { return RType(); };
    RType visit(Bytes*) { return RType(); };
    RType visit(NameConstant*) { return RType(); };
    RType visit(Subscript*) { return RType(); };
    RType visit(List*) { return RType(); };


	RType dispatch(AstNode *node)
	{
		Derived *p = static_cast<Derived*>(this);

		switch(node->type)
		{
        case AST_NAME: return p->visit(static_cast<Name*>(node));
        case AST_NUM: return p->visit(static_cast<Num*>(node));
        case AST_STR: return p->visit(static_cast<Str*>(node));
        case AST_MODULE: return p->visit(static_cast<Module*>(node));
        case AST_ASSIGN: return p->visit(static_cast<Assign*>(node));
        case AST_BINOP: return p->visit(static_cast<BinOp*>(node));
        case AST_TUPLE: return p->visit(static_cast<Tuple*>(node));
        case AST_AST: return p->visit(static_cast<Ast*>(node));
        case AST_ARG: return p->visit(static_cast<Arg*>(node));
        case AST_FUNCTIONDEF: return p->visit(static_cast<FunctionDef*>(node));
        case AST_KEYWORDARG: return p->visit(static_cast<KeywordArg*>(node));
        case AST_CALL: return p->visit(static_cast<Call*>(node));
        case AST_STARRED: return p->visit(static_cast<Starred*>(node));
        case AST_FOR: return p->visit(static_cast<For*>(node));
        case AST_IF: return p->visit(static_cast<If*>(node));
        case AST_ATTRIBUTE: return p->visit(static_cast<Attribute*>(node));
        case AST_IFEXPR: return p->visit(static_cast<IfExpr*>(node));
        case AST_UNARYOP: return p->visit(static_cast<UnaryOp*>(node));
        case AST_AUGASSIGN: return p->visit(static_cast<AugAssign*>(node));
        case AST_COMPARE: return p->visit(static_cast<Compare*>(node));
        case AST_DELETE: return p->visit(static_cast<Delete*>(node));
        case AST_RETURN: return p->visit(static_cast<Return*>(node));
        case AST_PASS: return p->visit(static_cast<Pass*>(node));
        case AST_BREAK: return p->visit(static_cast<Break*>(node));
        case AST_CONTINUE: return p->visit(static_cast<Continue*>(node));
        case AST_WHILE: return p->visit(static_cast<While*>(node));
        case AST_RAISE: return p->visit(static_cast<Raise*>(node));
        case AST_TRY: return p->visit(static_cast<Try*>(node));
        case AST_ASSERT: return p->visit(static_cast<Assert*>(node));
        case AST_IMPORT: return p->visit(static_cast<Import*>(node));
        case AST_IMPORTFROM: return p->visit(static_cast<ImportFrom*>(node));
        case AST_GLOBAL: return p->visit(static_cast<Global*>(node));
        case AST_NONLOCAL: return p->visit(static_cast<NonLocal*>(node));
        case AST_CLASSDEF: return p->visit(static_cast<ClassDef*>(node));
        case AST_LAMBDA: return p->visit(static_cast<Lambda*>(node));
        case AST_DICT: return p->visit(static_cast<Dict*>(node));
        case AST_SET: return p->visit(static_cast<Set*>(node));
        case AST_LISTCOMP: return p->visit(static_cast<ListComp*>(node));
        case AST_SETCOMP: return p->visit(static_cast<SetComp*>(node));
        case AST_DICTCOMP: return p->visit(static_cast<DictComp*>(node));
        case AST_GENERATOREXPR: return p->visit(static_cast<GeneratorExpr*>(node));
        case AST_YIELD: return p->visit(static_cast<Yield*>(node));
        case AST_YIELDFROM: return p->visit(static_cast<YieldFrom*>(node));
        case AST_BYTES: return p->visit(static_cast<Bytes*>(node));
        case AST_NAMECONSTANT: return p->visit(static_cast<NameConstant*>(node));
        case AST_SUBSCRIPT: return p->visit(static_cast<Subscript*>(node));
        case AST_LIST: return p->visit(static_cast<List*>(node));
        default:
        	assert(0 && "Invalid Node Type");
        	return RType();
		}

	}
};

} /* namespace py */

#endif /* _INCLUDED_ASTVISITOR_H_ */
