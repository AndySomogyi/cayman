
/* Module definition and import interface */

#ifndef Ca_IMPORT_H
#define Ca_IMPORT_H

#include <ca_port.h>

#ifdef __cplusplus
extern "C" {
#endif



CaAPI_FUNC(long) CaImport_GetMagicNumber(void);
CaAPI_FUNC(const char *) CaImport_GetMagicTag(void);
CaAPI_FUNC(CaObject *) CaImport_ExecCodeModule(
    const char *name,           /* UTF-8 encoded string */
    CaObject *co
    );
CaAPI_FUNC(CaObject *) CaImport_ExecCodeModuleEx(
    const char *name,           /* UTF-8 encoded string */
    CaObject *co,
    const char *pathname        /* decoded from the filesystem encoding */
    );
CaAPI_FUNC(CaObject *) CaImport_ExecCodeModuleWithPathnames(
    const char *name,           /* UTF-8 encoded string */
    CaObject *co,
    const char *pathname,       /* decoded from the filesystem encoding */
    const char *cpathname       /* decoded from the filesystem encoding */
    );
CaAPI_FUNC(CaObject *) CaImport_ExecCodeModuleObject(
    CaObject *name,
    CaObject *co,
    CaObject *pathname,
    CaObject *cpathname
    );
CaAPI_FUNC(CaObject *) CaImport_GetModuleDict(void);
CaAPI_FUNC(CaObject *) CaImport_AddModuleObject(
    CaObject *name
    );
CaAPI_FUNC(CaObject *) CaImport_AddModule(
    const char *name            /* UTF-8 encoded string */
    );
CaAPI_FUNC(CaObject *) CaImport_ImportModule(
    const char *name            /* UTF-8 encoded string */
    );
CaAPI_FUNC(CaObject *) CaImport_ImportModuleNoBlock(
    const char *name            /* UTF-8 encoded string */
    );
CaAPI_FUNC(CaObject *) CaImport_ImportModuleLevel(
    const char *name,           /* UTF-8 encoded string */
    CaObject *globals,
    CaObject *locals,
    CaObject *fromlist,
    int level
    );
CaAPI_FUNC(CaObject *) CaImport_ImportModuleLevelObject(
    CaObject *name,
    CaObject *globals,
    CaObject *locals,
    CaObject *fromlist,
    int level
    );

#define CaImport_ImportModuleEx(n, g, l, f) \
    CaImport_ImportModuleLevel(n, g, l, f, 0)

CaAPI_FUNC(CaObject *) CaImport_GetImporter(CaObject *path);
CaAPI_FUNC(CaObject *) CaImport_Import(CaObject *name);
CaAPI_FUNC(CaObject *) CaImport_ReloadModule(CaObject *m);
CaAPI_FUNC(void) CaImport_Cleanup(void);
CaAPI_FUNC(int) CaImport_ImportFrozenModuleObject(
    CaObject *name
    );
CaAPI_FUNC(int) CaImport_ImportFrozenModule(
    const char *name            /* UTF-8 encoded string */
    );


CaAPI_DATA(CaTypeObject) CaNullImporter_Type;

CaAPI_FUNC(int) CaImport_AppendInittab(
    const char *name,           /* ASCII encoded string */
    CaObject* (*initfunc)(void)
    );



#ifdef __cplusplus
}
#endif
#endif /* !Ca_IMPORT_H */
