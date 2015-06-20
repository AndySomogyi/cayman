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
    flags(0), started(0), error(0), pending(0)
{
	file = fopen(uri.c_str(), "r");
	ts = PyTokenizer_FromFile(file, NULL, NULL);
}

ParserContext::ParserContext(std::ostream& inpt):
    ast(new Ast()),
    ts(NULL),
    parser(*this),
    file(NULL),
    flags(0), started(0), error(0), pending(0)
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
    
    *node = NULL;
    *loc = location();
    
    //if (ctx.ts->done == E_EOF) {
    //    *node = NULL;
    //
    //    return 0;
    //}
    


	type = (pytoken::_tok)PyTokenizer_Get(ctx.ts, &a, &b);
    
    std::cout << std::endl << "* tokstatus: " << dump_done(ctx.ts->done) <<
    ", pendin: " << ctx.ts->pendin << ", indent: " << ctx.ts->indent << ", tok: ";
    tok_dump(type, a, b);
    std::cout << std::endl;
    
    // break out of loop for syntax error
    if (type == pytoken::ERRORTOKEN)
    {
        //err_ret->error = tok->done;
        // TODO raise error
        //break;
        return 0;
    }

    // check if end, and return the two extra tokens the parser expects,
    // a endmarker, and eof, endmarker from tokenizer was eaten below.
    if (type == pytoken::ENDMARKER && ctx.pending > 0)
    {
    	if (ctx.pending == 2)
    	{
    		ctx.pending = 1;
    		return tok::ENDMARKER;
    	}

    	// return EOF to parser, done with stream.
    	return 0;
    }


    if (type == pytoken::ENDMARKER && ctx.started)
    {
        ctx.started = 0;
        
        // pending ENDMARKER and EOF
        ctx.pending = 2;
        /* Add the right number of dedent tokens,
         except if a certain flag is given --
         codeop.py uses this.

         setting tokenzier->pending causes the tokenizer to return a
         stream of dedent/ indent tokens untill the pending tokens are
         cleared.
         */
        if (ctx.ts->indent ) // && !(*flags & PyPARSE_DONT_IMPLY_DEDENT))
        {
            ctx.ts->pendin = -ctx.ts->indent;
            ctx.ts->indent = 0;
        }

        /* Add an extra newline, not sure why this is needed, but cpython does it.  */
        return tok::NEWLINE;
    }
    else
    {
        ctx.started = 1;
        ctx.pending = 0;
    }
    
    
	if (a >= ctx.ts->line_start)
		col_offset = a - ctx.ts->line_start;
	else
		col_offset = -1;

	// TODO calc end pos of token
	*loc = location(position(NULL, ctx.ts->lineno, col_offset));

	// print token
	

	*node = NULL;


    // TODO, make sure its OK to strncmp to length len+1!!!

	switch (type)
	{
	case pytoken::ENDMARKER:
		result = tok::ENDMARKER;
		break;
	case pytoken::NAME:
        {
            std::string str(a, b);
            if (str == "def")
            {
                result = tok::DEF;
            }
            else if (str == "in")
            {
                result = tok::IN;
            }
            else if (str == "for")
            {
                result = tok::FOR;
            }
            else if(str == "if")
            {
                result = tok::IF;
            }
            else if(str == "else")
            {
                result = tok::ELSE;
            }
            else if(str == "elif")
            {
                result = tok::ELIF;
            }
            else if (str == "and")
            {
                result = tok::AND;
            }
            else if (str == "or")
            {
                result = tok::OR;
            }
            else if (str == "not")
            {
                result = tok::NOT;
            }
            else if (str == "del")
            {
                result = tok::DEL;
            }
            else if (str == "break")
            {
                result = tok::BREAK;
            }
            else if (str == "return")
            {
                result = tok::RETURN;
            }
            else if (str == "continue")
            {
                result = tok::CONTINUE;
            }
            else if (str == "yield")
            {
                result = tok::YIELD;
            }
            else if (str == "pass")
            {
                result = tok::PASS;
            }
            else if (str == "raise")
            {
                result = tok::RAISE;
            }
            else if (str == "from")
            {
                result = tok::FROM;
            }
            else if (str == "import")
            {
                result = tok::IMPORT;
            }
            else if (str == "as")
            {
                result = tok::AS;
            }
            else if (str == "global")
            {
                result = tok::GLOBAL;
            }
            else if (str == "nonlocal")
            {
                result = tok::NONLOCAL;
            }
            else if (str == "assert")
            {
                result = tok::ASSERT;
            }
            else
            {
                result = tok::NAME;
                *node = ctx.ast->CreateName(*loc, a, b);
            }
        }
		
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
    case pytoken::LARROW:
        result = tok::LARROW;
        break;
    case pytoken::RARROW:
        result = tok::RARROW;
        break;
    case pytoken::ELLIPSIS:
        result = tok::ELLIPSIS;
        break;
	case pytoken::ERRORTOKEN:
		result = 0;
		break;
	default:
		result = 0;
		break;
	}


	// if the result node has NOT been already populated with a terminal
	// node type that has a semnatic value, such as a string, number, or
	// other type, we check if it is an operator type and get the operator
	// semantic value.
	if(*node == NULL)
	{
		*node = TokenAstNodes::GetAstNode(result);
	}

	return result;
}


/**
 * array of dummy ast nodes to map tokens to ast nodes for the parser.
 */
static AstNode tokenAstNodes [py::EndOp];

OperatorType TokenAstNodes::GetTokenOperatorType(int tokenValue)
{
	switch(tokenValue)
	{
    case tok::PLUS:
        return Add;
    case tok::MINUS:
        return Sub;
    case tok::STAR:
        return Mult;
    case tok::SLASH:
        return Div;
    case tok::VBAR:
        return BitOr;
    case tok::AMPER:
        return BitAnd;
    case tok::LESS:
        return Lt;
    case tok::GREATER:
        return Gt;
    case tok::PERCENT:
        return Mod;
    case tok::EQEQUAL:
        return Eq;
    case tok::NOTEQUAL:
        return NotEq;
    case tok::LESSEQUAL:
        return LtEq;
    case tok::GREATEREQUAL:
        return GtEq;
    case tok::CIRCUMFLEX:
        return BitXor;
    case tok::LEFTSHIFT:
        return LShift;
    case tok::RIGHTSHIFT:
        return RShift;
    case tok::DOUBLESTAR:
        return Pow;
    case tok::PLUSEQUAL:
        return Add;
    case tok::MINEQUAL:
        return Sub;
    case tok::STAREQUAL:
        return Mult;
    case tok::SLASHEQUAL:
        return Div;
    case tok::PERCENTEQUAL:
        return Mod;
    case tok::AMPEREQUAL:
        return BitAnd;
    case tok::VBAREQUAL:
        return BitOr;
    case tok::CIRCUMFLEXEQUAL:
        return BitXor;
    case tok::LEFTSHIFTEQUAL:
        return LShift;
    case tok::RIGHTSHIFTEQUAL:
        return RShift;
    case tok::DOUBLESTAREQUAL:
        return Pow;
    case tok::DOUBLESLASH:
        return FloorDiv;
    case tok::DOUBLESLASHEQUAL:
        return FloorDiv;
    case tok::IN:
    	return In;
    case tok::IS:
    	return Is;
    case tok::AND:
    	return And;
    case tok::OR:
    	return Or;
    case tok::TILDE:
        return Invert;
    case tok::NOT:
        return Not;
    default:
    	return EndOp;
	}
}

#undef tok

AstNode *TokenAstNodes::GetAstNode(int tokenValue)
{
	unsigned offset = GetTokenOperatorType(tokenValue);

	if (offset < EndOp) {
		return &tokenAstNodes[offset];
	}

	return NULL;
}


OperatorType TokenAstNodes::GetOperatorType(const AstNode *node)
{
    unsigned offset = node - &tokenAstNodes[0];
	return (offset < EndOp) ? (OperatorType)(offset) : EndOp;
}


AstNode *TokenAstNodes::GetAstNodeForOperatorType(OperatorType type)
{
	return &tokenAstNodes[type];
}

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


