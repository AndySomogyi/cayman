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
	return o->getAttrString(str);
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
	return o->getTypeObject();
}

Ca_ssize_t CaObject_Size(CaObject* o)
{
	return 0;
}

CaAPI_FUNC(uint32_t) Ca_IncRef(CaObject* o)
{
	return o->incref();
}

CaAPI_FUNC(uint32_t) Ca_DecRef(CaObject* o)
{
	return o->decref();
}



CaObject* CaObject_Repr(CaObject* o)
{
	return o->repr();
}

CaObject* CaObject_Str(CaObject* o)
{
	return o->str();
}

}
