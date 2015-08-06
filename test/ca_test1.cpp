/*
 * ca_test1.cpp
 *
 *  Created on: Jul 3, 2015
 *      Author: andy
 */

#include "cayman_test.h"
#include <cayman.h>

#include "JITContext.h"


#include <iostream>

using namespace std;

static void usage() {
	cout << "usage: ca_test module_name func_name [arg0 arg1 arg...]" << std::endl;
}


int ca_test1(int argc, const char** argv)
{
    Ca_Initialize();
    
    JITContext &ctx = JITContext::Get();
    
    
    const char* names[] = {
        "test",
        "_test",
        "__test",
        "test.test",
        "_test.test",
        "1test",
        "test test",
        "test%test"
    };
    
    for(int i = 0; i < sizeof(names)/sizeof(char*); ++i) {
        std::cout << names[i] << ", " << ctx.mangle(names[i]) << std::endl;
    }
    
    
	if (argc < 3) {
		usage();
		return -1;
	}







	CaObject *module = CaImport_ImportModule(argv[2]);

	if (module == NULL) {
        
        cout << "error, no module" << std::endl;
        return 0;
	}


	// get the function object
	CaObject *func = CaObject_GetAttrString(module, "test_add");

	// make sure its callable
	if (!func || !CaCallable_Check(func)) return -1;

	// lets say we want to call this for string, int and a double
	// first need to make the type info.
	CaType *dblType = CaType_FromPrimitive(CA_FLOAT32, 0);


	// define the tupe of the function pointer
	typedef double (*FuncPtr)(double, double);

	// get the address of the function pointer
	FuncPtr pfunc = (FuncPtr)CaCallable_GetFuctionAddressObjArgs(func, dblType,
			dblType, dblType, NULL);
    
    if (pfunc == nullptr) {
        cout << "error, function NULL" << std::endl;
        return 0;
    }

	// call the func
	double result = pfunc(1.0, 2.0);

	cout << "test_add(1.0, 2.0) -> " << result << std::endl;

	return 0;
}


int testNumber(const char* str) {

	Ca_Initialize();

	CaObject *val = CaNumber_FromString(str);
    
    
    if(val) {
        std::cout << "parsed OK" << std::endl;
        
        CaObject *str = CaObject_Str(val);
        
        if (str) {
            std::cout << "parsed value: " << CaString_AsString(str) << std::endl;
            Ca_DecRef(str);
        }
        
        Ca_DecRef(val);
    }
    else {
        std::cout << "failed to parse as number" << std::endl;
    }


	Ca_Finalize();
    
    return 0;
}


