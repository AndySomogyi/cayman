/*
 * ca_runtime.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */


#include <unistd.h>
#include <Python.h>

#include "cayman_private.h"
#include "cayman_llvm.h"
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
	// initialize LLVM runtime
	llvm::InitializeNativeTarget();
	llvm::InitializeNativeTargetAsmPrinter();
	llvm::InitializeNativeTargetAsmParser();

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
    //arena = CaArena_New();
    //if (arena == NULL) {
    //    Ca_XDECREF(v);
    //    Ca_XDECREF(w);
    //    return -1;
    //}
    mod = CaParser_ASTFromFile(fp, filename,
                               Ca_single_input, ps1, ps2,
                               flags, &errcode, arena);
    Ca_XDECREF(v);
    Ca_XDECREF(w);
    if (mod == NULL) {
        CaArena_Free(arena);
        if (errcode == E_EOF) {
            CaErr_Clear();
            return E_EOF;
        }
        CaErr_Print();
        return -1;
    }
    m = CaImport_AddModule("__main__");
    if (m == NULL) {
        CaArena_Free(arena);
        return -1;
    }
    d = CaModule_GetDict(m);
    v = run_mod(mod, filename, d, d, flags, arena);
    CaArena_Free(arena);
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

int CaRun_SimpleStringFlags(const char* command, CaCompilerFlags* flags)
{
#if 0
    PyObject *m, *d, *v;
    m = PyImport_AddModule("__main__");
    if (m == NULL)
        return -1;
    d = PyModule_GetDict(m);
    v = PyRun_StringFlags(command, Py_file_input, d, d, flags);
    if (v == NULL) {
        PyErr_Print();
        return -1;
    }
    Py_DECREF(v);
    if (Py_FlushLine())
        PyErr_Clear();
    return 0;
#endif
	return 0;
}

int CaRun_SimpleFileExFlags(FILE* fp, const char* filename, int closeit,
		CaCompilerFlags* flags)
{
#if 0
    PyObject *m, *d, *v;
    const char *ext;
    int set_file_name = 0, len, ret = -1;

    m = PyImport_AddModule("__main__");
    if (m == NULL)
        return -1;
    Py_INCREF(m);
    d = PyModule_GetDict(m);
    if (PyDict_GetItemString(d, "__file__") == NULL) {
        PyObject *f = PyString_FromString(filename);
        if (f == NULL)
            goto done;
        if (PyDict_SetItemString(d, "__file__", f) < 0) {
            Py_DECREF(f);
            goto done;
        }
        set_file_name = 1;
        Py_DECREF(f);
    }
    len = strlen(filename);
    ext = filename + len - (len > 4 ? 4 : 0);
    if (maybe_pyc_file(fp, filename, ext, closeit)) {
        /* Try to run a pyc file. First, re-open in binary */
        if (closeit)
            fclose(fp);
        if ((fp = fopen(filename, "rb")) == NULL) {
            fprintf(stderr, "python: Can't reopen .pyc file\n");
            goto done;
        }
        /* Turn on optimization if a .pyo file is given */
        if (strcmp(ext, ".pyo") == 0)
            Py_OptimizeFlag = 1;
        v = run_pyc_file(fp, filename, d, d, flags);
    } else {
        v = PyRun_FileExFlags(fp, filename, Py_file_input, d, d,
                              closeit, flags);
    }
    if (v == NULL) {
        PyErr_Print();
        goto done;
    }
    Py_DECREF(v);
    if (Py_FlushLine())
        PyErr_Clear();
    ret = 0;
  done:
    if (set_file_name && PyDict_DelItemString(d, "__file__"))
        PyErr_Clear();
    Py_DECREF(m);
    return ret;

#endif
	return 0;
}


CaObject* CaRun_StringFlags(const char* str, int start, CaObject* globals, CaObject* locals, CaCompilerFlags* flags)
{
	/*
	PyObject *ret = NULL;
    mod_ty mod;
    PyArena *arena = PyArena_New();
    if (arena == NULL)
        return NULL;

    mod = PyParser_ASTFromString(str, "<string>", start, flags, arena);
    if (mod != NULL)
        ret = run_mod(mod, "<string>", globals, locals, flags, arena);
    PyArena_Free(arena);
    return ret;
	 */
	return NULL;
}

CaObject* CaRun_FileExFlags(FILE* fp, const char* filename, int start, CaObject* globals, CaObject* locals, int closeit, CaCompilerFlags* flags)
{
	/*
	PyObject *ret;
    mod_ty mod;
    PyArena *arena = PyArena_New();
    if (arena == NULL)
        return NULL;

    mod = PyParser_ASTFromFile(fp, filename, start, 0, 0,
                               flags, NULL, arena);
    if (closeit)
        fclose(fp);
    if (mod == NULL) {
        PyArena_Free(arena);
        return NULL;
    }
    ret = run_mod(mod, filename, globals, locals, flags, arena);
    PyArena_Free(arena);
    return ret;
	 */
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

int CaRun_AnyFile(FILE *fp, const char *name)
{
    return CaRun_AnyFileExFlags(fp, name, 0, NULL);
}

int CaRun_AnyFileEx(FILE *fp, const char *name, int closeit)
{
    return CaRun_AnyFileExFlags(fp, name, closeit, NULL);
}

int CaRun_AnyFileFlags(FILE *fp, const char *name, CaCompilerFlags *flags)
{
    return CaRun_AnyFileExFlags(fp, name, 0, flags);
}

CaObject* CaRun_File(FILE *fp, const char *p, int s, CaObject *g, CaObject *l)
{
    return CaRun_FileExFlags(fp, p, s, g, l, 0, NULL);
}

CaObject* CaRun_FileEx(FILE *fp, const char *p, int s, CaObject *g, CaObject *l, int c)
{
    return CaRun_FileExFlags(fp, p, s, g, l, c, NULL);
}

CaObject* CaRun_FileFlags(FILE *fp, const char *p, int s, CaObject *g, CaObject *l,
                CaCompilerFlags *flags)
{
    return CaRun_FileExFlags(fp, p, s, g, l, 0, flags);
}

int CaRun_SimpleFile(FILE *f, const char *p)
{
    return CaRun_SimpleFileExFlags(f, p, 0, NULL);
}

int CaRun_SimpleFileEx(FILE *f, const char *p, int c)
{
    return CaRun_SimpleFileExFlags(f, p, c, NULL);
}

CaObject* CaRun_String(const char *str, int s, CaObject *g, CaObject *l)
{
    return CaRun_StringFlags(str, s, g, l, NULL);
}

int CaRun_SimpleString(const char *s)
{
    return CaRun_SimpleStringFlags(s, NULL);
}

int Ca_Main(int argc, const char **argv)
{
	CaCompilerFlags cf = {0};

	int sts = CaRun_AnyFileFlags(stdin, "<stdin>", &cf) != 0;
    return sts;
}



