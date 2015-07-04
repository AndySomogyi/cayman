/*
 * ca_test1.cpp
 *
 *  Created on: Jul 3, 2015
 *      Author: andy
 */

#include <cayman.h>



int ca_test1(int argc, const char** argv)
{
	CaObject *module;

	// get the function object
	CaObject *func = CaObject_GetAttrString(module, "SomeFunctionName");

	// make sure its callable
	if (!func || !CaCallable_Check(func)) return -1;

	// lets say we want to call this for string, int and a double
	// first need to make the type info.
	CaTypeObject *strType = CaType_FromPrimitive(CA_STRING, 0);
	CaTypeObject *intType = CaType_FromPrimitive(CA_INT32, 0);
	CaTypeObject *dblType = CaType_FromPrimitive(CA_DOUBLE, 0);
	CaTypeObject *voidType = CaType_FromPrimitive(CA_VOID, 0);

	// define the tupe of the function pointer
	typedef void (*FuncPtr)(const char*, int, double);

	// get the address of the function pointer
	FuncPtr pfunc = (FuncPtr)CaCallable_GetFuctionAddressObjArgs(func, voidType,
			strType, intType, dblType, NULL);

	// call the func
	pfunc("hello", 1, 1.123);

	return 0;
}


