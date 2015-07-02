/*
 * ca_runtime.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDE_CA_RUNTIME_H_
#define _INCLUDE_CA_RUNTIME_H_

#include <ca_port.h>



#ifdef __cplusplus
extern "C" {
#endif


CaAPI_FUNC(wchar_t *) Ca_GetProgramName(void);

CaAPI_FUNC(void) Ca_SetCaymanHome(wchar_t *);
CaAPI_FUNC(wchar_t *) Ca_GetCaymanHome(void);


CaAPI_FUNC(void) Ca_Initialize(void);
CaAPI_FUNC(void) Ca_InitializeEx(int);

CaAPI_FUNC(void) Ca_Finalize(void);
CaAPI_FUNC(int) Ca_IsInitialized(void);





/* Ca_CaAtExit is for the atexit module, Ca_AtExit is for low-level
 * exit functions.
 */

CaAPI_FUNC(int) Ca_AtExit(void (*func)(void));

CaAPI_FUNC(void) Ca_Exit(int);

/* Restore signals that the interpreter has called SIG_IGN on to SIG_DFL. */


/* Bootstrap __main__ (defined in Modules/main.c) */
CaAPI_FUNC(int) Ca_Main(int argc, wchar_t **argv);

/* In getpath.c */
CaAPI_FUNC(wchar_t *) Ca_GetProgramFullPath(void);
CaAPI_FUNC(wchar_t *) Ca_GetPrefix(void);
CaAPI_FUNC(wchar_t *) Ca_GetExecPrefix(void);
CaAPI_FUNC(wchar_t *) Ca_GetPath(void);
CaAPI_FUNC(void)      Ca_SetPath(const wchar_t *);


/* In their own files */
CaAPI_FUNC(const char *) Ca_GetVersion(void);
CaAPI_FUNC(const char *) Ca_GetPlatform(void);
CaAPI_FUNC(const char *) Ca_GetCopyright(void);
CaAPI_FUNC(const char *) Ca_GetCompiler(void);
CaAPI_FUNC(const char *) Ca_GetBuildInfo(void);



/* Signals */
typedef void (*CaOS_sighandler_t)(int);
CaAPI_FUNC(CaOS_sighandler_t) CaOS_getsig(int);
CaAPI_FUNC(CaOS_sighandler_t) CaOS_setsig(int, CaOS_sighandler_t);

/* Random */
CaAPI_FUNC(int) _CaOS_URandom (void *buffer, Ca_ssize_t size);


CaAPI_FUNC(void) CaErr_Print(void);
CaAPI_FUNC(void) CaErr_PrintEx(int);
CaAPI_FUNC(void) CaErr_Display(CaObject *, CaObject *, CaObject *);

CaAPI_FUNC(void) CaErr_SetString(
    CaObject *exception,
    const char *string   /* decoded from utf-8 */
    );
CaAPI_FUNC(CaObject *) CaErr_Occurred(void);
CaAPI_FUNC(void) CaErr_Clear(void);
CaAPI_FUNC(void) CaErr_Fetch(CaObject **, CaObject **, CaObject **);
CaAPI_FUNC(void) CaErr_Restore(CaObject *, CaObject *, CaObject *);
CaAPI_FUNC(void) CaErr_GetExcInfo(CaObject **, CaObject **, CaObject **);
CaAPI_FUNC(void) CaErr_SetExcInfo(CaObject *, CaObject *, CaObject *);



#ifdef __cplusplus
}
#endif


#endif /* _INCLUDE_CA_RUNTIME_H_ */
