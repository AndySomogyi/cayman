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

#include "ca_object.h"
#include "ca_symbol.h"
#include "ca_list.h"

#ifdef __cplusplus

struct CaAst : CaObject {

};


/**
 * Arguments to a function or process
 */
struct CaArgument : CaObject {

};

struct CaStmt : CaObject {
	int column;
	int line;
};

struct CaExpr : CaStmt {

};

struct CaProcessArgument : CaObject {
	CaSymbol *name;
	CaExpr *stoichiometry;
	CaExpr *annotation;
};

struct CaProcessDef : CaObject {
	CaList *reactants;
	CaList *products;
	CaList *modifiers;
	CaList *decorators;

	/**
	 * The body of the process definition, this can either be interpreted
	 * as a rate expression in the case of a rate process, or a sequence of
	 * operations in the case of a conditional process.
	 */
	CaList *body;
};




#endif


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif



#endif /* _INCLUDE_CA_AST_H_ */
