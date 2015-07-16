/*
 * ca_type.h
 *
 *  Created on: Jul 3, 2015
 *      Author: andy
 */

#ifndef PYCALC_INCLUDE_CA_TYPE_H_
#define PYCALC_INCLUDE_CA_TYPE_H_

#include "ca_port.h"
#include "ca_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Return true if the object o is a type object, including instances of types
 * derived from the standard type object. Return false in all other cases.
 */
CaAPI_DATA(int) CaType_Check(CaObject *o);

/**
 Return true if the object o is a type object, but not a subtype
 of the standard type object. Return false in all other cases.
 */
CaAPI_DATA(int) CaType_CheckExact(CaObject *o);

/**
 Clear the internal lookup cache. Return the current version tag.
 */
CaAPI_DATA(unsigned int) CaType_ClearCache();

/**
 Invalidate the internal lookup cache for the type and all of its subtypes.
 This function must be called after any manual modification of the attributes or base classes of the type.
 */
CaAPI_DATA(void) CaType_Modified(CaTypeObject *type);

/**
 * Return true if the type object o sets the feature feature.
 * Type features are denoted by single bit flags.
 */
CaAPI_DATA(int) CaType_HasFeature(CaObject *o, int feature);

/**
 * Return true if a is a subtype of b.
 *
 * This function only checks for actual subtypes, which means that
 * __subclasscheck__() is not called on b. Call CaObject_IsSubclass()
 * to do the same check that issubclass() would do.
 */
CaAPI_DATA(int) CaType_IsSubtype(CaTypeObject *a, CaTypeObject *b);

/**
 * Return value: New reference.
 */
CaAPI_DATA(CaObject*) CaType_GenericAlloc(CaTypeObject *type, Ca_ssize_t nitems);

/**
 * Return value: New reference.
 */
CaAPI_DATA(CaObject*) CaType_GenericNew(CaTypeObject *type, CaObject *args,
		CaObject *kwds);


typedef enum {CA_VOID, CA_INT8, CA_INT16, CA_INT32, CA_INT64, CA_INT128, CA_FLOAT,
	CA_DOUBLE, CA_STRING} CaPrimitive;

typedef enum {CA_POINTER = 1, CA_ARRAY = 1 << 1} Ca_PrimitiveModifier;


CaAPI_DATA(CaTypeObject*) CaType_FromPrimitive(uint32_t primitive,
		uint32_t primitiveModifier);

#ifdef __cplusplus
}
#endif

#endif /* PYCALC_INCLUDE_CA_TYPE_H_ */
