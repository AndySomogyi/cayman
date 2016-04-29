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

typedef PyObject CaModule;

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
CaAPI_FUNC(CaModule*) CaModule_New(const char *name);

/**
 * Return value: Borrowed reference.
 * Return the dictionary object that implements module‘s namespace;
 * this object is the same as the __dict__ attribute of the module object.
 * This function never fails. It is recommended extensions use other CaModule_*()
 * and CaObject_*() functions rather than directly manipulate a module’s __dict__.
 */
CaAPI_FUNC(CaObject*) CaModule_GetDict(CaModule *module);

/**
 * Return module‘s __name__ value. If the module does not provide one,
 * or if it is not a string, SystemError is raised and NULL is returned.
 */
CaAPI_FUNC(const char*) CaModule_GetName(CaModule *module);

/**
 * Return the name of the file from which module was loaded using module‘s __file__
 * attribute. If this is not defined, or if it is not a string, raise SystemError
 * and return NULL.
 */
CaAPI_FUNC(const char*) CaModule_GetFilename(CaModule *module);

/**
 * Add an object to module as name. This is a convenience function which can be used
 * from the module’s initialization function. This steals a reference to value.
 * Return -1 on error, 0 on success.
 */
CaAPI_FUNC(int) CaModule_AddObject(CaModule *module, const char *name, CaObject *value);



/**
 * Create and initialize a new module in as a sub-module of an existing module.
 *
 * @param(module) the parent module
 * @param(name) the module name of the new module to create
 * @param(methods) is the list of top-level functions
 * @param(doc) is the documentation string
 * @param(passthrough) is passed as self to functions defined in the module,
 * usually null
 * @param(api_version) is the value of PYTHON_API_VERSION at the time the
     module was compiled

   Return value is a borrowed reference to the module object; or NULL
   if an error occurred (in Python 1.4 and before, errors were fatal).
   Errors may still leak memory.
*/
CaAPI_FUNC(CaModule*) CaModule_CreateSubModule(CaModule *module, const char *name,
		PyMethodDef *methods, const char *doc,
               CaModule *passthrough, int module_api_version);

#ifdef __cplusplus
}
#endif

#endif /* PYCALC_INCLUDE_CA_MODULE_H_ */
