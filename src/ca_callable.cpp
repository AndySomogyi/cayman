/*
 * ca_callable.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: andy
 */


#include "CaCallable.h"
#include "cayman_private.h"
#include <stdarg.h>
#include <iostream>




/// PUBLIC API SECTION
extern "C" {


int CaCallable_Check(CaObject *)
{
	return 0;
}

CaObject * CaCallable_Call(CaCallable* callable_object, CaObject* args, CaObject* kw)
{
	return NULL;
}

CaObject * CaCallable_CallObject(CaCallable* callable_object, CaObject* args)
{
	return NULL;
}

CaObject * CaCallable_CallFunction(CaCallable* callable_object, const char* format, ...)
{
	return NULL;
}

CaObject * CaCallable_CallFunctionObjArgs(CaCallable* callable, ...)
{
	return NULL;
}



}


