/*
 * ca_object.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include <CaType.h>
#include "cayman_private.h"
#include <stdarg.h>
#include <iostream>



extern "C" {

void Ca_Dealloc(CaObject*)
{
}

CaObject * CaObject_GetAttrString(CaObject* o, const char* str)
{
	CaGetAttrFn func = o->type->tp_getattr;
	return func ? (CaObject*)func(o, const_cast<char*>(str)) : nullptr;
}

CaObject * CaObject_CallMethod(CaObject* o, const char* method, const char* format, ...)
{
	return NULL;
}

CaObject * CaObject_CallMethodObjArgs(CaObject* o, CaObject* method, ...)
{
	return NULL;
}

CaObject* CaObject_Type(CaObject* o)
{
	return o->type;
}

Ca_ssize_t CaObject_Size(CaObject* o)
{
	return o->type->tp_basicsize;
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



long CaObject_Hash(CaObject* o)
{
	CaTypeObject *tp = o->type;

    if (tp->tp_hash != NULL)
    {
        return tp->tp_hash(o);
    }



    /*
    if (tp->tp_compare == NULL && RICHCOMPARE(tp) == NULL) {
        return _Py_HashPointer(v); // Use address as hash value
    }
    */

    //If there's a cmp but no hash defined, the object can't be hashed
    return CaObject_HashNotImplemented(o);
}

}


