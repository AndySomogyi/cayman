/*
 * ca_number.h
 *
 *  Created on: Jul 8, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CA_NUMBER_H_
#define _INCLUDED_CA_NUMBER_H_

#include "ca_object.h"


#ifdef __cplusplus
extern "C"
{
#endif

CaAPI_FUNC(int) CaNumber_Check(CaObject *o);

/*
 Returns 1 if the object, o, provides numeric protocols, and
 false otherwise.

 This function always succeeds.
 */

CaAPI_FUNC(CaObject *) CaNumber_Add(CaObject *o1, CaObject *o2);

/*
 Returns the result of adding o1 and o2, or null on failure.
 This is the equivalent of the Cayman expression: o1+o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Subtract(CaObject *o1, CaObject *o2);

/*
 Returns the result of subtracting o2 from o1, or null on
 failure.  This is the equivalent of the Cayman expression:
 o1-o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Multiply(CaObject *o1, CaObject *o2);

/*
 Returns the result of multiplying o1 and o2, or null on
 failure.  This is the equivalent of the Cayman expression:
 o1*o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_MatrixMultiply(CaObject *o1, CaObject *o2);

/*
 This is the equivalent of the Cayman expression: o1 @ o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_FloorDivide(CaObject *o1, CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving an integral result,
 or null on failure.
 This is the equivalent of the Cayman expression: o1//o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_TrueDivide(CaObject *o1, CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving a float result,
 or null on failure.
 This is the equivalent of the Cayman expression: o1/o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Remainder(CaObject *o1, CaObject *o2);

/*
 Returns the remainder of dividing o1 by o2, or null on
 failure.  This is the equivalent of the Cayman expression:
 o1%o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Divmod(CaObject *o1, CaObject *o2);

/*
 See the built-in function divmod.  Returns NULL on failure.
 This is the equivalent of the Cayman expression:
 divmod(o1,o2).
 */

CaAPI_FUNC(CaObject *) CaNumber_Power(CaObject *o1, CaObject *o2,
		CaObject *o3);

/*
 See the built-in function pow.  Returns NULL on failure.
 This is the equivalent of the Cayman expression:
 pow(o1,o2,o3), where o3 is optional.
 */

CaAPI_FUNC(CaObject *) CaNumber_Negative(CaObject *o);

/*
 Returns the negation of o on success, or null on failure.
 This is the equivalent of the Cayman expression: -o.
 */

CaAPI_FUNC(CaObject *) CaNumber_Positive(CaObject *o);

/*
 Returns the (what?) of o on success, or NULL on failure.
 This is the equivalent of the Cayman expression: +o.
 */

CaAPI_FUNC(CaObject *) CaNumber_Absolute(CaObject *o);

/*
 Returns the absolute value of o, or null on failure.  This is
 the equivalent of the Cayman expression: abs(o).
 */

CaAPI_FUNC(CaObject *) CaNumber_Invert(CaObject *o);

/*
 Returns the bitwise negation of o on success, or NULL on
 failure.  This is the equivalent of the Cayman expression:
 ~o.
 */

CaAPI_FUNC(CaObject *) CaNumber_Lshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of left shifting o1 by o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1 << o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Rshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of right shifting o1 by o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1 >> o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_And(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise and of o1 and o2 on success, or
 NULL on failure. This is the equivalent of the Cayman
 expression: o1&o2.

 */

CaAPI_FUNC(CaObject *) CaNumber_Xor(CaObject *o1, CaObject *o2);

/*
 Returns the bitwise exclusive or of o1 by o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1^o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_Or(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise or on o1 and o2 on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: o1|o2.
 */

#define CaIndex_Check(obj) \
   ((obj)->ob_type->tp_as_number != NULL && \
    (obj)->ob_type->tp_as_number->nb_index != NULL)

CaAPI_FUNC(CaObject *) CaNumber_Index(CaObject *o);

/*
 Returns the object converted to a Cayman int
 or NULL with an error raised on failure.
 */

CaAPI_FUNC(Ca_ssize_t) CaNumber_AsSsize_t(CaObject *o, CaObject *exc);

/*
 Returns the object converted to Ca_ssize_t by going through
 CaNumber_Index first.  If an overflow error occurs while
 converting the int to Ca_ssize_t, then the second argument
 is the error-type to return.  If it is NULL, then the overflow error
 is cleared and the value is clipped.
 */

CaAPI_FUNC(CaObject *) CaNumber_Long(CaObject *o);

/*
 Returns the o converted to an integer object on success, or
 NULL on failure.  This is the equivalent of the Cayman
 expression: int(o).
 */

CaAPI_FUNC(CaObject *) CaNumber_Float(CaObject *o);

/*
 Returns the o converted to a float object on success, or NULL
 on failure.  This is the equivalent of the Cayman expression:
 float(o).
 */

/*  In-place variants of (some of) the above number protocol functions */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceAdd(CaObject *o1, CaObject *o2);

/*
 Returns the result of adding o2 to o1, possibly in-place, or null
 on failure.  This is the equivalent of the Cayman expression:
 o1 += o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceSubtract(CaObject *o1, CaObject *o2);

/*
 Returns the result of subtracting o2 from o1, possibly in-place or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 -= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceMultiply(CaObject *o1, CaObject *o2);

/*
 Returns the result of multiplying o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 *= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceMatrixMultiply(CaObject *o1, CaObject *o2);

/*
 This is the equivalent of the Cayman expression: o1 @= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceFloorDivide(CaObject *o1,
		CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving an integral result,
 possibly in-place, or null on failure.
 This is the equivalent of the Cayman expression:
 o1 /= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceTrueDivide(CaObject *o1,
		CaObject *o2);

/*
 Returns the result of dividing o1 by o2 giving a float result,
 possibly in-place, or null on failure.
 This is the equivalent of the Cayman expression:
 o1 /= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceRemainder(CaObject *o1, CaObject *o2);

/*
 Returns the remainder of dividing o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 %= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlacePower(CaObject *o1, CaObject *o2,
		CaObject *o3);

/*
 Returns the result of raising o1 to the power of o2, possibly
 in-place, or null on failure.  This is the equivalent of the Cayman
 expression: o1 **= o2, or pow(o1, o2, o3) if o3 is present.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceLshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of left shifting o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 <<= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceRshift(CaObject *o1, CaObject *o2);

/*
 Returns the result of right shifting o1 by o2, possibly in-place or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 >>= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceAnd(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise and of o1 and o2, possibly in-place,
 or null on failure. This is the equivalent of the Cayman
 expression: o1 &= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceXor(CaObject *o1, CaObject *o2);

/*
 Returns the bitwise exclusive or of o1 by o2, possibly in-place, or
 null on failure.  This is the equivalent of the Cayman expression:
 o1 ^= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_InPlaceOr(CaObject *o1, CaObject *o2);

/*
 Returns the result of bitwise or of o1 and o2, possibly in-place,
 or null on failure.  This is the equivalent of the Cayman
 expression: o1 |= o2.
 */

CaAPI_FUNC(CaObject *) CaNumber_ToBase(CaObject *n, int base);

/*
 Returns the integer n converted to a string with a base, with a base
 marker of 0b, 0o or 0x prefixed if applicable.
 If n is not an int object, it is converted with CaNumber_Index first.
 */

#ifdef __cplusplus
}
#endif



#endif /* _INCLUDED_CA_NUMBER_H_ */
