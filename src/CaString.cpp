/*
 * CaString.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: andy
 */

#include <CaString.h>

CaString::CaString(const char* v) : CaObject(CA_STRING), value(v)
{
}

CaString::CaString(const char* v, size_t len) : CaObject(CA_STRING), value(v, len)
{
}

const char* CaString::asString()
{
	return value.c_str();
}

CaStringType::CaStringType() : CaPrimitiveType(CA_STRING_TYPE)
{
}
