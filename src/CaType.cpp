/*
 * CaTypeObject.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include "cayman_private.h"

int CaType::addToModule(CaObject* module)
{
	CaModule *mod = dyn_cast<CaModule>(module);

	if (mod == nullptr) {
		return -1;
	}

	//return mod->setAttrString(ob_type->tp_name, this);
}
