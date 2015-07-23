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

typedef std::vector<CaTypeObject*> CaTypeObjectVec;


class CaCallable : public CaObject
{
public:
	CaCallable(py::FunctionDef* _func) :
		CaObject(TY_CALLABLE), func(_func), pfunc(nullptr) {};

	py::FunctionDef *func;

	void *pfunc;

	void *GetFuctionAddress(CaTypeObject* retType, const CaTypeObjectVec& args);



	static bool classof(const CaObject *o)
	{
		return o->GetType() == TY_CALLABLE;
	}
};

#endif /* _INCLUDED_CACALLABLE_H_ */
