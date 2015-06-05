/*
 * Lexer.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef PY_LEXER_H_
#define PY_LEXER_H_

#include "py_parser.hh"

namespace py
{

class Lexer
{
public:
	Lexer();
	virtual ~Lexer();

	/**
	 * Get the next token in the stream.
	 */
	py_parser::symbol_type Next();
};


} /* namespace py */

#endif /* PYCALC_SRC_LEXER_H_ */
