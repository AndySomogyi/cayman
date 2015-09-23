/*
 * CaCallable.h
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CACALLABLE_H_
#define _INCLUDED_CACALLABLE_H_

#include "cayman_private.h"
#include "Ast.h"


struct CaCallable : public CaObject
{
public:
	CaCallable(py::FunctionDef* _func) :
		CaObject(CA_CALLABLE), func(_func), pfunc(nullptr) {};


	py::FunctionDef *func;

	void *pfunc;

	void *GetFuctionAddress(CaType* retType, const CaTypeObjectVec& args);

	static bool classof(const CaObject *o)
	{
		return o->typeId == CA_CALLABLE;
	}
};

#endif /* _INCLUDED_CACALLABLE_H_ */
