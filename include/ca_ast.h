/*
 * ca_ast.h
 *
 *  Created on: Aug 4, 2015
 *      Author: andy
 *
 * Reflection
 */

#ifndef _INCLUDE_CA_AST_H_
#define _INCLUDE_CA_AST_H_

/**
 * Cayman AST
 *
 * Creates a set of type definitions in the cayman.ast namespace when used under
 * Python. or a in the 'ast' namespace when stand-alone.
 *
 * Many language elements, such as strings, lists, dictionaries, primitives parse
 * directly into thier native type, i.e. as in scheme, there is no difference
 * between a quasi-quoted string and a string itself, i.e.
 *
 * "foo" is the same as '"foo".
 *
 * Other, more complex language elments parse into a 'defintion' object, such as
 * a function defintion "FuncDef", or a class definition, "ClassDef". Here, there is a
 * difference betwen the compiled object and its definition. This is the same as in
 * scheme:
 *
 * >>> (define foodef '(define (foo x) x))
 * >>> foodef
 * '(define (foo x) x)
 * >>> (eval foodef)
 * >>> foo
 * #<procedure:foo>
 */

#include "ca_object.h"
#include "ca_symbol.h"
#include "ca_list.h"


#ifdef __cplusplus
extern "C" {
#endif




// C++ versions of function definitions, give some C++ inheritence syntactic sugar
#ifdef __cplusplus

struct CaAst : CaObject {
	int column;
	int line;
};

/**
 * Arguments to a function or process
 */
struct CaArgument : CaObject {

};

struct CaStmt : CaAst {
};

struct CaExpr : CaStmt {

};

struct CaModuleDef : CaAst {
	CaList *body;
};

struct CaProcessArgument : CaAst {
	CaSymbol *name;
	CaExpr *stoichiometry;
	CaExpr *annotation;
};


struct CaDefinition: CaAst {
	CaSymbol *name;
	CaSymbol *identifier;
	CaList *decorators;

};

struct CaRateProcessDef : CaDefinition  {

	CaList *reactants;
	CaList *products;
	CaList *modifiers;


	/**
	 * The body of the process definition, this can either be interpreted
	 * as a rate expression in the case of a rate process, or a sequence of
	 * operations in the case of a conditional process.
	 */
	CaObject *rate;
};


struct CaCall : CaAst {

	/**
	 * Name of function being called
	 */
	CaSymbol *name;
	CaList *arguments;
	CaList *keywords;
};

struct CaFunctionDef : CaDefinition {

    CaList *arguments;
    CaObject *body;


    /**
     * return type expression
     */
    CaObject *returns;
} ;


struct CaClassDef : CaDefinition {

    CaList *bases;
    CaList *keywords;
    CaList *body;
};


#endif

/**
 * create new function def.
 */
CaAPI_FUNC(CaFunctionDef*) CaFunctionDef_New(CaSymbol *name, CaList *args, CaList *body,
                        CaList *decorators, CaObject *returns, int line,
                        int column);






#ifdef __cplusplus
}
#endif



#endif /* _INCLUDE_CA_AST_H_ */
