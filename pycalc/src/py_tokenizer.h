#ifndef Py_TOKENIZER_H
#define Py_TOKENIZER_H

/* Tokenizer interface */

#include "py_token.h"      /* For token types */

#define MAXINDENT 100   /* Max indentation level */

/* Tokenizer state */
struct tok_state {
    /* Input state; buf <= cur <= inp <= end */
    /* NB an entire line is held in the buffer */
    char *buf;          /* Input buffer, or NULL; malloc'ed if fp != NULL */
    char *cur;          /* Next character in buffer */
    char *inp;          /* End of data in buffer */
    char *end;          /* End of input buffer if buf != NULL */
    char *start;        /* Start of current token if not NULL */
    int done;           /* E_OK normally, E_EOF at EOF, otherwise error code */
    /* NB If done != E_OK, cur must be == inp!!! */
    FILE *fp;           /* Rest of input; NULL if tokenizing a string */
    int tabsize;        /* Tab spacing */
    int indent;         /* Current indentation index */
    int indstack[MAXINDENT];            /* Stack of indents */
    int atbol;          /* Nonzero if at begin of new line */
    int pendin;         /* Pending indents (if > 0) or dedents (if < 0) */
    char *prompt, *nextprompt;          /* For interactive prompting */
    int lineno;         /* Current line number */
    int level;          /* () [] {} Parentheses nesting level */
            /* Used to allow free continuations inside them */
    /* Stuff for checking on different tab sizes */
    const char *filename;       /* For error messages */
    int altwarning;     /* Issue warning if alternate tabs don't match */
    int alterror;       /* Issue error if alternate tabs don't match */
    int alttabsize;     /* Alternate tab spacing */
    int altindstack[MAXINDENT];         /* Stack of alternate indents */
    /* Stuff for PEP 0263 */
    int decoding_state;         /* -1:decoding, 0:init, 1:raw */
    int decoding_erred;         /* whether erred in decoding  */
    int read_coding_spec;       /* whether 'coding:...' has been read  */
    char *encoding;
    int cont_line;          /* whether we are in a continuation line. */
    const char* line_start;     /* pointer to start of current line */
//#ifndef PGEN
//    PyObject *decoding_readline; /* codecs.open(...).readline */
//    PyObject *decoding_buffer;
//#endif
    const char* enc;
    const char* str;
    const char* input; /* Tokenizer's newline translated copy of the string. */
};

tok_state *PyTokenizer_FromString(const char *, int);
tok_state *PyTokenizer_FromFile(FILE *, char *, char *);
void PyTokenizer_Free(tok_state *);


/**
 * Get the next token from the token stream. 
 *
 * If the ENDMARKER token is returned, the tok->done field will be set
 * to E_EOF.
 *
 * If there is a large block of newlines or comments after the last syntactically
 * relevant line, the tokenizer will still return and ENDMARKER after a single 
 * NEWLINE following the last code line. All remaining comments, whitespace, and
 * newlines after the last code line will be ignored.
 */
int PyTokenizer_Get(tok_state *tok, char **, char **);


char * PyTokenizer_RestoreEncoding(tok_state* tok, int len, int *offset);

int PyTokenizer_Test(const char* fname);

void tok_dump(int type, char *start, char *end);

#define PyPARSE_DONT_IMPLY_DEDENT	0x0002



#endif /* !Py_TOKENIZER_H */
