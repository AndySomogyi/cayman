/*
 * cayman_private.h
 *
 *  Created on: Jul 6, 2015
 *      Author: andy
 *
 * The internal, private header file which actually specifies all of the
 * opaque cayman data structures.
 *
 * This file must never be included before the public cayman.h file,
 * as this ensures that the public api files will never have any dependancy
 * on the internal details.
 */

#ifndef _INCLUDED_CAYMAN_H_
#include "cayman.h"
#endif

#ifndef _INCLUDED_CAYMAN_PRIVATE_H_
#define _INCLUDED_CAYMAN_PRIVATE_H_



#include "CaObject.h"
#include "CaType.h"
#include "CaModule.h"
#include "CaInt.h"
#include "CaFloat.h"



/**
 * Initialize the runtime eval modules (builtins, globals)
 */
int initEval();


/**
 * Shutdown the eval modules
 */
int finalizeEval();


#endif /* _INCLUDED_CAYMAN_PRIVATE_H_ */
