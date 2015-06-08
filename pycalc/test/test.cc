#include <cstdio>
#include "Parser.h"
#include <iostream>

using namespace py;

int main(int argc, const char** argv)
{
	if (argc < 2)
	{
		return 0;
	}

	Parser tok(argv[1]);
    
    tok.SetDebugLevel(1);
    
    tok.SetDebugStream(std::cout);
    
    tok.Tokenize();
    
    Parser parser(argv[1]);
    
    parser.SetDebugLevel(1);
    
    parser.SetDebugStream(std::cout);
    
	AstPtr ast = parser.Parse();
}
