/*
 * ca_module.h
 *
 *  Created on: Jul 6, 2015
 *      Author: andy
 *
 * module functions, definitions and documentation copied from official
 * python website for python compatiblity.
 */

#ifndef _INCLUDED_CA_MODULE_H_
#define _INCLUDED_CA_MODULE_H_

#include "ca_object.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * This instance of CaTypeObject represents the Cayman module type. 
 */
CaAPI_DATA(CaType*) CaModule_Type;

/**
 * Return true if p is a module object, or a subtype of a module object.
 */
CaAPI_FUNC(int) CaModule_Check(CaObject *p);

/**
 * Return true if p is a module object, but not a subtype of CaModule_Type.
 */
CaAPI_FUNC(int) CaModule_CheckExact(CaObject *p);

/**
 * Return value: New reference.
 * Return a new module object with the __name__ attribute set to name.
 * Only the module’s __doc__ and __name__ attributes are filled in;
 * the caller is responsible for providing a __file__ attribute.
 */
CaAPI_FUNC(CaObject*) CaModule_New(const char *name);

/**
 * Return value: Borrowed reference.
 * Return the dictionary object that implements module‘s namespace;
 * this object is the same as the __dict__ attribute of the module object.
 * This function never fails. It is recommended extensions use other CaModule_*()
 * and CaObject_*() functions rather than directly manipulate a module’s __dict__.
 */
CaAPI_FUNC(CaObject*) CaModule_GetDict(CaObject *module);

/**
 * Return module‘s __name__ value. If the module does not provide one,
 * or if it is not a string, SystemError is raised and NULL is returned.
 */
CaAPI_FUNC(const char*) CaModule_GetName(CaObject *module);

/**
 * Return the name of the file from which module was loaded using module‘s __file__
 * attribute. If this is not defined, or if it is not a string, raise SystemError
 * and return NULL.
 */
CaAPI_FUNC(const char*) CaModule_GetFilename(CaObject *module);

/**
 * Add an object to module as name. This is a convenience function which can be used
 * from the module’s initialization function. This steals a reference to value.
 * Return -1 on error, 0 on success.
 */
CaAPI_FUNC(int) CaModule_AddObject(CaObject *module, const char *name, CaObject *value);

#ifdef __cplusplus
}
#endif

#endif /* PYCALC_INCLUDE_CA_MODULE_H_ */
