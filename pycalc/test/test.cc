#include <cstdio>
#include "Parser.h"
#include <iostream>
#include <string>

using namespace py;
using namespace std;

int main(int argc, const char** argv)
{
	if (argc == 3)
	{
        if (string("t") == argv[1])
        {
            Parser tok(argv[2]);
            
            tok.SetDebugLevel(1);
            
            tok.SetDebugStream(std::cout);
            
            tok.Tokenize();
            
            std::cout << "all done" << std::endl;
            
            return 0;
            
        }
        else if(string("p") == argv[1])
        {
            Parser parser(argv[2]);
            
            parser.SetDebugLevel(1);
            
            parser.SetDebugStream(std::cout);
            
            AstPtr ast = parser.Parse();
            
            ast->Print(std::cout);
            
            std::cout << "all done" << std::endl;
            
            return 0;
            
        }
    }
    
    
    std::cout << "usage: pytest t | p filename" << std::endl;
    std::cout << "t for tokenizing, p for parsing" << std::endl;
    return -1;

}