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
 *
 * When a new CaModule is created, this represents a single cayman 'module',
 * which is essentially a namespace with a set of functions, variables and
 * class definitions. When it is first loaded, all of the definitions
 * need to be added to the JITContext, but only the definitions.
 *
 * When a new CaModule is created, all of the function definitions (prototypes)
 * are accessable by the JITContext.
 * At that point, these definitions are available, and when requested,
 * full function definitions may be JITed as requested.
 */
class CaModule: public CaObject
{
public:

	CaModule(const std::string& _name, const std::string& _fname = "") :
		CaObject(CA_MODULE), name(_name), fname(_fname) {};

	CaModule(const std::string& _name, const std::string& _fname,
		std::unique_ptr<py::Module> _ast);

	virtual ~CaModule() {};

	/**
	 * The parsed module ast.
	 */
	std::unique_ptr<py::Module> ast;

	static bool classof(const CaObject *o)
	{
		return o->type == CA_MODULE;
	}

	// name of module
	std::string name;

	// filename of module
	std::string fname;

	/**
	 * TODO remove these virtuals with static methods
	 */
	virtual CaObject *getAttrString(const char* str);

	/**
	 * A prototype only defines a function signature and symbol name.
	 * It does not specify the location (address) of the function.
	 *
	 * Address resolulution is handled later by the lambda resolver in the
	 * JITContext, which actually maps symbols names to address at runtime.
	 */
	const PrototypeAST* GetPrototypeAST(const std::string &name) const;

	/**
	 * A function ast define both a function defintion and a body.
	 *
	 * The CaModule only stores uncompiled ASTs, IR generatation and
	 * object code generation is handled by the JIT Context.
	 */
	const FunctionAST* GetFunctionAST(const std::string &name) const;

private:

	/**
	 * Add the function definitions in the cayman module to the
	 * JIT context.
	 */
	void AddDefinitionsToContext();
};

#endif /* _INCLUDED_CAMODULE_H_ */
