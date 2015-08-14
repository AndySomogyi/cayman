/*
 * ca_int.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: andy
 */

#include "cayman.h"
#include "CaInt.h"
#include "cayman_private.h"

extern "C" {

int CaInt_Check(CaObject* o)
{
	return dyn_cast<CaInt>(o) != nullptr;
}

int CaInt_CheckExact(CaObject* o)
{
	return o->type == CA_INT;
}

CaObject* CaInt_FromString(const char* str, char** pend, int base)
{
	return CaInt::fromString(str, pend, base);
}

CaObject* CaInt_FromLong(long ival)
{
	return new CaInt(ival);
}

CaObject* CaInt_FromSize_t(size_t ival)
{
	return CaInt::fromSize_t(ival);
}

long CaInt_AsLong(CaObject* io)
{
    CA_NOTIMPLEMENTED;
}

unsigned long long CaInt_AsUnsignedLongLongMask(CaObject* io)
{
    CA_NOTIMPLEMENTED;
}

size_t CaInt_AsSize_t(CaObject* io)
{
    CA_NOTIMPLEMENTED;
}

long CaInt_GetMax()
{
    CA_NOTIMPLEMENTED;
}

}


