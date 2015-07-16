/*
 * ca_test1.cpp
 *
 *  Created on: Jul 3, 2015
 *      Author: andy
 */

#include "cayman_test.h"
#include <cayman.h>


#include <iostream>

using namespace std;

static void usage() {
	cout << "usage: ca_test module_name func_name [arg0 arg1 arg...]" << std::endl;
}


int ca_test1(int argc, const char** argv)
{
	if (argc < 3) {
		usage();
		return -1;
	}

    Ca_Initialize();


	CaObject *module = CaImport_ImportModule(argv[2]);

	if (module == NULL) {

	}


	// get the function object
	CaObject *func = CaObject_GetAttrString(module, "test_add");

	// make sure its callable
	if (!func || !CaCallable_Check(func)) return -1;

	// lets say we want to call this for string, int and a double
	// first need to make the type info.
	CaTypeObject *dblType = CaType_FromPrimitive(CA_DOUBLE, 0);


	// define the tupe of the function pointer
	typedef double (*FuncPtr)(double, double);

	// get the address of the function pointer
	FuncPtr pfunc = (FuncPtr)CaCallable_GetFuctionAddressObjArgs(func, dblType,
			dblType, NULL);

	// call the func
	double result = pfunc(1.0, 2.0);

	cout << "test_add(1.0, 2.0) -> " << result << std::endl;

	return 0;
}


