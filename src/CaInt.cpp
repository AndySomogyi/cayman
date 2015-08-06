/*
 * CaInt.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: andy
 */

#include "CaInt.h"
#include "LiteralSupport.h"
#include "JITContext.h"
#include <llvm/ADT/APSInt.h>
#include <iostream>

CaInt::CaInt() : CaObject(CA_INT_TYPE)
{
	setTypeObject(CaIntType::fromBitWidth(value.getBitWidth()));
}

CaInt::CaInt(const llvm::APInt& val) : CaObject(CA_INT_TYPE), value(val)
{
	setTypeObject(CaIntType::fromBitWidth(value.getBitWidth()));
}

CaInt::CaInt(long val) : CaObject(CA_INT_TYPE)
{
	setTypeObject(CaIntType::fromBitWidth(value.getBitWidth()));
}

CaInt* CaInt::fromString(const char* str, char** pend, int base)
{
	clang::NumericLiteralParser parser(str);

	if(parser.isIntegerLiteral()) {
		
        if (parser.hasUDSuffix()) {
         
            std::cout << "suffix: " << parser.getUDSuffix().str() << std::endl;
        } else {
            std::cout << "suffix: " << "" << std::endl;
        }
        
        std::cout << "signed: " << std::boolalpha << !parser.isUnsigned << std::endl;

		unsigned bits = parser.isLong ? 64 : (parser.isLongLong ? 128 : 32);
        
        std::cout << "bits: " << bits << std::endl;

		llvm::APSInt val(bits, 0);

		parser.GetIntegerValue(val);
		return new CaInt(val);
	}
	return nullptr;
}

CaInt* CaInt::fromSize_t(size_t ival)
{
	return new CaInt(ival);
}

long CaInt::asLong()
{
	return value.getZExtValue();
}

unsigned long long CaInt::asUnsignedLongLongMask()
{
	return 0;
}

size_t CaInt::asSize_t()
{
	return value.getZExtValue();
}

long CaInt::getMax()
{
	return 0;
}

static CaIntType *intType8 = nullptr;
static CaIntType *intType16 = nullptr;
static CaIntType *intType32 = nullptr;
static CaIntType *intType64 = nullptr;
static CaIntType *intType128 = nullptr;

CaIntType* CaIntType::fromBitWidth(unsigned numBits)
{
	switch (numBits) {
	case 8: return intType8;
	case 16: return intType16;
	case 32: return intType32;
	case 64: return intType64;
	case 128: return intType128;
	default: assert(0 && "invalid bits"); break;
	}
	return nullptr;
}

int CaIntType::initialize()
{
	llvm::LLVMContext &ctx = JITContext::Get().getLLVMContext();
	intType8 = new CaIntType(ctx, 8);
	intType16 = new CaIntType(ctx, 16);
	intType32 = new CaIntType(ctx, 32);
	intType64 = new CaIntType(ctx, 64);
	intType128 = new CaIntType(ctx, 128);
	return 0;
}

int CaIntType::finalize()
{
	intType8->decref();
	intType16->decref();
	intType32->decref();
	intType64->decref();
	intType128->decref();
	return 0;
}

CaIntType::CaIntType(llvm::LLVMContext& c, unsigned numBits) : CaPrimitiveType(CA_INT_TYPE)
{
	switch (numBits) {
		case 8: llvmType = llvm::Type::getInt8Ty(c); break;
		case 16: llvmType = llvm::Type::getInt16Ty(c); break;
		case 32: llvmType = llvm::Type::getInt32Ty(c); break;
		case 64: llvmType = llvm::Type::getInt64Ty(c); break;
		case 128: llvmType = llvm::Type::getInt128Ty(c); break;
		default: assert(0 && "invalid bits"); break;
	}
}
