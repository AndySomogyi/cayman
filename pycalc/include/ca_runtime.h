/*
 * ca_runtime.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDE_CA_RUNTIME_H_
#define _INCLUDE_CA_RUNTIME_H_

#include <ca_port.h>
#include <ca_object.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
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



/* In getpath.c */
CaAPI_FUNC(wchar_t *) Ca_GetProgramFullPath(void);
CaAPI_FUNC(wchar_t *) Ca_GetPrefix(void);
CaAPI_FUNC(wchar_t *) Ca_GetExecPrefix(void);
CaAPI_FUNC(wchar_t *) Ca_GetPath(void);
CaAPI_FUNC(void) Ca_SetPath(const wchar_t *);

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
		const char *string /* decoded from utf-8 */
);

/**
 * Test whether the error indicator is set. If set, return the exception type
 * (the first argument to the last call to one of the CaErr_Set*() functions or to CaErr_Restore()).
 * If not set, return NULL. You do not own a reference to the return value,
 * so you do not need to Ca_DECREF() it.
 */
CaAPI_FUNC(CaObject *) CaErr_Occurred(void);


CaAPI_FUNC(void) CaErr_Clear(void);
CaAPI_FUNC(void) CaErr_Fetch(CaObject **, CaObject **, CaObject **);
CaAPI_FUNC(void) CaErr_Restore(CaObject *, CaObject *, CaObject *);
CaAPI_FUNC(void) CaErr_GetExcInfo(CaObject **, CaObject **, CaObject **);
CaAPI_FUNC(void) CaErr_SetExcInfo(CaObject *, CaObject *, CaObject *);

/**

 *************************
 The Very High Level Layer
 *************************

 The functions in this chapter will let you execute Cathon source code given in a
 file or a buffer, but they will not let you interact in a more detailed way with
 the interpreter.

 Several of these functions accept a start symbol from the grammar as a
 parameter.  The available start symbols are :const:`Ca_eval_input`,
 :const:`Ca_file_input`, and :const:`Ca_single_input`.  These are described
 following the functions which accept them as parameters.

 Note also that several of these functions take :c:type:`FILE\*` parameters.  One
 particular issue which needs to be handled carefully is that the :c:type:`FILE`
 structure for different C libraries can be different and incompatible.  Under
 Windows (at least), it is possible for dynamically linked extensions to actually
 use different libraries, so care should be taken that :c:type:`FILE\*` parameters
 are only passed to these functions if it is certain that they were created by
 the same library that the Cathon runtime is using.
 */


/**
 * Return true (nonzero) if the standard I/O file fp with name filename is deemed interactive.
 * This is the case for files for which "isatty(fileno(fp))" is true. If the global flag
 * Ca_InteractiveFlag is true, this function also returns true if the filename pointer is
 * NULL or if the name is equal to one of the strings '<stdin>' or '???'.
 */
CaAPI_FUNC(int) Ca_FdIsInteractive(FILE *, const char *);

/**
 * The main program for the standard interpreter.  This is made available for
 * programs which embed Cathon.  The *argc* and *argv* parameters should be
 * prepared exactly as those which are passed to a C program's :c:func:`main`
 * function.  It is important to note that the argument list may be modified (but
 * the contents of the strings pointed to by the argument list are not). The return
 * value will be ``0`` if the interpreter exits normally (ie, without an
 * exception), ``1`` if the interpreter exits due to an exception, or ``2``
 * if the parameter list does not represent a valid Cathon command line.
 *
 * Note that if an otherwise unhandled :exc:`SystemExit` is raised, this
 * function will not return ``1``, but exit the process, as long as
 * ``Ca_InspectFlag`` is not set.
 */
CaAPI_FUNC(int) Ca_Main(int argc, char **argv);

/**
 * This is a simplified interface to :c:func:`CaRun_AnyFileExFlags` below, leaving
 * closeit* set to ``0`` and *flags* set to *NULL*.
 */
CaAPI_FUNC(int) CaRun_AnyFile(FILE *fp, const char *filename);

typedef struct
{
	int cf_flags; /* bitmask of CO_xxx flags relevant to future */
} CaCompilerFlags;

/**
 * This is a simplified interface to :c:func:`CaRun_AnyFileExFlags` below, leaving
 * the *closeit* argument set to ``0``.
 */

CaAPI_FUNC(int) CaRun_AnyFileFlags(FILE *fp, const char *filename,
		CaCompilerFlags *flags);

/**
 * This is a simplified interface to :c:func:`CaRun_AnyFileExFlags` below, leaving
 * the *flags* argument set to *NULL*.
 */
CaAPI_FUNC(int) CaRun_AnyFileEx(FILE *fp, const char *filename, int closeit);

/**
 * If *fp* refers to a file associated with an interactive device (console or
 * terminal input or Unix pseudo-terminal), return the value of
 * :c:func:`CaRun_InteractiveLoop`, otherwise return the result of
 * :c:func:`CaRun_SimpleFile`.  If *filename* is *NULL*, this function uses
 * ``"???"`` as the filename.
 */
CaAPI_FUNC(int) CaRun_AnyFileExFlags(FILE *fp, const char *filename,
		int closeit, CaCompilerFlags *flags);

/**
 * This is a simplified interface to :c:func:`CaRun_SimpleStringFlags` below,
 * leaving the *CaCompilerFlags\** argument set to NULL.
 */

CaAPI_FUNC(int) CaRun_SimpleString(const char *command);

/**
 Executes the cayman source code from *command* in the :mod:`__main__` module
 according to the *flags* argument. If :mod:`__main__` does not already exist, it
 is created.  Returns ``0`` on success or ``-1`` if an exception was raised.  If
 there was an error, there is no way to get the exception information. For the
 meaning of *flags*, see below.

 Note that if an otherwise unhandled :exc:`SystemExit` is raised, this
 function will not return ``-1``, but exit the process, as long as
 ``Ca_InspectFlag`` is not set.
 */
CaAPI_FUNC(int) CaRun_SimpleStringFlags(const char *command,
		CaCompilerFlags *flags);

/**
 This is a simplified interface to :c:func:`CaRun_SimpleFileExFlags` below,
 leaving *closeit* set to ``0`` and *flags* set to *NULL*.
 */
CaAPI_FUNC(int) CaRun_SimpleFile(FILE *fp, const char *filename);

/**
 This is a simplified interface to :c:func:`CaRun_SimpleFileExFlags` below,
 leaving *closeit* set to ``0``.
 */
CaAPI_FUNC(int) CaRun_SimpleFileFlags(FILE *fp, const char *filename,
		CaCompilerFlags *flags);

/**
 This is a simplified interface to :c:func:`CaRun_SimpleFileExFlags` below,
 leaving *flags* set to *NULL*.
 */
CaAPI_FUNC(int) CaRun_SimpleFileEx(FILE *fp, const char *filename, int closeit);

/**
 Similar to :c:func:`CaRun_SimpleStringFlags`, but the Cathon source code is read
 from *fp* instead of an in-memory string. *filename* should be the name of the
 file.  If *closeit* is true, the file is closed before CaRun_SimpleFileExFlags
 returns.

 */
CaAPI_FUNC(int) CaRun_SimpleFileExFlags(FILE *fp, const char *filename,
		int closeit, CaCompilerFlags *flags);

/**
 * This is a simplified interface to :c:func:`CaRun_InteractiveOneFlags` below,
 * leaving *flags* set to *NULL*.
 */
CaAPI_FUNC(int) CaRun_InteractiveOne(FILE *fp, const char *filename);

/**
 * Read and execute a single statement from a file associated with an
 * interactive device according to the *flags* argument.  The user will be
 * prompted using ``sys.ps1`` and ``sys.ps2``.  Returns ``0`` when the input was
 * executed successfully, ``-1`` if there was an exception, or an error code
 * from the :file:`errcode.h` include file distributed as part of Cathon if
 * there was a parse error.  (Note that :file:`errcode.h` is not included by
 * :file:`cayman.h`, so must be included specifically if needed.)
 */
CaAPI_FUNC(int) CaRun_InteractiveOneFlags(FILE *fp, const char *filename,
		CaCompilerFlags *flags);

/**
 * This is a simplified interface to :c:func:`CaRun_InteractiveLoopFlags` below,
 * leaving *flags* set to *NULL*.
 */
CaAPI_FUNC(int) CaRun_InteractiveLoop(FILE *fp, const char *filename);

/**
 * Read and execute statements from a file associated with an interactive device
 * until EOF is reached.  The user will be prompted using ``sys.ps1`` and
 * ``sys.ps2``.  Returns ``0`` at EOF.
 */
CaAPI_FUNC(int) CaRun_InteractiveLoopFlags(FILE *fp, const char *filename,
		CaCompilerFlags *flags);

/*

 CaAPI_FUNC(struct) _node* CaParser_SimpleParseString(const char *str,
 int start);

 This is a simplified interface to
 :c:func:`CaParser_SimpleParseStringFlagsFilename` below, leaving  *filename* set
 to *NULL* and *flags* set to ``0``.


 CaAPI_FUNC(struct) _node* CaParser_SimpleParseStringFlags( const char *str,
 int start, int flags);

 This is a simplified interface to
 :c:func:`CaParser_SimpleParseStringFlagsFilename` below, leaving  *filename* set
 to *NULL*.


 CaAPI_FUNC(struct) _node* CaParser_SimpleParseStringFlagsFilename( const char *str,
 const char *filename, int start, int flags);

 Parse Cathon source code from *str* using the start token *start* according to
 the *flags* argument.  The result can be used to create a code object which can
 be evaluated efficiently. This is useful if a code fragment must be evaluated
 many times.


 CaAPI_FUNC(struct) _node* CaParser_SimpleParseFile(FILE *fp, const char
 *filename, int start);

 This is a simplified interface to :c:func:`CaParser_SimpleParseFileFlags` below,
 leaving *flags* set to ``0``


 CaAPI_FUNC(struct) _node* CaParser_SimpleParseFileFlags(FILE *fp, const char
 *filename, int start, int flags);

 Similar to :c:func:`CaParser_SimpleParseStringFlagsFilename`, but the Cathon
 source code is read from *fp* instead of an in-memory string.
 */

/**
 * This is a simplified interface to :c:func:`CaRun_StringFlags` below, leaving
 * *flags* set to *NULL*.
 */
CaAPI_FUNC(CaObject*) CaRun_String(const char *str, int start, CaObject *globals,
		CaObject *locals);

/*
 Execute Cathon source code from *str* in the context specified by the
 dictionaries *globals* and *locals* with the compiler flags specified by
 *flags*.  The parameter *start* specifies the start token that should be used to
 parse the source code.

 Returns the result of executing the code as a Cathon object, or *NULL* if an
 exception was raised.
 */
CaAPI_FUNC(CaObject*) CaRun_StringFlags(const char *str, int start,
		CaObject *globals, CaObject *locals, CaCompilerFlags *flags);

/*
 This is a simplified interface to :c:func:`CaRun_FileExFlags` below, leaving
 *closeit* set to ``0`` and *flags* set to *NULL*.

 */

CaAPI_FUNC(CaObject*) CaRun_File(FILE *fp, const char *filename, int start,
		CaObject *globals, CaObject *locals);

/*
 This is a simplified interface to :c:func:`CaRun_FileExFlags` below, leaving
 *flags* set to *NULL*.
 */
CaAPI_FUNC(CaObject*) CaRun_FileEx(FILE *fp, const char *filename, int start,
		CaObject *globals, CaObject *locals, int closeit);

/*
 This is a simplified interface to :c:func:`CaRun_FileExFlags` below, leaving
 *closeit* set to ``0``.

 */
CaAPI_FUNC(CaObject*) CaRun_FileFlags(FILE *fp, const char *filename, int start,
		CaObject *globals, CaObject *locals, CaCompilerFlags *flags);

/*

 Similar to :c:func:`CaRun_StringFlags`, but the Cathon source code is read from
 *fp* instead of an in-memory string. *filename* should be the name of the file.
 If *closeit* is true, the file is closed before :c:func:`CaRun_FileExFlags`
 returns.

 */

CaAPI_FUNC(CaObject*) CaRun_FileExFlags(FILE *fp, const char *filename, int start,
		CaObject *globals, CaObject *locals, int closeit, CaCompilerFlags *flags);

/*
 This is a simplified interface to :c:func:`Ca_CompileStringFlags` below, leaving
 *flags* set to *NULL*.
 */

CaAPI_FUNC(CaObject*) Ca_CompileString(const char *str, const char *filename,
		int start);

/*
 Parse and compile the Cathon source code in *str*, returning the resulting code
 object.  The start token is given by *start*; this can be used to constrain the
 code which can be compiled and should be :const:`Ca_eval_input`,
 :const:`Ca_file_input`, or :const:`Ca_single_input`.  The filename specified by
 *filename* is used to construct the code object and may appear in tracebacks or
 :exc:`SyntaxError` exception messages.  This returns *NULL* if the code cannot
 be parsed or compiled.

 */

CaAPI_FUNC(CaObject*) Ca_CompileStringFlags(const char *str, const char *filename,
		int start, CaCompilerFlags *flags);

/*
 This is a simplified interface to :c:func:`CaEval_EvalCodeEx`, with just
 the code object, and the dictionaries of global and local variables.
 The other arguments are set to *NULL*.


 CaAPI_FUNC(CaObject*) CaEval_EvalCode(CaCodeObject *co, CaObject *globals,
 CaObject *locals);



 Evaluate a precompiled code object, given a particular environment for its
 evaluation.  This environment consists of dictionaries of global and local
 variables, arrays of arguments, keywords and defaults, and a closure tuple of
 cells.

 CaAPI_FUNC(CaObject*) CaEval_EvalCodeEx(CaCodeObject *co, CaObject *globals, C
 aObject *locals,  CaObject **args, int argcount, CaObject **kws, int kwcount,
 CaObject **defs, int defcount, CaObject *closure);



 Evaluate an execution frame.  This is a simplified interface to
 CaEval_EvalFrameEx, for backward compatibility.


 CaAPI_FUNC(CaObject*) CaEval_EvalFrame(CaFrameObject *f);


 CaAPI_FUNC(CaObject*) CaEval_EvalFrameEx(CaFrameObject *f, int throwflag);

 This is the main, unvarnished function of Cathon interpretation.  It is
 literally 2000 lines long.  The code object associated with the execution
 frame *f* is executed, interpreting bytecode and executing calls as needed.
 The additional *throwflag* parameter can mostly be ignored - if true, then
 it causes an exception to immediately be thrown; this is used for the
 :meth:`~generator.throw` methods of generator objects.


 CaAPI_FUNC(int) CaEval_MergeCompilerFlags(CaCompilerFlags *cf);

 This function changes the flags of the current evaluation frame, and returns
 true on success, false on failure.


 */


/**
 * System Functions
 * These are utility functions that make functionality from the sys module accessible to C code.
 * They all work with the current interpreter thread’s sys module’s dict, which is contained in
 * the internal thread state structure.
 */

/**
 * Return value: Borrowed reference.
Return the object name from the sys module or NULL if it does not exist, without setting an exception.
 */
CaAPI_FUNC(CaObject*) CaSys_GetObject(const char *name);

/**
 * Return the FILE* associated with the object name in the sys module, or def if name is
 * not in the module or is not associated with a FILE*.
 */
CaAPI_FUNC(FILE*) CaSys_GetFile(const char *name, FILE *def);

/**
 * Set name in the sys module to v unless v is NULL, in which case name is deleted from
 * the sys module. Returns 0 on success, -1 on error.
 */
CaAPI_FUNC(int) CaSys_SetObject(const char *name, CaObject *v);

struct CaArena;

struct CaAst;


CaAPI_FUNC(CaAst*) CaParser_ASTFromString(const char *, const char *,
                                                 int, CaCompilerFlags *flags,
                                                 CaArena *);

CaAPI_FUNC(CaAst*) CaParser_ASTFromFile(FILE *, const char *, int,
                                               char *, char *,
                                               CaCompilerFlags *, int *,
                                               CaArena *);

#ifdef __cplusplus
}
#endif

#endif /* _INCLUDE_CA_RUNTIME_H_ */
