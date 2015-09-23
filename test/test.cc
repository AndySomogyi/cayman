#include <cstdio>
#include "Parser.h"
#include <iostream>
#include <string>
#include "llvm_test1.h"
#include <cayman.h>
#include "cayman_test.h"
#include "cayman_llvm.h"
#include <llvm/Support/DynamicLibrary.h>

using namespace py;
using namespace std;

void printAddress(const char* name) {
    size_t a = llvm::RTDyldMemoryManager::getSymbolAddressInProcess(name);
    cout << "address of " << name << ": " << a << std::endl;
}

extern "C" double foo(double x) {
    return x + 1;
}



int main(int argc, const char** argv)
{

    llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);
    printAddress("printlf");
    printAddress("_printlf");
    printAddress("llvm_orc_initial");
    printAddress("_llvm_orc_initial");
    printAddress("printf");
    printAddress("_printf");
    
    printAddress("Ca_Initialize");
    printAddress("_Ca_Initialize");
    
    printAddress("foo");
    


    
    if (argc > 1)
    {
        if (string("k") == argv[1])
        {
            return llvm_orc_initial(argc, argv);
        }
        else if (string("ki") == argv[1])
        {
            return  llvm_orc_lazy_irgen(argc, argv);
        }
        else if(string("t1") == argv[1])
        {
            return ca_test1(argc, argv);
        }
        

        
        if (argc >= 3)
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
            else if(string("num") == argv[1])
            {
                return testNumber(argv[2]);
            }

        }
        
        return Ca_Main(argc, argv);
        
    }
    

    
    
    std::cout << "usage: pytest t | p filename | k" << std::endl;
    std::cout << "t for tokenizing, p for parsing, k for LLVM Kaleidoscope test" << std::endl;
    return -1;

}
