set(SRC
  py_tokenizer.cc
  py_parser.cc
  Lexer.cpp
  ParserContext.cpp
  AST.h
  ASTNode.h
  )
  
set(HEADERS
  AST.h
  Lexer.h
  ParserContext.h
  position.hh
  py_parser.hh
  py_token.h
  stack.hh
  ASTNode.h
  Parser.h
  location.hh
  py_errcode.h
  py_private.h
  py_tokenizer.h
  )


add_library(pycalc ${SRC} ${HEADERS})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (pycalc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})