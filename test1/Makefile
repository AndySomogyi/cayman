all:
	bison3 waffleshop.yy
	flex waffleshop.l
	g++ lex.yy.cc Main.cpp waffleshop.tab.c -o waffleshop


clean:
	rm -rf waffleshop.tab.c waffleshop.tab.h location.hh position.hh stack.hh
	rm -rf lex.yy.cc
	rm -rf waffleshop
