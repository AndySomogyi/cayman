set(SRC
  py_tokenizer.cc
  )
  
set(HEADERS
  py_token.h
  py_tokenizer.h
  )


add_library(pycalc ${SRC} ${HEADERS})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (pycalc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})