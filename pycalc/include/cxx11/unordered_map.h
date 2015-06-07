#ifndef _INCLUDED_CXX11_UNORDERED_MAP_H_
#define _INCLUDED_CXX11_UNORDERED_MAP_H_

/** 
 * @brief A proxy for maintaining compatibility across C++ std library versions
 * @details C++11 moved tr1 headers and classes into the standard namespace,
 * hence no use for a tr1 prefix.
 */

#include "cxx11_ns.h"

#if __APPLE__ && __clang__
  // is Mavericks
  #if (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9) || (__cplusplus >= 201103L)
    #include <unordered_map>
  #else
    #include <tr1/unordered_map>
  #endif                                                   // OSX ver
#else                                                      // not __APPLE__
  #if (__cplusplus >= 201103L) || defined(_MSC_VER)
    #include <unordered_map>
  #else
    #include <tr1/unordered_map>
  #endif
#endif                                                     // __APPLE__

#endif //  _INCLUDED_CXX11_UNORDERED_MAP_H_
