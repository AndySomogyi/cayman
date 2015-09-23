/*
 * ca_callable.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: andy
 */


#include <CaType.h>
#include "CaCallable.h"
#include "cayman_private.h"
#include <stdarg.h>
#include <iostream>




/// PUBLIC API SECTION
extern "C" {

int CaCallable_Check(CaObject* obj)
{
	return dyn_cast<CaCallable>(obj) != nullptr;
}

void* CaCallable_GetFuctionAddress(CaCallable* callable, CaType* retType,
		CaObject* argTypes)
{
	return 0;
}

void* CaCallable_GetFuctionAddressObjArgs(CaCallable* obj,
		CaType* retType, ...)
{
	va_list ap;
    

	CaType *type;

	CaTypeObjectVec args;

	CaCallable *callable = dyn_cast<CaCallable>(obj);

	if (!callable) {
		return nullptr;
	}

    va_start(ap, retType);
    int arg = 0;

	while ((type = va_arg(ap, CaType*)) != nullptr)
	{
        std::cout << "arg:" << arg++ << ", type: " << type->typeId << std::endl;
		args.push_back(type);
	}
    
    va_end(ap);

	return callable->GetFuctionAddress(retType, args);
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


