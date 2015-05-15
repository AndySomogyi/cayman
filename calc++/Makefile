all:
	bison3 calc++-parser.yy -o calc++-parser.cc
	flex calc++-scanner.ll
	g++ lex.yy.c calc++-driver.cc  calc++-parser.cc calc++.cc -o calc++



clean:
	rm -rf rm calc++-parser.cc calc++-parser.hh
	rm -rf lex.yy.c
	rm -rf calc++
