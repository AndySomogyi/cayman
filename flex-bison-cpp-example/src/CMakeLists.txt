#FlexLexer.h             driver.cc               exprtest.txt            parser.cc               readme.dox              stack.hh
#Makefile.am             driver.h                exprtest.vcproj         parser.hh               scanner.cc              y.tab.h
#Makefile.in             expression.h            libexampleparser.vcproj parser.yy               scanner.h
#Makefile.plain          exprtest.cc             location.hh             position.hh             scanner.ll


set(SRC
  driver.cc
  parser.cc   
  scanner.cc 
  exprtest.cc
  )

set(HEADER
  FlexLexer.h
  stack.hh
  driver.h
  parser.hh
  y.tab.h
  expression.h
  scanner.h
  location.hh
  position.hh  
  )


add_executable(exprtest ${SRC} ${HEADER})