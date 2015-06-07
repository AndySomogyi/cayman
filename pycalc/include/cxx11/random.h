#ifndef _INCLUDED_CXX11_RANDOM_H_
#define _INCLUDED_CXX11_RANDOM_H_

/**
 * @brief A proxy for maintaining compatibility across C++ std library versions
 * @details C++11 moved tr1 headers and classes into the standard namespace,
 * hence no use for a tr1 prefix.
 */

#include "cxx11_ns.h"

#if __APPLE__ && __clang__
  // is Mavericks
  #if (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9) || (__cplusplus >= 201103L)
    #include <random>
    // mavericks forces C++ 11 random generator.
    #define CXX11_RANDOM
  #else
    #include <tr1/random>
  #endif                                                    // OSX ver
#else                                                       // not __APPLE__
  #if (__cplusplus >= 201103L) || defined(_MSC_VER)
    #include <random>
  #else
    #include <tr1/random>
  #endif
  // MSVC can use either C++ 11 random or C++ tr1 random
  #if (__cplusplus >= 201103L)
    #define CXX11_RANDOM
  #endif

#endif                                                     // __APPLE__

#endif // _INCLUDED_CXX11_RANDOM_H_
