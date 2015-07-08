/*
 * run.cc
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */


#include <cayman.h>
#include <stdlib.h>

int ca_run(int argc, char *argv[])
{
    CaObject *pName, *pModule, *pDict, *pFunc;
    CaObject *pArgs, *pValue;
    int i;

    if (argc < 3) {
        fprintf(stderr,"Usage: call cayman file funcname [args]\n");
        return 1;
    }


    Ca_Initialize();
    pName = CaString_FromString(argv[1]);
    /* Error checking of pName left out */

    pModule = CaImport_Import(pName);
    Ca_DECREF(pName);

    if (pModule != NULL) {
        pFunc = CaObject_GetAttrString(pModule, argv[2]);
        /* pFunc is a new reference */

        if (pFunc && CaCallable_Check(pFunc)) {
            pArgs = CaTuple_New(argc - 3);
            for (i = 0; i < argc - 3; ++i) {
                pValue = CaLong_FromLong(atoi(argv[i + 3]));
                if (!pValue) {
                    Ca_DECREF(pArgs);
                    Ca_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return 1;
                }
                /* pValue reference stolen here: */
                CaTuple_SetItem(pArgs, i, pValue);
            }
            pValue = CaObject_CallObject(pFunc, pArgs);
            Ca_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %ld\n", CaLong_AsLong(pValue));
                Ca_DECREF(pValue);
            }
            else {
                Ca_DECREF(pFunc);
                Ca_DECREF(pModule);
                CaErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (CaErr_Occurred())
                CaErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
        }
        Ca_XDECREF(pFunc);
        Ca_DECREF(pModule);
    }
    else {
        CaErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    Ca_Finalize();
    return 0;
}

