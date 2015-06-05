/*
 * ParserContext.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef SOURCE_DIRECTORY__PYCALC_SRC_PARSERCONTEXT_H_
#define SOURCE_DIRECTORY__PYCALC_SRC_PARSERCONTEXT_H_


#include <string>
#include "py_parser.hh"
#include "Lexer.h"

namespace py
{

/**
 * An internal class that holds parsing state information, and the
 * parser and lexer
 */
class ParserContext
{
public:
	ParserContext();
	virtual ~ParserContext();


	std::string& GetFilename();


	py_parser parser;

	Lexer lexer;
};


/**
 * The yylex function that the bison parser calls.
 */
inline py_parser::symbol_type yylex(ParserContext& ctx)
{
    return ctx.lexer.Next();
}


} /* namespace py */

#endif /* SOURCE_DIRECTORY__PYCALC_SRC_PARSERCONTEXT_H_ */
