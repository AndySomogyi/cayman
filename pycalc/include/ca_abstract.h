#ifndef Ca_ABSTRACTOBJECT_H
#define Ca_ABSTRACTOBJECT_H

#include <ca_object.h>

#ifdef __cplusplus
extern "C"
{
#endif



/* new buffer API */

CaAPI_FUNC(CaObject *) CaObject_Format(CaObject* obj,
		CaObject *format_spec);
/*
 Takes an arbitrary object and returns the result of
 calling obj.__format__(format_spec).
 */

/* Iterators */

CaAPI_FUNC(CaObject *) CaObject_GetIter(CaObject *);
/* Takes an object and returns an iterator for it.
 This is typically a new iterator but if the argument
 is an iterator, this returns itself. */

#define CaIter_Check(obj) \
    ((obj)->ob_type->tp_iternext != NULL && \
     (obj)->ob_type->tp_iternext != &_CaObject_NextNotImplemented)

CaAPI_FUNC(CaObject *) CaIter_Next(CaObject *);
/* Takes an iterator object and calls its tp_iternext slot,
 returning the next value.  If the iterator is exhausted,
 this returns NULL without setting an exception.
 NULL with an exception means an error occurred. */


/*  Sequence protocol:*/

CaAPI_FUNC(int) CaSequence_Check(CaObject *o);

/*
 Return 1 if the object provides sequence protocol, and zero
 otherwise.

 This function always succeeds.
 */

CaAPI_FUNC(Ca_ssize_t) CaSequence_Size(CaObject *o);

/*
 Return the size of sequence object o, or -1 on failure.
 */

/* For DLL compatibility */
#undef CaSequence_Length
CaAPI_FUNC(Ca_ssize_t) CaSequence_Length(CaObject *o);
#define CaSequence_Length CaSequence_Size

CaAPI_FUNC(CaObject *) CaSequence_Concat(CaObject *o1, CaObject *o2);

/*
 Return the concatenation of o1 and o2 on success, and NULL on
 failure.   This is the equivalent of the Cayman
 expression: o1+o2.
 */

CaAPI_FUNC(CaObject *) CaSequence_Repeat(CaObject *o, Ca_ssize_t count);

/*
 Return the result of repeating sequence object o count times,
 or NULL on failure.  This is the equivalent of the Cayman
 expression: o1*count.
 */

CaAPI_FUNC(CaObject *) CaSequence_GetItem(CaObject *o, Ca_ssize_t i);

/*
 Return the ith element of o, or NULL on failure. This is the
 equivalent of the Cayman expression: o[i].
 */

CaAPI_FUNC(CaObject *) CaSequence_GetSlice(CaObject *o, Ca_ssize_t i1, Ca_ssize_t i2);

/*
 Return the slice of sequence object o between i1 and i2, or
 NULL on failure. This is the equivalent of the Cayman
 expression: o[i1:i2].
 */

CaAPI_FUNC(int) CaSequence_SetItem(CaObject *o, Ca_ssize_t i, CaObject *v);

/*
 Assign object v to the ith element of o.  Returns
 -1 on failure.  This is the equivalent of the Cayman
 statement: o[i]=v.
 */

CaAPI_FUNC(int) CaSequence_DelItem(CaObject *o, Ca_ssize_t i);

/*
 Delete the ith element of object v.  Returns
 -1 on failure.  This is the equivalent of the Cayman
 statement: del o[i].
 */

CaAPI_FUNC(int) CaSequence_SetSlice(CaObject *o, Ca_ssize_t i1, Ca_ssize_t i2,
		CaObject *v);

/*
 Assign the sequence object, v, to the slice in sequence
 object, o, from i1 to i2.  Returns -1 on failure. This is the
 equivalent of the Cayman statement: o[i1:i2]=v.
 */

CaAPI_FUNC(int) CaSequence_DelSlice(CaObject *o, Ca_ssize_t i1, Ca_ssize_t i2);

/*
 Delete the slice in sequence object, o, from i1 to i2.
 Returns -1 on failure. This is the equivalent of the Cayman
 statement: del o[i1:i2].
 */

CaAPI_FUNC(CaObject *) CaSequence_Tuple(CaObject *o);

/*
 Returns the sequence, o, as a tuple on success, and NULL on failure.
 This is equivalent to the Cayman expression: tuple(o)
 */

CaAPI_FUNC(CaObject *) CaSequence_List(CaObject *o);
/*
 Returns the sequence, o, as a list on success, and NULL on failure.
 This is equivalent to the Cayman expression: list(o)
 */

CaAPI_FUNC(CaObject *) CaSequence_Fast(CaObject *o, const char* m);
/*
 Return the sequence, o, as a list, unless it's already a
 tuple or list.  Use CaSequence_Fast_GET_ITEM to access the
 members of this list, and CaSequence_Fast_GET_SIZE to get its length.

 Returns NULL on failure.  If the object does not support iteration,
 raises a TypeError exception with m as the message text.
 */

#define CaSequence_Fast_GET_SIZE(o) \
    (CaList_Check(o) ? CaList_GET_SIZE(o) : CaTuple_GET_SIZE(o))
/*
 Return the size of o, assuming that o was returned by
 CaSequence_Fast and is not NULL.
 */

#define CaSequence_Fast_GET_ITEM(o, i)\
     (CaList_Check(o) ? CaList_GET_ITEM(o, i) : CaTuple_GET_ITEM(o, i))
/*
 Return the ith element of o, assuming that o was returned by
 CaSequence_Fast, and that i is within bounds.
 */

#define CaSequence_ITEM(o, i)\
    ( Ca_TYPE(o)->tp_as_sequence->sq_item(o, i) )
/* Assume tp_as_sequence and sq_item exist and that i does not
 need to be corrected for a negative index
 */

#define CaSequence_Fast_ITEMS(sf) \
    (CaList_Check(sf) ? ((CaListObject *)(sf))->ob_item \
                      : ((CaTupleObject *)(sf))->ob_item)
/* Return a pointer to the underlying item array for
 an object retured by CaSequence_Fast */

CaAPI_FUNC(Ca_ssize_t) CaSequence_Count(CaObject *o, CaObject *value);

/*
 Return the number of occurrences on value on o, that is,
 return the number of keys for which o[key]==value.  On
 failure, return -1.  This is equivalent to the Cayman
 expression: o.count(value).
 */

CaAPI_FUNC(int) CaSequence_Contains(CaObject *seq, CaObject *ob);
/*
 Return -1 if error; 1 if ob in seq; 0 if ob not in seq.
 Use __contains__ if possible, else _CaSequence_IterSearch().
 */

/* For DLL-level backwards compatibility */
#undef CaSequence_In
CaAPI_FUNC(int) CaSequence_In(CaObject *o, CaObject *value);

/* For source-level backwards compatibility */
#define CaSequence_In CaSequence_Contains

/*
 Determine if o contains value.  If an item in o is equal to
 X, return 1, otherwise return 0.  On error, return -1.  This
 is equivalent to the Cayman expression: value in o.
 */

CaAPI_FUNC(Ca_ssize_t) CaSequence_Index(CaObject *o, CaObject *value);

/*
 Return the first index for which o[i]=value.  On error,
 return -1.    This is equivalent to the Cayman
 expression: o.index(value).
 */

/* In-place versions of some of the above Sequence functions. */

CaAPI_FUNC(CaObject *) CaSequence_InPlaceConcat(CaObject *o1, CaObject *o2);

/*
 Append o2 to o1, in-place when possible. Return the resulting
 object, which could be o1, or NULL on failure.  This is the
 equivalent of the Cayman expression: o1 += o2.

 */

CaAPI_FUNC(CaObject *) CaSequence_InPlaceRepeat(CaObject *o, Ca_ssize_t count);

/*
 Repeat o1 by count, in-place when possible. Return the resulting
 object, which could be o1, or NULL on failure.  This is the
 equivalent of the Cayman expression: o1 *= count.

 */

/*  Mapping protocol:*/

CaAPI_FUNC(int) CaMapping_Check(CaObject *o);

/*
 Return 1 if the object provides mapping protocol, and zero
 otherwise.

 This function always succeeds.
 */

CaAPI_FUNC(Ca_ssize_t) CaMapping_Size(CaObject *o);

/*
 Returns the number of keys in object o on success, and -1 on
 failure.  For objects that do not provide sequence protocol,
 this is equivalent to the Cayman expression: len(o).
 */

/* For DLL compatibility */
#undef CaMapping_Length
CaAPI_FUNC(Ca_ssize_t) CaMapping_Length(CaObject *o);
#define CaMapping_Length CaMapping_Size

/* implemented as a macro:

 int CaMapping_DelItemString(CaObject *o, const char *key);

 Remove the mapping for object, key, from the object *o.
 Returns -1 on failure.  This is equivalent to
 the Cayman statement: del o[key].
 */
#define CaMapping_DelItemString(O,K) CaObject_DelItemString((O),(K))

/* implemented as a macro:

 int CaMapping_DelItem(CaObject *o, CaObject *key);

 Remove the mapping for object, key, from the object *o.
 Returns -1 on failure.  This is equivalent to
 the Cayman statement: del o[key].
 */
#define CaMapping_DelItem(O,K) CaObject_DelItem((O),(K))

CaAPI_FUNC(int) CaMapping_HasKeyString(CaObject *o, const char *key);

/*
 On success, return 1 if the mapping object has the key, key,
 and 0 otherwise.  This is equivalent to the Cayman expression:
 key in o.

 This function always succeeds.
 */

CaAPI_FUNC(int) CaMapping_HasKey(CaObject *o, CaObject *key);

/*
 Return 1 if the mapping object has the key, key,
 and 0 otherwise.  This is equivalent to the Cayman expression:
 key in o.

 This function always succeeds.

 */

CaAPI_FUNC(CaObject *) CaMapping_Keys(CaObject *o);

/*
 On success, return a list or tuple of the keys in object o.
 On failure, return NULL.
 */

CaAPI_FUNC(CaObject *) CaMapping_Values(CaObject *o);

/*
 On success, return a list or tuple of the values in object o.
 On failure, return NULL.
 */

CaAPI_FUNC(CaObject *) CaMapping_Items(CaObject *o);

/*
 On success, return a list or tuple of the items in object o,
 where each item is a tuple containing a key-value pair.
 On failure, return NULL.

 */

CaAPI_FUNC(CaObject *) CaMapping_GetItemString(CaObject *o,
		const char *key);

/*
 Return element of o corresponding to the object, key, or NULL
 on failure. This is the equivalent of the Cayman expression:
 o[key].
 */

CaAPI_FUNC(int) CaMapping_SetItemString(CaObject *o, const char *key,
		CaObject *value);

/*
 Map the object, key, to the value, v.  Returns
 -1 on failure.  This is the equivalent of the Cayman
 statement: o[key]=v.
 */



#ifdef __cplusplus
}
#endif

#endif /* Ca_ABSTRACTOBJECT_H */
