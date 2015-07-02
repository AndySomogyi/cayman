
/* Tuple object interface */

#ifndef Ca_TUPLEOBJECT_H
#define Ca_TUPLEOBJECT_H

#include <ca_object.h>


#ifdef __cplusplus
extern "C" {
#endif

/*
Another generally useful object type is a tuple of object pointers.
For Cayman, this is an immutable type.  C code can change the tuple items
(but not their number), and even use tuples are general-purpose arrays of
object references, but in general only brand new tuples should be mutated,
not ones that might already have been exposed to Cayman code.

*** WARNING *** CaTuple_SetItem does not increment the new item's reference
count, but does decrement the reference count of the item it replaces,
if not nil.  It does *decrement* the reference count if it is *not*
inserted in the tuple.  Similarly, CaTuple_GetItem does not increment the
returned item's reference count.
*/



CaAPI_DATA(CaTypeObject) CaTuple_Type;
CaAPI_DATA(CaTypeObject) CaTupleIter_Type;

#define CaTuple_Check(op) \
                 CaType_FastSubclass(Ca_TYPE(op), Ca_TPFLAGS_TUPLE_SUBCLASS)
#define CaTuple_CheckExact(op) (Ca_TYPE(op) == &CaTuple_Type)

CaAPI_FUNC(CaObject *) CaTuple_New(Ca_ssize_t size);
CaAPI_FUNC(Ca_ssize_t) CaTuple_Size(CaObject *);
CaAPI_FUNC(CaObject *) CaTuple_GetItem(CaObject *, Ca_ssize_t);
CaAPI_FUNC(int) CaTuple_SetItem(CaObject *, Ca_ssize_t, CaObject *);
CaAPI_FUNC(CaObject *) CaTuple_GetSlice(CaObject *, Ca_ssize_t, Ca_ssize_t);
CaAPI_FUNC(CaObject *) CaTuple_Pack(Ca_ssize_t, ...);
CaAPI_FUNC(int) CaTuple_ClearFreeList(void);


#ifdef __cplusplus
}
#endif
#endif /* !Ca_TUPLEOBJECT_H */
