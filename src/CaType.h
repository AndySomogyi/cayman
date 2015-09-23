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

/**
 * Type objects
 *
 * The type object has essentially three levels of descriptions:
 *
 * 1: The original AST that defines the tupe
 * 2: The LLVM type that defines the data layout
 * 3: The programmatic accessor of CaType that manages the vtable.
 */

struct CaType: public CaObject
{
public:



	llvm::Type *getLLVMType() const {
		return llvmType;
	}

	/**
	 * Adds this type object to an existing module
	 */
	int addToModule(CaObject *module);

protected:
	CaType(CaObjectType _type) : CaObject(_type), llvmType(nullptr) {};


	friend struct CaObject;

	llvm::Type *llvmType;
};

typedef std::vector<CaType*> CaTypeObjectVec;

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
		return o->typeId == CA_PRIMITIVE_TYPE;
	}

	uint32_t primitiveType;

	uint32_t primitiveTypeModifier;

protected:

};





#endif /* _INCLUDED_CATYPEOBJECT_H_ */
