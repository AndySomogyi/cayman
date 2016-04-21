/*
 * CaModule.h
 *
 *  Created on: Jul 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CAMODULE_H_
#define _INCLUDED_CAMODULE_H_

#include "cayman_private.h"
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





#endif /* _INCLUDED_CAMODULE_H_ */
