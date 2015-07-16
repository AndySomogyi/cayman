/*
 * ca_callable.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: andy
 */


#include "CaCallable.h"
#include "cayman_private.h"
#include "CaTypeObject.h"
#include <stdarg.h>
#include <iostream>




/// PUBLIC API SECTION
extern "C" {

int CaCallable_Check(CaObject* obj)
{
	return dyn_cast<CaCallable>(obj) != nullptr;
}

void* CaCallable_GetFuctionAddress(CaObject* callable, CaTypeObject* retType,
		CaObject* argTypes)
{
	return 0;
}

void* CaCallable_GetFuctionAddressObjArgs(CaObject* obj,
		CaTypeObject* retType, ...)
{
	va_list ap;

	CaTypeObject *type;

	CaTypeObjectVec args;

	CaCallable *callable = dyn_cast<CaCallable>(obj);

	if (!callable) {
		return nullptr;
	}


	for (type = va_arg(ap, CaTypeObject*); type != nullptr;
			type = va_arg(ap, CaTypeObject*))
	{
		args.push_back(type);
		std::cout << type->type << std::endl;
	}

	return callable->GetFuctionAddress(retType, args);
}


CaObject * CaCallable_Call(CaObject* callable_object, CaObject* args, CaObject* kw)
{
	return NULL;
}

CaObject * CaCallable_CallObject(CaObject* callable_object, CaObject* args)
{
	return NULL;
}

CaObject * CaCallable_CallFunction(CaObject* callable_object, const char* format, ...)
{
	return NULL;
}

CaObject * CaCallable_CallFunctionObjArgs(CaObject* callable, ...)
{
	return NULL;
}



}


