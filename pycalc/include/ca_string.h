/*
 * ca_string.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDE_CA_STRING_H_
#define _INCLUDE_CA_STRING_H_

#include <ca_port.h>


/* Decode a null-terminated string using Ca_FileSystemDefaultEncoding
   and the "surrogateescape" error handler.

   If Ca_FileSystemDefaultEncoding is not set, fall back to the locale
   encoding.

   Use CaUnicode_DecodeFSDefaultAndSize() if the string length is known.
*/

CaAPI_FUNC(CaObject*) CaUnicode_DecodeFSDefault(
    const char *s               /* encoded string */
    );



#endif /* _INCLUDE_CA_STRING_H_ */
