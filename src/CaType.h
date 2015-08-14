/*
 * CaTypeObject.h
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CATYPEOBJECT_H_
#define _INCLUDED_CATYPEOBJECT_H_

#include "CaObject.h"
#include "cayman_llvm.h"

struct CaType: public CaObject
{
public:

	PyTypeObject *getPyTypeObject() {
		return &pyType;
	}

	llvm::Type *getLLVMType() const {
		return llvmType;
	}

protected:
	CaType(CaObjectType _type) : CaObject(_type), llvmType(nullptr) {};

	PyTypeObject pyType = {0};

	friend struct CaObject;

	llvm::Type *llvmType;
};

class CaPrimitiveType : public CaType
{
public:
	CaPrimitiveType(CaObjectType _type, uint32_t primitive=0, uint32_t primitiveModifier=0) :
			CaType(_type), primitiveType(primitive),
			primitiveTypeModifier(primitiveModifier)
	{
	}

	static bool classof(const CaObject *o)
	{
		return o->type == CA_PRIMITIVE_TYPE;
	}

	uint32_t primitiveType;

	uint32_t primitiveTypeModifier;

protected:

};





#endif /* _INCLUDED_CATYPEOBJECT_H_ */
