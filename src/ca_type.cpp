/*
 * ca_type.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: andy
 */
#include "cayman_private.h"

int CaType_Check(CaObject* o)
{
	return 0;
}

int CaType_CheckExact(CaObject* o)
{
	return 0;
}

unsigned int CaType_ClearCache()
{
	return 0;
}

void CaType_Modified(CaTypeObject* type)
{
}

int CaType_HasFeature(CaObject* o, int feature)
{
	return 0;
}

int CaType_IsSubtype(CaTypeObject* a, CaTypeObject* b)
{
	return 0;
}

CaObject* CaType_GenericAlloc(CaTypeObject* type, Ca_ssize_t nitems)
{
	return NULL;
}

CaObject* CaType_GenericNew(CaTypeObject* type, CaObject* args, CaObject* kwds)
{
	return NULL;
}

CaTypeObject* CaType_FromPrimitive(int primitive, int primitiveModifier)
{
	return NULL;
}



