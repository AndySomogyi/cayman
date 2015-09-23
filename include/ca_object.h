/*
 * ca_object.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CA_OBJECT_H_
#define _INCLUDED_CA_OBJECT_H_

#include <ca_port.h>

#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif

/**
 * Basic opaque Cayman object type.
 */
struct CaObject;

/**
 * Basic opaque Cayman type type.
 */
//typedef struct CaType CaTypeObject;

struct CaTypeObject;

struct CaType;

#define Ca_REFCNT(ob)           (((CaObject*)(ob))->ob_refcnt)
#define Ca_TYPE(ob)             (((CaObject*)(ob))->ob_type)
#define Ca_SIZE(ob)             (((CaVarObject*)(ob))->ob_size)

#define Ca_INCREF(o) { Ca_IncRef((CaObject*)(o)); }

#define Ca_DECREF(o) { Ca_DecRef((CaObject*)(o)); }

/* Safely decref `op` and set `op` to NULL, especially useful in tp_clear
 * and tp_dealloc implementations.
 *
 * Note that "the obvious" code can be deadly:
 *
 *     Ca_XDECREF(op);
 *     op = NULL;
 *
 * Typically, `op` is something like self->containee, and `self` is done
 * using its `containee` member.  In the code sequence above, suppose
 * `containee` is non-NULL with a refcount of 1.  Its refcount falls to
 * 0 on the first line, which can trigger an arbitrary amount of code,
 * possibly including finalizers (like __del__ methods or weakref callbacks)
 * coded in Cayman, which in turn can release the GIL and allow other threads
 * to run, etc.  Such code may even invoke methods of `self` again, or cause
 * cyclic gc to trigger, but-- oops! --self->containee still points to the
 * object being torn down, and it may be in an insane state while being torn
 * down.  This has in fact been a rich historic source of miserable (rare &
 * hard-to-diagnose) segfaulting (and other) bugs.
 *
 * The safe way is:
 *
 *      Ca_CLEAR(op);
 *
 * That arranges to set `op` to NULL _before_ decref'ing, so that any code
 * triggered as a side-effect of `op` getting torn down no longer believes
 * `op` points to a valid object.
 *
 * There are cases where it's safe to use the naive code, but they're brittle.
 * For example, if `op` points to a Cayman integer, you know that destroying
 * one of those can't cause problems -- but in part that relies on that
 * Cayman integers aren't currently weakly referencable.  Best practice is
 * to use Ca_CLEAR() even if you can't think of a reason for why you need to.
 */
#define Ca_CLEAR(op)                            \
    do {                                        \
        CaObject *_py_tmp = (CaObject *)(op);   \
        if (_py_tmp != NULL) {                  \
            (op) = NULL;                        \
            Ca_DECREF(_py_tmp);                 \
        }                                       \
    } while (0)

/* Macros to use in case the object pointer may be NULL: */
#define Ca_XINCREF(op)                                \
    do {                                              \
        CaObject *_py_xincref_tmp = (CaObject *)(op); \
        if (_py_xincref_tmp != NULL)                  \
            Ca_INCREF(_py_xincref_tmp);               \
    } while (0)

#define Ca_XDECREF(op)                                \
    do {                                              \
        CaObject *_py_xdecref_tmp = (CaObject *)(op); \
        if (_py_xdecref_tmp != NULL)                  \
            Ca_DECREF(_py_xdecref_tmp);               \
    } while (0)

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Print an object, o, on file, fp.  Returns -1 on
 * error.  The flags argument is used to enable certain printing
 * options. The only option currently supported is Ca_Print_RAW.
 */
CaAPI_FUNC(int) CaObject_Print(CaObject *o, FILE *fp, int flags);

/**
 * Returns 1 if o has the attribute attr_name, and 0 otherwise.
 * This is equivalent to the Cayman expression:
 * hasattr(o,attr_name).
 *
 * This function always succeeds.
 */
CaAPI_FUNC(int) CaObject_HasAttrString(CaObject *o, const char *attr_name);

/**
 * Retrieve an attributed named attr_name form object o.
 * Returns the attribute value on success, or NULL on failure.
 * This is the equivalent of the Cayman expression: o.attr_name.
 */
CaAPI_FUNC(CaObject)* CaObject_GetAttrString(CaObject *o,
		const char *attr_name);

/**
 * Returns 1 if o has the attribute attr_name, and 0 otherwise.
 * This is equivalent to the Cayman expression:
 * hasattr(o,attr_name).
 * This function always succeeds.
 */
CaAPI_FUNC(int) CaObject_HasAttr(CaObject *o, CaObject *attr_name);

/**
 * Retrieve an attributed named attr_name form object o.
 * Returns the attribute value on success, or NULL on failure.
 * This is the equivalent of the Cayman expression: o.attr_name.
 */
CaAPI_FUNC(CaObject)* CaObject_GetAttr(CaObject *o, CaObject *attr_name);

/**
 * Set the value of the attribute named attr_name, for object o,
 * to the value, v. Returns -1 on failure.  This is
 * the equivalent of the Cayman statement: o.attr_name=v.
 */
CaAPI_FUNC(int) CaObject_SetAttrString(CaObject *o, const char *attr_name,
		CaObject *v);

/**
 * Set the value of the attribute named attr_name, for object o,
 * to the value, v. Returns -1 on failure.  This is
 * the equivalent of the Cayman statement: o.attr_name=v.
 */
CaAPI_FUNC(int) CaObject_SetAttr(CaObject *o, CaObject *attr_name, CaObject *v);

/**
 * Delete attribute named attr_name, for object o. Returns
 * -1 on failure.  This is the equivalent of the Cayman
 * statement: del o.attr_name.
 */
CaAPI_FUNC(int) CaObject_DelAttrString(CaObject *o, const char *attr_name);

/**
 * Delete attribute named attr_name, for object o. Returns -1
 * on failure.  This is the equivalent of the Cayman
 * statement: del o.attr_name.
 */
CaAPI_FUNC(int) CaObject_DelAttr(CaObject *o, CaObject *attr_name);

/**
 * Compute the string representation of object, o.  Returns the
 * string representation on success, NULL on failure.  This is
 * the equivalent of the Cayman expression: repr(o).
 *
 * Called by the repr() built-in function.
 */
CaAPI_FUNC(CaObject) *CaObject_Repr(CaObject *o);

/**
 * Compute the string representation of object, o.  Returns the
 * string representation on success, NULL on failure.  This is
 * the equivalent of the Cayman expression: str(o).)
 *
 * Called by the str() and print() built-in functions.
 */
CaAPI_FUNC(CaObject) *CaObject_Str(CaObject *o);

/**
 * Call the method named m of object o with a variable number of
 * C arguments. Returns the result of the call
 * on success, or NULL on failure.  This is the equivalent of
 * the Cayman expression: o.method(args).
 */
CaAPI_FUNC(CaObject *) CaObject_CallMethod(CaObject *o,
		const char *method,
		const char *format, ...);

/**
 * Call the method named m of object o with a variable number of
 * C arguments.  The C arguments are provided as CaObject *
 * values, terminated by NULL.  Returns the result of the call
 * on success, or NULL on failure.  This is the equivalent of
 * the Cayman expression: o.method(args).
 */
CaAPI_FUNC(CaObject *) CaObject_CallMethodObjArgs(CaObject *o,
		CaObject *method, ...);

/**
 *  Compute and return the hash, hash_value, of an object, o.  On
 failure, return -1.  This is the equivalent of the Cayman
 expression: hash(o).
 */

CaAPI_FUNC(long) CaObject_Hash(CaObject *o);

/**
 *  Returns 1 if the object, o, is considered to be true, 0 if o is
 considered to be false and -1 on failure. This is equivalent to the
 Cayman expression: not not o
 */

CaAPI_FUNC(int) CaObject_IsTrue(CaObject *o);

/**
 * Returns 0 if the object, o, is considered to be true, 1 if o is
 considered to be false and -1 on failure. This is equivalent to the
 Cayman expression: not o
 */
CaAPI_FUNC(int) CaObject_Not(CaObject *o);

/**
 * On success, returns a type object corresponding to the object
 * type of object o. On failure, returns NULL.  This is
 * equivalent to the Cayman expression: type(o).
 */
CaAPI_FUNC(CaObject *) CaObject_Type(CaObject *o);

/**
 * Return the size of object o.  If the object, o, provides
 * both sequence and mapping protocols, the sequence size is
 * returned. On error, -1 is returned.  This is the equivalent
 * to the Cayman expression: len(o).
 */
CaAPI_FUNC(Ca_ssize_t) CaObject_Size(CaObject *o);

/**
 * Guess the size of object o using len(o) or o.__length_hint__().
 * If neither of those return a non-negative value, then return the
 * default value.  If one of the calls fails, this function returns -1.
 */
CaAPI_FUNC(Ca_ssize_t) CaObject_Length(CaObject *o);

/**
 * Return element of o corresponding to the object, key, or NULL
 * on failure. This is the equivalent of the Cayman expression:
 * o[key].
 */
CaAPI_FUNC(CaObject *) CaObject_GetItem(CaObject *o, CaObject *key);

/**
 * Map the object, key, to the value, v.  Returns
 * -1 on failure.  This is the equivalent of the Cayman
 * statement: o[key]=v.
 */
CaAPI_FUNC(int) CaObject_SetItem(CaObject *o, CaObject *key, CaObject *v);

/**
 * Remove the mapping for object, key, from the object *o.
 Returns -1 on failure.  This is equivalent to
 the Cayman statement: del o[key].
 */

CaAPI_FUNC(int) CaObject_DelItemString(CaObject *o, const char *key);

/**
 * Delete the mapping for key from *o.  Returns -1 on failure.
 This is the equivalent of the Cayman statement: del o[key].
 */

CaAPI_FUNC(int) CaObject_DelItem(CaObject *o, CaObject *key);


CaAPI_FUNC(int) CaObject_IsInstance(CaObject *object, CaObject *typeorclass);
/* isinstance(object, typeorclass) */

CaAPI_FUNC(int) CaObject_IsSubclass(CaObject *object, CaObject *typeorclass);
/* issubclass(object, typeorclass) */

CaAPI_FUNC(void) Ca_Dealloc(CaObject *);

CaAPI_FUNC(uint32_t) Ca_IncRef(CaObject *o);

CaAPI_FUNC(uint32_t) Ca_DecRef(CaObject *o);

CaAPI_FUNC(CaObject *) CaObject_GetAttrString(CaObject *, const char *);


#ifdef __cplusplus
}
#endif

#endif /* _INCLUDED_CA_OBJECT_H_ */
