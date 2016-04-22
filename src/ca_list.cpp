/*
 * ca_list.cpp
 *
 *  Created on: Apr 22, 2016
 *      Author: andy
 */

#include "ca_list.h"

extern "C" {

CaList* CaList_New(Ca_ssize_t sze)
{
	return (CaList*)PyList_New((Ca_ssize_t)sze);
}

Ca_ssize_t CaList_Size(CaList* list)
{
	return PyList_Size((PyObject*) list);
}

CaObject * CaList_GetItem(CaList* lst, Ca_ssize_t size)
{
	return (CaList*)PyList_GetItem((PyObject*)lst, size);
}

int CaList_SetItem(CaList* list, Ca_ssize_t index, CaObject* value)
{
	return PyList_SetItem((PyObject*)list, index, (PyObject*)value);
}

int CaList_Insert(CaList*, Ca_ssize_t unsignedLongInt, CaObject*)
{
}

int CaList_Append(CaList*, CaObject*)
{
}

CaObject * CaList_GetSlice(CaList*, Ca_ssize_t unsignedLongInt, Ca_ssize_t unsignedLongInt1)
{
}

int CaList_SetSlice(CaList*, Ca_ssize_t unsignedLongInt,
		Ca_ssize_t unsignedLongInt1, CaObject*) {
}

int CaList_Sort(CaList*)
{
}

int CaList_Reverse(CaList*)
{
}

CaObject * CaList_AsTuple(CaList*)
{
}

CaObject * _CaList_Extend(CaList*, CaObject*)
{
}

int CaList_ClearFreeList(void)
{
}

void _CaList_DebugMallocStats(FILE* out)
{
}

}
