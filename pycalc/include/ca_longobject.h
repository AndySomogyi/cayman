#ifndef Ca_LONGOBJECT_H
#define Ca_LONGOBJECT_H

#include <ca_object.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Long (arbitrary precision) integer object interface */

typedef struct _longobject CaLongObject; /* Revealed in longintrepr.h */

CaAPI_DATA(CaTypeObject) CaLong_Type;

#define CaLong_Check(op) \
        CaType_FastSubclass(Ca_TYPE(op), Ca_TPFLAGS_LONG_SUBCLASS)
#define CaLong_CheckExact(op) (Ca_TYPE(op) == &CaLong_Type)

CaAPI_FUNC(CaObject *) CaLong_FromLong(long);
CaAPI_FUNC(CaObject *) CaLong_FromUnsignedLong(unsigned long);
CaAPI_FUNC(CaObject *) CaLong_FromSize_t(size_t);
CaAPI_FUNC(CaObject *) CaLong_FromSsize_t(Ca_ssize_t);
CaAPI_FUNC(CaObject *) CaLong_FromDouble(double);
CaAPI_FUNC(long) CaLong_AsLong(CaObject *);
CaAPI_FUNC(long) CaLong_AsLongAndOverflow(CaObject *, int *);
CaAPI_FUNC(Ca_ssize_t) CaLong_AsSsize_t(CaObject *);
CaAPI_FUNC(size_t) CaLong_AsSize_t(CaObject *);
CaAPI_FUNC(unsigned long) CaLong_AsUnsignedLong(CaObject *);
CaAPI_FUNC(unsigned long) CaLong_AsUnsignedLongMask(CaObject *);
CaAPI_FUNC(CaObject *) CaLong_GetInfo(void);

/* It may be useful in the future. I've added it in the CaInt -> CaLong
   cleanup to keep the extra information. [CH] */
#define CaLong_AS_LONG(op) CaLong_AsLong(op)

/* Issue #1983: pid_t can be longer than a C long on some systems */
#if !defined(SIZEOF_PID_T) || SIZEOF_PID_T == SIZEOF_INT
#define _Ca_PARSE_PID "i"
#define CaLong_FromPid CaLong_FromLong
#define CaLong_AsPid CaLong_AsLong
#elif SIZEOF_PID_T == SIZEOF_LONG
#define _Ca_PARSE_PID "l"
#define CaLong_FromPid CaLong_FromLong
#define CaLong_AsPid CaLong_AsLong
#elif defined(SIZEOF_LONG_LONG) && SIZEOF_PID_T == SIZEOF_LONG_LONG
#define _Ca_PARSE_PID "L"
#define CaLong_FromPid CaLong_FromLongLong
#define CaLong_AsPid CaLong_AsLongLong
#else
#error "sizeof(pid_t) is neither sizeof(int), sizeof(long) or sizeof(long long)"
#endif /* SIZEOF_PID_T */

#if SIZEOF_VOID_P == SIZEOF_INT
#  define _Ca_PARSE_INTPTR "i"
#  define _Ca_PARSE_UINTPTR "I"
#elif SIZEOF_VOID_P == SIZEOF_LONG
#  define _Ca_PARSE_INTPTR "l"
#  define _Ca_PARSE_UINTPTR "k"
#elif defined(SIZEOF_LONG_LONG) && SIZEOF_VOID_P == SIZEOF_LONG_LONG
#  define _Ca_PARSE_INTPTR "L"
#  define _Ca_PARSE_UINTPTR "K"
#else
#  error "void* different in size from int, long and long long"
#endif /* SIZEOF_VOID_P */



CaAPI_FUNC(double) CaLong_AsDouble(CaObject *);
CaAPI_FUNC(CaObject *) CaLong_FromVoidPtr(void *);
CaAPI_FUNC(void *) CaLong_AsVoidPtr(CaObject *);



CaAPI_FUNC(CaObject *) CaLong_FromString(const char *, char **, int);




/* These aren't really part of the int object, but they're handy. The
   functions are in Cayman/mystrtoul.c.
 */
CaAPI_FUNC(unsigned long) CaOS_strtoul(const char *, char **, int);
CaAPI_FUNC(long) CaOS_strtol(const char *, char **, int);

/* For use by the gcd function in mathmodule.c */
CaAPI_FUNC(CaObject *) _CaLong_GCD(CaObject *, CaObject *);

#ifdef __cplusplus
}
#endif
#endif /* !Ca_LONGOBJECT_H */
