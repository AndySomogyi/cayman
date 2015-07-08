/*
 * AstToken.h
 *
 *  Created on: Jun 22, 2015
 *      Author: andy
 */

#ifndef _ASTTOKEN_H_
#define _ASTTOKEN_H_

#include "AstNode.h"

namespace py
{

/**
 * internal class, map token values to AstNodes, lets us keep a single
 * data type in the parser instead of the more complex variant or union.
 *
 * This class basically maps the tokens defined in the bison parser to
 * dummy Ast nodes which are used by the bison parser, and these nodes
 * are then in turn mapped to Ast operator enum vales.
 */
class AstToken : AstNode
{
public:


	const char* name;
	const char* value;
	const int id;
	OperatorType operatorType;


	/*
	static AstNode *Plus;
	static AstNode *Minus;
	static AstNode *Star;
	static AstNode *Slash;
	static AstNode *Percent;
	static AstNode *StarStar;
	static AstNode *LeftShift;
	static AstNode *RightShift;
	static AstNode *VertBar;
	static AstNode *Circumflex;
	static AstNode *Amper;
	static AstNode *DblSlash;

	static AstNode *Less;


	LESS "<"
	GREATER ">"
	EQUAL "="
	DOT "."
	PERCENT "%"
	BACKQUOTE "`"
	LBRACE "{"
	RBRACE "}"
	EQEQUAL "=="
	NOTEQUAL "!="
	LESSEQUAL "<="
	GREATEREQUAL ">="
	TILDE "~"
	CIRCUMFLEX "^"
	LEFTSHIFT "<<"
	RIGHTSHIFT ">>"
	DOUBLESTAR "**"
	PLUSEQUAL "+="
	MINEQUAL "-="
	STAREQUAL "*="
	SLASHEQUAL "/="
	PERCENTEQUAL "%="
	AMPEREQUAL "&="
	VBAREQUAL "|="
	CIRCUMFLEXEQUAL "^="
	LEFTSHIFTEQUAL "<<="
	RIGHTSHIFTEQUAL ">>="
	DOUBLESTAREQUAL "**+"
	DOUBLESLASH "//"
	DOUBLESLASHEQUAL "//="

	*/


	/**
	 * Get an dummy AstNode for a python token id.
	 *
	 * Note, the AstNode pointer returned here
	 * MUST NOT BE USED FOR ANYTHING OTHER THAN COMPARISONS!
	 *
	 * THESE ARE LIKELY NOT VALID NODE POINTERS!!!!
	 */
	static AstNode *GetAstNode(int pyTokenValue);

	static OperatorType GetOperatorType(AstNode *node);

	static AstNode *GetAstNodeForOperatorType(OperatorType);


	static const AstToken *True;
	static const AstToken *False;

private:
	AstToken(const char* tokenName, const char* tokenValue, int tokenNum,
			OperatorType operatorType = EndOp);

	friend class AstTokenInitializer;
};


} /* namespace py */

#endif /* _ASTTOKEN_H_ */
