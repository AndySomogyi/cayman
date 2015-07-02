/*
 * ca_import.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDE_CA_IMPORT_H_
#define _INCLUDE_CA_IMPORT_H_

typedef size_t         Ca_ssize_t;



/* Declarations for symbol visibility.

  CaAPI_FUNC(type): Declares a public Cayman API function and return type
  CaAPI_DATA(type): Declares public Cayman data and its type
  CaMODINIT_FUNC:   A Cayman module init function.  If these functions are
                    inside the Cayman core, they are private to the core.
                    If in an extension module, it may be declared with
                    external linkage depending on the platform.

  As a number of platforms support/require "__declspec(dllimport/dllexport)",
  we support a HAVE_DECLSPEC_DLL macro to save duplication.
*/

/*
  All windows ports, except cygwin, are handled in PC/pyconfig.h.

  Cygwin is the only other autoconf platform requiring special
  linkage handling and it uses __declspec().
*/
#if defined(__CYGWIN__)
#       define HAVE_DECLSPEC_DLL
#endif

/* only get special linkage if built as shared or platform is Cygwin */
#if defined(Ca_ENABLE_SHARED) || defined(__CYGWIN__)
#       if defined(HAVE_DECLSPEC_DLL)
#               ifdef Ca_BUILD_CORE
#                       define CaAPI_FUNC(RTYPE) __declspec(dllexport) RTYPE
#                       define CaAPI_DATA(RTYPE) extern __declspec(dllexport) RTYPE
        /* module init functions inside the core need no external linkage */
        /* except for Cygwin to handle embedding */
#                       if defined(__CYGWIN__)
#                               define CaMODINIT_FUNC __declspec(dllexport) CaObject*
#                       else /* __CYGWIN__ */
#                               define CaMODINIT_FUNC CaObject*
#                       endif /* __CYGWIN__ */
#               else /* Ca_BUILD_CORE */
        /* Building an extension module, or an embedded situation */
        /* public Cayman functions and data are imported */
        /* Under Cygwin, auto-import functions to prevent compilation */
        /* failures similar to those described at the bottom of 4.1: */
        /* http://docs.python.org/extending/windows.html#a-cookbook-approach */
#                       if !defined(__CYGWIN__)
#                               define CaAPI_FUNC(RTYPE) __declspec(dllimport) RTYPE
#                       endif /* !__CYGWIN__ */
#                       define CaAPI_DATA(RTYPE) extern __declspec(dllimport) RTYPE
        /* module init functions outside the core must be exported */
#                       if defined(__cplusplus)
#                               define CaMODINIT_FUNC extern "C" __declspec(dllexport) CaObject*
#                       else /* __cplusplus */
#                               define CaMODINIT_FUNC __declspec(dllexport) CaObject*
#                       endif /* __cplusplus */
#               endif /* Ca_BUILD_CORE */
#       endif /* HAVE_DECLSPEC */
#endif /* Ca_ENABLE_SHARED */

/* If no external linkage macros defined by now, create defaults */
#ifndef CaAPI_FUNC
#       define CaAPI_FUNC(RTYPE) RTYPE
#endif
#ifndef CaAPI_DATA
#       define CaAPI_DATA(RTYPE) extern RTYPE
#endif
#ifndef CaMODINIT_FUNC
#       if defined(__cplusplus)
#               define CaMODINIT_FUNC extern "C" CaObject*
#       else /* __cplusplus */
#               define CaMODINIT_FUNC CaObject*
#       endif /* __cplusplus */
#endif


#endif /* _INCLUDE_CA_IMPORT_H_ */


