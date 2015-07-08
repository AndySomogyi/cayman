/*
 * ca_object.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "cayman_private.h"



extern "C" {

int CaCallable_Check(CaObject*)
{
	return 0;
}

void Ca_Dealloc(CaObject*)
{
}

CaObject * CaObject_GetAttrString(CaObject*, const char*)
{
	return NULL;
}

CaObject * CaObject_Call(CaObject* callable_object, CaObject* args, CaObject* kw)
{
	return NULL;
}

CaObject * CaObject_CallObject(CaObject* callable_object, CaObject* args)
{
	return NULL;
}

CaObject * CaObject_CallFunction(CaObject* callable_object, const char* format, ...)
{
	return NULL;
}

CaObject * CaObject_CallMethod(CaObject* o, const char* method, const char* format, ...)
{
	return NULL;
}

CaObject * CaObject_CallFunctionObjArgs(CaObject* callable, ...)
{
	return NULL;
}

CaObject * CaObject_CallMethodObjArgs(CaObject* o, CaObject* method, ...)
{
	return NULL;
}

void* CaCallable_GetFuctionAddress(CaObject* callable, CaTypeObject* retType,
		CaObject* argTypes)
{
	return 0;
}

void* CaCallable_GetFuctionAddressObjArgs(CaObject* callable,
		CaTypeObject* retType, ...)
{
	return 0;
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


