/*
 * ca_object.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "ca_object.h"



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

}
