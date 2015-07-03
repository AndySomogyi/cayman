/*
 * ca_floatobject.h
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#ifndef _INCLUDE_CA_FLOATOBJECT_H_
#define _INCLUDE_CA_FLOATOBJECT_H_

#include "ca_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Check if the object is a float
 */
CaAPI_FUNC(double) CaFloat_Check(CaObject*);

/*
 * Return Python float from C double.
 */
CaAPI_FUNC(CaObject *) CaFloat_FromDouble(double);

/*
 * Extract C double from Python float.
 */
CaAPI_FUNC(double) CaFloat_AsDouble(CaObject *);


#ifdef __cplusplus
}
#endif


#endif /* _INCLUDE_CA_FLOATOBJECT_H_ */
