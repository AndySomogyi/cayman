/*
 * CaCallable.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include "CaCallable.h"
#include "cayman_llvm.h"
#include "JITContext.h"


void* CaCallable::GetFuctionAddress(CaType* retType,
		const CaTypeObjectVec& args)
{
	if (pfunc) return pfunc;

	JITContext &ctx = JITContext::Get();

	// Get the address of the JIT'd function in memory.
	auto symbol = ctx.findSymbol(func->name);

	// this may not exist yet
	if (!symbol)
	{

	}

	// Cast it to the right type (takes no arguments, returns a double) so we
	// can call it as a native function.
	pfunc = (void*)symbol.getAddress();


	return pfunc;
}
