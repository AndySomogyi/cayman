/*
 * CaObject.cpp
 *
 *  Created on: Aug 4, 2015
 *      Author: andy
 */
#include "CaObject.h"
#include "CaType.h"

#include <cstddef>

CaType* CaObject::getTypeObject()
{
	static const size_t typeOffset = offsetof(CaType, pyType);

	if (ob_type)
	{
		unsigned char* p = reinterpret_cast<unsigned char*>(ob_type);
		unsigned char* ptype = p - typeOffset;
		return reinterpret_cast<CaType*>(ptype);
	}
	return nullptr;
}

void CaObject::setTypeObject(CaType* type)
{
	ob_type = type->getPyTypeObject();

	assert(getTypeObject() == type);
}

uint32_t CaObject::incref()
{
	return ++ob_refcnt;
}

uint32_t CaObject::decref()
{
	CaObject *p = this;
	uint32_t result = --p->ob_refcnt;
	if(result <= 0) {
		delete p;
	}
	return result;
}
