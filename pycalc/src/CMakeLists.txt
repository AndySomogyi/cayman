set(API_SRC
    ca_abstract.cpp  
    ca_import.cpp
    ca_object.cpp
    ca_runtime.cpp
    ca_tupleobject.cpp
    ca_floatobject.cpp 
    ca_longobject.cpp
    ca_port.cpp
    ca_string.cpp
    )

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
  AstToken.cpp
  llvm_test1.cpp
  llvm_orc_lazy_irgen.cpp
  llvm_orc_lazy_codegen.cpp
  llvm_orc_initial.cpp
  llvm_orc_fully_lazy.cpp
  ${API_SRC}
  )


set(HEADERS
  ${CAYMAN_PUBLIC_HEADERS}
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
  AstToken.h
  llvm_test1.h
  )


add_library(pycalc ${SRC} ${HEADERS})

source_group("Public Header Files" FILES ${CAYMAN_PUBLIC_HEADERS})

message("CAYMAN_PUBLIC_HEADERS: ${CAYMAN_PUBLIC_HEADERS}")



# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (pycalc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against LLVM libraries
target_link_libraries(pycalc ${LLVM_LIBS})

target_link_libraries(pycalc ${PYTHON_LIBRARIES})
