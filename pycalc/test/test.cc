#include <cstdio>
#include "Parser.h"

using namespace py;

int main(int argc, const char** argv)
{
	if (argc < 2)
	{
		return 0;
	}

	Parser parser(argv[1]);

	AstPtr ast = parser.Parse();
}
