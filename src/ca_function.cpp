/*
 * ca_function.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: andy
 */
#include "cayman.h"
#include "cayman_private.h"


/// PUBLIC API SECTION
extern "C" {

int CaFunction_Check(CaObject* o)
{
	return 0;
}

CaObject* CaFunction_New(CaObject* code, CaObject* globals)
{
	return 0;
}

CaObject* CaFunction_NewWithQualName(CaObject* code, CaObject* globals, CaObject* qualname)
{
	return 0;
}

CaObject* CaFunction_GetCode(CaObject* op)
{
	return 0;
}

CaObject* CaFunction_GetGlobals(CaObject* op)
{
	return 0;
}

CaObject* CaFunction_GetModule(CaObject* op)
{
	return 0;
}

CaObject* CaFunction_GetDefaults(CaObject* op)
{
	return 0;
}

int CaFunction_SetDefaults(CaObject* op, CaObject* defaults)
{
	return 0;
}

CaObject* CaFunction_GetClosure(CaObject* op)
{
	return 0;
}

int CaFunction_SetClosure(CaObject* op, CaObject* closure)
{
	return 0;
}

CaObject* CaFunction_GetAnnotations(CaObject* op)
{
	return 0;
}

int CaFunction_SetAnnotations(CaObject* op, CaObject* annotations)
{
	return 0;
}

}
