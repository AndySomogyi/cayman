/*
 * ca_function.h
 *
 *  Created on: Aug 3, 2015
 *      Author: andy
 *
 * Function Objects
 * There are a few functions specific to Python functions.
 */

#ifndef _INCLUDED_CA_FUNCTION_H_
#define _INCLUDED_CA_FUNCTION_H_

#include "ca_object.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * Return true if o is a function object (has type CaFunction_Type). The parameter
 * must not be NULL.
 */
CaAPI_FUNC(int) CaFunction_Check(CaObject *o);

/**
 * Return value: New reference.
 * Return a new function object associated with the code object code. globals must
 * be a dictionary with the global variables accessible to the function.
 *
 * The function’s docstring, name and __module__ are retrieved from the code object,
 * the argument defaults and closure are set to NULL.
 */
CaAPI_FUNC(CaObject*) CaFunction_New(CaObject *code, CaObject *globals);


/**
 * Return value: New reference.
 * As CaFunction_New(), but also allows to set the function object’s __qualname__
 * attribute. qualname should be a unicode object or NULL; if NULL, the
 * __qualname__ attribute is set to the same value as its __name__ attribute.
 */
CaAPI_FUNC(CaObject*) CaFunction_NewWithQualName(CaObject *code, CaObject *globals,
		CaObject *qualname);

/**
 * Return value: Borrowed reference.
 * Return the code object associated with the function object op.
 */
CaAPI_FUNC(CaObject*) CaFunction_GetCode(CaObject *op);

/**
 * Return value: Borrowed reference.
 * Return the globals dictionary associated with the function object op.
 */
CaAPI_FUNC(CaObject*) CaFunction_GetGlobals(CaObject *op);

/**
 * Return value: Borrowed reference.
 * Return the __module__ attribute of the function object op. This is normally a
 * string containing the module name, but can be set to any other object by
 * Cathon code.
 */
CaAPI_FUNC(CaObject*) CaFunction_GetModule(CaObject *op);

/**
 * Return value: Borrowed reference.
 * Return the argument default values of the function object op. This can be a
 * tuple of arguments or NULL.
 */
CaAPI_FUNC(CaObject*) CaFunction_GetDefaults(CaObject *op);

/**
 * Set the argument default values for the function object op. defaults must be
 * Ca_None or a tuple.
 * Raises SystemError and returns -1 on failure.
 */
CaAPI_FUNC(int) CaFunction_SetDefaults(CaObject *op, CaObject *defaults);

/**
 * Return value: Borrowed reference.
 * Return the closure associated with the function object op. This can be NULL or
 * a tuple of cell objects.
 */
CaAPI_FUNC(CaObject*) CaFunction_GetClosure(CaObject *op);

/**
 * Set the closure associated with the function object op. closure must be Ca_None
 * or a tuple of cell objects.
 *
 * Raises SystemError and returns -1 on failure.
 */
CaAPI_FUNC(int) CaFunction_SetClosure(CaObject *op, CaObject *closure);

/**
 * Return the annotations of the function object op. This can be a mutable
 * dictionary or NULL.
 */
CaAPI_FUNC(CaObject*) CaFunction_GetAnnotations(CaObject *op);

/**
 * Set the annotations for the function object op. annotations must be a dictionary
 * or Ca_None.
 *
 * Raises SystemError and returns -1 on failure.
 */
CaAPI_FUNC(int) CaFunction_SetAnnotations(CaObject *op, CaObject *annotations);


#ifdef __cplusplus
}
#endif

#endif /* _INCLUDED_CA_FUNCTION_H_ */
