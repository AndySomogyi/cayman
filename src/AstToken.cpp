/*
 * AstToken.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: andy
 */

#include "AstToken.h"
#include "py_parser.hh"

#include <unordered_map>

namespace py {

class AstTokenInitializer
{
public:
	static AstToken tokens[];

	AstTokenInitializer();
};


typedef std::unordered_map<int, AstToken*> IntTokenMap;

static IntTokenMap tokenIdPtrMap;

#define tok py_parser::token

AstToken AstTokenInitializer::tokens [] = {
	AstToken("PLUS", "+", tok::PLUS, Add),
	AstToken("MINUS", "-", tok::MINUS, Sub),
	AstToken("STAR", "*", tok::STAR, Mult),
	AstToken("SLASH", "/", tok::SLASH, Div),
	AstToken("PERCENT", "%", tok::PERCENT, Mod),
	AstToken("DOUBLESTAR", "**", tok::DOUBLESTAR, Pow),
    AstToken("LEFTSHIFT", "<<", tok::LEFTSHIFT, LShift),
    AstToken("RIGHTSHIFT", ">>", tok::RIGHTSHIFT, RShift),
    AstToken("VBAR", "|", tok::VBAR, BitOr),
    AstToken("CIRCUMFLEX", "^", tok::CIRCUMFLEX, BitXor),
    AstToken("AMPER", "&", tok::AMPER, BitAnd),
    AstToken("DOUBLESLASH", "//", tok::DOUBLESLASH, FloorDiv),
    AstToken("NOT", "not", tok::NOT, Not),
	AstToken("TILDE", "~", tok::TILDE, Invert),
    AstToken("EQEQUAL", "==", tok::EQEQUAL, Eq),
    AstToken("NOTEQUAL", "!=", tok::NOTEQUAL, NotEq),
	AstToken("LESS", "<", tok::LESS, Lt),
    AstToken("LESSEQUAL", "<=", tok::LESSEQUAL, LtEq),
    AstToken("GREATER", ">", tok::GREATER, Gt),
    AstToken("GREATEREQUAL", ">=", tok::GREATEREQUAL, GtEq),
    AstToken("IS", "is", tok::IS, Is),
	AstToken("IS NOT", "is not", 0, IsNot),
    AstToken("IN", "in", tok::IN, In),
	AstToken("NOT IN", "not in", 0, NotIn),
    AstToken("AND", "and", tok::AND, And),
    AstToken("OR", "or", tok::OR, Or),
	AstToken("END_OP", "", 0, EndOp),

	// normal operator types
    AstToken("DEF", "def", tok::DEF),
    AstToken("PASS", "pass", tok::PASS),
    AstToken("IF", "if", tok::IF),
    AstToken("ELSE", "else", tok::ELSE),
    AstToken("ELIF", "elif", tok::ELIF),
    AstToken("FOR", "for", tok::FOR),
    AstToken("DEL", "del", tok::DEL),
    AstToken("ENDMARKER","", tok::ENDMARKER),
    AstToken("NEWLINE","", tok::NEWLINE),
    AstToken("INDENT","", tok::INDENT),
    AstToken("DEDENT","", tok::DEDENT),
    AstToken("LPAR", "(", tok::LPAR),
    AstToken("RPAR", ")", tok::RPAR),
    AstToken("LSQB", "[", tok::LSQB),
    AstToken("RSQB", "]", tok::RSQB),
    AstToken("COLON", ":", tok::COLON),
    AstToken("COMMA", ",", tok::COMMA),
    AstToken("SEMI", ";", tok::SEMI),
    AstToken("EQUAL", "=", tok::EQUAL),
    AstToken("DOT", ".", tok::DOT),
    AstToken("BACKQUOTE", "`", tok::BACKQUOTE),
    AstToken("LBRACE", "{", tok::LBRACE),
    AstToken("RBRACE", "}", tok::RBRACE),
    AstToken("PLUSEQUAL", "+=", tok::PLUSEQUAL, Add),
    AstToken("MINEQUAL", "-=", tok::MINEQUAL, Sub),
    AstToken("STAREQUAL", "*=", tok::STAREQUAL, Mult),
    AstToken("SLASHEQUAL", "/=", tok::SLASHEQUAL, Div),
    AstToken("PERCENTEQUAL", "%=", tok::PERCENTEQUAL, Mod),
    AstToken("AMPEREQUAL", "&=", tok::AMPEREQUAL, BitAnd),
    AstToken("VBAREQUAL", "|=", tok::VBAREQUAL, BitOr),
    AstToken("CIRCUMFLEXEQUAL", "^=", tok::CIRCUMFLEXEQUAL, BitXor),
    AstToken("LEFTSHIFTEQUAL", "<<=", tok::LEFTSHIFTEQUAL, LShift),
    AstToken("RIGHTSHIFTEQUAL", ">>=", tok::RIGHTSHIFTEQUAL, RShift),
    AstToken("DOUBLESTAREQUAL", "**=", tok::DOUBLESTAREQUAL, Pow),
    AstToken("DOUBLESLASHEQUAL", "//=", tok::DOUBLESLASHEQUAL, FloorDiv),
    AstToken("LARROW", "<-", tok::LARROW),
    AstToken("RARROW", "->", tok::RARROW),
    AstToken("ELLIPSIS", "...", tok::ELLIPSIS),
    AstToken("AT", "@", tok::AT),
    AstToken("AWAIT", "await", tok::AWAIT),
    AstToken("ASYNC", "async", tok::ASYNC),
    AstToken("FROM", "from", tok::FROM),
    AstToken("IMPORT", "import", tok::IMPORT),
    AstToken("YIELD", "yield", tok::YIELD),
    AstToken("BREAK", "break", tok::BREAK),
    AstToken("CONTINUE", "continue", tok::CONTINUE),
    AstToken("RAISE", "raise", tok::RAISE),
    AstToken("RETURN", "return", tok::RETURN),
    AstToken("AS", "as", tok::AS),
    AstToken("GLOBAL", "global", tok::GLOBAL),
    AstToken("NONLOCAL", "nonlocal", tok::NONLOCAL),
    AstToken("ASSERT", "assert", tok::ASSERT),
    AstToken("WHILE", "while", tok::WHILE),
    AstToken("FALSE", "False", tok::FALSE),
    AstToken("NONE", "None", tok::NONE),
    AstToken("TRUE", "True", tok::TRUE),
    AstToken("CLASS", "class", tok::CLASS),
    AstToken("EXCEPT", "except", tok::EXCEPT),
    AstToken("FINALLY", "finally", tok::FINALLY),
    AstToken("LAMBDA", "lambda", tok::LAMBDA),
    AstToken("TRY", "try", tok::TRY),
    AstToken("WITH", "with", tok::WITH),
	AstToken("TRUE", "True", tok::TRUE),
	AstToken("FALSE", "True", tok::FALSE)
};

static const size_t numTokens = sizeof(AstTokenInitializer::tokens)/sizeof(AstToken);

bool tokensInitialized = false;

AstTokenInitializer::AstTokenInitializer()
{
	assert(tokensInitialized == false);

	for (int i = 0; i < numTokens; ++i) {
		AstToken *ptr = &tokens[i];
		tokenIdPtrMap[ptr->id] = ptr;
	}

	assert(EndOp < numTokens);

	assert(tokens[Add].operatorType == Add);
	assert(tokens[Sub].operatorType == Sub);
	assert(tokens[Mult].operatorType == Mult);
	assert(tokens[Div].operatorType == Div);
	assert(tokens[Mod].operatorType == Mod);
	assert(tokens[Pow].operatorType == Pow);
	assert(tokens[LShift].operatorType == LShift);
	assert(tokens[RShift].operatorType == RShift);
	assert(tokens[BitOr].operatorType == BitOr);
	assert(tokens[BitXor].operatorType == BitXor);
	assert(tokens[BitAnd].operatorType == BitAnd);
	assert(tokens[FloorDiv].operatorType == FloorDiv);
	assert(tokens[Not].operatorType == Not);
	assert(tokens[Invert].operatorType == Invert);
	assert(tokens[Eq].operatorType == Eq);
	assert(tokens[NotEq].operatorType == NotEq);
	assert(tokens[Lt].operatorType == Lt);
	assert(tokens[LtEq].operatorType == LtEq);
	assert(tokens[Gt].operatorType == Gt);
	assert(tokens[GtEq].operatorType == GtEq);
	assert(tokens[Is].operatorType == Is);
	assert(tokens[IsNot].operatorType == IsNot);
	assert(tokens[In].operatorType == In);
	assert(tokens[NotIn].operatorType == NotIn);
	assert(tokens[And].operatorType == And);
	assert(tokens[Or].operatorType == Or);

	tokensInitialized = true;
}

#undef tok
    
AstTokenInitializer dummy;

AstNode *AstToken::GetAstNode(int tokenValue)
{
	IntTokenMap::const_iterator iter = tokenIdPtrMap.find(tokenValue);

	if (iter != tokenIdPtrMap.end()) {
		return iter->second;
	}

	return NULL;
}


OperatorType AstToken::GetOperatorType(AstNode *node)
{
    // can't dynamic_cast because these are stack allocated
    // objects
    if (node >= &AstTokenInitializer::tokens[0] &&
        node < &AstTokenInitializer::tokens[numTokens]) {
        AstToken *token = static_cast<AstToken*>(node);
        return token->operatorType;
    }
    return  EndOp;
}

AstNode* AstToken::GetAstNodeForOperatorType(OperatorType operatorType)
{
	if (operatorType < EndOp) {
		return &AstTokenInitializer::tokens[operatorType];
	}
	return NULL;
}

AstToken::AstToken(const char* _tokenName, const char* _tokenValue,
		int _tokenNum, OperatorType _operatorType) :
		AstNode(AST_TOKEN, NULL, location()), name(_tokenName), value(_tokenValue),
		id(_tokenNum), operatorType(_operatorType)
{
}


}
