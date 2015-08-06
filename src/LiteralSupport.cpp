//===--- LiteralSupport.cpp - Code to parse and process literals ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the NumericLiteralParser, CharLiteralParser, and
// StringLiteralParser interfaces.
//
//===----------------------------------------------------------------------===//

#include "LiteralSupport.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/ConvertUTF.h"




namespace clang
{

class LangOptions  {
public:

	bool MicrosoftExt;

	bool CPlusPlus14;

	bool CPlusPlus11;

	bool HexFloats;

	bool CPlusPlus;

	bool C99;
};


class SourceManager  {
public:

};


class SourceLocation  {
public:

};

class FullSourceLoc : public SourceLocation {
public:

	SourceManager &getManager()
	{
		return s;
	}

	SourceManager s;
};




class CharSourceRange {
public:

};


class DiagnosticBuilder  {
public:



};

class DiagnosticsEngine {
public:

	DiagnosticBuilder Report(SourceLocation Loc, unsigned DiagID) {
		return DiagnosticBuilder();
	}

};



class Token {
public:


};

class TargetInfo  {
public:

};


class Preprocessor {
public:

	DiagnosticsEngine *Diags;

	/// Forwarding function for diagnostics.  This emits a diagnostic at
	/// the specified Token's location, translating the token's start
	/// position in the current buffer into a SourcePosition object for rendering.
	DiagnosticBuilder Diag(SourceLocation Loc, unsigned DiagID) const {
		return Diags->Report(Loc, DiagID);
	}
	/*
	  DiagnosticBuilder Diag(const Token &Tok, unsigned DiagID) const {
	    return Diags->Report(Tok.getLocation(), DiagID);
	  }
	 */

	/// \brief Given a location that specifies the start of a
	/// token, return a new location that specifies a character within the token.
	SourceLocation AdvanceToTokenCharacter(SourceLocation TokStart,
			unsigned Char) const
	{
		return SourceLocation();
	}


	const LangOptions& getLangOpts() const {
		return langOpt;
	}


	LangOptions langOpt;
};


inline const DiagnosticBuilder &operator<<(const DiagnosticBuilder &DB,
		StringRef S)
{

	// DB.AddString(S);
	return DB;
}

inline const DiagnosticBuilder &operator<<(const DiagnosticBuilder &DB,
		const CharSourceRange& c)
{

	// DB.AddString(S);
	return DB;
}

inline const DiagnosticBuilder &operator<<(const DiagnosticBuilder &DB,
		int c)
{

	// DB.AddString(S);
	return DB;
}

class Lexer {
public:
	static SourceLocation AdvanceToTokenCharacter(SourceLocation TokStart, unsigned Char,
			const SourceManager &SourceMgr, const LangOptions &Features)
	{
		return TokStart;
	}
};


}


using namespace clang;


Preprocessor PP;


static CharSourceRange MakeCharSourceRange(const LangOptions &Features,
		FullSourceLoc TokLoc,
		const char *TokBegin,
		const char *TokRangeBegin,
		const char *TokRangeEnd)
{
	/*
   SourceLocation Begin =
     Lexer::AdvanceToTokenCharacter(TokLoc, TokRangeBegin - TokBegin,
                                    TokLoc.getManager(), Features);
   SourceLocation End =
     Lexer::AdvanceToTokenCharacter(Begin, TokRangeEnd - TokRangeBegin,
                                    TokLoc.getManager(), Features);
   return CharSourceRange::getCharRange(Begin, End);
	 */

	return CharSourceRange();
}



/// \brief Produce a diagnostic highlighting some portion of a literal.
///
/// Emits the diagnostic \p DiagID, highlighting the range of characters from
/// \p TokRangeBegin (inclusive) to \p TokRangeEnd (exclusive), which must be
/// a substring of a spelling buffer for the token beginning at \p TokBegin.
static DiagnosticBuilder Diag(DiagnosticsEngine *Diags,
		const LangOptions &Features, FullSourceLoc TokLoc,
		const char *TokBegin, const char *TokRangeBegin,
		const char *TokRangeEnd, unsigned DiagID) {
	SourceLocation Begin =
			Lexer::AdvanceToTokenCharacter(TokLoc, TokRangeBegin - TokBegin,
					TokLoc.getManager(), Features);
	return Diags->Report(Begin, DiagID) <<
			MakeCharSourceRange(Features, TokLoc, TokBegin, TokRangeBegin, TokRangeEnd);
}


static void appendCodePoint(unsigned Codepoint,
		llvm::SmallVectorImpl<char> &Str) {
	char ResultBuf[4];
	char *ResultPtr = ResultBuf;
	bool Res = llvm::ConvertCodePointToUTF8(Codepoint, ResultPtr);
	(void)Res;
	assert(Res && "Unexpected conversion failure");
	Str.append(ResultBuf, ResultPtr);
}

void clang::expandUCNs(SmallVectorImpl<char> &Buf, StringRef Input) {
	for (StringRef::iterator I = Input.begin(), E = Input.end(); I != E; ++I) {
		if (*I != '\\') {
			Buf.push_back(*I);
			continue;
		}

		++I;
		assert(*I == 'u' || *I == 'U');

		unsigned NumHexDigits;
		if (*I == 'u')
			NumHexDigits = 4;
		else
			NumHexDigits = 8;

		assert(I + NumHexDigits <= E);

		uint32_t CodePoint = 0;
		for (++I; NumHexDigits != 0; ++I, --NumHexDigits) {
			unsigned Value = llvm::hexDigitValue(*I);
			assert(Value != -1U);

			CodePoint <<= 4;
			CodePoint += Value;
		}

		appendCodePoint(CodePoint, Buf);
		--I;
	}
}

/// ProcessUCNEscape - Read the Universal Character Name, check constraints and
/// return the UTF32.
static bool ProcessUCNEscape(const char *ThisTokBegin, const char *&ThisTokBuf,
		const char *ThisTokEnd,
		uint32_t &UcnVal, unsigned short &UcnLen,
		FullSourceLoc Loc, DiagnosticsEngine *Diags,
		const LangOptions &Features,
		bool in_char_string_literal = false) {
	const char *UcnBegin = ThisTokBuf;

	// Skip the '\u' char's.
	ThisTokBuf += 2;

	if (ThisTokBuf == ThisTokEnd || !isHexDigit(*ThisTokBuf)) {
		if (Diags)
			Diag(Diags, Features, Loc, ThisTokBegin, UcnBegin, ThisTokBuf,
					diag::err_hex_escape_no_digits) << StringRef(&ThisTokBuf[-1], 1);
		return false;
	}
	UcnLen = (ThisTokBuf[-1] == 'u' ? 4 : 8);
	unsigned short UcnLenSave = UcnLen;
	for (; ThisTokBuf != ThisTokEnd && UcnLenSave; ++ThisTokBuf, UcnLenSave--) {
		int CharVal = llvm::hexDigitValue(ThisTokBuf[0]);
		if (CharVal == -1) break;
		UcnVal <<= 4;
		UcnVal |= CharVal;
	}
	// If we didn't consume the proper number of digits, there is a problem.
	if (UcnLenSave) {
		if (Diags)
			Diag(Diags, Features, Loc, ThisTokBegin, UcnBegin, ThisTokBuf,
					diag::err_ucn_escape_incomplete);
		return false;
	}

	// Check UCN constraints (C99 6.4.3p2) [C++11 lex.charset p2]
	if ((0xD800 <= UcnVal && UcnVal <= 0xDFFF) || // surrogate codepoints
			UcnVal > 0x10FFFF) {                      // maximum legal UTF32 value
		if (Diags)
			Diag(Diags, Features, Loc, ThisTokBegin, UcnBegin, ThisTokBuf,
					diag::err_ucn_escape_invalid);
		return false;
	}

	// C++11 allows UCNs that refer to control characters and basic source
	// characters inside character and string literals
	if (UcnVal < 0xa0 &&
			(UcnVal != 0x24 && UcnVal != 0x40 && UcnVal != 0x60)) {  // $, @, `
		bool IsError = (!Features.CPlusPlus11 || !in_char_string_literal);
		if (Diags) {
			char BasicSCSChar = UcnVal;
			if (UcnVal >= 0x20 && UcnVal < 0x7f)
				Diag(Diags, Features, Loc, ThisTokBegin, UcnBegin, ThisTokBuf,
						IsError ? diag::err_ucn_escape_basic_scs :
								diag::warn_cxx98_compat_literal_ucn_escape_basic_scs)
								<< StringRef(&BasicSCSChar, 1);
			else
				Diag(Diags, Features, Loc, ThisTokBegin, UcnBegin, ThisTokBuf,
						IsError ? diag::err_ucn_control_character :
								diag::warn_cxx98_compat_literal_ucn_control_character);
		}
		if (IsError)
			return false;
	}

	if (!Features.CPlusPlus && !Features.C99 && Diags)
		Diag(Diags, Features, Loc, ThisTokBegin, UcnBegin, ThisTokBuf,
				diag::warn_ucn_not_valid_in_c89_literal);

	return true;
}

/// MeasureUCNEscape - Determine the number of bytes within the resulting string
/// which this UCN will occupy.
static int MeasureUCNEscape(const char *ThisTokBegin, const char *&ThisTokBuf,
		const char *ThisTokEnd, unsigned CharByteWidth,
		const LangOptions &Features, bool &HadError) {
	// UTF-32: 4 bytes per escape.
	if (CharByteWidth == 4)
		return 4;

	uint32_t UcnVal = 0;
	unsigned short UcnLen = 0;
	FullSourceLoc Loc;

	if (!ProcessUCNEscape(ThisTokBegin, ThisTokBuf, ThisTokEnd, UcnVal,
			UcnLen, Loc, nullptr, Features, true)) {
		HadError = true;
		return 0;
	}

	// UTF-16: 2 bytes for BMP, 4 bytes otherwise.
	if (CharByteWidth == 2)
		return UcnVal <= 0xFFFF ? 2 : 4;

	// UTF-8.
	if (UcnVal < 0x80)
		return 1;
	if (UcnVal < 0x800)
		return 2;
	if (UcnVal < 0x10000)
		return 3;
	return 4;
}


///       integer-constant: [C99 6.4.4.1]
///         decimal-constant integer-suffix
///         octal-constant integer-suffix
///         hexadecimal-constant integer-suffix
///         binary-literal integer-suffix [GNU, C++1y]
///       user-defined-integer-literal: [C++11 lex.ext]
///         decimal-literal ud-suffix
///         octal-literal ud-suffix
///         hexadecimal-literal ud-suffix
///         binary-literal ud-suffix [GNU, C++1y]
///       decimal-constant:
///         nonzero-digit
///         decimal-constant digit
///       octal-constant:
///         0
///         octal-constant octal-digit
///       hexadecimal-constant:
///         hexadecimal-prefix hexadecimal-digit
///         hexadecimal-constant hexadecimal-digit
///       hexadecimal-prefix: one of
///         0x 0X
///       binary-literal:
///         0b binary-digit
///         0B binary-digit
///         binary-literal binary-digit
///       integer-suffix:
///         unsigned-suffix [long-suffix]
///         unsigned-suffix [long-long-suffix]
///         long-suffix [unsigned-suffix]
///         long-long-suffix [unsigned-sufix]
///       nonzero-digit:
///         1 2 3 4 5 6 7 8 9
///       octal-digit:
///         0 1 2 3 4 5 6 7
///       hexadecimal-digit:
///         0 1 2 3 4 5 6 7 8 9
///         a b c d e f
///         A B C D E F
///       binary-digit:
///         0
///         1
///       unsigned-suffix: one of
///         u U
///       long-suffix: one of
///         l L
///       long-long-suffix: one of
///         ll LL
///
///       floating-constant: [C99 6.4.4.2]
///         TODO: add rules...
///
NumericLiteralParser::NumericLiteralParser(StringRef TokSpelling)
: ThisTokBegin(TokSpelling.begin()), ThisTokEnd(TokSpelling.end()) {

	// This routine assumes that the range begin/end matches the regex for integer
	// and FP constants (specifically, the 'pp-number' regex), and assumes that
	// the byte at "*end" is both valid and not part of the regex.  Because of
	// this, it doesn't have to check for 'overscan' in various places.
	assert(!isPreprocessingNumberBody(*ThisTokEnd) && "didn't maximally munch?");

	s = DigitsBegin = ThisTokBegin;
	saw_exponent = false;
	saw_period = false;
	saw_ud_suffix = false;
	isLong = false;
	isUnsigned = false;
	isLongLong = false;
	isFloat = false;
	isImaginary = false;
	MicrosoftInteger = 0;
	hadError = false;

	SourceLocation TokLoc;

	if (*s == '0') { // parse radix
		ParseNumberStartingWithZero(TokLoc);
		if (hadError)
			return;
	} else { // the first digit is non-zero
		radix = 10;
		s = SkipDigits(s);
		if (s == ThisTokEnd) {
			// Done.
		} else if (isHexDigit(*s) && !(*s == 'e' || *s == 'E')) {
			PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, s - ThisTokBegin),
					diag::err_invalid_decimal_digit) << StringRef(s, 1);
			hadError = true;
			return;
		} else if (*s == '.') {
			checkSeparator(TokLoc, s, CSK_AfterDigits);
			s++;
			saw_period = true;
			checkSeparator(TokLoc, s, CSK_BeforeDigits);
			s = SkipDigits(s);
		}
		if ((*s == 'e' || *s == 'E')) { // exponent
			checkSeparator(TokLoc, s, CSK_AfterDigits);
			const char *Exponent = s;
			s++;
			saw_exponent = true;
			if (*s == '+' || *s == '-')  s++; // sign
			checkSeparator(TokLoc, s, CSK_BeforeDigits);
			const char *first_non_digit = SkipDigits(s);
			if (first_non_digit != s) {
				s = first_non_digit;
			} else {
				PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, Exponent - ThisTokBegin),
						diag::err_exponent_has_no_digits);
				hadError = true;
				return;
			}
		}
	}

	SuffixBegin = s;
	checkSeparator(TokLoc, s, CSK_AfterDigits);

	// Parse the suffix.  At this point we can classify whether we have an FP or
	// integer constant.
	bool isFPConstant = isFloatingLiteral();
	const char *ImaginarySuffixLoc = nullptr;

	// Loop over all of the characters of the suffix.  If we see something bad,
	// we break out of the loop.
	for (; s != ThisTokEnd; ++s) {
		switch (*s) {
		case 'f':      // FP Suffix for "float"
		case 'F':
			if (!isFPConstant) break;  // Error for integer constant.
			if (isFloat || isLong) break; // FF, LF invalid.
			isFloat = true;
			continue;  // Success.
		case 'u':
		case 'U':
			if (isFPConstant) break;  // Error for floating constant.
			if (isUnsigned) break;    // Cannot be repeated.
			isUnsigned = true;
			continue;  // Success.
		case 'l':
		case 'L':
			if (isLong || isLongLong) break;  // Cannot be repeated.
			if (isFloat) break;               // LF invalid.

			// Check for long long.  The L's need to be adjacent and the same case.
			if (s[1] == s[0]) {
				assert(s + 1 < ThisTokEnd && "didn't maximally munch?");
				if (isFPConstant) break;        // long long invalid for floats.
				isLongLong = true;
				++s;  // Eat both of them.
			} else {
				isLong = true;
			}
			continue;  // Success.
		case 'i':
		case 'I':
			if (PP.getLangOpts().MicrosoftExt) {
				if (isLong || isLongLong || MicrosoftInteger)
					break;

				if (!isFPConstant) {
					// Allow i8, i16, i32, i64, and i128.
					switch (s[1]) {
					case '8':
						s += 2; // i8 suffix
						MicrosoftInteger = 8;
						break;
					case '1':
						if (s[2] == '6') {
							s += 3; // i16 suffix
							MicrosoftInteger = 16;
						} else if (s[2] == '2' && s[3] == '8') {
							s += 4; // i128 suffix
							MicrosoftInteger = 128;
						}
						break;
					case '3':
						if (s[2] == '2') {
							s += 3; // i32 suffix
							MicrosoftInteger = 32;
						}
						break;
					case '6':
						if (s[2] == '4') {
							s += 3; // i64 suffix
							MicrosoftInteger = 64;
						}
						break;
					default:
						break;
					}
				}
				if (MicrosoftInteger) {
					assert(s <= ThisTokEnd && "didn't maximally munch?");
					break;
				}
			}
			// "i", "if", and "il" are user-defined suffixes in C++1y.
			if (*s == 'i' && PP.getLangOpts().CPlusPlus14)
				break;
			// fall through.
		case 'j':
		case 'J':
			if (isImaginary) break;   // Cannot be repeated.
			isImaginary = true;
			ImaginarySuffixLoc = s;
			continue;  // Success.
		}
		// If we reached here, there was an error or a ud-suffix.
		break;
	}

	if (s != ThisTokEnd) {
		// FIXME: Don't bother expanding UCNs if !tok.hasUCN().
		expandUCNs(UDSuffixBuf, StringRef(SuffixBegin, ThisTokEnd - SuffixBegin));
		if (isValidUDSuffix(PP.getLangOpts(), UDSuffixBuf)) {
			// Any suffix pieces we might have parsed are actually part of the
			// ud-suffix.
			isLong = false;
			isUnsigned = false;
			isLongLong = false;
			isFloat = false;
			isImaginary = false;
			MicrosoftInteger = 0;

			saw_ud_suffix = true;
			return;
		}

		// Report an error if there are any.
		PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, SuffixBegin - ThisTokBegin),
				isFPConstant ? diag::err_invalid_suffix_float_constant :
						diag::err_invalid_suffix_integer_constant)
    				  << StringRef(SuffixBegin, ThisTokEnd-SuffixBegin);
		hadError = true;
		return;
	}

	if (isImaginary) {
		PP.Diag(PP.AdvanceToTokenCharacter(TokLoc,
				ImaginarySuffixLoc - ThisTokBegin),
				diag::ext_imaginary_constant);
	}
}

/// Determine whether a suffix is a valid ud-suffix. We avoid treating reserved
/// suffixes as ud-suffixes, because the diagnostic experience is better if we
/// treat it as an invalid suffix.
bool NumericLiteralParser::isValidUDSuffix(const LangOptions &LangOpts,
		StringRef Suffix) {
	if (!LangOpts.CPlusPlus11 || Suffix.empty())
		return false;

	// By C++11 [lex.ext]p10, ud-suffixes starting with an '_' are always valid.
	if (Suffix[0] == '_')
		return true;

	// In C++11, there are no library suffixes.
	if (!LangOpts.CPlusPlus14)
		return false;

	// In C++1y, "s", "h", "min", "ms", "us", and "ns" are used in the library.
	// Per tweaked N3660, "il", "i", and "if" are also used in the library.
	return llvm::StringSwitch<bool>(Suffix)
			.Cases("h", "min", "s", true)
			.Cases("ms", "us", "ns", true)
			.Cases("il", "i", "if", true)
			.Default(false);
}

void NumericLiteralParser::checkSeparator(SourceLocation TokLoc,
		const char *Pos,
		CheckSeparatorKind IsAfterDigits) {
	if (IsAfterDigits == CSK_AfterDigits) {
		if (Pos == ThisTokBegin)
			return;
		--Pos;
	} else if (Pos == ThisTokEnd)
		return;

	if (isDigitSeparator(*Pos))
		PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, Pos - ThisTokBegin),
				diag::err_digit_separator_not_between_digits)
				<< IsAfterDigits;
}

/// ParseNumberStartingWithZero - This method is called when the first character
/// of the number is found to be a zero.  This means it is either an octal
/// number (like '04') or a hex number ('0x123a') a binary number ('0b1010') or
/// a floating point number (01239.123e4).  Eat the prefix, determining the
/// radix etc.
void NumericLiteralParser::ParseNumberStartingWithZero(SourceLocation TokLoc) {
	assert(s[0] == '0' && "Invalid method call");
	s++;

	int c1 = s[0];

	// Handle a hex number like 0x1234.
	if ((c1 == 'x' || c1 == 'X') && (isHexDigit(s[1]) || s[1] == '.')) {
		s++;
		assert(s < ThisTokEnd && "didn't maximally munch?");
		radix = 16;
		DigitsBegin = s;
		s = SkipHexDigits(s);
		bool noSignificand = (s == DigitsBegin);
		if (s == ThisTokEnd) {
			// Done.
		} else if (*s == '.') {
			s++;
			saw_period = true;
			const char *floatDigitsBegin = s;
			checkSeparator(TokLoc, s, CSK_BeforeDigits);
			s = SkipHexDigits(s);
			noSignificand &= (floatDigitsBegin == s);
		}

		if (noSignificand) {
			PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, s - ThisTokBegin),
					diag::err_hexconstant_requires_digits);
			hadError = true;
			return;
		}

		// A binary exponent can appear with or with a '.'. If dotted, the
		// binary exponent is required.
		if (*s == 'p' || *s == 'P') {
			checkSeparator(TokLoc, s, CSK_AfterDigits);
			const char *Exponent = s;
			s++;
			saw_exponent = true;
			if (*s == '+' || *s == '-')  s++; // sign
			const char *first_non_digit = SkipDigits(s);
			if (first_non_digit == s) {
				PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, Exponent-ThisTokBegin),
						diag::err_exponent_has_no_digits);
				hadError = true;
				return;
			}
			checkSeparator(TokLoc, s, CSK_BeforeDigits);
			s = first_non_digit;

			if (!PP.getLangOpts().HexFloats)
				PP.Diag(TokLoc, diag::ext_hexconstant_invalid);
		} else if (saw_period) {
			PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, s-ThisTokBegin),
					diag::err_hexconstant_requires_exponent);
			hadError = true;
		}
		return;
	}

	// Handle simple binary numbers 0b01010
	if ((c1 == 'b' || c1 == 'B') && (s[1] == '0' || s[1] == '1')) {
		// 0b101010 is a C++1y / GCC extension.
		PP.Diag(TokLoc,
				PP.getLangOpts().CPlusPlus14
				? diag::warn_cxx11_compat_binary_literal
						: PP.getLangOpts().CPlusPlus
						  ? diag::ext_binary_literal_cxx14
								  : diag::ext_binary_literal);
		++s;
		assert(s < ThisTokEnd && "didn't maximally munch?");
		radix = 2;
		DigitsBegin = s;
		s = SkipBinaryDigits(s);
		if (s == ThisTokEnd) {
			// Done.
		} else if (isHexDigit(*s)) {
			PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, s-ThisTokBegin),
					diag::err_invalid_binary_digit) << StringRef(s, 1);
			hadError = true;
		}
		// Other suffixes will be diagnosed by the caller.
		return;
	}

	// For now, the radix is set to 8. If we discover that we have a
	// floating point constant, the radix will change to 10. Octal floating
	// point constants are not permitted (only decimal and hexadecimal).
	radix = 8;
	DigitsBegin = s;
	s = SkipOctalDigits(s);
	if (s == ThisTokEnd)
		return; // Done, simple octal number like 01234

	// If we have some other non-octal digit that *is* a decimal digit, see if
	// this is part of a floating point number like 094.123 or 09e1.
	if (isDigit(*s)) {
		const char *EndDecimal = SkipDigits(s);
		if (EndDecimal[0] == '.' || EndDecimal[0] == 'e' || EndDecimal[0] == 'E') {
			s = EndDecimal;
			radix = 10;
		}
	}

	// If we have a hex digit other than 'e' (which denotes a FP exponent) then
	// the code is using an incorrect base.
	if (isHexDigit(*s) && *s != 'e' && *s != 'E') {
		PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, s-ThisTokBegin),
				diag::err_invalid_octal_digit) << StringRef(s, 1);
		hadError = true;
		return;
	}

	if (*s == '.') {
		s++;
		radix = 10;
		saw_period = true;
		checkSeparator(TokLoc, s, CSK_BeforeDigits);
		s = SkipDigits(s); // Skip suffix.
	}
	if (*s == 'e' || *s == 'E') { // exponent
		checkSeparator(TokLoc, s, CSK_AfterDigits);
		const char *Exponent = s;
		s++;
		radix = 10;
		saw_exponent = true;
		if (*s == '+' || *s == '-')  s++; // sign
		const char *first_non_digit = SkipDigits(s);
		if (first_non_digit != s) {
			checkSeparator(TokLoc, s, CSK_BeforeDigits);
			s = first_non_digit;
		} else {
			PP.Diag(PP.AdvanceToTokenCharacter(TokLoc, Exponent-ThisTokBegin),
					diag::err_exponent_has_no_digits);
			hadError = true;
			return;
		}
	}
}

static bool alwaysFitsInto64Bits(unsigned Radix, unsigned NumDigits) {
	switch (Radix) {
	case 2:
		return NumDigits <= 64;
	case 8:
		return NumDigits <= 64 / 3; // Digits are groups of 3 bits.
	case 10:
		return NumDigits <= 19; // floor(log10(2^64))
	case 16:
		return NumDigits <= 64 / 4; // Digits are groups of 4 bits.
	default:
		llvm_unreachable("impossible Radix");
	}
}

/// GetIntegerValue - Convert this numeric literal value to an APInt that
/// matches Val's input width.  If there is an overflow, set Val to the low bits
/// of the result and return true.  Otherwise, return false.
bool NumericLiteralParser::GetIntegerValue(llvm::APInt &Val) {
	// Fast path: Compute a conservative bound on the maximum number of
	// bits per digit in this radix. If we can't possibly overflow a
	// uint64 based on that bound then do the simple conversion to
	// integer. This avoids the expensive overflow checking below, and
	// handles the common cases that matter (small decimal integers and
	// hex/octal values which don't overflow).
	const unsigned NumDigits = SuffixBegin - DigitsBegin;
	if (alwaysFitsInto64Bits(radix, NumDigits)) {
		uint64_t N = 0;
		for (const char *Ptr = DigitsBegin; Ptr != SuffixBegin; ++Ptr)
			if (!isDigitSeparator(*Ptr))
				N = N * radix + llvm::hexDigitValue(*Ptr);

		// This will truncate the value to Val's input width. Simply check
		// for overflow by comparing.
		Val = N;
		return Val.getZExtValue() != N;
	}

	Val = 0;
	const char *Ptr = DigitsBegin;

	llvm::APInt RadixVal(Val.getBitWidth(), radix);
	llvm::APInt CharVal(Val.getBitWidth(), 0);
	llvm::APInt OldVal = Val;

	bool OverflowOccurred = false;
	while (Ptr < SuffixBegin) {
		if (isDigitSeparator(*Ptr)) {
			++Ptr;
			continue;
		}

		unsigned C = llvm::hexDigitValue(*Ptr++);

		// If this letter is out of bound for this radix, reject it.
		assert(C < radix && "NumericLiteralParser ctor should have rejected this");

		CharVal = C;

		// Add the digit to the value in the appropriate radix.  If adding in digits
		// made the value smaller, then this overflowed.
		OldVal = Val;

		// Multiply by radix, did overflow occur on the multiply?
		Val *= RadixVal;
		OverflowOccurred |= Val.udiv(RadixVal) != OldVal;

		// Add value, did overflow occur on the value?
		//   (a + b) ult b  <=> overflow
		Val += CharVal;
		OverflowOccurred |= Val.ult(CharVal);
	}
	return OverflowOccurred;
}

llvm::APFloat::opStatus
NumericLiteralParser::GetFloatValue(llvm::APFloat &Result) {
	using llvm::APFloat;
    
    int a = SuffixBegin - ThisTokBegin;
    int b = ThisTokEnd - ThisTokBegin;

	unsigned n = std::min(SuffixBegin - ThisTokBegin, ThisTokEnd - ThisTokBegin);

	llvm::SmallString<16> Buffer;
	StringRef Str(ThisTokBegin, n);
	if (Str.find('\'') != StringRef::npos) {
		Buffer.reserve(n);
		std::remove_copy_if(Str.begin(), Str.end(), std::back_inserter(Buffer),
				&isDigitSeparator);
		Str = Buffer;
	}

	return Result.convertFromString(Str, APFloat::rmNearestTiesToEven);
}

