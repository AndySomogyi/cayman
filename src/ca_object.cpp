/*
 * ca_object.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "cayman_private.h"
#include "CaTypeObject.h"
#include <stdarg.h>
#include <iostream>



extern "C" {



void Ca_Dealloc(CaObject*)
{
}

CaObject * CaObject_GetAttrString(CaObject* o, const char* str)
{
	return o->GetAttrString(str);
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
	return 0;
}

Ca_ssize_t CaObject_Size(CaObject* o)
{
	return 0;
}

CaAPI_FUNC(uint32_t) Ca_IncRef(CaObject* o)
{
	return 0;
}

CaAPI_FUNC(uint32_t) Ca_DecRef(CaObject* o)
{
	return 0;
}

}


