/*
 * ParserContext.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#include "ParserContext.h"
#include "py_tokenizer.h"
#include "py_errcode.h"
#include "py_token.h"
#include <cstring>

namespace py
{


ParserContext::ParserContext(const std::string& uri):
    ast(new Ast()),
    ts(NULL),
    parser(*this),
    file(NULL),
    flags(0), started(0), error(0)
{
	file = fopen(uri.c_str(), "r");
	ts = PyTokenizer_FromFile(file, NULL, NULL);
}

ParserContext::ParserContext(std::ostream& inpt):
    ast(new Ast()),
    ts(NULL),
    parser(*this),
    file(NULL),
    flags(0), started(0), error(0)
{
}

ParserContext::~ParserContext()
{
    fclose(file);
	PyTokenizer_Free(ts);
}


void ParserContext::Error(const py_parser::location_type& l, const std::string& m)
{
	std::cout << "oh crap, loc: " << l << ", err: " << m << std::endl;

}


#define tok py_parser::token

std::string dump_done(int done)
{
    switch (done)
    {
    case E_OK: return "E_OK";
    case E_EOF: return "E_EOF"; //		11	/* End Of File */
    case E_INTR: return "E_INTR"; //		12	/* Interrupted */
    case E_TOKEN: return "E_TOKEN"; //		13	/* Bad token */
    case E_SYNTAX: return "E_SYNTAX"; //	14	/* Syntax error */
    case E_NOMEM: return "E_NOMEM"; //		15	/* Ran out of memory */
    case E_DONE: return "E_DONE"; //		16	/* Parsing complete */
    case E_ERROR: return "E_ERROR"; //		17	/* Execution error */
    case E_TABSPACE: return "E_TABSPACE"; //	18	/* Inconsistent mixing of tabs and spaces */
    case E_OVERFLOW: return "E_OVERFLOW"; //      19	/* Node had too many children */
    case E_TOODEEP: return "E_TOODEEP"; //	20	/* Too many indentation levels */
    case E_DEDENT: return "E_DEDENT"; //	21	/* No matching outer block for dedent */
    case E_DECODE: return "E_DECODE"; //	22	/* Error in decoding into Unicode */
    case E_EOFS: return "E_EOFS"; //		23	/* EOF in triple-quoted string */
    case E_EOLS: return "E_EOLS"; //		24	/* EOL in single-quoted string */
    case E_LINECONT: return "E_LINECONT"; //	25	/* Unexpected characters after a line continuation */
    default: return "UNKNOWN ERROR CODE";
    }
}



int yylex(py_parser::semantic_type* node, py_parser::location_type* loc,
		ParserContext& ctx)
{
	char *a, *b;
    pytoken::_tok type;
	size_t len;
	char *str;
	int col_offset;
	int result = tok::ENDMARKER;
    
    if (ctx.ts->done == E_EOF) {
        *node = NULL;
        
        return 0;
    }

	type = (pytoken::_tok)PyTokenizer_Get(ctx.ts, &a, &b);
    std::cout << "status: " << dump_done(ctx.ts->done) << std::endl;
    
#if 0
    
	if (type == pytoken::ERRORTOKEN || type == EOF || type == pytoken::ENDMARKER)
	{
		ctx.error = ctx.ts->done;
		//break;
	}
	if (type == pytoken::ENDMARKER && ctx.started)
	{
		type = pytoken::NEWLINE; /* Add an extra newline */
		ctx.started = 0;
		/* Add the right number of dedent tokens,
		 except if a certain flag is given --
		 codeop.py uses this. */
		if (ctx.ts->indent && !(*(ctx.flags) & PyPARSE_DONT_IMPLY_DEDENT))
		{
			ctx.ts->pendin = -ctx.ts->indent;
			ctx.ts->indent = 0;
		}
	}
	else
	{
		ctx.started = 1;
	}
    
#endif
    
	len = b - a; /* XXX this may compute NULL - NULL */
	str = (char *) malloc(len + 1);
	if (str == NULL)
	{
		fprintf(stderr, "no mem for next token\n");
		ctx.error = E_NOMEM;
		//break;
	}
	if (len > 0)
		strncpy(str, a, len);
	str[len] = '\0';

	if (a >= ctx.ts->line_start)
		col_offset = a - ctx.ts->line_start;
	else
		col_offset = -1;

	// TODO calc end pos of token
	*loc = location(position(NULL, ctx.ts->lineno, col_offset));

	// print token
	tok_dump(type, a, b);

	*node = NULL;


	switch (type)
	{
	case pytoken::ENDMARKER:
		result = tok::ENDMARKER;
		break;
	case pytoken::NAME:

		if (strncmp(a, "def", 3) == 0)
		{
			result = tok::DEF;
		}
		else
		{
			result = tok::NAME;
		}
		*node = ctx.ast->CreateName(*loc, a, b);
		break;
	case pytoken::NUMBER:
		result = tok::NUMBER;
		*node = ctx.ast->CreateNum(*loc, a, b);
		break;
	case pytoken::STRING:
		result = tok::STRING;
		break;
	case pytoken::NEWLINE:
		result = tok::NEWLINE;
		break;
	case pytoken::INDENT:
		result = tok::INDENT;
		break;
	case pytoken::DEDENT:
		result = tok::DEDENT;
		break;
	case pytoken::LPAR:
		result = tok::LPAR;
		break;
	case pytoken::RPAR:
		result = tok::RPAR;
		break;
	case pytoken::LSQB:
		result = tok::LSQB;
		break;
	case pytoken::RSQB:
		result = tok::RSQB;
		break;
	case pytoken::COLON:
		result = tok::COLON;
		break;
	case pytoken::COMMA:
		result = tok::COMMA;
		break;
	case pytoken::SEMI:
		result = tok::SEMI;
		break;
	case pytoken::PLUS:
		result = tok::PLUS;
		break;
	case pytoken::MINUS:
		result = tok::MINUS;
		break;
	case pytoken::STAR:
		result = tok::STAR;
		break;
	case pytoken::SLASH:
		result = tok::SLASH;
		break;
	case pytoken::VBAR:
		result = tok::VBAR;
		break;
	case pytoken::AMPER:
		result = tok::AMPER;
		break;
	case pytoken::LESS:
		result = tok::LESS;
		break;
	case pytoken::GREATER:
		result = tok::GREATER;
		break;
	case pytoken::EQUAL:
		result = tok::EQUAL;
		break;
	case pytoken::DOT:
		result = tok::DOT;
		break;
	case pytoken::PERCENT:
		result = tok::PERCENT;
		break;
	case pytoken::BACKQUOTE:
		result = tok::BACKQUOTE;
		break;
	case pytoken::LBRACE:
		result = tok::LBRACE;
		break;
	case pytoken::RBRACE:
		result = tok::RBRACE;
		break;
	case pytoken::EQEQUAL:
		result = tok::EQEQUAL;
		break;
	case pytoken::NOTEQUAL:
		result = tok::NOTEQUAL;
		break;
	case pytoken::LESSEQUAL:
		result = tok::LESSEQUAL;
		break;
	case pytoken::GREATEREQUAL:
		result = tok::GREATEREQUAL;
		break;
	case pytoken::TILDE:
		result = tok::TILDE;
		break;
	case pytoken::CIRCUMFLEX:
		result = tok::CIRCUMFLEX;
		break;
	case pytoken::LEFTSHIFT:
		result = tok::LEFTSHIFT;
		break;
	case pytoken::RIGHTSHIFT:
		result = tok::RIGHTSHIFT;
		break;
	case pytoken::DOUBLESTAR:
		result = tok::DOUBLESTAR;
		break;
	case pytoken::PLUSEQUAL:
		result = tok::PLUSEQUAL;
		break;
	case pytoken::MINEQUAL:
		result = tok::MINEQUAL;
		break;
	case pytoken::STAREQUAL:
		result = tok::STAREQUAL;
		break;
	case pytoken::SLASHEQUAL:
		result = tok::SLASHEQUAL;
		break;
	case pytoken::PERCENTEQUAL:
		result = tok::PERCENTEQUAL;
		break;
	case pytoken::AMPEREQUAL:
		result = tok::AMPEREQUAL;
		break;
	case pytoken::VBAREQUAL:
		result = tok::VBAREQUAL;
		break;
	case pytoken::CIRCUMFLEXEQUAL:
		result = tok::CIRCUMFLEXEQUAL;
		break;
	case pytoken::LEFTSHIFTEQUAL:
		result = tok::LEFTSHIFTEQUAL;
		break;
	case pytoken::RIGHTSHIFTEQUAL:
		result = tok::RIGHTSHIFTEQUAL;
		break;
	case pytoken::DOUBLESTAREQUAL:
		result = tok::DOUBLESTAREQUAL;
		break;
	case pytoken::DOUBLESLASH:
		result = tok::DOUBLESLASH;
		break;
	case pytoken::DOUBLESLASHEQUAL:
		result = tok::DOUBLESLASHEQUAL;
		break;
	case pytoken::AT:
		result = tok::AT;
		break;
	case pytoken::OP:
		result = 0;
		break;
	case pytoken::ERRORTOKEN:
		result = 0;
		break;
	default:
		result = 0;
		break;
	}

	return result;
}

#undef tok

struct perrdetail {
	int error;
#ifndef PGEN
	/* The filename is useless for pgen, see comment in tok_state structure */
	char *filename;
#endif
	int lineno;
	int offset;
	char *text;                 /* UTF-8-encoded string */
	int token;
	int expected;
};

// static node *
//parsetok(struct tok_state *tok, grammar *g, int start, perrdetail *err_ret,
//         int *flags)
//{

#if 0

int parsetok(tok_state *tok, int start, perrdetail *err_ret, int *flags)
{
	//parser_state *ps;
	//node *n;
	int started = 0;

	//if ((ps = PyParser_New(g, start)) == NULL) {
	//    err_ret->error = E_NOMEM;
	//    PyTokenizer_Free(tok);
	//    return NULL;
	//}
#ifdef PY_PARSER_REQUIRES_FUTURE_KEYWORD
	if (*flags & PyPARSE_BARRY_AS_BDFL)
	ps->p_flags |= CO_FUTURE_BARRY_AS_BDFL;
#endif

	for (;;)
	{
		char *a, *b;
		int type;
		size_t len;
		char *str;
		int col_offset;

		type = PyTokenizer_Get(tok, &a, &b);

		// break out of loop for syntax error
		if (type == pytoken::ERRORTOKEN)
		{
			err_ret->error = tok->done;
			break;
		}
		if (type == pytoken::ENDMARKER && started)
		{
			type = pytoken::NEWLINE; /* Add an extra newline */
			started = 0;
			/* Add the right number of dedent tokens,
			 except if a certain flag is given --
			 codeop.py uses this. */
			if (tok->indent && !(*flags & PyPARSE_DONT_IMPLY_DEDENT))
			{
				tok->pendin = -tok->indent;
				tok->indent = 0;
			}
		}
		else
		{
			started = 1;
		}
		len = b - a; /* XXX this may compute NULL - NULL */
		str = (char *) malloc(len + 1);
		if (str == NULL)
		{
			err_ret->error = E_NOMEM;
			break;
		}
		if (len > 0)
			strncpy(str, a, len);
		str[len] = '\0';

#ifdef PY_PARSER_REQUIRES_FUTURE_KEYWORD
		if (type == NOTEQUAL)
		{
			if (!(ps->p_flags & CO_FUTURE_BARRY_AS_BDFL) &&
					strcmp(str, "!="))
			{
				PyObject_FREE(str);
				err_ret->error = E_SYNTAX;
				break;
			}
			else if ((ps->p_flags & CO_FUTURE_BARRY_AS_BDFL) &&
					strcmp(str, "<>"))
			{
				PyObject_FREE(str);
				err_ret->text = "with Barry as BDFL, use '<>' "
				"instead of '!='";
				err_ret->error = E_SYNTAX;
				break;
			}
		}
#endif
		if (a >= tok->line_start)
		{
			col_offset = (int) (a - tok->line_start);
		}
		else
		{
			col_offset = -1;
		}

		if ((err_ret->error = PyParser_AddToken(ps, (int) type, str,
				tok->lineno, col_offset, &(err_ret->expected))) != E_OK)
		{
			if (err_ret->error != E_DONE)
			{
				free(str);
				err_ret->token = type;
			}
			break;
		}
	}

	if (err_ret->error == E_DONE)
	{
		n = ps->p_tree;
		ps->p_tree = NULL;

#ifndef PGEN
		/* Check that the source for a single input statement really
		 is a single statement by looking at what is left in the
		 buffer after parsing.  Trailing whitespace and comments
		 are OK.  */
		if (start == single_input)
		{
			char *cur = tok->cur;
			char c = *tok->cur;

			for (;;)
			{
				while (c == ' ' || c == '\t' || c == '\n' || c == '\014')
					c = *++cur;

				if (!c)
					break;

				if (c != '#')
				{
					err_ret->error = E_BADSINGLE;
					PyNode_Free (n);
					n = NULL;
					break;
				}

				/* Suck up comment. */
				while (c && c != '\n')
					c = *++cur;
			}
		}
#endif
	}
	else
		n = NULL;

#ifdef PY_PARSER_REQUIRES_FUTURE_KEYWORD
	*flags = ps->p_flags;
#endif
	PyParser_Delete (ps);

	if (n == NULL)
	{
		if (tok->done == E_EOF)
			err_ret->error = E_EOF;
		err_ret->lineno = tok->lineno;
		if (tok->buf != NULL)
		{
			size_t len;
			assert(tok->cur - tok->buf < INT_MAX);
			err_ret->offset = (int) (tok->cur - tok->buf);
			len = tok->inp - tok->buf;
			err_ret->text = (char *) PyObject_MALLOC(len + 1);
			if (err_ret->text != NULL)
			{
				if (len > 0)
					strncpy(err_ret->text, tok->buf, len);
				err_ret->text[len] = '\0';
			}
		}
	}
	else if (tok->encoding != NULL)
	{
		/* 'nodes->n_str' uses PyObject_*, while 'tok->encoding' was
		 * allocated using PyMem_
		 */
		node* r = PyNode_New(encoding_decl);
		if (r)
			r->n_str = PyObject_MALLOC(strlen(tok->encoding) + 1);
		if (!r || !r->n_str)
		{
			err_ret->error = E_NOMEM;
			if (r)
				PyObject_FREE(r);
			n = NULL;
			goto done;
		}
		strcpy(r->n_str, tok->encoding);
		PyMem_FREE(tok->encoding);
		tok->encoding = NULL;
		r->n_nchildren = 1;
		r->n_child = n;
		n = r;
	}

	done: PyTokenizer_Free(tok);

	return n;
}

#endif

} /* namespace py */


