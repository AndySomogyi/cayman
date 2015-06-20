/* Token types */

#ifndef Py_TOKEN_H
#define Py_TOKEN_H
#ifdef __cplusplus
extern "C"
{
#endif

#undef TILDE   /* Prevent clash of our definition with system macro. Ex AIX, ioctl.h */


namespace pytoken {

enum _tok
{
	ENDMARKER = 0,
	NAME = 1,
	NUMBER = 2,
	STRING = 3,
	NEWLINE = 4,
	INDENT = 5,
	DEDENT = 6,
	LPAR = 7,
	RPAR = 8,
	LSQB = 9,
	RSQB = 10,
	COLON = 11,
	COMMA = 12,
	SEMI = 13,
	PLUS = 14,
	MINUS = 15,
	STAR = 16,
	SLASH = 17,
	VBAR = 18,
	AMPER = 19,
	LESS = 20,
	GREATER = 21,
	EQUAL = 22,
	DOT = 23,
	PERCENT = 24,
	BACKQUOTE = 25,
	LBRACE = 26,
	RBRACE = 27,
	EQEQUAL = 28,
	NOTEQUAL = 29,
	LESSEQUAL = 30,
	GREATEREQUAL = 31,
	TILDE = 32,
	CIRCUMFLEX = 33,
	LEFTSHIFT = 34,
	RIGHTSHIFT = 35,
	DOUBLESTAR = 36,
	PLUSEQUAL = 37,
	MINEQUAL = 38,
	STAREQUAL = 39,
	SLASHEQUAL = 40,
	PERCENTEQUAL = 41,
	AMPEREQUAL = 42,
	VBAREQUAL = 43,
	CIRCUMFLEXEQUAL = 44,
	LEFTSHIFTEQUAL = 45,
	RIGHTSHIFTEQUAL = 46,
	DOUBLESTAREQUAL = 47,
	DOUBLESLASH = 48,
	DOUBLESLASHEQUAL = 49,
	AT = 50,
    LARROW = 51,
    RARROW = 52,
	ELLIPSIS = 53,
	/* Don't forget to update the table _PyParser_TokenNames in tokenizer.c! */
	OP = 54,

    ERRORTOKEN = 55,
	N_TOKENS = 56
};

}

/* Special definitions for cooperation with parser */

#define NT_OFFSET 256

#define ISTERMINAL(x)		((x) < NT_OFFSET)
#define ISNONTERMINAL(x)	((x) >= NT_OFFSET)
#define ISEOF(x)		((x) == TOK_ENDMARKER)

int PyToken_OneChar(int);
int PyToken_TwoChars(int, int);
int PyToken_ThreeChars(int, int, int);

#ifdef __cplusplus
}
#endif
#endif /* !Py_TOKEN_H */
