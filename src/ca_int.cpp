/*
 * ca_int.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: andy
 */

#include "cayman.h"
#include "cayman_private.h"

extern "C" {

CaObject* CaInt_FromLong(long ival)
{
	return NULL;
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


