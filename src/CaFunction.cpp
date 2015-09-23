/*
 * CaFunction.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: andy
 */

#include <CaFunction.h>
#include "JITContext.h"

static bool isSpecialized(const py::FunctionDef *func)
{
	return false;
}

static py::FunctionDef *specializeFunctionDef(const py::FunctionDef *func, CaType* retType,
		const CaTypeObjectVec& args)
{

	// check if function is already
	return nullptr;
}




void* CaFunction::getFuctionAddress(const CaTypeObjectVec& args,
		CaType* retType)
{
	return nullptr;
}

llvm::Function* CaFunction::getFunctionProto(const CaTypeObjectVec& args,
		CaType* retType)
{
	return nullptr;
}
