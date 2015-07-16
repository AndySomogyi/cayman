/*
 * CaCallable.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include "CaCallable.h"
#include "cayman_llvm.h"
#include "JITContext.h"


void* CaCallable::GetFuctionAddress(CaTypeObject* retType,
		const CaTypeObjectVec& args)
{
	if (pfunc) return pfunc;

	JITContext &ctx = JITContext::Get();


	return nullptr;
}
