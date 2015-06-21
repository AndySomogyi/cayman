/*
 * AST.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_AST_H_
#define _INCLUDED_AST_H_

#include "AstNode.h"
#include "Expr.h"
#include "Stmt.h"
#include "cxx11/memory.h"

namespace py
{

class Ast: public AstNode
{
public:
	Ast();
	virtual ~Ast();

    Module *module;

    virtual int Accept(class AstVisitor *v);

    virtual void Print(std::ostream &os);

    /**
     * create a basic assignment statement with only a single value (what is being assigned), 
     * and a single target (what is being assigned to)
     */
    Assign *CreateAssign(const location &_loc, AstNode *target, AstNode *value);
    
	Name *CreateName(location &loc, const char* begin, const char* end);

	Num *CreateNum(const location &loc, const char* begin, const char* end);

	Module *CreateModule(const location &loc, const AstNodes &body);


    Tuple *CreateTuple(const location &loc, const AstNodes &items, ExprContext ctx);

	Tuple *CreateTuple(const location &_loc, ExprContext ctx);

    Tuple *CreateTuple(const location& loc, ExprContext ctx, AstNode *seq, AstNode *item=NULL);
    
    Tuple *CreateTuple(const location& loc, AstNode *seq, AstNode *item=NULL);

	Arg *CreateArg(const location& loc, AstNode *name, AstNode *def=NULL,
			AstNode *type=NULL);


    /**
     * Create a fuction def. 
     *
     * @param loc src code location
     * @param nm function name (should be a Name or DottedName
     * @param args argument list
     * @param returns an expresion for the return type, may be NULL
     * @param suite sequence of statements in a Tuple
     */
	FunctionDef *CreateFunctionDef(const location& loc, AstNode *nm, AstNode *args,
        AstNode *returns, AstNode *suite);

	BinOp *CreateBinOp(const location& _loc, AstNode *op, AstNode* _left, AstNode* _right);

	Starred *CreateStarred(const location &loc, AstNode *_value, ExprContext ctx = UnknownCtx);


	/**
	 * Only to be used by the bison parser
	 */
	DblStarred *CreateDblStarred(const location &loc, AstNode *_value);

	/**
	 * Create a call node, if args is NULL, an empty Call obj is created.
	 *
	 * args should be a tuple created in an arglist.
	 *
	 * The args node is consumed in the process.
	 */
	Call *CreateCall(const location& loc, AstNode *name=NULL, AstNode* args = NULL);

	KeywordArg *CreateKeywordArg(const location &loc, AstNode *name, AstNode *value);


	For* CreateFor(const location& loc, AstNode *_target = NULL,
				AstNode *_iter = NULL, AstNode *_body = NULL,
				AstNode *_orelse = NULL);

	/**
	 * Creates an if / elif node.
	 *
	 * If parentIf is not null, it is expected to the parent if statement in an
	 * elif statment, and the test and body are for the elif statment.
	 */
	If *CreateIf(const location& _loc,  AstNode *_test = NULL,
			AstNode *_body = NULL, AstNode *orelse = NULL,
			AstNode *trailingElse = NULL);

	/**
	 * create an If for an elif block, and add it to the parent sequence
	 * else pointer.
	 */
	If *CreateElif(const location& loc, AstNode *elifSeq, AstNode *test,
			AstNode *body = NULL);


	Attribute *CreateAttribute(const location& loc,  ExprContext ctx, AstNode* value,
				AstNode *attr);

	/**
	 * @parm op An AstNode for the operator, used by the parser.
	 */
	UnaryOp *CreateUnaryOp(const location& _loc, AstNode *op, AstNode *operand);

	AugAssign *CreateAugAssign(const location &loc, AstNode *target,
				AstNode *op, AstNode *value);


    /**
     * Create or extend a Compare node. 
     *
     * Compare sequences are handled by the EBNF production rule
     * comparison: expr (comp_op expr)*
     * 
     * Which is implemnted in the parser by the BNF production rule
     * comparison:
     *     expr
     *     | comparison comp_op expr
     * 
     * This method creates or extends a Compare node depending on wether 
     * or not the given seq arg is an expression or an existing Compare.
     */
    Compare *CreateCompare(const location &loc, AstNode *seq, AstNode *op, 
                           AstNode *expr);

    Delete *CreateDelete(const location &loc, AstNode *expr);
    
    Break *CreateBreak(const location &loc);
    
    Continue *CreateContinue(const location &loc);
    
    Return *CreateReturn(const location &loc, AstNode *expr = NULL);
    
    Raise *CreateRaise(const location &loc, AstNode *expr = NULL, AstNode *from = NULL);
    
    Yield *CreateYield(const location &loc, AstNode *expr = NULL);

    YieldFrom *CreateYieldFrom(const location &loc, AstNode *from);
    
    Pass *CreatePass(const location &loc);
    
    AliasNodes *CreateAliasNodes(const location &loc, AstNode *prev, AstNode *name, AstNode *asname = NULL);

    Import *CreateImport(const location &loc, AstNode *names);

    ImportFrom *CreateImportFrom(const location &loc, AstNode *module, AstNode *names, AstNode *level=NULL);

    ImportFrom *CreateImportFrom(const location &loc, int level);

    /**
     * Used by the parser to increment the level,
     *
     * @param prevLevel: a ImportFrom node from prev interation
     * @param level: current dot level
     */
    ImportFrom *CreateImportFrom(const location &loc, AstNode *prevLevel, int level);
    
    
    Global *CreateGlobal(const location &loc, AstNode *names);

    NonLocal *CreateNonLocal(const location &loc, AstNode *names);

    Assert *CreateAssert(const location &loc, AstNode *test, AstNode *msg=NULL);

    While *CreateWhile(const location &loc, AstNode *test, AstNode *body,
                       AstNode *orelse = NULL);
    
    
    AstNode *CreateDecorated(const location& loc, AstNode *decorators, AstNode *thing);

	/**
	 * classdef: 'class' NAME ['(' [arglist] ')'] ':' suite
	 *
	 * @param arglist: optional, may be NULL
	 */
	ClassDef *CreateClassDef(const location &loc, AstNode *name,
			AstNode *arglist, AstNode *suite);


	Dict *CreateDict(const location &loc, AstNode *seq = NULL,
				AstNode *key=NULL, AstNode *value=NULL);

	void Free(AstNode* node);








private:
	// memory managment details of AST
	// All ASTNodes are owned by the root AST object.
	// All other objects, includeing ASTNodes themselves
	// may contain pointers to ASTNodes, but these are
	// borrowed references, owned by the root AST object.
	// ASTNodes are created by the ASTFactory, and these
	// are added to the AST object. In the future, we
	// may employ some sort of block memory managment scheme
	// such as that used in Google V8, but currently, nodes
	// will just be standard 'new'ed and a pointer added
	// to the root AST.

	friend class ASTNodeFactory;

	friend class py_parser;

	TmpArguments *CreateTmpArguments(const location& loc);

	std::vector<AstNode*> nodes;

};

typedef cxx11_ns::shared_ptr<Ast> AstPtr;






} /* namespace py */
#endif /* _INCLUDED_AST_H_ */

