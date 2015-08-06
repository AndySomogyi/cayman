/*
 * ca_type.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: andy
 */
#include "cayman.h"
#include "CaType.h"
#include "CaInt.h"
#include "CaFloat.h"


int CaType_Check(CaObject* o)
{
	return 0;
}

int CaType_CheckExact(CaObject* o)
{
	return 0;
}

unsigned int CaType_ClearCache()
{
	return 0;
}

void CaType_Modified(CaType* type)
{
}

int CaType_HasFeature(CaObject* o, int feature)
{
	return 0;
}

int CaType_IsSubtype(CaType* a, CaType* b)
{
	return 0;
}

CaObject* CaType_GenericAlloc(CaType* type, size_t nitems)
{
	return NULL;
}

CaObject* CaType_GenericNew(CaType* type, CaObject* args, CaObject* kwds)
{
	return NULL;
}

CaType* CaType_FromPrimitive(uint32_t primitive, uint32_t primitiveModifier)
{
	switch (primitive)
	{
	case CA_INT8:
		return CaIntType::fromBitWidth(8);
	case CA_INT16:
		return CaIntType::fromBitWidth(16);
	case CA_INT32:
		return CaIntType::fromBitWidth(32);
	case CA_INT64:
		return CaIntType::fromBitWidth(64);
	case CA_INT128:
		return CaIntType::fromBitWidth(128);
	case CA_FLOAT32:
		return CaFloatType::fromBitWidth(32);
	case CA_FLOAT64:
		return CaFloatType::fromBitWidth(64);
	default:
		// TODO error
		assert(0);
		return nullptr;
	}
}



