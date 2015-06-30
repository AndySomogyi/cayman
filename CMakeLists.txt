project(BisonTesting)

cmake_minimum_required(VERSION 2.5)

##
# Search for the LLVMConfig.cmake file which is included as part of
# LLVM 3.5 and newer
#

unset(LLVMCONFIG_PATH CACHE)

# the LLVMConfig.cmake from brew
file(GLOB_RECURSE _LLVMCONFIG_FILES  FOLLOW_SYMLINKS TRUE "/usr/local/opt/llvm/*/LLVMConfig.cmake")

# TODO check for list length
list(LENGTH _LLVMCONFIG_FILES _LLVMCONFIG_FILES_LEN)

list(GET _LLVMCONFIG_FILES 0 _LLVMCONFIG_FILE)

# TODO add to cache CACHE
# get_filename_component wants the ${} around the loc, doesn't work otherwise
# at least on cmake 3.2.3
get_filename_component(_LLVMCONFIG_DIR ${_LLVMCONFIG_FILE} DIRECTORY)

list(APPEND CMAKE_MODULE_PATH "${_LLVMCONFIG_DIR}")
list(APPEND CMAKE_PREFIX_PATH "${_LLVMCONFIG_DIR}")

message("_LLVMCONFIG_FILE: ${_LLVMCONFIG_FILE}")
message("_LLVMCONFIG_FILES_LEN: ${_LLVMCONFIG_FILES_LEN}")
message("_LLVMCONFIG_FILE: ${_LLVMCONFIG_FILE}")
message("_LLVMCONFIG_DIR: ${_LLVMCONFIG_DIR}")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

find_package(LLVM CONFIG)

unset(_LLVMCONFIG_FILE)
unset(_LLVMCONFIG_FILES_LEN)
unset(_LLVMCONFIG_FILE)
unset(_LLVMCONFIG_DIR)


message("Found LLVM ${LLVM_PACKAGE_VERSION}")
message("Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(LLVM_LIBS core mcjit native)


message("LLVM_CMAKE_DIR: ${LLVM_CMAKE_DIR}")
message("LLVM_DEFINITIONS: ${LLVM_DEFINITIONS}")
message("LLVM_ENABLE_ASSERTIONS: ${LLVM_ENABLE_ASSERTIONS}")
message("LLVM_ENABLE_EH: ${LLVM_ENABLE_EH}")
message("LLVM_ENABLE_RTTI: ${LLVM_ENABLE_RTTI}")
message("LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message("LLVM_PACKAGE_VERSION: ${LLVM_PACKAGE_VERSION}")
message("LLVM_TOOLS_BINARY_DIR: ${LLVM_TOOLS_BINARY_DIR}")
message("LLVM_LIBS: ${LLVM_LIBS}")



##
# need to enable C++ 11 mode for LLVM, MSVC >= 2012 is C++ 11 by default
#
# 

message("compiler id: ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_COMPILER_IS_GNUCXX: ${CMAKE_COMPILER_IS_GNUCXX}")

# Compiler-specific C++11 activation.
if (CMAKE_COMPILER_IS_GNUCXX)
  message("Found gcc compiler, version : ${GXX_VERSION}")
  if (NOT (GXX_VERSION VERSION_GREATER 4.7 OR GXX_VERSION VERSION_EQUAL 4.7))
    message(FATAL_ERROR "${PROJECT_NAME} requires g++ 4.7 or greater.")
  endif ()

  # set gcc compiler flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")

  # not sure how to get clang version from cmake
  execute_process(COMMAND ${CMAKE_C_COMPILER} --version OUTPUT_VARIABLE CLANG_VERSION)
  message("Found clang compiler, version: ${CLANG_VERSION}")
  
  # set clang compiler flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
else ()
  message(FATAL_ERROR "Your C++ compiler does not support C++11.")
endif ()


if(CMAKE_GENERATOR STREQUAL Xcode)
  message("Xcode build")
  set(CMAKE_XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
endif()


#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED on)
#add_definitions(-std=c++11 -stdlib=libc++)


#add_subdirectory(calc++)
#add_subdirectory(flex-bison-cpp-example)
#add_subdirectory(mfcalc)
#add_subdirectory(rpcalc)
#add_subdirectory(test1)
#add_subdirectory(python)
add_subdirectory(pycalc)