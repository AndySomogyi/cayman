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
 *
 *
 * NOTES:
 *
 * A CaModule object is read from a module definiton file.
 *
 *
 * A module may be read from a module def file, or created dynamically.
 * A module is not 'loaded' until it is told to do so, e.g. an unloaded
 * module definitions are not available to other modules until the module
 * is loaded.
 */
struct CaModule: public CaObject
{
public:

	CaModule(const std::string& _name, const std::string& _fname = "");

	CaModule(const std::string& _name, const std::string& _fname,
		std::unique_ptr<py::Module> _ast);

    ~CaModule() {};

	/**
	 * The parsed module ast.
	 */
	std::unique_ptr<py::Module> ast;

	static bool classof(const CaObject *o)
	{
		return o->typeId == CA_MODULE;
	}

	// name of module
	std::string name;

	// filename of module
	std::string fname;

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


	int addNativeFunction(const std::string &name, void *address,
			CaType* retType, const CaTypeObjectVec& args);

private:

	/**
	 * Add the function definitions in the cayman module to the
	 * JIT context.
	 */
	void AddDefinitionsToContext();


	/**
	 * Type definitions are added via SetAttrString
	 */
	llvm::StringMap<CaObject*> types;
};


CaObject * CaModule_GetAttrString(CaModule* o, const char* str);



#endif /* _INCLUDED_CAMODULE_H_ */
