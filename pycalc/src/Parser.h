/*
 * Parser.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef PYCALC_SRC_PARSER_H_
#define PYCALC_SRC_PARSER_H_

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
	virtual ~Parser();
};

} /* namespace py */

#endif /* PYCALC_SRC_PARSER_H_ */
