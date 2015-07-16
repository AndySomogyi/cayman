/*
 * cayman_private.h
 *
 *  Created on: Jul 6, 2015
 *      Author: andy
 *
 * The internal, private header file which actually specifies all of the
 * opaque cayman data structures.
 *
 * This file must never be included before the public cayman.h file,
 * as this ensures that the public api files will never have any dependancy
 * on the internal details.
 */

#ifndef _INCLUDED_CAYMAN_H_
#include "cayman.h"
#endif

#ifndef _INCLUDED_CAYMAN_PRIVATE_H_
#define _INCLUDED_CAYMAN_PRIVATE_H_

// use LLVM style type casting
#include "llvm/Support/Casting.h"

using llvm::dyn_cast;

#include <Python.h>

struct CaObject : _object
{
	enum TypeId {
		TY_TYPEOBJECT,
		TY_MODULE,
		TY_CALLABLE
	};



	const TypeId type;

	CaObject(TypeId _type) : type(_type)
	{
		ob_refcnt = 0; ob_type = nullptr;
	}

	virtual ~CaObject() {};

	TypeId GetType() const {return type;}

	/**
	 * TODO remove these virtuals with static methods
	 */
	virtual CaObject *GetAttrString(const char* str)
	{
		return nullptr;
	}

};







#endif /* _INCLUDED_CAYMAN_PRIVATE_H_ */
