/*
 * CaInt.h
 *
 *  Created on: Aug 5, 2015
 *      Author: andy
 */

#ifndef SRC_CAINT_H_
#define SRC_CAINT_H_

#include "CaObject.h"
#include "CaType.h"
#include "cayman_llvm.h"


class CaInt : public CaObject
{
public:
	/**
	 * Set to zero 32 bit value
	 */
	CaInt();

	/**
	 * create from an existing value
	 */
	CaInt(const llvm::APInt &val);

	/**
	 * from existing value
	 */
	CaInt(long val);

	/**
	 * Return value: New reference.
	 * Return a new CaIntObject or CaLongObject based on the string value in str,
	 * which is interpreted according to the radix in base. If pend is non-NULL,
	 * *pend will point to the first character in str which follows the
	 * representation of the number. If base is 0, the radix will be determined
	 * based on the leading characters of str: if str starts with '0x' or '0X',
	 * radix 16 will be used; if str starts with '0', radix 8 will be used;
	 * otherwise radix 10 will be used. If base is not 0, it must be between
	 * 2 and 36, inclusive. Leading spaces are ignored. If there are no digits,
	 * ValueError will be raised. If the string represents a number too large
	 * to be contained within the machine’s long int type and overflow warnings
	 * are being suppressed, a CaLongObject will be returned. If overflow warnings
	 * are not being suppressed, NULL will be returned in this case.
	 */
	static CaInt *fromString(const char *str, char **pend, int base);

	/**
	 * Create a new integer object with a value of ival. If the value exceeds
	 * LONG_MAX, a long integer object is returned.
	 */
	static CaInt *fromSize_t(size_t ival);

	/**
	 * Will first attempt to cast the object to a CaIntObject, if it is not
	 * already one, and then return its value. If there is an error, -1 is
	 * returned, and the caller should check CaErr_Occurred() to find out
	 * whether there was an error, or whether the value just happened to be -1.
	 */
	long asLong();

	/**
	 * Will first attempt to cast the object to a CaIntObject or CaLongObject,
	 * if it is not already one, and then return its value as unsigned long long,
	 * without checking for overflow.
	 */
	unsigned long long asUnsignedLongLongMask();

	/**
	 * Will first attempt to cast the object to a CaIntObject or CaLongObject,
	 * if it is not already one, and then return its value as Ca_ssize_t.
	 */
	size_t asSize_t();

	/**
	 * Return the system’s idea of the largest integer it can handle
	 * (LONG_MAX, as defined in the system header files).
	 */
	long getMax();

	/**
	 * The actual value, this is an arbitrary precision integer
	 */
	llvm::APInt value;

	static bool classof(const CaObject *o)
	{
		return o->type == CA_INT_TYPE;
	}
};

class CaIntType : public CaPrimitiveType
{
public:

	static bool classof(const CaObject *o)
	{
		return o->type == CA_INT_TYPE;
	}

	/**
	 * cache the standard bitwidth float types.
	 */
	static CaIntType *fromBitWidth(unsigned numBits);

	static int initialize();

	static int finalize();

private:
	CaIntType(llvm::LLVMContext &c, unsigned numBits);
};

#endif /* SRC_CAINT_H_ */
