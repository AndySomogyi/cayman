/*
 * ParserContext.h
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#ifndef _INCLUDED__PARSERCONTEXT_H_
#define _INCLUDED__PARSERCONTEXT_H_


#include <string>
#include <ostream>
#include <cstdio>
#include "py_parser.hh"
#include "Ast.h"
#include "AstNodeFactory.h"

struct tok_state;

namespace py
{

/**
 * An internal class that holds parsing state information, and the
 * parser and lexer
 */
class ParserContext
{
public:
	ParserContext(const std::string& uri);

	ParserContext(std::ostream& inpt);

	~ParserContext();
    
    AstPtr ast;
    
    tok_state *ts;


	std::string fileName;


	py_parser parser;

	

	AstNodeFactory factory;

	

	/**
	 * file pointer if using file based io, TODO, replace this
	 * with c++ stream.
	 */
	std::FILE *file;

	int *flags;

	// was at least a single token read
	int started;

	int error;

	/**
	 * As sequence of statments that are built either durring a function definition,
	 */
	AstNodes stmts;
    
    /**
     * Has the ENDMARKER token been seen?
     * The python tokenizer will correctly yield a stream of DEDENT 
     * tokens if the file ends in the middle of a  indent block. 
     * however, it does not seem to return an EOF token after the ENDMARKER token, 
     * but will continue to return ENDMARKER tokens. 
     *
     * here we keep track of the endmarker, if one is seen, the next token returned to 
     * bison will be an eof. 
     */
    int pending;

	/**
	 * Error function called by the parser. the call to the Error func
	 * is specified in the grammar.
	 */
	void Error(const py_parser::location_type& l, const std::string& m);



};





/**
 * The yylex function that the bison parser calls.
 *
 * The yylex function is the glue betwen the lexer (a lexer based on the python
 * tokenizer in our case), and the bison based parser.
 *
 * When the bison %define api.token.constructor {false} is set to false,
 * the bison %define api.value.type is NOT set to variant or union, the calling
 * convention of the yylex function is called like
 *
 *  yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, context));
 *
 *  So, it has the signature of
 *
 *  int yylex(semantic_type*, location_type*, param_type),
 *
 *  where semamtic_type is the type defined by the bison directive, %define api.value.type
 *  and location_type is location type used by the parser. Both semantic_type, and
 *  location_type are typedefs within the parser class, however param_type is not
 *  typedeffed.
 *
 *  This yylex function is defined in ParserContext.cpp
 *
 */
int yylex(py_parser::semantic_type*, py_parser::location_type*, ParserContext&);


} /* namespace py */

#endif /* _INCLUDED_PARSERCONTEXT_H_ */
