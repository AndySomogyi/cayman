/*
 * CaTypeObject.h
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CATYPEOBJECT_H_
#define _INCLUDED_CATYPEOBJECT_H_

#include "cayman_private.h"


struct CaTypeObject: CaObject
{
	CaTypeObject(uint32_t primitive, uint32_t primitiveModifier) :
			CaObject(CA_TYPEOBJECT), primitiveType(primitive),
			primitiveTypeModifier(primitiveModifier)
	{
	}

	static bool classof(const CaObject *o)
	{
		return o->GetType() == CA_TYPEOBJECT;
	}

	uint32_t primitiveType;

	uint32_t primitiveTypeModifier;
};

#endif /* _INCLUDED_CATYPEOBJECT_H_ */
