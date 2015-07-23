/*
 * ca_import.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "cayman_private.h"
#include "CaModule.h"
#include "Parser.h"
#include "JITContext.h"
#include <string>

using std::string;

using namespace std;

extern "C"
{

CaObject* CaImport_ImportModule(const char* name)
{
	try {
		 string fname = string(name) + ".py";

		 py::Parser parser(fname);

		 py::AstPtr ast = parser.Parse();

		 py::Ast *p = ast.get();

		 p->Print(std::cout);

		 if(ast->module != nullptr)
		 {
		     CaModule *mod = new CaModule(name, fname, std::unique_ptr<py::Module>(ast->module));

		     JITContext::Get().AddCaModule(mod);

		     return mod;
		 }

	} catch (...)
	{
		cout << "error";
	}
	return 0;
}

CaObject* CaImport_ImportModuleNoBlock(const char* name)
{
	return 0;
}

CaObject* CaImport_ImportModuleEx(char* name, CaObject* globals,
		CaObject* locals, CaObject* fromlist)
{
	return 0;
}

CaObject* CaImport_ImportModuleLevel(char* name, CaObject* globals,
		CaObject* locals, CaObject* fromlist, int level)
{
	return 0;
}

CaObject* CaImport_Import(CaObject* name)
{
	return 0;
}

CaObject* CaImport_ReloadModule(CaObject* m)
{
	return 0;
}

CaObject* CaImport_AddModule(const char* name)
{
	return 0;
}

CaObject* CaImport_ExecCodeModule(char* name, CaObject* co)
{
	return 0;
}

CaObject* CaImport_ExecCodeModuleEx(char* name, CaObject* co, char* pathname)
{
	return 0;
}

long CaImport_GetMagicNumber()
{
	return 0;
}

CaObject* CaImport_GetModuleDict()
{
	return 0;
}

}
