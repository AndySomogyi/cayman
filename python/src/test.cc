#include <stdio.h>

#include "py_tokenizer.h"

int main(int argc, const char** argv)
{
	if (argc < 2)
	{
		return 0;
	}

	PyTokenizer_Test(argv[1]);
}
