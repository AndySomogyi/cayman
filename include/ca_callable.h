/*
 * ca_module.h
 *
 *  Created on: Jul 6, 2015
 *      Author: andy
 *
 * module functions, definitions and documentation copied from official
 * python website for python compatiblity.
 */

#ifndef _INCLUDED_CA_CALLABLE_H_
#define _INCLUDED_CA_CALLABLE_H_

#include "ca_object.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef CA_STRICT
struct CaCallable;
#else
typedef CaObject CaCallable;
#endif




/**
 * Determine if the object, o, is callable.  Return 1 if the
 * object is callable and 0 otherwise..
 *
 * This function always succeeds.
 */
CaAPI_FUNC(int) CaCallable_Check(CaObject *);

/**
 * Return the raw, callable address of the specified function.
 * This is intended to be cast to a function pointer and called.
 * This may involve code generation
 *
 * This is the key function is the Cayman runtime.
 *
 * Here, the callable object is specialized and JITed for the given
 * argument types. I.e. the functions foo(int) and foo(double) are
 * different, as the function was specialized for a different type
 * in each case.
 *
 * For example, to get a callable function pointer to a function
 * defined in a module, one would:
 * @code
 * // assuming one already has a module
 * CoObject* module;
 *
 *
 * @endcode
 *
 * @param callable: A callable CaObject. This may be either a named,
 *                  a functor (an object with the __call__) method, or
 *                  a method on a an object.
 *
 * @param argTypes: A sequence of CaTypeObjects packed into a tuple.
 * @returns: the raw function pointer address of the underlying
 *           native code object.
 */
CaAPI_FUNC(void*) CaCallable_GetFuctionAddress(CaCallable *callable,
		CaType *retType, CaObject *argTypes);

/**
 * Same as CaCallable_GetFuctionAddress, except the arguments types are
 * given as variable number of C arguments.  The C arguments are provided
 * as CaTypeObject * values, terminated by a NULL.
 */
CaAPI_FUNC(void*) CaCallable_GetFuctionAddressObjArgs(CaCallable *callable,
		CaType *retType, ...);

/**
 * Call a callable Cayman object, callable, with
 * arguments and keywords arguments.  The 'args' argument can not be
 * NULL, but the 'kw' argument can be NULL.
 */
CaAPI_FUNC(CaObject *) CaCallable_Call(CaCallable *callable,
		CaObject *args, CaObject *kw);

/**
 * Compatibility macro
 */
#define CaObject_Call CaCallable_Call

/**
 * Call a callable Cayman object, callable_object, with
 * arguments given by the tuple, args.  If no arguments are
 * needed, then args may be NULL.  Returns the result of the
 * call on success, or NULL on failure.  This is the equivalent
 * of the Cayman expression: o(*args).
 */
CaAPI_FUNC(CaObject *) CaCallable_CallObject(CaCallable *callable,
		CaObject *args);

#define CaObject_CallObject CaCallable_CallObject

/**
 * Call a callable Cayman object, callable_object, with a
 * variable number of C arguments. The C arguments are described
 * using a mkvalue-style format string. The format may be NULL,
 * indicating that no arguments are provided.  Returns the
 * result of the call on success, or NULL on failure.  This is
 * the equivalent of the Cayman expression: o(*args).
 */
CaAPI_FUNC(CaObject *) CaCallable_CallFunction(CaCallable *callable,
		const char *format, ...);

#define CaObject_CallFunction CaCallable_CallFunction


/**
 * Call a callable Cayman object, callable, with a
 * variable number of C arguments.  The C arguments are provided
 * as CaObject * values, terminated by a NULL.  Returns the
 * result of the call on success, or NULL on failure.  This is
 * the equivalent of the Cayman expression: o(*args).
 */
CaAPI_FUNC(CaObject *) CaCallable_CallFunctionObjArgs(CaCallable *callable,
		...);

/**
 * Compatibility macro, Python defined this originally as
 * PyObject_CallFunctionObjArgs
 */
#define CaObject_CallFunctionObjArgs CaCallable_CallFunctionObjArgs




#ifdef __cplusplus
}
#endif

#endif /* _INCLUDED_CA_CALLABLE_H_ */
