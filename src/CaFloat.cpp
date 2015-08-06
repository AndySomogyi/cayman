/*
 * CaFloat.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: andy
 */

#include "CaFloat.h"
#include "JITContext.h"

CaFloat::CaFloat() : CaObject(CA_FLOAT), value(0.0f)
{
}

CaFloat::CaFloat(const llvm::APFloat& val) : CaObject(CA_FLOAT), value(val)
{
}

CaFloat::CaFloat(double val) : CaObject(CA_FLOAT), value(val)
{
}

CaFloat* CaFloat::fromString(const char* str)
{
}

double CaFloat::asDouble()
{
}

CaObject* CaFloat::getInfo(void)
{
}

double CaFloat::getMax()
{
}

double CaFloat::getMin()
{
}

static CaFloatType* floatType32 = nullptr;
static CaFloatType* floatType64 = nullptr;

CaFloatType* CaFloatType::fromBitWidth(unsigned numBits)
{
	switch(numBits) {
	case 32: return floatType32;
	case 64: return floatType64;
	}
	return nullptr;
}

int CaFloatType::initialize()
{
	llvm::LLVMContext &ctx = JITContext::Get().getLLVMContext();
	floatType32 = new CaFloatType(ctx, 32);
	floatType64 = new CaFloatType(ctx, 64);
	return 0;
}

int CaFloatType::finalize()
{
	floatType32->decref();
	floatType64->decref();
	return 0;
}

CaFloatType::CaFloatType(llvm::LLVMContext& c, unsigned numBits) : CaPrimitiveType(CA_FLOAT_TYPE)
{
	switch(numBits) {
		case 32: llvmType = llvm::Type::getFloatTy(c); break;
		case 64: llvmType = llvm::Type::getFloatTy(c); break;
		default: assert(0 && "Invalid bits"); break;
	}
}