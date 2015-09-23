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

static CaTypeObject ModuleTypeObject(
    "CaModule",       // const char *tp_name; /* For printing, in format "<module>.<name>" */
    sizeof(CaModule), // size_t tp_basicsize,
    0,                // size_t tp_itemsize; /* For allocation */
    /* Methods to implement standard operations */
    0,                // CaDestructorFn tp_dealloc;
    0,                // CaPrintFn tp_print;
    (CaGetAttrFn)CaModule_GetAttrString,                // CaGetAttrFn tp_getattr;
    0,                // CaSetAttrFn tp_setattr;
    0,                // CaCmpFn tp_compare;
    0,                // CaReprFn tp_repr;
    /* Method suites for standard classes */
    0,                // CaNumberMethods *tp_as_number;
    0,                // CaSequenceMethods *tp_as_sequence;
    0,                // CaMappingMethods *tp_as_mapping;
    /* More standard operations (here for binary compatibility) */
    0,                // CaHashFn tp_hash;
    0,                // CaTernaryFn tp_call;
    0,                // CaReprFn tp_str;
    0,                // CaGetAttroFn tp_getattro;
    0,                // CaSetAttroFn tp_setattro;
    /* Functions to access object as input/output buffer */
    0,                // CaBufferProcs *tp_as_buffer;
    /* Flags to define presence of optional/expanded features */
    0,                // long tp_flags;
    0,                // const char *tp_doc; /* Documentation string */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    0,                // CaTraverseFn tp_traverse;
    /* delete references to contained objects */
    0,                // CaInquiryFn tp_clear;
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    0,                // CaRichCmpFn tp_richcompare;
    /* weak reference enabler */
    0,                // size_t tp_weaklistoffset;
    /* Added in release 2.2 */
    /* Iterators */
    0,                // CaGetIterFn tp_iter;
    0,                // CaIterNextFn tp_iternext;
    /* Attribute descriptor and subclassing stuff */
    0,                // struct CaMethodDef *tp_methods;
    0,                // struct CaMemberDef *tp_members;
    0,                // struct CaGetSetDef *tp_getset;
    0,                // struct _typeobject *tp_base;
    0,                // CaObject *tp_dict;
    0,                // CaDescGetFn tp_descr_get;
    0,                // CaDescSetFn tp_descr_set;
    0,                // size_t tp_dictoffset;
    0,                // CaInitFn tp_init;
    0,                // CaAllocFn tp_alloc;
    0,                // CaNewFn tp_new;
    0,                // CaFreeFn tp_free; /* Low-level free-memory routine */
    0,                // CaInquiryFn tp_is_gc; /* For CaObject_IS_GC */
    0,                // CaObject *tp_bases;
    0,                // CaObject *tp_mro; /* method resolution order */
    0,                // CaObject *tp_cache;
    0,                // CaObject *tp_subclasses;
    0,                // CaObject *tp_weaklist;
    0,                // CaDestructorFn tp_del; 
    /* Type attribute cache version tag. Added in version 2.6 */
    0                 // unsigned int tp_version_tag;
    );



CaModule::CaModule(const std::string& _name, const std::string& _fname) :
    CaObject(CA_MODULE, &ModuleTypeObject), name(_name), fname(_fname)
{
};
 
CaModule::CaModule(const std::string& _name, const std::string& _fname,
		   std::unique_ptr<py::Module> _ast) :
    CaObject(CA_MODULE, &ModuleTypeObject), name(_name), fname(_fname),
    ast(std::move(_ast))
{
    AddDefinitionsToContext();
}

CaObject* CaModule_GetAttrString(CaModule *m, const char* str)
{
	CaModule *o = (CaModule*)m;

    py::Module *p = o->ast.get();
    
    AstNodes nodes = p->body;

    
    for(auto i = o->ast->body.begin(), end = o->ast->body.end(); i != end; ++i) {
        FunctionDef* func = dynamic_cast<FunctionDef*>(*i);
        if(func && func->name.compare(str) == 0) {
            return new CaCallable(func);
        }
    }
    return nullptr;
}

const PrototypeAST* CaModule::GetPrototypeAST(const std::string& name) const
{
    CA_NOTIMPLEMENTED;
}

const FunctionAST* CaModule::GetFunctionAST(const std::string& name) const
{
    CA_NOTIMPLEMENTED;
}

void CaModule::AddDefinitionsToContext()
{
    for(auto i = ast->body.begin(), end = ast->body.end(); i != end; ++i) {
	FunctionDef* func = dynamic_cast<FunctionDef*>(*i);

    }
}
