/*
 * ca_number.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: andy
 */

#include "cayman.h"
#include "cayman_private.h"
#include "LiteralSupport.h"
#include "cayman_llvm.h"
#include <llvm/ADT/APSInt.h>
#include <iostream>


// public API:

extern "C" {

int CaNumber_Check(CaObject* o)
{
	return 0;
}

CaObject *CaNumber_Add(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Subtract(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Multiply(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_MatrixMultiply(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_FloorDivide(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_TrueDivide(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Remainder(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Divmod(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Power(CaObject* o1, CaObject* o2, CaObject* o3)
{
	return nullptr;
}

CaObject *CaNumber_Negative(CaObject* o)
{
	return nullptr;
}

CaObject *CaNumber_Positive(CaObject* o)
{
	return nullptr;
}

CaObject *CaNumber_Absolute(CaObject* o)
{
	return nullptr;
}

CaObject *CaNumber_Invert(CaObject* o)
{
	return nullptr;
}

CaObject *CaNumber_Lshift(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Rshift(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_And(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Xor(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Or(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_Index(CaObject* o)
{
	return nullptr;
}

Ca_ssize_t CaNumber_AsSsize_t(CaObject* o, CaObject* exc)
{
	return 0;
}

CaObject *CaNumber_Long(CaObject* o)
{
	return nullptr;
}

CaObject *CaNumber_Float(CaObject* o)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceAdd(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceSubtract(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceMultiply(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceMatrixMultiply(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceFloorDivide(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceTrueDivide(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceRemainder(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlacePower(CaObject* o1, CaObject* o2, CaObject* o3)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceLshift(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceRshift(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceAnd(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceXor(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_InPlaceOr(CaObject* o1, CaObject* o2)
{
	return nullptr;
}

CaObject *CaNumber_ToBase(CaObject* n, int base)
{
	return nullptr;
}

CaObject *CaNumber_FromString(const char* str)
{
	clang::NumericLiteralParser parser(str);

	if(!parser.hadError && parser.isIntegerLiteral())
	{
		std::cout << "is integer literal" << std::endl;

        if (parser.hasUDSuffix())
        {
            std::cout << "suffix: " << parser.getUDSuffix().str() << std::endl;
        } else
        {
            std::cout << "suffix: " << "" << std::endl;
        }

        std::cout << "signed: " << std::boolalpha << !parser.isUnsigned << std::endl;

		unsigned bits = parser.isLong ? 64 : (parser.isLongLong ? 128 : 32);

        std::cout << "bits: " << bits << std::endl;

		llvm::APSInt val(bits, 0);

        // checks for overflow
		if (!parser.GetIntegerValue(val))
		{
			return new CaInt(val);
		}
		std::cout << "GetIntegerValue failed, overflow" << std::endl;
	}

	else if(!parser.hadError && parser.isFloatingLiteral())
	{
		std::cout << "is float literal" << std::endl;

        if (parser.hasUDSuffix())
        {
            std::cout << "suffix: " << parser.getUDSuffix().str() << std::endl;
        } else
        {
            std::cout << "suffix: " << "" << std::endl;
        }

		llvm::APFloat val(0.0f);
        


        llvm::APFloat::opStatus stat = parser.GetFloatValue(val);
        
        switch (stat) {
            case llvm::APFloat::opOK:
                std::cout << "opOK" << std::endl;
            case llvm::APFloat::opInvalidOp:
                std::cout << "opInvalidOp" << std::endl;
                break;
            case llvm::APFloat::opDivByZero:
                std::cout << "opDivByZero" << std::endl;
                break;
            case llvm::APFloat::opOverflow:
                std::cout << "opOverflow" << std::endl;
                break;
            case llvm::APFloat::opUnderflow:
                std::cout << "opUnderflow" << std::endl;
                break;
            case llvm::APFloat::opInexact:
                std::cout << "opInexact" << std::endl;
                break;
        }
        
        return new CaFloat(val);
	}

	return nullptr;
}

}





