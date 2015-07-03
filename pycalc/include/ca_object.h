/*
 * ca_object.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDE_CA_OBJECT_H_
#define _INCLUDE_CA_OBJECT_H_

#include <ca_port.h>


#ifdef __cplusplus
extern "C" {
#endif


/* Object and type object interface */

/*
Objects are structures allocated on the heap.  Special rules apply to
the use of objects to ensure they are properly garbage-collected.
Objects are never allocated statically or on the stack; they must be
accessed through special macros and functions only.  (Type objects are
exceptions to the first rule; the standard types are represented by
statically initialized type objects, although work on type/class unification
for Cayman 2.2 made it possible to have heap-allocated type objects too).

An object has a 'reference count' that is increased or decreased when a
pointer to the object is copied or deleted; when the reference count
reaches zero there are no references to the object left and it can be
removed from the heap.

An object has a 'type' that determines what it represents and what kind
of data it contains.  An object's type is fixed when it is created.
Types themselves are represented as objects; an object contains a
pointer to the corresponding type object.  The type itself has a type
pointer pointing to the object representing the type 'type', which
contains a pointer to itself!).

Objects do not float around in memory; once allocated an object keeps
the same size and address.  Objects that must hold variable-size data
can contain pointers to variable-size parts of the object.  Not all
objects of the same type have the same size; but the size cannot change
after allocation.  (These restrictions are made so a reference to an
object can be simply a pointer -- moving an object would require
updating all the pointers, and changing an object's size would require
moving it if there was another object right next to it.)

Objects are always accessed through pointers of the type 'CaObject *'.
The type 'CaObject' is a structure that only contains the reference count
and the type pointer.  The actual memory allocated for an object
contains other data that can only be accessed after casting the pointer
to a pointer to a longer structure type.  This longer type must start
with the reference count and type fields; the macro CaObject_HEAD should be
used for this (to accommodate for future changes).  The implementation
of a particular object type can cast the object pointer to the proper
type and back.

A standard interface exists for objects that contain an array of items
whose size is determined when the object is allocated.
*/


#define _CaObject_HEAD_EXTRA
#define _CaObject_EXTRA_INIT


/* CaObject_HEAD defines the initial segment of every CaObject. */
#define CaObject_HEAD                   CaObject ob_base;

#define CaObject_HEAD_INIT(type)        \
    { _CaObject_EXTRA_INIT              \
    1, type },

#define CaVarObject_HEAD_INIT(type, size)       \
    { CaObject_HEAD_INIT(type) size },

/* CaObject_VAR_HEAD defines the initial segment of all variable-size
 * container objects.  These end with a declaration of an array with 1
 * element, but enough space is malloc'ed so that the array actually
 * has room for ob_size elements.  Note that ob_size is an element count,
 * not necessarily a byte count.
 */
#define CaObject_VAR_HEAD      CaVarObject ob_base;
#define Ca_INVALID_SIZE (Ca_ssize_t)-1


struct CaObject;




typedef struct _typeobject CaTypeObject; /* opaque */


CaAPI_FUNC(void) Ca_Dealloc(CaObject *);

#define Ca_REFCNT(ob)           (((CaObject*)(ob))->ob_refcnt)
#define Ca_TYPE(ob)             (((CaObject*)(ob))->ob_type)
#define Ca_SIZE(ob)             (((CaVarObject*)(ob))->ob_size)


#define Ca_INCREF(op)

#define Ca_DECREF(op)

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




CaAPI_FUNC(CaObject *) CaObject_GetAttrString(CaObject *, const char *);


/* Generic operations on objects */
struct _Ca_Identifier;

CaAPI_FUNC(CaObject *) CaObject_Repr(CaObject *);
CaAPI_FUNC(CaObject *) CaObject_Str(CaObject *);
CaAPI_FUNC(CaObject *) CaObject_ASCII(CaObject *);
CaAPI_FUNC(CaObject *) CaObject_Bytes(CaObject *);
CaAPI_FUNC(CaObject *) CaObject_RichCompare(CaObject *, CaObject *, int);
CaAPI_FUNC(int) CaObject_RichCompareBool(CaObject *, CaObject *, int);
CaAPI_FUNC(CaObject *) CaObject_GetAttrString(CaObject *, const char *);
CaAPI_FUNC(int) CaObject_SetAttrString(CaObject *, const char *, CaObject *);
CaAPI_FUNC(int) CaObject_HasAttrString(CaObject *, const char *);
CaAPI_FUNC(CaObject *) CaObject_GetAttr(CaObject *, CaObject *);
CaAPI_FUNC(int) CaObject_SetAttr(CaObject *, CaObject *, CaObject *);
CaAPI_FUNC(int) CaObject_HasAttr(CaObject *, CaObject *);
CaAPI_FUNC(int) _CaObject_IsAbstract(CaObject *);
CaAPI_FUNC(CaObject *) _CaObject_GetAttrId(CaObject *, struct _Ca_Identifier *);
CaAPI_FUNC(int) _CaObject_SetAttrId(CaObject *, struct _Ca_Identifier *, CaObject *);
CaAPI_FUNC(int) _CaObject_HasAttrId(CaObject *, struct _Ca_Identifier *);
CaAPI_FUNC(CaObject *) CaObject_SelfIter(CaObject *);
CaAPI_FUNC(CaObject *) CaObject_GenericGetAttr(CaObject *, CaObject *);
CaAPI_FUNC(int) CaObject_GenericSetAttr(CaObject *,
                                              CaObject *, CaObject *);
CaAPI_FUNC(int) CaObject_GenericSetDict(CaObject *, CaObject *, void *);
CaAPI_FUNC(int) CaObject_IsTrue(CaObject *);
CaAPI_FUNC(int) CaObject_Not(CaObject *);

/**
 * Check if an object can be called.
 */
CaAPI_FUNC(int) CaCallable_Check(CaObject *);


#ifdef __cplusplus
}
#endif






#endif /* PYCALC_INCLUDE_CA_OBJECT_H_ */
