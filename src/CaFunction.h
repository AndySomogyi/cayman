/*
 * CaFunction.h
 *
 *  Created on: Aug 3, 2015
 *      Author: andy
 */

#ifndef SRC_CAFUNCTION_H_
#define SRC_CAFUNCTION_H_

#include "CaCallable.h"


class CaModule;

/**
 *
 * The CaFunction object represents
 */
class CaFunction : public CaObject
{
public:


	CaFunction(py::FunctionDef* _func) :
		CaObject(CA_FUNCTION), func(_func) {};

	/**
	 * The original AST function definition.
	 *
	 * This may or may not already be specalized.
	 */
	py::FunctionDef *func;

	/**
	 * map of specialized defs, key is mangled name of the function and args.
	 *
	 * TODO, this is very ineficient, come up with better key based on byte
	 * buffer of type codes or something.
	 */
	llvm::StringMap<py::FunctionDef> specializedDefs;

	/**
	 * A borrowed reference to the module to which this funciton belongs.
	 * This needs be be borrowed in order to eliminate circular references,
	 * as the module also owns the functions.
	 *
	 * May be null
	 */
	CaModule *module = nullptr;

	/**
	 *
	 */
	void *pfunc = nullptr;

	void *getFuctionAddress(const CaTypeObjectVec& args, CaType* retType);


	/**
	 * Emit a type specialized function prototype.
	 */
	llvm::Function *getFunctionProto(const CaTypeObjectVec& args, CaType* retType);






	static bool classof(const CaObject *o)
	{
		return o->typeId == CA_FUNCTION;
	}

};

#endif /* SRC_CAFUNCTION_H_ */
