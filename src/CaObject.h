/*
 * CaObject.h
 *
 *  Created on: Aug 4, 2015
 *      Author: andy
 */

#ifndef SRC_CAOBJECT_H_
#define SRC_CAOBJECT_H_

#include <Python.h>


// use LLVM style type casting
#include "llvm/Support/Casting.h"

using llvm::dyn_cast;

/**
 * All Cayman types that can be cast via dyn_cast need to have an id
 * in this list
 *
 * The Type objects for each type have a '_TYPE' suffix.
 */

enum CaObjectType
{
	CA_OBJECT,
	CA_TYPE,
	CA_INT,
	CA_FLOAT,
	CA_PRIMITIVE_TYPE,
	CA_INT_TYPE,
	CA_FLOAT_TYPE,
	CA_STRING_TYPE,
	CA_MODULE,
	CA_CALLABLE,
};

class CaType;

/**
 * The CaObject type is designed to be binary compatible with the PyObject
 * struct. As such, a direct inheritance from PyObject result in the correct
 * memory layout.
 *
 * The CaType pointer is a bit tricky. As the CaObject adds a few members to
 * basic PyObject, if CaType inherits from CaObject, and also inerits from
 * PyObjectType, it will not have the correct binary layout of PyObjectType.
 * Therefore, CaType contains a PyObjectType field, this is the value that
 * gets storred in the basic PyObject ob_type field. In order to get
 * back to the CaType, and without adding any extra fields, only the
 * offset of CaType->pyType needs to be known, this is used to retrieve
 * the original CaType.
 */
struct CaObject : PyObject
{
	const CaObjectType type;

	CaObject(CaObjectType _type) : type(_type)
	{
		ob_refcnt = 1; ob_type = nullptr;
	}

	virtual ~CaObject() {};

	/**
	 * TODO remove these virtuals with static methods
	 */
	virtual CaObject *getAttrString(const char* str)
	{
		return nullptr;
	}

	virtual int setAttrString(const char *attr_name, CaObject *v)
	{
		return 0;
	}

	/**
	 * returns a borrowed reference to the CaType object.
	 */
	CaType *getTypeObject();


	void setTypeObject(CaType*);

	/**
	 * Increase the reference count on this object
	 */
	uint32_t incref();

	/**
	 * decrease the refernce count.
	 */
	uint32_t decref();
};





#endif /* SRC_CAOBJECT_H_ */
