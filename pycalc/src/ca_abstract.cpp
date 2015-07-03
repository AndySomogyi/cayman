/*
 * ca_abstract.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "ca_abstract.h"


CaObject * CaObject_Call(CaObject* callable_object, CaObject* args, CaObject* kw)
{
	return NULL;
}

CaObject * CaObject_CallObject(CaObject* callable_object, CaObject* args)
{
	return NULL;
}

CaObject * CaObject_CallFunction(CaObject* callable_object, const char* format)
{
	return NULL;
}

CaObject * CaObject_CallMethod(CaObject* o, const char* method, const char* format)
{
	return NULL;
}

CaObject * CaObject_CallFunctionObjArgs(CaObject* callable)
{
	return NULL;
}

CaObject * CaObject_CallMethodObjArgs(CaObject* o, CaObject* method)
{
	return NULL;
}



