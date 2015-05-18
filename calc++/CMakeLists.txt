set(SRC
  lex.yy.cc
  calc++-driver.cc
  calc++-parser.cc
  calc++.cc)

configure_file(calc++-scanner.ll calc++-scanner.ll  COPYONLY)

add_executable(calc++ ${SRC})

