/*
 * Parser.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <ostream>
#include "Ast.h"


namespace py
{

/**
 * public Parser class to create an AST from a python++ source fragment
 * or document
 */
class Parser
{
public:
	Parser();

	/**
	 * Creates a parser from an input path.
	 */
	Parser(const std::string& inputUri);
	virtual ~Parser();

	void SetDebugLevel(int dbgLevel);

	int GetDebugLevel() const;

	void SetDebugStream(std::ostream& dbgStream);


	AstPtr Parse();


	class ParserContext *ctx;
};

} /* namespace py */

#endif /* PYCALC_SRC_PARSER_H_ */
