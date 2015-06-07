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
		file(NULL),
		ts(NULL),
		flags(0), started(0), error(0),
		parser(*this)
{
	file = fopen(uri.c_str(), "r");
	ts = PyTokenizer_FromFile(file, NULL, NULL);
}

ParserContext::ParserContext(std::ostream& inpt):
		file(NULL),
		ts(NULL),
		flags(0), started(0), error(0),
		parser(*this)
{
}

ParserContext::~ParserContext()
{
	PyTokenizer_Free(ts);
	fclose(file);
}


void ParserContext::Error(const py_parser::location_type& l, const std::string& m)
{
	std::cout << "oh crap, loc: " << l << ", err: " << m << std::endl;

}


#define tok py_parser::token



int yylex(py_parser::semantic_type* node, py_parser::location_type* loc,
		ParserContext& ctx)
{
	char *a, *b;
	int type;
	size_t len;
	char *str;
	int col_offset;
	int result = tok::END;

	type = PyTokenizer_Get(ctx.ts, &a, &b);
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
		ctx.started = 1;
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

	// print token

	tok_dump(type, a, b);
	printf("\n");



	switch (type)
	{
	case pytoken::ENDMARKER:
		result = tok::ENDMARKER;
		break;
	case pytoken::NAME:
		result = tok::NAME;
		break;
	case pytoken::NUMBER:
		result = tok::NUMBER;
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

} /* namespace py */


