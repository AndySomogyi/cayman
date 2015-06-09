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


    
    Parser parser(argv[1]);
    
    parser.SetDebugLevel(1);
    
    parser.SetDebugStream(std::cout);
    
	AstPtr ast = parser.Parse();
    
    std::cout << "all done" << std::endl;
}
