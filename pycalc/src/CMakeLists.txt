set(SRC
  py_tokenizer.cc
  py_parser.cc
  Parser.cpp
  ParserContext.cpp
  Ast.cpp
  AstNode.cpp
  AstNodeFactory.cpp
  Expr.cpp
  Stmt.cpp
  AstPrinter.cpp
  )
  
set(HEADERS
  Ast.h
  AstNode.h
  AstNodeFactory.h
  ParserContext.h
  position.hh
  py_parser.hh
  py_token.h
  stack.hh
  Parser.h
  location.hh
  py_errcode.h
  py_private.h
  py_tokenizer.h
  Expr.h
  Stmt.h
  AstVisitor.h
  AstPrinter.h
  )


add_library(pycalc ${SRC} ${HEADERS})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (pycalc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})