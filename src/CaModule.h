/*
 * CaModule.h
 *
 *  Created on: Jul 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CAMODULE_H_
#define _INCLUDED_CAMODULE_H_

#include "cayman_private.h"
#include "cayman_llvm.h"
#include "Ast.h"

#include <memory>

/**
 * takes ownership of a parsed cayman module ast, and stuffs all of the
 * code *definitions* into the JITContext.
 *
 * Note, the JITContext is only made aware of the AST objects, no IR or
 * object code is initially generated, use lazy evaluation to get IR and object
 * code.
 */
class CaModule: public CaObject
{
public:

	CaModule(const std::string& _name, const std::string& _fname = "") :
		CaObject(TY_MODULE), name(_name), fname(_fname) {};

	CaModule(const std::string& _name, const std::string& _fname,
		std::unique_ptr<py::Module> _ast);

	virtual ~CaModule() {};

	/**
	 * The parsed module ast.
	 */
	std::unique_ptr<py::Module> ast;

	static bool classof(const CaObject *o)
	{
		return o->GetType() == TY_MODULE;
	}

	std::string name;
	std::string fname;

	/**
	 * TODO remove these virtuals with static methods
	 */
	virtual CaObject *GetAttrString(const char* str);
};

#endif /* _INCLUDED_CAMODULE_H_ */
