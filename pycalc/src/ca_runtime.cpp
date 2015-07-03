/*
 * ca_runtime.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */

#include "cayman.h"
#include <unistd.h>
#include <Python.h>

#include "py_errcode.h"

int Ca_InteractiveFlag = 0;


CaObject* CaErr_Occurred(void)
{
	return NULL;
}

void Ca_Initialize(void)
{
}

void Ca_InitializeEx(int int1)
{
}

void Ca_Finalize(void)
{
}

int Ca_IsInitialized(void)
{
	return 0;
}

void CaErr_Print(void)
{
}

void CaErr_PrintEx(int int1)
{
}

int Ca_Main(int argc, char** argv)
{
}

int CaRun_AnyFile(FILE* fp, const char* filename)
{
}

int CaRun_AnyFileFlags(FILE* fp, const char* filename, CaCompilerFlags* flags)
{
}

int CaRun_AnyFileEx(FILE* fp, const char* filename, int closeit)
{
}

int CaRun_AnyFileExFlags(FILE* fp, const char* filename, int closeit,
		CaCompilerFlags* flags)
{
    if (filename == NULL)
        filename = "???";
    if (Ca_FdIsInteractive(fp, filename))
    {
        int err = CaRun_InteractiveLoopFlags(fp, filename, flags);
        if (closeit)
            fclose(fp);
        return err;
    }
    else
        return CaRun_SimpleFileExFlags(fp, filename, closeit, flags);
}


/*
 * The file descriptor fd is considered ``interactive'' if either
 *   a) isatty(fd) is TRUE, or
 *   b) the -i flag was given, and the filename associated with
 *      the descriptor is NULL or "<stdin>" or "???".
 */
int Ca_FdIsInteractive(FILE* fp, const char* filename)
{
    if (isatty((int)fileno(fp)))
        return 1;
    if (!Ca_InteractiveFlag)
        return 0;
    return (filename == NULL) ||
           (strcmp(filename, "<stdin>") == 0) ||
           (strcmp(filename, "???") == 0);
}

int CaRun_InteractiveOne(FILE* fp, const char* filename)
{
	return CaRun_InteractiveOneFlags(fp, filename, NULL);
}

int CaRun_InteractiveOneFlags(FILE *fp, const char *filename, CaCompilerFlags *flags)
{

	/*
    CaObject *m, *d, *v, *w;
    //mod_ty mod;
    //PyArena *arena;
    char *ps1 = "", *ps2 = "";
    int errcode = 0;

    v = CaSys_GetObject("ps1");
    if (v != NULL) {
        v = CaObject_Str(v);
        if (v == NULL)
            CaErr_Clear();
        else if (CaString_Check(v))
            ps1 = CaString_AsString(v);
    }
    w = CaSys_GetObject("ps2");
    if (w != NULL) {
        w = CaObject_Str(w);
        if (w == NULL)
            CaErr_Clear();
        else if (CaString_Check(w))
            ps2 = CaString_AsString(w);
    }
    //arena = PyArena_New();
    //if (arena == NULL) {
    //    Py_XDECREF(v);
    //    Py_XDECREF(w);
    //    return -1;
    //}
    mod = CaParser_ASTFromFile(fp, filename,
                               Ca_single_input, ps1, ps2,
                               flags, &errcode, arena);
    Ca_XDECREF(v);
    Ca_XDECREF(w);
    if (mod == NULL) {
        PyArena_Free(arena);
        if (errcode == E_EOF) {
            PyErr_Clear();
            return E_EOF;
        }
        CaErr_Print();
        return -1;
    }
    m = CaImport_AddModule("__main__");
    if (m == NULL) {
        PyArena_Free(arena);
        return -1;
    }
    d = CaModule_GetDict(m);
    v = run_mod(mod, filename, d, d, flags, arena);
    PyArena_Free(arena);
    if (v == NULL) {
        CaErr_Print();
        return -1;
    }
    Ca_DECREF(v);
    if (Ca_FlushLine())
        CaErr_Clear();
    return 0;
    */
	return 0;
}

int CaRun_InteractiveLoop(FILE *f, const char *p)
{
    return CaRun_InteractiveLoopFlags(f, p, NULL);
}



int CaRun_InteractiveLoopFlags(FILE *fp, const char *filename, CaCompilerFlags *flags)
{
    CaObject *v;
    int ret;
    CaCompilerFlags local_flags;

    if (flags == NULL) {
        flags = &local_flags;
        local_flags.cf_flags = 0;
    }
    v = CaSys_GetObject("ps1");
    if (v == NULL) {
        CaSys_SetObject("ps1", v = CaString_FromString(">>> "));
        Ca_XDECREF(v);
    }
    v = CaSys_GetObject("ps2");
    if (v == NULL) {
        CaSys_SetObject("ps2", v = CaString_FromString("... "));
        Ca_XDECREF(v);
    }
    for (;;) {
        ret = CaRun_InteractiveOneFlags(fp, filename, flags);
        if (ret == E_EOF)
            return 0;
    }
}

CaObject* CaSys_GetObject(const char* name)
{
	return NULL;
}

FILE* CaSys_GetFile(const char* name, FILE* def)
{
	return NULL;
}

int CaSys_SetObject(const char* name, CaObject* v)
{
	return 0;
}

int CaRun_SimpleString(const char* command)
{
	return 0;
}

int CaRun_SimpleStringFlags(const char* command, CaCompilerFlags* flags)
{
	return 0;
}

int CaRun_SimpleFile(FILE* fp, const char* filename)
{
	return 0;
}

int CaRun_SimpleFileFlags(FILE* fp, const char* filename,
		CaCompilerFlags* flags)
{
	return 0;
}

int CaRun_SimpleFileEx(FILE* fp, const char* filename, int closeit)
{
	return 0;
}

int CaRun_SimpleFileExFlags(FILE* fp, const char* filename, int closeit,
		CaCompilerFlags* flags)
{
	return 0;
}

CaObject* CaRun_String(const char* str, int start, CaObject* globals, CaObject* locals)
{
	return NULL;
}

CaObject* CaRun_StringFlags(const char* str, int start, CaObject* globals, CaObject* locals, CaCompilerFlags* flags)
{
	return NULL;
}

CaObject* CaRun_File(FILE* fp, const char* filename, int start, CaObject* globals, CaObject* locals)
{
	return NULL;
}

CaObject* CaRun_FileEx(FILE* fp, const char* filename, int start, CaObject* globals, CaObject* locals, int closeit)
{
	return NULL;
}

CaObject* CaRun_FileFlags(FILE* fp, const char* filename, int start, CaObject* globals, CaObject* locals, CaCompilerFlags* flags)
{
	return NULL;
}

CaObject* CaRun_FileExFlags(FILE* fp, const char* filename, int start, CaObject* globals, CaObject* locals, int closeit, CaCompilerFlags* flags)
{
	return NULL;
}

CaAst* CaParser_ASTFromString(const char*, const char*, int int1, CaCompilerFlags* flags, CaArena*)
{
	return NULL;
}

CaAst* CaParser_ASTFromFile(FILE*, const char*, int int1, char*, char*, CaCompilerFlags*, int*, CaArena*)
{
	return NULL;
}


