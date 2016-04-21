/*
 * ca_object.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "cayman_private.h"
#include <stdarg.h>
#include <iostream>



extern "C" {

void Ca_Dealloc(CaObject*)
{
}



CaObject * CaObject_CallMethod(CaObject* o, const char* method, const char* format, ...)
{
	return NULL;
}

CaObject * CaObject_CallMethodObjArgs(CaObject* o, CaObject* method, ...)
{
	return NULL;
}


CaAPI_FUNC(uint32_t) Ca_IncRef(CaObject* o)
{
	//return o->incref();
}

CaAPI_FUNC(uint32_t) Ca_DecRef(CaObject* o)
{
	//return o->decref();
}



CaObject* CaObject_Repr(CaObject* o)
{
	//return o->repr();
}

CaObject* CaObject_Str(CaObject* o)
{
	//return o->str();
}


long CaObject_HashNotImplemented(CaObject *self)
{
	/*
    PyErr_Format(PyExc_TypeError, "unhashable type: '%.200s'",
                 self->ob_type->tp_name);
                 */
    return -1;
}

//_Py_HashSecret_t _Py_HashSecret;




}


