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


template<typename Derived, typename RetType, typename StackType>
class AstVisitor
{
protected:

	RetType visit(Name*, StackType) { return RetType(); };
	RetType visit(Num*, StackType) { return RetType(); };
	RetType visit(Str*, StackType) { return RetType(); };
	RetType visit(Module*, StackType) { return RetType(); };
	RetType visit(Assign*, StackType) { return RetType(); };
	RetType visit(BinOp*, StackType) { return RetType(); };
	RetType visit(Tuple*, StackType) { return RetType(); };
	RetType visit(Ast*, StackType) { return RetType(); };
	RetType visit(Arg*, StackType) { return RetType(); };
	RetType visit(FunctionDef*, StackType) { return RetType(); };
	RetType visit(KeywordArg*, StackType) { return RetType(); };
	RetType visit(Call*, StackType) { return RetType(); };
	RetType visit(Starred*, StackType) { return RetType(); };
	RetType visit(For*, StackType) { return RetType(); };
	RetType visit(If*, StackType) { return RetType(); };
	RetType visit(Attribute*, StackType) { return RetType(); };
	RetType visit(IfExpr*, StackType) { return RetType(); };
	RetType visit(UnaryOp*, StackType) { return RetType(); };
	RetType visit(AugAssign*, StackType) { return RetType(); };
	RetType visit(Compare*, StackType) { return RetType(); };
	RetType visit(Delete*, StackType) { return RetType(); };
    RetType visit(Return*, StackType) { return RetType(); };
    RetType visit(Pass*, StackType) { return RetType(); };
    RetType visit(Break*, StackType) { return RetType(); };
    RetType visit(Continue*, StackType) { return RetType(); };
    RetType visit(While*, StackType) { return RetType(); };
    RetType visit(Raise*, StackType) { return RetType(); };
    RetType visit(Try*, StackType) { return RetType(); };
    RetType visit(Assert*, StackType) { return RetType(); };
    RetType visit(Import*, StackType) { return RetType(); };
    RetType visit(ImportFrom*, StackType) { return RetType(); };
    RetType visit(Global*, StackType) { return RetType(); };
    RetType visit(NonLocal*, StackType) { return RetType(); };
    RetType visit(ClassDef*, StackType) { return RetType(); };
    RetType visit(Lambda*, StackType) { return RetType(); };
    RetType visit(Dict*, StackType) { return RetType(); };
    RetType visit(Set*, StackType) { return RetType(); };
    RetType visit(ListComp*, StackType) { return RetType(); };
    RetType visit(SetComp*, StackType) { return RetType(); };
    RetType visit(DictComp*, StackType) { return RetType(); };
    RetType visit(GeneratorExpr*, StackType) { return RetType(); };
    RetType visit(Yield*, StackType) { return RetType(); };
    RetType visit(YieldFrom*, StackType) { return RetType(); };
    RetType visit(Bytes*, StackType) { return RetType(); };
    RetType visit(NameConstant*, StackType) { return RetType(); };
    RetType visit(Subscript*, StackType) { return RetType(); };
    RetType visit(List*, StackType) { return RetType(); };


	RetType dispatch(AstNode *node, StackType stk)
	{
		Derived *p = static_cast<Derived*>(this);

		switch(node->type)
		{
        case AST_NAME: return p->visit(static_cast<Name*>(node), stk);
        case AST_NUM: return p->visit(static_cast<Num*>(node), stk);
        case AST_STR: return p->visit(static_cast<Str*>(node), stk);
        case AST_MODULE: return p->visit(static_cast<Module*>(node), stk);
        case AST_ASSIGN: return p->visit(static_cast<Assign*>(node), stk);
        case AST_BINOP: return p->visit(static_cast<BinOp*>(node), stk);
        case AST_TUPLE: return p->visit(static_cast<Tuple*>(node), stk);
        case AST_AST: return p->visit(static_cast<Ast*>(node), stk);
        case AST_ARG: return p->visit(static_cast<Arg*>(node), stk);
        case AST_FUNCTIONDEF: return p->visit(static_cast<FunctionDef*>(node), stk);
        case AST_KEYWORDARG: return p->visit(static_cast<KeywordArg*>(node), stk);
        case AST_CALL: return p->visit(static_cast<Call*>(node), stk);
        case AST_STARRED: return p->visit(static_cast<Starred*>(node), stk);
        case AST_FOR: return p->visit(static_cast<For*>(node), stk);
        case AST_IF: return p->visit(static_cast<If*>(node), stk);
        case AST_ATTRIBUTE: return p->visit(static_cast<Attribute*>(node), stk);
        case AST_IFEXPR: return p->visit(static_cast<IfExpr*>(node), stk);
        case AST_UNARYOP: return p->visit(static_cast<UnaryOp*>(node), stk);
        case AST_AUGASSIGN: return p->visit(static_cast<AugAssign*>(node), stk);
        case AST_COMPARE: return p->visit(static_cast<Compare*>(node), stk);
        case AST_DELETE: return p->visit(static_cast<Delete*>(node), stk);
        case AST_RETURN: return p->visit(static_cast<Return*>(node), stk);
        case AST_PASS: return p->visit(static_cast<Pass*>(node), stk);
        case AST_BREAK: return p->visit(static_cast<Break*>(node), stk);
        case AST_CONTINUE: return p->visit(static_cast<Continue*>(node), stk);
        case AST_WHILE: return p->visit(static_cast<While*>(node), stk);
        case AST_RAISE: return p->visit(static_cast<Raise*>(node), stk);
        case AST_TRY: return p->visit(static_cast<Try*>(node), stk);
        case AST_ASSERT: return p->visit(static_cast<Assert*>(node), stk);
        case AST_IMPORT: return p->visit(static_cast<Import*>(node), stk);
        case AST_IMPORTFROM: return p->visit(static_cast<ImportFrom*>(node), stk);
        case AST_GLOBAL: return p->visit(static_cast<Global*>(node), stk);
        case AST_NONLOCAL: return p->visit(static_cast<NonLocal*>(node), stk);
        case AST_CLASSDEF: return p->visit(static_cast<ClassDef*>(node), stk);
        case AST_LAMBDA: return p->visit(static_cast<Lambda*>(node), stk);
        case AST_DICT: return p->visit(static_cast<Dict*>(node), stk);
        case AST_SET: return p->visit(static_cast<Set*>(node), stk);
        case AST_LISTCOMP: return p->visit(static_cast<ListComp*>(node), stk);
        case AST_SETCOMP: return p->visit(static_cast<SetComp*>(node), stk);
        case AST_DICTCOMP: return p->visit(static_cast<DictComp*>(node), stk);
        case AST_GENERATOREXPR: return p->visit(static_cast<GeneratorExpr*>(node), stk);
        case AST_YIELD: return p->visit(static_cast<Yield*>(node), stk);
        case AST_YIELDFROM: return p->visit(static_cast<YieldFrom*>(node), stk);
        case AST_BYTES: return p->visit(static_cast<Bytes*>(node), stk);
        case AST_NAMECONSTANT: return p->visit(static_cast<NameConstant*>(node), stk);
        case AST_SUBSCRIPT: return p->visit(static_cast<Subscript*>(node), stk);
        case AST_LIST: return p->visit(static_cast<List*>(node), stk);
        default:
        	assert(0 && "Invalid Node Type");
        	return RetType();
		}

	}
};

} /* namespace py */

#endif /* _INCLUDED_ASTVISITOR_H_ */
