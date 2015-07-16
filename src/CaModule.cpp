/*
 * CaModule.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: andy
 */

#include "CaModule.h"
#include "CaCallable.h"
#include "JITContext.h"
#include <algorithm>


using py::AstNodes;
using py::FunctionDef;
using py::AstNode;

CaModule::CaModule(const std::string& _name, const std::string& _fname,
		std::unique_ptr<py::Module> _ast) :
		CaObject(TY_MODULE), name(_name), fname(_fname),
		ast(std::move(_ast))
{
}

CaObject* CaModule::GetAttrString(const char* str)
{
	for(auto i = ast->body.begin(), end = ast->body.end(); i != end; ++i) {
		FunctionDef* func = dynamic_cast<FunctionDef*>(*i);
		if(func && func->name.compare(str) == 0) {
			return new CaCallable(func);
		}
	}
	return nullptr;
}
