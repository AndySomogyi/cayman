/*
 * ca_reflection.h
 *
 *  Created on: Aug 4, 2015
 *      Author: andy
 *
 * Reflection
 */

#ifndef _INCLUDE_CA_REFLECTION_H_
#define _INCLUDE_CA_REFLECTION_H_

#include <ca_port.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Cython Scope resolution, same as Python, follows the LEGB Rule.
 *
 * L, Local — Names assigned in any way within a function (def or lambda)), and
 *    not declared global in that function.
 *
 * E, Enclosing function locals — Name in the local scope of any and all
 *    enclosing functions (def or lambda), from inner to outer.
 *
 * G, Global (module) — Names assigned at the top-level of a module file,
 *    or declared global in a def within the file.
 *
 * B, Built-in (Python) — Names preassigned in the built-in names module :
 *    open,range,SyntaxError,...
 */

/**
 * Return value: Borrowed reference.
 * Return a dictionary of the builtins in the current execution frame, or the
 * interpreter of the thread state if no frame is currently executing.
 */
CaAPI_FUNC(CaObject*) CaEval_GetBuiltins();

/**
 * Return value: Borrowed reference.
 * Return a dictionary of the local variables in the current execution frame,
 * or NULL if no frame is currently executing.
 */
CaAPI_FUNC(CaObject*) CaEval_GetLocals();

/**
 * Return value: Borrowed reference.
 * Return a dictionary of the global variables in the current execution frame,
 * or NULL if no frame is currently executing.
 */
CaAPI_FUNC(CaObject*) CaEval_GetGlobals();

/**
 * Return value: Borrowed reference.
 * Return the current thread state’s frame, which is NULL if no frame is
 * currently executing.
 */
// CaFrameObject* CaEval_GetFrame();

/**
 * Return the line number that frame is currently executing.
 */
// int CaFrame_GetLineNumber(CaFrameObject *frame);

/**
 * Return the name of func if it is a function, class or instance object,
 * else the name of funcs type.
 */
CaAPI_FUNC(const char*) CaEval_GetFuncName(CaObject *func);

/**
 * Return a description string, depending on the type of func. Return values
 * include "()" for functions and methods, " constructor", " instance",
 * and ” object”. Concatenated with the result of CaEval_GetFuncName(), the
 * result will be a description of func.
 */
CaAPI_FUNC(const char*) CaEval_GetFuncDesc(CaObject *func);


#ifdef __cplusplus
}
#endif



#endif /* _INCLUDE_CA_REFLECTION_H_ */
