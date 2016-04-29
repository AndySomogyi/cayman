/*
 * ca_module.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: andy
 */
#include "cayman_private.h"
#include "CaModule.h"


extern "C" {

CaModule* CaModule_New(const char* name)
{
}

int CaModule_Check(CaObject* p) {
}

int CaModule_CheckExact(CaObject* p) {
}

CaAPI_FUNC(CaObject*)* CaModule_GetDict(CaModule* module)
{
}

const char* CaModule_GetName(CaModule* module) {
}

const char* CaModule_GetFilename(CaModule* module) {
}

int CaModule_AddObject(CaModule* module, const char* name, CaObject* value) {
}

CaModule* CaModule_CreateSubModule(CaModule* m, const char* name, PyMethodDef* methods,
		const char* doc, CaModule* passthrough, int module_api_version)
{
    PyObject  *d = PyModule_GetDict(m);
    const char* parentName = PyModule_GetName(m);
    CaModule *newModule = (CaModule*)PyDict_GetItemString(d, name);
    if (newModule == NULL) {
        newModule = PyModule_New((std::string(parentName) + + "." + std::string(name)).c_str());
        if (newModule != NULL) {
            // TODO error
        }
    }
}

} // extern "C"
