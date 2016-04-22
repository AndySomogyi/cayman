/*
 * ca_list.h
 *
 *  Created on: Apr 22, 2016
 *      Author: andy
 */

#ifndef INCLUDE_CA_LIST_H_
#define INCLUDE_CA_LIST_H_

#include <ca_object.h>


/* List object interface */

/*
Another generally useful object type is an list of object pointers.
This is a mutable type: the list items can be changed, and items can be
added or removed.  Out-of-range indices or non-list objects are ignored.

*** WARNING *** CaList_SetItem does not increment the new item's reference
count, but does decrement the reference count of the item it replaces,
if not nil.  It does *decrement* the reference count if it is *not*
inserted in the list.  Similarly, CaList_GetItem does not increment the
returned item's reference count.
*/

#ifdef __cplusplus

struct CaList : CaObject {

    /* Vector of pointers to list elements.  list[0] is ob_item[0], etc. */
	CaObject **ob_item;

    /* ob_item contains space for 'allocated' elements.  The number
     * currently in use is ob_size.
     * Invariants:
     *     0 <= ob_size <= allocated
     *     len(list) == ob_size
     *     ob_item == NULL implies ob_size == allocated == 0
     * list.sort() temporarily sets allocated to -1 to detect mutations.
     *
     * Items must normally not be NULL, except during construction when
     * the list is not yet visible outside the function that builds it.
     */
    Ca_ssize_t allocated;
} ;

#endif

#ifdef __cplusplus
extern "C" {
#endif




//PyAPI_DATA(PyTypeObject) PyList_Type;
//PyAPI_DATA(PyTypeObject) PyListIter_Type;
//PyAPI_DATA(PyTypeObject) PyListRevIter_Type;
//PyAPI_DATA(PyTypeObject) PySortWrapper_Type;

#define CaList_Check(op) \
    PyType_FastSubclass(Py_TYPE(op), Py_TPFLAGS_LIST_SUBCLASS)
#define PyList_CheckExact(op) (Py_TYPE(op) == &PyList_Type)

CaAPI_FUNC(CaList *) CaList_New(Ca_ssize_t size);
CaAPI_FUNC(Ca_ssize_t) CaList_Size(CaList *);
CaAPI_FUNC(CaObject *) CaList_GetItem(CaList *, Ca_ssize_t);
CaAPI_FUNC(int) CaList_SetItem(CaList *, Ca_ssize_t, CaObject *);
CaAPI_FUNC(int) CaList_Insert(CaList *, Ca_ssize_t, CaObject *);
CaAPI_FUNC(int) CaList_Append(CaList *, CaObject *);
CaAPI_FUNC(CaObject *) CaList_GetSlice(CaList *, Ca_ssize_t, Ca_ssize_t);
CaAPI_FUNC(int) CaList_SetSlice(CaList *, Ca_ssize_t, Ca_ssize_t, CaObject *);
CaAPI_FUNC(int) CaList_Sort(CaList *);
CaAPI_FUNC(int) CaList_Reverse(CaList *);
CaAPI_FUNC(CaObject *) CaList_AsTuple(CaList *);

CaAPI_FUNC(CaObject *) _CaList_Extend(CaList *, CaObject *);

CaAPI_FUNC(int) CaList_ClearFreeList(void);
CaAPI_FUNC(void) _CaList_DebugMallocStats(FILE *out);


/* Macro, trading safety for speed */

#define CaList_GET_ITEM(op, i) (((CaListObject *)(op))->ob_item[i])
#define CaList_SET_ITEM(op, i, v) (((CaListObject *)(op))->ob_item[i] = (v))
#define CaList_GET_SIZE(op)    Ca_SIZE(op)
#define _CaList_ITEMS(op)      (((CaListObject *)(op))->ob_item)


#ifdef __cplusplus
}
#endif


#endif /* INCLUDE_CA_LIST_H_ */
