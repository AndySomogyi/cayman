set(API_SRC
    ca_abstract.cpp  
    ca_import.cpp
    ca_object.cpp
    ca_runtime.cpp
    ca_tupleobject.cpp
    ca_floatobject.cpp 
    ca_port.cpp
    ca_number.cpp
    ca_string.cpp
    ca_type.cpp
    ca_callable.cpp
    ca_function.cpp
    ca_eval.cpp
    ca_int.cpp
    ca_float.cpp
    )

set(SRC
  py_tokenizer.cc
  py_parser.cc
  Parser.cpp
  ParserContext.cpp
  Ast.cpp
  AstNode.cpp
  AstNodeFactory.cpp
  AstCodegen.cpp
  AstInterpreter.cpp
  Expr.cpp
  Stmt.cpp
  AstPrinter.cpp
  AstToken.cpp
  CaModule.cpp
  CaObject.cpp
  CaType.cpp
  CaInt.cpp
  CaFloat.cpp
  CaCallable.cpp
  CaFunction.cpp
  CaString.cpp
  JITContext.cpp
  LiteralSupport.cpp
  CharInfo.cpp
  llvm_test1.cpp
  llvm_orc_lazy_irgen.cpp
  llvm_orc_lazy_codegen.cpp
  llvm_orc_initial.cpp
  llvm_orc_fully_lazy.cpp
  ${API_SRC}
  )


set(HEADERS
  ${CAYMAN_PUBLIC_HEADERS}
  cayman_private.h
  Ast.h
  AstNode.h
  AstNodeFactory.h
  AstCodegen.h
  AstInterpreter.h
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
  CaObject.h
  CaModule.h
  CaType.h
  CaCallable.h
  CaFunction.h
  CaInt.h
  CaFloat.h
  CaString.h
  JITContext.h
  AstVisitor.h
  AstPrinter.h
  AstToken.h
  CharInfo.h
  LiteralSupport.h
  llvm_test1.h
  )


add_library(cayman ${SRC} ${HEADERS})

source_group("Public Header Files" FILES ${CAYMAN_PUBLIC_HEADERS})

message("CAYMAN_PUBLIC_HEADERS: ${CAYMAN_PUBLIC_HEADERS}")



# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (cayman PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against LLVM libraries
target_link_libraries(cayman ${LLVM_LIBS})

target_link_libraries(cayman ${PYTHON_LIBRARIES})
