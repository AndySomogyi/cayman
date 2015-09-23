/*
 * CaFloat.h
 *
 *  Created on: Aug 5, 2015
 *      Author: andy
 */

#ifndef SRC_CAFLOAT_H_
#define SRC_CAFLOAT_H_

#include "CaObject.h"
#include "CaType.h"
#include "cayman_llvm.h"

class CaFloat : public CaObject
{
public:
	/**
	 * Set to zero 32 bit value
	 */
	CaFloat();

	/**
	 * create from an existing value
	 */
	CaFloat(const llvm::APFloat &val);

	/**
	 * from existing value.
	 */
	CaFloat(double val);

	/**
	 * Return value: New reference.
	 * Create a CaFloatObject object based on the string value in str, or NULL on
	 * failure.
	 */
	static CaFloat *fromString(const char *str);

	/**
	 * Return a C double representation of the contents of Cafloat.
	 *
	 * If Cafloat is not a Cathon floating point object but has a __float__()
	 * method, this method will first be called to convert Cafloat into a float.
	 * This method returns -1.0 upon failure, so one should call
	 * CaErr_Occurred() to check for errors.
	 */
	double asDouble();

	/**
	 * Return a structseq instance which contains information about the precision,
	 * minimum and maximum values of a float. It’s a thin wrapper around the header
	 * file float.h.
	 */
	CaObject* getInfo(void);

	/**
	 * Return the maximum representable finite float DBL_MAX as C double.
	 */
	double getMax();

	/**
	 * Return the minimum normalized positive float DBL_MIN as C double.
	 */
	double getMin();

	CaObject *repr();

	CaObject *str();

	/**
	 * The value in this object, this is an arbitrary precision float value.
	 */
	llvm::APFloat value;

	static bool classof(const CaObject *o)
	{
		return o->typeId == CA_FLOAT;
	}
};

class CaFloatType : public CaPrimitiveType
{
public:

	static bool classof(const CaObject *o)
	{
		return o->typeId == CA_FLOAT_TYPE;
	}

	/**
	 * cache the standard bitwidth float types.
	 */
	static CaFloatType *fromBitWidth(unsigned numBits);

	static int initialize();

	static int finalize();

private:
	CaFloatType(llvm::LLVMContext &c, unsigned numBits);
};

#endif /* SRC_CAFLOAT_H_ */
