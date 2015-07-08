/*
 * ca_module.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: andy
 */



extern "C" {

int CaModule_Check(CaObject* p)
{
	return 0;
}

int CaModule_CheckExact(CaObject* p)
{
	return 0;
}

CaObject* CaModule_New(const char* name)
{
	return 0;
}

CaObject* CaModule_GetDict(CaObject* module)
{
	return 0;
}

const char* CaModule_GetName(CaObject* module)
{
	return 0;
}

const char* CaModule_GetFilename(CaObject* module)
{
	return 0;
}

int CaModule_AddObject(CaObject* module, const char* name,
		CaObject* value)
{
	return 0;
}

}
