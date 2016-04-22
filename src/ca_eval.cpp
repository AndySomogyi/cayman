/*
 * ca_eval.cpp
 *
 *  Created on: Aug 4, 2015
 *      Author: andy
 */

#include "cayman_private.h"

//static CaModule *builtins = nullptr;
//static CaModule *globals = nullptr;


/**
 * Initialize the runtime eval modules (builtins, globals)
 */
int initEval()
{
	//assert(builtins == nullptr);

	//builtins = new CaModule("__builtins__");






	return 0;

}

/**
 * Shutdown the eval modules
 */
int finalizeEval()
{
	return 0;
}


/// public API

extern "C" {


CaObject* CaEval_GetBuiltins()
{
	//return builtins;
}

CaObject* CaEval_GetLocals()
{
	//return nullptr;
}

CaObject* CaEval_GetGlobals()
{
	//return globals;
}

const char* CaEval_GetFuncName(CaObject* func)
{
	//return nullptr;
}

const char* CaEval_GetFuncDesc(CaObject* func)
{
	return nullptr;
}

}




