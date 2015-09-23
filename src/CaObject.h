/*
 * CaObject.h
 *
 *  Created on: Aug 4, 2015
 *      Author: andy
 */

#ifndef SRC_CAOBJECT_H_
#define SRC_CAOBJECT_H_


#include "cayman.h"

// use LLVM style type casting
#include "llvm/Support/Casting.h"


using llvm::dyn_cast;

/**
 * All Cayman types that can be cast via dyn_cast need to have an id
 * in this list
 *
 * The Type objects for each type have a '_TYPE' suffix.
 */

enum CaObjectType
{
	CA_OBJECT,
	CA_TYPE,
	CA_INT,
	CA_FLOAT,
	CA_PRIMITIVE_TYPE,
	CA_INT_TYPE,
	CA_FLOAT_TYPE,
	CA_STRING,
	CA_STRING_TYPE,
	CA_MODULE,
	CA_MODULE_TYPE,
	CA_CALLABLE,
	CA_FUNCTION
};

struct CaType;

struct CaObject;

//#ifdef __cplusplus
//extern "C" {
//#endif


/* Object and type object interface */

/*
Objects are structures allocated on the heap.  Special rules apply to
the use of objects to ensure they are properly garbage-collected.
Objects are never allocated statically or on the stack; they must be
accessed through special macros and functions only.  (Type objects are
exceptions to the first rule; the standard types are represented by
statically initialized type objects, although work on type/class unification
for Cathon 2.2 made it possible to have heap-allocated type objects too).

An object has a 'reference count' that is increased or decreased when a
pointer to the object is copied or deleted; when the reference count
reaches zero there are no references to the object left and it can be
removed from the heap.

An object has a 'type' that determines what it represents and what kind
of data it contains.  An object's type is fixed when it is created.
Types themselves are represented as objects; an object contains a
pointer to the corresponding type object.  The type itself has a type
pointer pointing to the object representing the type 'type', which
contains a pointer to itself!).

Objects do not float around in memory; once allocated an object keeps
the same size and address.  Objects that must hold variable-size data
can contain pointers to variable-size parts of the object.  Not all
objects of the same type have the same size; but the size cannot change
after allocation.  (These restrictions are made so a reference to an
object can be simply a pointer -- moving an object would require
updating all the pointers, and changing an object's size would require
moving it if there was another object right next to it.)

Objects are always accessed through pointers of the type 'CaObject *'.
The type 'CaObject' is a structure that only contains the reference count
and the type pointer.  The actual memory allocated for an object
contains other data that can only be accessed after casting the pointer
to a pointer to a longer structure type.  This longer type must start
with the reference count and type fields; the macro CaObject_HEAD should be
used for this (to accommodate for future changes).  The implementation
of a particular object type can cast the object pointer to the proper
type and back.

A standard interface exists for objects that contain an array of items
whose size is determined when the object is allocated.
*/


/* CaObject_HEAD defines the initial segment of every CaObject. */
//#define CaObject_HEAD                   \
//    _CaObject_HEAD_EXTRA                \
//    size_t ob_refcnt;               \
//    struct _typeobject *ob_type;


 //   CaObject_HEAD_INIT(type) size,

/* CaObject_VAR_HEAD defines the initial segment of all variable-size
 * container objects.  These end with a declaration of an array with 1
 * element, but enough space is malloc'ed so that the array actually
 * has room for ob_size elements.  Note that ob_size is an element count,
 * not necessarily a byte count.
 */
//#define CaObject_VAR_HEAD               \
//    CaObject_HEAD                       \
//    size_t ob_size; /* Number of items in variable part */
//#define Ca_INVALID_SIZE (size_t)-1

/* Nothing is actually declared to be a CaObject, but every pointer to
 * a Cathon object can be cast to a CaObject*.  This is inheritance built
 * by hand.  Similarly every pointer to a variable-size Cathon object can,
 * in addition, be cast to CaVarObject*.
 */
//typedef struct _object {
//    CaObject_HEAD
//} CaObject;

//typedef struct {
//    CaObject_VAR_HEAD
//} CaVarObject;

//#define Ca_REFCNT(ob)           (((CaObject*)(ob))->ob_refcnt)
//#define Ca_TYPE(ob)             (((CaObject*)(ob))->ob_type)
//#define Ca_SIZE(ob)             (((CaVarObject*)(ob))->ob_size)

/*
Type objects contain a string containing the type name (to help somewhat
in debugging), the allocation parameters (see CaObject_New() and
CaObject_NewVar()),
and methods for accessing objects of the type.  Methods are optional, a
nil pointer meaning that particular kind of access is not available for
this type.  The Ca_DECREF() macro uses the tp_dealloc method without
checking for a nil pointer; it should always be implemented except if
the implementation can guarantee that the reference count will never
reach zero (e.g., for statically allocated type objects).

NB: the methods for certain type groups are now contained in separate
method blocks.
*/

typedef CaObject * (*CaUnaryFn)(CaObject *);
typedef CaObject * (*CaBinaryFn)(CaObject *, CaObject *);
typedef CaObject * (*CaTernaryFn)(CaObject *, CaObject *, CaObject *);
typedef int (*CaInquiryFn)(CaObject *);
typedef size_t (*CaLenFn)(CaObject *);
typedef int (*CaCoercionFn)(CaObject **, CaObject **);
//typedef CaObject *(*intargfunc)(CaObject *, int) Ca_DEPRECATED(2.5);
//typedef CaObject *(*intintargfunc)(CaObject *, int, int) Ca_DEPRECATED(2.5);
typedef CaObject *(*CaSizeArgFn)(CaObject *, size_t);
typedef CaObject *(*CaSizeSizeArgFn)(CaObject *, size_t, size_t);
typedef int(*CaIntObjArgFn)(CaObject *, int, CaObject *);
typedef int(*CaIntIntObjArgFn)(CaObject *, int, int, CaObject *);
typedef int(*CaSizetObjFn)(CaObject *, size_t, CaObject *);
typedef int(*CaSizetSizetObjFn)(CaObject *, size_t, size_t, CaObject *);
typedef int(*CaObjObjArgFn)(CaObject *, CaObject *, CaObject *);



/* int-based buffer interface */
typedef int (*CaGetReadBufferFn)(CaObject *, int, void **);
typedef int (*CaGetWriteBufferFn)(CaObject *, int, void **);
typedef int (*CaGetSegCountFn)(CaObject *, int *);
typedef int (*CaGetCharBufferFn)(CaObject *, int, char **);
/* ssize_t-based buffer interface */
typedef size_t (*CaReadBufferFn)(CaObject *, size_t, void **);
typedef size_t (*CaWriteBufferFn)(CaObject *, size_t, void **);
typedef size_t (*CaSegCountFn)(CaObject *, size_t *);
typedef size_t (*CaCharBufferFn)(CaObject *, size_t, char **);


/* Ca3k buffer interface */
struct Ca_buffer {
    void *buf;
    CaObject *obj;        /* owned reference */
    size_t len;
    size_t itemsize;  /* This is size_t so it can be
                             pointed to by strides in simple case.*/
    int readonly;
    int ndim;
    char *format;
    size_t *shape;
    size_t *strides;
    size_t *suboffsets;
    size_t smalltable[2];  /* static store for shape and strides of
                                  mono-dimensional buffers. */
    void *internal;
};

typedef int (*CaGetBufferFn)(CaObject *, Ca_buffer *, int);
typedef void (*CaReleaseBufferFn)(CaObject *, Ca_buffer *);

    /* Flags for getting buffers */
#define CaBUF_SIMPLE 0
#define CaBUF_WRITABLE 0x0001
/*  we used to include an E, backwards compatible alias  */
#define CaBUF_WRITEABLE CaBUF_WRITABLE
#define CaBUF_FORMAT 0x0004
#define CaBUF_ND 0x0008
#define CaBUF_STRIDES (0x0010 | CaBUF_ND)
#define CaBUF_C_CONTIGUOUS (0x0020 | CaBUF_STRIDES)
#define CaBUF_F_CONTIGUOUS (0x0040 | CaBUF_STRIDES)
#define CaBUF_ANY_CONTIGUOUS (0x0080 | CaBUF_STRIDES)
#define CaBUF_INDIRECT (0x0100 | CaBUF_STRIDES)

#define CaBUF_CONTIG (CaBUF_ND | CaBUF_WRITABLE)
#define CaBUF_CONTIG_RO (CaBUF_ND)

#define CaBUF_STRIDED (CaBUF_STRIDES | CaBUF_WRITABLE)
#define CaBUF_STRIDED_RO (CaBUF_STRIDES)

#define CaBUF_RECORDS (CaBUF_STRIDES | CaBUF_WRITABLE | CaBUF_FORMAT)
#define CaBUF_RECORDS_RO (CaBUF_STRIDES | CaBUF_FORMAT)

#define CaBUF_FULL (CaBUF_INDIRECT | CaBUF_WRITABLE | CaBUF_FORMAT)
#define CaBUF_FULL_RO (CaBUF_INDIRECT | CaBUF_FORMAT)


#define CaBUF_READ  0x100
#define CaBUF_WRITE 0x200
#define CaBUF_SHADOW 0x400
/* end Ca3k buffer interface */

typedef int (*CaObjObjFn)(CaObject *, CaObject *);
typedef int (*CaVisitFn)(CaObject *, void *);
typedef int (*CaTraverseFn)(CaObject *, CaVisitFn, void *);

typedef struct {
    /* For numbers without flag bit Ca_TPFLAGS_CHECKTYPES set, all
       arguments are guaranteed to be of the object's type (modulo
       CaCoercionFn hacks -- i.e. if the type's CaCoercionFn function
       returns other types, then these are allowed as well).  Numbers that
       have the Ca_TPFLAGS_CHECKTYPES flag bit set should check *both*
       arguments for proper type and implement the necessary conversions
       in the slot functions themselves. */

    CaBinaryFn nb_add;
    CaBinaryFn nb_subtract;
    CaBinaryFn nb_multiply;
    CaBinaryFn nb_divide;
    CaBinaryFn nb_remainder;
    CaBinaryFn nb_divmod;
    CaTernaryFn nb_power;
    CaUnaryFn nb_negative;
    CaUnaryFn nb_positive;
    CaUnaryFn nb_absolute;
    CaInquiryFn nb_nonzero;
    CaUnaryFn nb_invert;
    CaBinaryFn nb_lshift;
    CaBinaryFn nb_rshift;
    CaBinaryFn nb_and;
    CaBinaryFn nb_xor;
    CaBinaryFn nb_or;
    CaCoercionFn nb_coerce;
    CaUnaryFn nb_int;
    CaUnaryFn nb_long;
    CaUnaryFn nb_float;
    CaUnaryFn nb_oct;
    CaUnaryFn nb_hex;
    /* Added in release 2.0 */
    CaBinaryFn nb_inplace_add;
    CaBinaryFn nb_inplace_subtract;
    CaBinaryFn nb_inplace_multiply;
    CaBinaryFn nb_inplace_divide;
    CaBinaryFn nb_inplace_remainder;
    CaTernaryFn nb_inplace_power;
    CaBinaryFn nb_inplace_lshift;
    CaBinaryFn nb_inplace_rshift;
    CaBinaryFn nb_inplace_and;
    CaBinaryFn nb_inplace_xor;
    CaBinaryFn nb_inplace_or;

    /* Added in release 2.2 */
    /* The following require the Ca_TPFLAGS_HAVE_CLASS flag */
    CaBinaryFn nb_floor_divide;
    CaBinaryFn nb_true_divide;
    CaBinaryFn nb_inplace_floor_divide;
    CaBinaryFn nb_inplace_true_divide;

    /* Added in release 2.5 */
    CaUnaryFn nb_index;
} CaNumberMethods;

typedef struct {
    CaLenFn sq_length;
    CaBinaryFn sq_concat;
    CaSizeArgFn sq_repeat;
    CaSizeArgFn sq_item;
    CaSizeSizeArgFn sq_slice;
    CaSizetObjFn sq_ass_item;
    CaSizetSizetObjFn sq_ass_slice;
    CaObjObjFn sq_contains;
    /* Added in release 2.0 */
    CaBinaryFn sq_inplace_concat;
    CaSizeArgFn sq_inplace_repeat;
} CaSequenceMethods;

typedef struct {
    CaLenFn mp_length;
    CaBinaryFn mp_subscript;
    CaObjObjArgFn mp_ass_subscript;
} CaMappingMethods;

typedef struct {
    CaReadBufferFn bf_getreadbuffer;
    CaWriteBufferFn bf_getwritebuffer;
    CaSegCountFn bf_getsegcount;
    CaCharBufferFn bf_getcharbuffer;
    CaGetBufferFn bf_getbuffer;
    CaReleaseBufferFn bf_releasebuffer;
} CaBufferProcs;


typedef void (*CaFreeFn)(void *);
typedef void (*CaDestructorFn)(CaObject *);
typedef int (*CaPrintFn)(CaObject *, FILE *, int);
typedef CaObject *(*CaGetAttrFn)(CaObject *,  const char *);
typedef CaObject *(*CaGetAttroFn)(CaObject *, CaObject *);
typedef int (*CaSetAttrFn)(CaObject *, char *, CaObject *);
typedef int (*CaSetAttroFn)(CaObject *, CaObject *, CaObject *);
typedef int (*CaCmpFn)(CaObject *, CaObject *);
typedef CaObject *(*CaReprFn)(CaObject *);
typedef long (*CaHashFn)(CaObject *);
typedef CaObject *(*CaRichCmpFn) (CaObject *, CaObject *, int);
typedef CaObject *(*CaGetIterFn) (CaObject *);
typedef CaObject *(*CaIterNextFn) (CaObject *);
typedef CaObject *(*CaDescGetFn) (CaObject *, CaObject *, CaObject *);
typedef int (*CaDescSetFn) (CaObject *, CaObject *, CaObject *);
typedef int (*CaInitFn)(CaObject *, CaObject *, CaObject *);
typedef CaObject *(*CaNewFn)(struct _typeobject *, CaObject *, CaObject *);
typedef CaObject *(*CaAllocFn)(struct _typeobject *, size_t);



/**
 */
struct CaObject
{
	struct CaTypeObject *type;
	const CaObjectType typeId;
	uint32_t refcnt;


	CaObject(CaObjectType _type) : typeId(_type)
	{
        refcnt = 1; type = nullptr;
	}

	CaObject(CaObjectType typeId, CaTypeObject *type) : typeId(typeId), type(type)
	{
        refcnt = 1;
	}
    
};

struct CaTypeObject : public CaObject
{
	const char *tp_name; /* For printing, in format "<module>.<name>" */
	size_t tp_basicsize;
	size_t tp_itemsize; /* For allocation */

	/* Methods to implement standard operations */
	CaDestructorFn tp_dealloc;
	CaPrintFn tp_print;
	CaGetAttrFn tp_getattr;
	CaSetAttrFn tp_setattr;
	CaCmpFn tp_compare;
	CaReprFn tp_repr;

	/* Method suites for standard classes */

	CaNumberMethods *tp_as_number;
	CaSequenceMethods *tp_as_sequence;
	CaMappingMethods *tp_as_mapping;

	/* More standard operations (here for binary compatibility) */

	CaHashFn tp_hash;
	CaTernaryFn tp_call;
	CaReprFn tp_str;
	CaGetAttroFn tp_getattro;
	CaSetAttroFn tp_setattro;

	/* Functions to access object as input/output buffer */
	CaBufferProcs *tp_as_buffer;

	/* Flags to define presence of optional/expanded features */
	long tp_flags;

	const char *tp_doc; /* Documentation string */

	/* Assigned meaning in release 2.0 */
	/* call function for all accessible objects */
	CaTraverseFn tp_traverse;

	/* delete references to contained objects */
	CaInquiryFn tp_clear;

	/* Assigned meaning in release 2.1 */
	/* rich comparisons */
	CaRichCmpFn tp_richcompare;

	/* weak reference enabler */
	size_t tp_weaklistoffset;

	/* Added in release 2.2 */
	/* Iterators */
	CaGetIterFn tp_iter;
	CaIterNextFn tp_iternext;

	/* Attribute descriptor and subclassing stuff */
	struct CaMethodDef *tp_methods;
	struct CaMemberDef *tp_members;
	struct CaGetSetDef *tp_getset;
	struct _typeobject *tp_base;
	CaObject *tp_dict;
	CaDescGetFn tp_descr_get;
	CaDescSetFn tp_descr_set;
	size_t tp_dictoffset;
	CaInitFn tp_init;
	CaAllocFn tp_alloc;
	CaNewFn tp_new;
	CaFreeFn tp_free; /* Low-level free-memory routine */
	CaInquiryFn tp_is_gc; /* For CaObject_IS_GC */
	CaObject *tp_bases;
	CaObject *tp_mro; /* method resolution order */
	CaObject *tp_cache;
	CaObject *tp_subclasses;
	CaObject *tp_weaklist;
	CaDestructorFn tp_del;

	/* Type attribute cache version tag. Added in version 2.6 */
	unsigned int tp_version_tag;



#ifdef COUNT_ALLOCS
	/* these must be last and never explicitly initialized */
	size_t tp_allocs;
	size_t tp_frees;
	size_t tp_maxalloc;
	struct _typeobject *tp_prev;
	struct _typeobject *tp_next;
#endif


	CaTypeObject();

	// Silly C++ won't let you do structure braces initialization with
	// inheritance
	CaTypeObject (
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
			unsigned int tp_version_tag);
};









#endif /* SRC_CAOBJECT_H_ */
