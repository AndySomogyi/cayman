/*
 * ca_import.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "ca_object.h"
#include "ca_import.h"



CaObject* CaImport_ExecCodeModule(const char* name, /* UTF-8 encoded string */
		CaObject* co)
{
	return NULL;
}

CaObject* CaImport_ExecCodeModuleEx(const char* name, /* UTF-8 encoded string */
		CaObject* co, const char* pathname)
{
	return NULL;
}

CaObject* CaImport_ExecCodeModuleWithPathnames(const char* name, /* UTF-8 encoded string */
		CaObject* co, const char* pathname, /* decoded from the filesystem encoding */
		const char* cpathname)
{
	return NULL;
}

CaObject* CaImport_ExecCodeModuleObject(CaObject* name, CaObject* co, CaObject* pathname, CaObject* cpathname)
{
	return NULL;
}

CaObject* CaImport_AddModuleObject(CaObject* name)
{
	return NULL;
}

CaObject* CaImport_AddModule(const char* name)
{
	return NULL;
}

CaObject* CaImport_ImportModule(const char* name)
{
	return NULL;
}

CaObject* CaImport_Import(CaObject* name)
{
	return NULL;
}



