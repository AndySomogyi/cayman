#ifndef Ca_ABSTRACTOBJECT_H
#define Ca_ABSTRACTOBJECT_H

#include <ca_object.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* Abstract Object Interface, copied from python, (many thanks to Jim Fulton) */

/*
 PROPOSAL: A Generic Cayman Object Interface for Cayman C Modules

 Problem

 Cayman modules written in C that must access Cayman objects must do
 so through routines whose interfaces are described by a set of
 include files.  Unfortunately, these routines vary according to the
 object accessed.  To use these routines, the C programmer must check
 the type of the object being used and must call a routine based on
 the object type.  For example, to access an element of a sequence,
 the programmer must determine whether the sequence is a list or a
 tuple:

 if(is_tupleobject(o))
 e=gettupleitem(o,i)
 else if(is_listitem(o))
 e=getlistitem(o,i)

 If the programmer wants to get an item from another type of object
 that provides sequence behavior, there is no clear way to do it
 correctly.

 The persistent programmer may peruse object.h and find that the
 _typeobject structure provides a means of invoking up to (currently
 about) 41 special operators.  So, for example, a routine can get an
 item from any object that provides sequence behavior. However, to
 use this mechanism, the programmer must make their code dependent on
 the current Cayman implementation.

 Also, certain semantics, especially memory management semantics, may
 differ by the type of object being used.  Unfortunately, these
 semantics are not clearly described in the current include files.
 An abstract interface providing more consistent semantics is needed.

 Proposal

 I propose the creation of a standard interface (with an associated
 library of routines and/or macros) for generically obtaining the
 services of Cayman objects.  This proposal can be viewed as one
 components of a Cayman C interface consisting of several components.

 From the viewpoint of C access to Cayman services, we have (as
 suggested by Guido in off-line discussions):

 - "Very high level layer": two or three functions that let you exec or
 eval arbitrary Cayman code given as a string in a module whose name is
 given, passing C values in and getting C values out using
 mkvalue/getargs style format strings.  This does not require the user
 to declare any variables of type "CaObject *".  This should be enough
 to write a simple application that gets Cayman code from the user,
 execs it, and returns the output or errors.  (Error handling must also
 be part of this API.)

 - "Abstract objects layer": which is the subject of this proposal.
 It has many functions operating on objects, and lest you do many
 things from C that you can also write in Cayman, without going
 through the Cayman parser.

 - "Concrete objects layer": This is the public type-dependent
 interface provided by the standard built-in types, such as floats,
 strings, and lists.  This interface exists and is currently
 documented by the collection of include files provided with the
 Cayman distributions.

 From the point of view of Cayman accessing services provided by C
 modules:

 - "Cayman module interface": this interface consist of the basic
 routines used to define modules and their members.  Most of the
 current extensions-writing guide deals with this interface.

 - "Built-in object interface": this is the interface that a new
 built-in type must provide and the mechanisms and rules that a
 developer of a new built-in type must use and follow.

 This proposal is a "first-cut" that is intended to spur
 discussion. See especially the lists of notes.

 The Cayman C object interface will provide four protocols: object,
 numeric, sequence, and mapping.  Each protocol consists of a
 collection of related operations.  If an operation that is not
 provided by a particular type is invoked, then a standard exception,
 NotImplementedError is raised with a operation name as an argument.
 In addition, for convenience this interface defines a set of
 constructors for building objects of built-in types.  This is needed
 so new objects can be returned from C functions that otherwise treat
 objects generically.

 Memory Management

 For all of the functions described in this proposal, if a function
 retains a reference to a Cayman object passed as an argument, then the
 function will increase the reference count of the object.  It is
 unnecessary for the caller to increase the reference count of an
 argument in anticipation of the object's retention.

 All Cayman objects returned from functions should be treated as new
 objects.  Functions that return objects assume that the caller will
 retain a reference and the reference count of the object has already
 been incremented to account for this fact.  A caller that does not
 retain a reference to an object that is returned from a function
 must decrement the reference count of the object (using
 DECREF(object)) to prevent memory leaks.

 Note that the behavior mentioned here is different from the current
 behavior for some objects (e.g. lists and tuples) when certain
 type-specific routines are called directly (e.g. setlistitem).  The
 proposed abstraction layer will provide a consistent memory
 management interface, correcting for inconsistent behavior for some
 built-in types.

 Protocols

 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/*  Object Protocol: */

/* Implemented elsewhere:

 int CaObject_Print(CaObject *o, FILE *fp, int flags);

 Print an object, o, on file, fp.  Returns -1 on
 error.  The flags argument is used to enable certain printing
 options. The only option currently supported is Ca_Print_RAW.

 (What should be said about Ca_Print_RAW?)

 */

/* Implemented elsewhere:

 int CaObject_HasAttrString(CaObject *o, const char *attr_name);

 Returns 1 if o has the attribute attr_name, and 0 otherwise.
 This is equivalent to the Cayman expression:
 hasattr(o,attr_name).

 This function always succeeds.

 */

/* Implemented elsewhere:

 CaObject* CaObject_GetAttrString(CaObject *o, const char *attr_name);

 Retrieve an attributed named attr_name form object o.
 Returns the attribute value on success, or NULL on failure.
 This is the equivalent of the Cayman expression: o.attr_name.

 */

/* Implemented elsewhere:

 int CaObject_HasAttr(CaObject *o, CaObject *attr_name);

 Returns 1 if o has the attribute attr_name, and 0 otherwise.
 This is equivalent to the Cayman expression:
 hasattr(o,attr_name).

 This function always succeeds.

 */

/* Implemented elsewhere:

 CaObject* CaObject_GetAttr(CaObject *o, CaObject *attr_name);

 Retrieve an attributed named attr_name form object o.
 Returns the attribute value on success, or NULL on failure.
 This is the equivalent of the Cayman expression: o.attr_name.

 */

/* Implemented elsewhere:

 int CaObject_SetAttrString(CaObject *o, const char *attr_name, CaObject *v);

 Set the value of the attribute named attr_name, for object o,
 to the value, v. Returns -1 on failure.  This is
 the equivalent of the Cayman statement: o.attr_name=v.

 */

/* Implemented elsewhere:

 int CaObject_SetAttr(CaObject *o, CaObject *attr_name, CaObject *v);

 Set the value of the attribute named attr_name, for object o,
 to the value, v. Returns -1 on failure.  This is
 the equivalent of the Cayman statement: o.attr_name=v.

 */

/* implemented as a macro:

 int CaObject_DelAttrString(CaObject *o, const char *attr_name);

 Delete attribute named attr_name, for object o. Returns
 -1 on failure.  This is the equivalent of the Cayman
 statement: del o.attr_name.

 */
#define  CaObject_DelAttrString(O,A) CaObject_SetAttrString((O),(A),NULL)

/* implemented as a macro:

 int CaObject_DelAttr(CaObject *o, CaObject *attr_name);

 Delete attribute named attr_name, for object o. Returns -1
 on failure.  This is the equivalent of the Cayman
 statement: del o.attr_name.

 */
#define  CaObject_DelAttr(O,A) CaObject_SetAttr((O),(A),NULL)

/* Implemented elsewhere:

 CaObject *CaObject_Repr(CaObject *o);

 Compute the string representation of object, o.  Returns the
 string representation on success, NULL on failure.  This is
 the equivalent of the Cayman expression: repr(o).

 Called by the repr() built-in function.

 */

/* Implemented elsewhere:

 CaObject *CaObject_Str(CaObject *o);

 Compute the string representation of object, o.  Returns the
 string representation on success, NULL on failure.  This is
 the equivalent of the Cayman expression: str(o).)

 Called by the str() and print() built-in functions.

 */

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
 CaAPI_FUNC(void*) CaCallable_GetFuctionAddress(CaObject *callable,
		 CaTypeObject *retType, CaObject *argTypes);


 /**
  * Same as CaCallable_GetFuctionAddress, except the arguments types are
  * given as variable number of C arguments.  The C arguments are provided
  * as CaTypeObject * values, terminated by a NULL.
  */
 CaAPI_FUNC(void*) CaCallable_GetFuctionAddressObjArgs(CaObject *callable,
 		CaTypeObject *retType, ...);



/**
 * Call a callable Cayman object, callable_object, with
 * arguments and keywords arguments.  The 'args' argument can not be
 * NULL, but the 'kw' argument can be NULL.
 */
CaAPI_FUNC(CaObject *) CaObject_Call(CaObject *callable_object,
		CaObject *args, CaObject *kw);

/**
 * Call a callable Cayman object, callable_object, with
 * arguments given by the tuple, args.  If no arguments are
 * needed, then args may be NULL.  Returns the result of the
 * call on success, or NULL on failure.  This is the equivalent
 * of the Cayman expression: o(*args).
 */
CaAPI_FUNC(CaObject *) CaObject_CallObject(CaObject *callable_object,
		CaObject *args);

/**
 * Call a callable Cayman object, callable_object, with a
 * variable number of C arguments. The C arguments are described
 * using a mkvalue-style format string. The format may be NULL,
 * indicating that no arguments are provided.  Returns the
 * result of the call on success, or NULL on failure.  This is
 * the equivalent of the Cayman expression: o(*args).
 */
CaAPI_FUNC(CaObject *) CaObject_CallFunction(CaObject *callable_object,
		const char *format, ...);

CaAPI_FUNC(CaObject *) CaObject_CallMethod(CaObject *o,
		const char *method,
		const char *format, ...);


/**
 * Call a callable Cayman object, callable, with a
 * variable number of C arguments.  The C arguments are provided
 * as CaObject * values, terminated by a NULL.  Returns the
 * result of the call on success, or NULL on failure.  This is
 * the equivalent of the Cayman expression: o(*args).
 */
CaAPI_FUNC(CaObject *) CaObject_CallFunctionObjArgs(CaObject *callable,
		...);

/**
 * Call the method named m of object o with a variable number of
 * C arguments.  The C arguments are provided as CaObject *
 * values, terminated by NULL.  Returns the result of the call
 * on success, or NULL on failure.  This is the equivalent of
 * the Cayman expression: o.method(args).
 */
CaAPI_FUNC(CaObject *) CaObject_CallMethodObjArgs(CaObject *o,
		CaObject *m, ...);



/* Implemented elsewhere:

 long CaObject_Hash(CaObject *o);

 Compute and return the hash, hash_value, of an object, o.  On
 failure, return -1.  This is the equivalent of the Cayman
 expression: hash(o).
 */

/* Implemented elsewhere:

 int CaObject_IsTrue(CaObject *o);

 Returns 1 if the object, o, is considered to be true, 0 if o is
 considered to be false and -1 on failure. This is equivalent to the
 Cayman expression: not not o
 */

/* Implemented elsewhere:

 int CaObject_Not(CaObject *o);

 Returns 0 if the object, o, is considered to be true, 1 if o is
 considered to be false and -1 on failure. This is equivalent to the
 Cayman expression: not o
 */


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



CaAPI_FUNC(int) CaObject_DelItemString(CaObject *o, const char *key);

/*
 Remove the mapping for object, key, from the object *o.
 Returns -1 on failure.  This is equivalent to
 the Cayman statement: del o[key].
 */

CaAPI_FUNC(int) CaObject_DelItem(CaObject *o, CaObject *key);

/*
 Delete the mapping for key from *o.  Returns -1 on failure.
 This is the equivalent of the Cayman statement: del o[key].
 */

/* old buffer API
 FIXME:  usage of these should all be replaced in Cayman itself
 but for backwards compatibility we will implement them.
 Their usage without a corresponding "unlock" mechansim
 may create issues (but they would already be there). */

CaAPI_FUNC(int) CaObject_AsCharBuffer(CaObject *obj,
		const char **buffer,
		Ca_ssize_t *buffer_len);

/*
 Takes an arbitrary object which must support the (character,
 single segment) buffer interface and returns a pointer to a
 read-only memory location useable as character based input
 for subsequent processing.

 0 is returned on success.  buffer and buffer_len are only
 set in case no error occurs. Otherwise, -1 is returned and
 an exception set.
 */

CaAPI_FUNC(int) CaObject_CheckReadBuffer(CaObject *obj);

/*
 Checks whether an arbitrary object supports the (character,
 single segment) buffer interface.  Returns 1 on success, 0
 on failure.
 */

CaAPI_FUNC(int) CaObject_AsReadBuffer(CaObject *obj,
		const void **buffer,
		Ca_ssize_t *buffer_len);

/*
 Same as CaObject_AsCharBuffer() except that this API expects
 (readable, single segment) buffer interface and returns a
 pointer to a read-only memory location which can contain
 arbitrary data.

 0 is returned on success.  buffer and buffer_len are only
 set in case no error occurs.  Otherwise, -1 is returned and
 an exception set.
 */

CaAPI_FUNC(int) CaObject_AsWriteBuffer(CaObject *obj,
		void **buffer,
		Ca_ssize_t *buffer_len);

/*
 Takes an arbitrary object which must support the (writable,
 single segment) buffer interface and returns a pointer to a
 writable memory location in buffer of size buffer_len.

 0 is returned on success.  buffer and buffer_len are only
 set in case no error occurs. Otherwise, -1 is returned and
 an exception set.
 */

/* new buffer API */

CaAPI_FUNC(CaObject *) CaObject_Format(CaObject* obj,
		CaObject *format_spec);
/*
 Takes an arbitrary object and returns the result of
 calling obj.__format__(format_spec).
 */

/* Iterators */

CaAPI_FUNC(CaObject *) CaObject_GetIter(CaObject *);
/* Takes an object and returns an iterator for it.
 This is typically a new iterator but if the argument
 is an iterator, this returns itself. */

#define CaIter_Check(obj) \
    ((obj)->ob_type->tp_iternext != NULL && \
     (obj)->ob_type->tp_iternext != &_CaObject_NextNotImplemented)

CaAPI_FUNC(CaObject *) CaIter_Next(CaObject *);
/* Takes an iterator object and calls its tp_iternext slot,
 returning the next value.  If the iterator is exhausted,
 this returns NULL without setting an exception.
 NULL with an exception means an error occurred. */

/*  Number Protocol:*/

CaAPI_FUNC(int) CaNumber_Check(CaObject *o);

/*
 Returns 1 if the object, o, provides numeric protocols, and
 false otherwise.

 This function always succeeds.
 */

CaAPI_FUNC(CaObject *) CaNumber_Add(CaObject *o1, CaObject *o2);

/*
 Returns the result of adding o1 and o2, or null on failure.
 This is the equivalent of the Cayman expression: o1+o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Subtract(CaObject *o1, CaObject *o2);

/*
 Returns the result of subtracting o2 from o1, or null on
 failure.  This is the equivalent of the Cayman expression:
 o1-o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Multiply(CaObject *o1, CaObject *o2);

/*
 Returns the result of multiplying o1 and o2, or null on
 failure.  This is the equivalent of the Cayman expression:
 o1*o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_MatrixMultiply(CaObject *o1, CaObject *o2);

/*
 This is the equivalent of the Cayman expression: o1 @ o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_FloorDivide(CaObject *o1, CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving an integral result,
 or null on failure.
 This is the equivalent of the Cayman expression: o1//o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_TrueDivide(CaObject *o1, CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving a float result,
 or null on failure.
 This is the equivalent of the Cayman expression: o1/o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Remainder(CaObject *o1, CaObject *o2);

/*
 Returns the remainder of dividing o1 by o2, or null on
 failure.  This is the equivalent of the Cayman expression:
 o1%o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Divmod(CaObject *o1, CaObject *o2);

/*
 See the built-in function divmod.  Returns NULL on failure.
 This is the equivalent of the Cayman expression:
 divmod(o1,o2).
 */

CaAPI_FUNC(CaObject *) CaNumber_Power(CaObject *o1, CaObject *o2,
		CaObject *o3);

/*
 See the built-in function pow.  Returns NULL on failure.
 This is the equivalent of the Cayman expression:
 pow(o1,o2,o3), where o3 is optional.
 */

CaAPI_FUNC(CaObject *) CaNumber_Negative(CaObject *o);

/*
 Returns the negation of o on success, or null on failure.
 This is the equivalent of the Cayman expression: -o.
 */

CaAPI_FUNC(CaObject *) CaNumber_Positive(CaObject *o);

/*
 Returns the (what?) of o on success, or NULL on failure.
 This is the equivalent of the Cayman expression: +o.
 */

CaAPI_FUNC(CaObject *) CaNumber_Absolute(CaObject *o);

/*
 Returns the absolute value of o, or null on failure.  This is
 the equivalent of the Cayman expression: abs(o).
 */

CaAPI_FUNC(CaObject *) CaNumber_Invert(CaObject *o);

/*
 Returns the bitwise negation of o on success, or NULL on
 failure.  This is the equivalent of the Cayman expression:
 ~o.
 */

CaAPI_FUNC(CaObject *) CaNumber_Lshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of left shifting o1 by o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1 << o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Rshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of right shifting o1 by o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1 >> o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_And(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise and of o1 and o2 on success, or
 NULL on failure. This is the equivalent of the Cayman
 expression: o1&o2.

 */

CaAPI_FUNC(CaObject *) CaNumber_Xor(CaObject *o1, CaObject *o2);

/*
 Returns the bitwise exclusive or of o1 by o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1^o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Or(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise or on o1 and o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1|o2.
 */

#define CaIndex_Check(obj) \
   ((obj)->ob_type->tp_as_number != NULL && \
    (obj)->ob_type->tp_as_number->nb_index != NULL)

CaAPI_FUNC(CaObject *) CaNumber_Index(CaObject *o);

/*
 Returns the object converted to a Cayman int
 or NULL with an error raised on failure.
 */

CaAPI_FUNC(Ca_ssize_t) CaNumber_AsSsize_t(CaObject *o, CaObject *exc);

/*
 Returns the object converted to Ca_ssize_t by going through
 CaNumber_Index first.  If an overflow error occurs while
 converting the int to Ca_ssize_t, then the second argument
 is the error-type to return.  If it is NULL, then the overflow error
 is cleared and the value is clipped.
 */

CaAPI_FUNC(CaObject *) CaNumber_Long(CaObject *o);

/*
 Returns the o converted to an integer object on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: int(o).
 */

CaAPI_FUNC(CaObject *) CaNumber_Float(CaObject *o);

/*
 Returns the o converted to a float object on success, or NULL
 on failure.  This is the equivalent of the Cayman expression:
 float(o).
 */

/*  In-place variants of (some of) the above number protocol functions */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceAdd(CaObject *o1, CaObject *o2);

/*
 Returns the result of adding o2 to o1, possibly in-place, or null
 on failure.  This is the equivalent of the Cayman expression:
 o1 += o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceSubtract(CaObject *o1, CaObject *o2);

/*
 Returns the result of subtracting o2 from o1, possibly in-place or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 -= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceMultiply(CaObject *o1, CaObject *o2);

/*
 Returns the result of multiplying o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 *= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceMatrixMultiply(CaObject *o1, CaObject *o2);

/*
 This is the equivalent of the Cayman expression: o1 @= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceFloorDivide(CaObject *o1,
		CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving an integral result,
 possibly in-place, or null on failure.
 This is the equivalent of the Cayman expression:
 o1 /= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceTrueDivide(CaObject *o1,
		CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving a float result,
 possibly in-place, or null on failure.
 This is the equivalent of the Cayman expression:
 o1 /= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceRemainder(CaObject *o1, CaObject *o2);

/*
 Returns the remainder of dividing o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 %= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlacePower(CaObject *o1, CaObject *o2,
		CaObject *o3);

/*
 Returns the result of raising o1 to the power of o2, possibly
 in-place, or null on failure.  This is the equivalent of the Cayman
 expression: o1 **= o2, or pow(o1, o2, o3) if o3 is present.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceLshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of left shifting o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 <<= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceRshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of right shifting o1 by o2, possibly in-place or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 >>= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceAnd(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise and of o1 and o2, possibly in-place,
 or null on failure. This is the equivalent of the Cayman
 expression: o1 &= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceXor(CaObject *o1, CaObject *o2);

/*
 Returns the bitwise exclusive or of o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 ^= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceOr(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise or of o1 and o2, possibly in-place,
 or null on failure.  This is the equivalent of the Cayman
 expression: o1 |= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_ToBase(CaObject *n, int base);

/*
 Returns the integer n converted to a string with a base, with a base
 marker of 0b, 0o or 0x prefixed if applicable.
 If n is not an int object, it is converted with CaNumber_Index first.
 */

/*  Sequence protocol:*/

CaAPI_FUNC(int) CaSequence_Check(CaObject *o);

/*
 Return 1 if the object provides sequence protocol, and zero
 otherwise.

 This function always succeeds.
 */

CaAPI_FUNC(Ca_ssize_t) CaSequence_Size(CaObject *o);

/*
 Return the size of sequence object o, or -1 on failure.
 */

/* For DLL compatibility */
#undef CaSequence_Length
CaAPI_FUNC(Ca_ssize_t) CaSequence_Length(CaObject *o);
#define CaSequence_Length CaSequence_Size

CaAPI_FUNC(CaObject *) CaSequence_Concat(CaObject *o1, CaObject *o2);

/*
 Return the concatenation of o1 and o2 on success, and NULL on
 failure.   This is the equivalent of the Cayman
 expression: o1+o2.
 */

CaAPI_FUNC(CaObject *) CaSequence_Repeat(CaObject *o, Ca_ssize_t count);

/*
 Return the result of repeating sequence object o count times,
 or NULL on failure.  This is the equivalent of the Cayman
 expression: o1*count.
 */

CaAPI_FUNC(CaObject *) CaSequence_GetItem(CaObject *o, Ca_ssize_t i);

/*
 Return the ith element of o, or NULL on failure. This is the
 equivalent of the Cayman expression: o[i].
 */

CaAPI_FUNC(CaObject *) CaSequence_GetSlice(CaObject *o, Ca_ssize_t i1, Ca_ssize_t i2);

/*
 Return the slice of sequence object o between i1 and i2, or
 NULL on failure. This is the equivalent of the Cayman
 expression: o[i1:i2].
 */

CaAPI_FUNC(int) CaSequence_SetItem(CaObject *o, Ca_ssize_t i, CaObject *v);

/*
 Assign object v to the ith element of o.  Returns
 -1 on failure.  This is the equivalent of the Cayman
 statement: o[i]=v.
 */

CaAPI_FUNC(int) CaSequence_DelItem(CaObject *o, Ca_ssize_t i);

/*
 Delete the ith element of object v.  Returns
 -1 on failure.  This is the equivalent of the Cayman
 statement: del o[i].
 */

CaAPI_FUNC(int) CaSequence_SetSlice(CaObject *o, Ca_ssize_t i1, Ca_ssize_t i2,
		CaObject *v);

/*
 Assign the sequence object, v, to the slice in sequence
 object, o, from i1 to i2.  Returns -1 on failure. This is the
 equivalent of the Cayman statement: o[i1:i2]=v.
 */

CaAPI_FUNC(int) CaSequence_DelSlice(CaObject *o, Ca_ssize_t i1, Ca_ssize_t i2);

/*
 Delete the slice in sequence object, o, from i1 to i2.
 Returns -1 on failure. This is the equivalent of the Cayman
 statement: del o[i1:i2].
 */

CaAPI_FUNC(CaObject *) CaSequence_Tuple(CaObject *o);

/*
 Returns the sequence, o, as a tuple on success, and NULL on failure.
 This is equivalent to the Cayman expression: tuple(o)
 */

CaAPI_FUNC(CaObject *) CaSequence_List(CaObject *o);
/*
 Returns the sequence, o, as a list on success, and NULL on failure.
 This is equivalent to the Cayman expression: list(o)
 */

CaAPI_FUNC(CaObject *) CaSequence_Fast(CaObject *o, const char* m);
/*
 Return the sequence, o, as a list, unless it's already a
 tuple or list.  Use CaSequence_Fast_GET_ITEM to access the
 members of this list, and CaSequence_Fast_GET_SIZE to get its length.

 Returns NULL on failure.  If the object does not support iteration,
 raises a TypeError exception with m as the message text.
 */

#define CaSequence_Fast_GET_SIZE(o) \
    (CaList_Check(o) ? CaList_GET_SIZE(o) : CaTuple_GET_SIZE(o))
/*
 Return the size of o, assuming that o was returned by
 CaSequence_Fast and is not NULL.
 */

#define CaSequence_Fast_GET_ITEM(o, i)\
     (CaList_Check(o) ? CaList_GET_ITEM(o, i) : CaTuple_GET_ITEM(o, i))
/*
 Return the ith element of o, assuming that o was returned by
 CaSequence_Fast, and that i is within bounds.
 */

#define CaSequence_ITEM(o, i)\
    ( Ca_TYPE(o)->tp_as_sequence->sq_item(o, i) )
/* Assume tp_as_sequence and sq_item exist and that i does not
 need to be corrected for a negative index
 */

#define CaSequence_Fast_ITEMS(sf) \
    (CaList_Check(sf) ? ((CaListObject *)(sf))->ob_item \
                      : ((CaTupleObject *)(sf))->ob_item)
/* Return a pointer to the underlying item array for
 an object retured by CaSequence_Fast */

CaAPI_FUNC(Ca_ssize_t) CaSequence_Count(CaObject *o, CaObject *value);

/*
 Return the number of occurrences on value on o, that is,
 return the number of keys for which o[key]==value.  On
 failure, return -1.  This is equivalent to the Cayman
 expression: o.count(value).
 */

CaAPI_FUNC(int) CaSequence_Contains(CaObject *seq, CaObject *ob);
/*
 Return -1 if error; 1 if ob in seq; 0 if ob not in seq.
 Use __contains__ if possible, else _CaSequence_IterSearch().
 */

/* For DLL-level backwards compatibility */
#undef CaSequence_In
CaAPI_FUNC(int) CaSequence_In(CaObject *o, CaObject *value);

/* For source-level backwards compatibility */
#define CaSequence_In CaSequence_Contains

/*
 Determine if o contains value.  If an item in o is equal to
 X, return 1, otherwise return 0.  On error, return -1.  This
 is equivalent to the Cayman expression: value in o.
 */

CaAPI_FUNC(Ca_ssize_t) CaSequence_Index(CaObject *o, CaObject *value);

/*
 Return the first index for which o[i]=value.  On error,
 return -1.    This is equivalent to the Cayman
 expression: o.index(value).
 */

/* In-place versions of some of the above Sequence functions. */

CaAPI_FUNC(CaObject *) CaSequence_InPlaceConcat(CaObject *o1, CaObject *o2);

/*
 Append o2 to o1, in-place when possible. Return the resulting
 object, which could be o1, or NULL on failure.  This is the
 equivalent of the Cayman expression: o1 += o2.

 */

CaAPI_FUNC(CaObject *) CaSequence_InPlaceRepeat(CaObject *o, Ca_ssize_t count);

/*
 Repeat o1 by count, in-place when possible. Return the resulting
 object, which could be o1, or NULL on failure.  This is the
 equivalent of the Cayman expression: o1 *= count.

 */

/*  Mapping protocol:*/

CaAPI_FUNC(int) CaMapping_Check(CaObject *o);

/*
 Return 1 if the object provides mapping protocol, and zero
 otherwise.

 This function always succeeds.
 */

CaAPI_FUNC(Ca_ssize_t) CaMapping_Size(CaObject *o);

/*
 Returns the number of keys in object o on success, and -1 on
 failure.  For objects that do not provide sequence protocol,
 this is equivalent to the Cayman expression: len(o).
 */

/* For DLL compatibility */
#undef CaMapping_Length
CaAPI_FUNC(Ca_ssize_t) CaMapping_Length(CaObject *o);
#define CaMapping_Length CaMapping_Size

/* implemented as a macro:

 int CaMapping_DelItemString(CaObject *o, const char *key);

 Remove the mapping for object, key, from the object *o.
 Returns -1 on failure.  This is equivalent to
 the Cayman statement: del o[key].
 */
#define CaMapping_DelItemString(O,K) CaObject_DelItemString((O),(K))

/* implemented as a macro:

 int CaMapping_DelItem(CaObject *o, CaObject *key);

 Remove the mapping for object, key, from the object *o.
 Returns -1 on failure.  This is equivalent to
 the Cayman statement: del o[key].
 */
#define CaMapping_DelItem(O,K) CaObject_DelItem((O),(K))

CaAPI_FUNC(int) CaMapping_HasKeyString(CaObject *o, const char *key);

/*
 On success, return 1 if the mapping object has the key, key,
 and 0 otherwise.  This is equivalent to the Cayman expression:
 key in o.

 This function always succeeds.
 */

CaAPI_FUNC(int) CaMapping_HasKey(CaObject *o, CaObject *key);

/*
 Return 1 if the mapping object has the key, key,
 and 0 otherwise.  This is equivalent to the Cayman expression:
 key in o.

 This function always succeeds.

 */

CaAPI_FUNC(CaObject *) CaMapping_Keys(CaObject *o);

/*
 On success, return a list or tuple of the keys in object o.
 On failure, return NULL.
 */

CaAPI_FUNC(CaObject *) CaMapping_Values(CaObject *o);

/*
 On success, return a list or tuple of the values in object o.
 On failure, return NULL.
 */

CaAPI_FUNC(CaObject *) CaMapping_Items(CaObject *o);

/*
 On success, return a list or tuple of the items in object o,
 where each item is a tuple containing a key-value pair.
 On failure, return NULL.

 */

CaAPI_FUNC(CaObject *) CaMapping_GetItemString(CaObject *o,
		const char *key);

/*
 Return element of o corresponding to the object, key, or NULL
 on failure. This is the equivalent of the Cayman expression:
 o[key].
 */

CaAPI_FUNC(int) CaMapping_SetItemString(CaObject *o, const char *key,
		CaObject *value);

/*
 Map the object, key, to the value, v.  Returns
 -1 on failure.  This is the equivalent of the Cayman
 statement: o[key]=v.
 */

CaAPI_FUNC(int) CaObject_IsInstance(CaObject *object, CaObject *typeorclass);
/* isinstance(object, typeorclass) */

CaAPI_FUNC(int) CaObject_IsSubclass(CaObject *object, CaObject *typeorclass);
/* issubclass(object, typeorclass) */

#ifdef __cplusplus
}
#endif

#endif /* Ca_ABSTRACTOBJECT_H */
