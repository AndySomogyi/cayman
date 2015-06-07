/*
 * Parser.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#include "Parser.h"
#include "ParserContext.h"

namespace py
{

Parser::Parser() : ctx(NULL)
{
	// TODO Auto-generated constructor stub

}

Parser::Parser(const std::string& inputUri) :
		ctx(NULL)
{
	ctx = new ParserContext(inputUri);
}

Parser::~Parser()
{
	delete ctx;
}

void Parser::SetDebugLevel(int dbgLevel)
{
	ctx->parser.set_debug_level(dbgLevel);
}

int Parser::GetDebugLevel() const
{
	return ctx->parser.debug_level();
}

void Parser::SetDebugStream(std::ostream& o)
{
	ctx->parser.set_debug_stream(o);
}

AstPtr Parser::Parse()
{
	ctx->parser.parse();
	return ctx->ast;
}

} /* namespace py */
