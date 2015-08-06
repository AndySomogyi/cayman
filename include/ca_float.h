/*
 * ca_string.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDE_CA_FLOAT_H_
#define _INCLUDE_CA_FLOAT_H_

#include <ca_port.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 Floating Point Objects
 CaFloatObject
 This subtype of CaObject represents a Cathon floating point object.

 CaTypeObject CaFloat_Type
 This instance of CaTypeObject represents the Cathon floating point type. This
 is the same object as float and types.FloatType.
 */

/**
 * Return true if its argument is a CaFloatObject or a subtype of CaFloatObject.
 * Allows subtypes to be accepted.
 */
CaAPI_FUNC(int) CaFloat_Check(CaObject *p);

/**
 * Return true if its argument is a CaFloatObject, but not a subtype of
 * CaFloatObject.
 */
CaAPI_FUNC(int) CaFloat_CheckExact(CaObject *p);

/**
 * Return value: New reference.
 * Create a CaFloatObject object based on the string value in str, or NULL on
 * failure.
 */
CaAPI_FUNC(CaObject*) CaFloat_FromString(const char *str);

/**
 * Return value: New reference.
 Create a CaFloatObject object from v, or NULL on failure.

 */
CaAPI_FUNC(CaObject*) CaFloat_FromDouble(double v);

/**
 * Return a C double representation of the contents of Cafloat.
 *
 * If Cafloat is not a Cathon floating point object but has a __float__()
 * method, this method will first be called to convert Cafloat into a float.
 * This method returns -1.0 upon failure, so one should call
 * CaErr_Occurred() to check for errors.
 */
CaAPI_FUNC(double) CaFloat_AsDouble(CaObject *p);

/**
 * Return a structseq instance which contains information about the precision,
 * minimum and maximum values of a float. It’s a thin wrapper around the header
 * file float.h.
 */
CaAPI_FUNC(CaObject*) CaFloat_GetInfo(void);

/**
 * Return the maximum representable finite float DBL_MAX as C double.
 */
CaAPI_FUNC(double) CaFloat_GetMax();

/**
 * Return the minimum normalized positive float DBL_MIN as C double.
 */
CaAPI_FUNC(double) CaFloat_GetMin();

#ifdef __cplusplus
}
#endif

#endif /* _INCLUDE_CA_FLOAT_H_ */
