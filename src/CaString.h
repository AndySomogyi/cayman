/*
 * CaString.h
 *
 *  Created on: Aug 6, 2015
 *      Author: andy
 */

#ifndef SRC_CASTRING_H_
#define SRC_CASTRING_H_

#include "CaObject.h"
#include "CaType.h"

class CaString : public CaObject
{
public:

	CaString(const char *v);

	CaString(const char *v, size_t len);

	/**
	 * Return a NUL-terminated representation of the contents of string. The
	 * pointer refers to the internal buffer of string, not a copy. The data
	 * must not be modified in any way, unless the string was just created using
	 * PyString_FromStringAndSize(NULL, size). It must not be deallocated.
	 * If string is a Unicode object, this function computes the default
	 * encoding of string and operates on that. If string is not a string object
	 * at all, PyString_AsString() returns NULL and raises TypeError.
	 */
	const char* asString();

	static bool classof(const CaObject *o)
	{
		return o->typeId == CA_STRING;
	}

private:
	std::string value;
};


class CaStringType : public CaPrimitiveType
{
public:

	static bool classof(const CaObject *o)
	{
		return o->typeId == CA_STRING_TYPE;
	}



private:
	CaStringType();
};

#endif /* SRC_CASTRING_H_ */
