/*
 * CaObject.cpp
 *
 *  Created on: Aug 4, 2015
 *      Author: andy
 */
#include "cayman_private.h"

#include <cstddef>

static CaTypeObject TypeObjectObject (
    "CaTypeObject",       // const char *tp_name; /* For printing, in format "<module>.<name>" */
    0,                // size_t tp_basicsize,
    0,                // size_t tp_itemsize; /* For allocation */
    /* Methods to implement standard operations */
    0,                // CaDestructorFn tp_dealloc;
    0,                // CaPrintFn tp_print;
    0,                // CaGetAttrFn tp_getattr;
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

CaTypeObject::CaTypeObject() :
    CaObject(CA_TYPE, &TypeObjectObject),
    tp_name(0),
    tp_basicsize(0),
    tp_itemsize(0),
    tp_dealloc(0),
    tp_print(0),
    tp_getattr(0),
    tp_setattr(0),
    tp_compare(0),
    tp_repr(0),
    tp_as_number(0),
    tp_as_sequence(0),
    tp_as_mapping(0),
    tp_hash(0),
    tp_call(0),
    tp_str(0),
    tp_getattro(0),
    tp_setattro(0),
    tp_as_buffer(0),
    tp_flags(0),
    tp_doc(0),
    tp_traverse(0),
    tp_clear(0),
    tp_richcompare(0),
    tp_weaklistoffset(0),
    tp_iter(0),
    tp_iternext(0),
    tp_methods(0),
    tp_members(0),
    tp_getset(0),
    tp_base(0),
    tp_dict(0),
    tp_descr_get(0),
    tp_descr_set(0),
    tp_dictoffset(0),
    tp_init(0),
    tp_alloc(0),
    tp_new(0),
    tp_free(0),
    tp_is_gc(0),
    tp_bases(0),
    tp_mro(0),
    tp_cache(0),
    tp_subclasses(0),
    tp_weaklist(0),
    tp_del(0),
    tp_version_tag(0)
{
};


// Silly C++ won't let you do structure braces initialization with
// inheritance
CaTypeObject::CaTypeObject (
    const char *tp_name,
    size_t tp_basicsize,
    size_t tp_itemsize,
    CaDestructorFn tp_dealloc,
    CaPrintFn tp_print,
    CaGetAttrFn tp_getattr,
    CaSetAttrFn tp_setattr,
    CaCmpFn tp_compare,
    CaReprFn tp_repr,
    /* Method suites for standard classes */
    CaNumberMethods *tp_as_number,
    CaSequenceMethods *tp_as_sequence,
    CaMappingMethods *tp_as_mapping,
    /* More standard operations (here for binary compatibility) */
    CaHashFn tp_hash,
    CaTernaryFn tp_call,
    CaReprFn tp_str,
    CaGetAttroFn tp_getattro,
    CaSetAttroFn tp_setattro,
    /* Functions to access object as input/output buffer */
    CaBufferProcs *tp_as_buffer,
    /* Flags to define presence of optional/expanded features */
    long tp_flags,
    const char *tp_doc, /* Documentation string */
                        /* Assigned meaning in release 2.0 */
                        /* call function for all accessible objects */
    CaTraverseFn tp_traverse,
    /* delete references to contained objects */
    CaInquiryFn tp_clear,
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    CaRichCmpFn tp_richcompare,
    /* weak reference enabler */
    size_t tp_weaklistoffset,
    /* Added in release 2.2 */
    /* Iterators */
    CaGetIterFn tp_iter,
    CaIterNextFn tp_iternext,
    /* Attribute descriptor and subclassing stuff */
    struct CaMethodDef *tp_methods,
    struct CaMemberDef *tp_members,
    struct CaGetSetDef *tp_getset,
    struct _typeobject *tp_base,
    CaObject *tp_dict,
    CaDescGetFn tp_descr_get,
    CaDescSetFn tp_descr_set,
    size_t tp_dictoffset,
    CaInitFn tp_init,
    CaAllocFn tp_alloc,
    CaNewFn tp_new,
    CaFreeFn tp_free, /* Low-level free-memory routine */
    CaInquiryFn tp_is_gc, /* For CaObject_IS_GC */
    CaObject *tp_bases,
    CaObject *tp_mro, /* method resolution order */
    CaObject *tp_cache,
    CaObject *tp_subclasses,
    CaObject *tp_weaklist,
    CaDestructorFn tp_del,
    /* Type attribute cache version tag. Added in version 2.6 */
    unsigned int tp_version_tag) :
    CaObject(CA_TYPE, &TypeObjectObject),
    tp_name(tp_name),
    tp_basicsize(tp_basicsize),
    tp_itemsize(tp_itemsize),
    tp_dealloc(tp_dealloc),
    tp_print(tp_print),
    tp_getattr(tp_getattr),
    tp_setattr(tp_setattr),
    tp_compare(tp_compare),
    tp_repr(tp_repr),
    tp_as_number(tp_as_number),
    tp_as_sequence(tp_as_sequence),
    tp_as_mapping(tp_as_mapping),
    tp_hash(tp_hash),
    tp_call(tp_call),
    tp_str(tp_str),
    tp_getattro(tp_getattro),
    tp_setattro(tp_setattro),
    tp_as_buffer(tp_as_buffer),
    tp_flags(tp_flags),
    tp_doc(tp_doc),
    tp_traverse(tp_traverse),
    tp_clear(tp_clear),
    tp_richcompare(tp_richcompare),
    tp_weaklistoffset(tp_weaklistoffset),
    tp_iter(tp_iter),
    tp_iternext(tp_iternext),
    tp_methods(tp_methods),
    tp_members(tp_members),
    tp_getset(tp_getset),
    tp_base(tp_base),
    tp_dict(tp_dict),
    tp_descr_get(tp_descr_get),
    tp_descr_set(tp_descr_set),
    tp_dictoffset(tp_dictoffset),
    tp_init(tp_init),
    tp_alloc(tp_alloc),
    tp_new(tp_new),
    tp_free(tp_free),
    tp_is_gc(tp_is_gc),
    tp_bases(tp_bases),
    tp_mro(tp_mro),
    tp_cache(tp_cache),
    tp_subclasses(tp_subclasses),
    tp_weaklist(tp_weaklist),
    tp_del(tp_del),
    tp_version_tag(tp_version_tag)
{
};



