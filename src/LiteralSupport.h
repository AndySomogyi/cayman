//===--- LiteralSupport.h ---------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the NumericLiteralParser, CharLiteralParser, and
// StringLiteralParser interfaces.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LEX_LITERALSUPPORT_H
#define LLVM_CLANG_LEX_LITERALSUPPORT_H

#include "CharInfo.h"
#include "cayman_llvm.h"

namespace clang {

using llvm::SmallVectorImpl;
using llvm::StringRef;
using llvm::SmallString;

class DiagnosticsEngine;


class Preprocessor;

class Token;
class SourceLocation;
class TargetInfo;
class SourceManager;
class LangOptions;

/// Copy characters from Input to Buf, expanding any UCNs.
void expandUCNs(SmallVectorImpl<char> &Buf, StringRef Input);

/// NumericLiteralParser - This performs strict semantic analysis of the content
/// of a ppnumber, classifying it as either integer, floating, or erroneous,
/// determines the radix of the value and can convert it to a useful value.
class NumericLiteralParser {


  const char *const ThisTokBegin;
  const char *const ThisTokEnd;
  const char *DigitsBegin, *SuffixBegin; // markers
  const char *s; // cursor

  unsigned radix;

  bool saw_exponent, saw_period, saw_ud_suffix;

  SmallString<32> UDSuffixBuf;

public:
  NumericLiteralParser(StringRef TokSpelling);
  bool hadError : 1;
  bool isUnsigned : 1;
  bool isLong : 1;          // This is *not* set for long long.
  bool isLongLong : 1;
  bool isFloat : 1;         // 1.0f
  bool isImaginary : 1;     // 1.0i
  uint8_t MicrosoftInteger; // Microsoft suffix extension i8, i16, i32, or i64.

  bool isIntegerLiteral() const {
    return !saw_period && !saw_exponent;
  }
  bool isFloatingLiteral() const {
    return saw_period || saw_exponent;
  }

  bool hasUDSuffix() const {
    return saw_ud_suffix;
  }
  StringRef getUDSuffix() const {
    assert(saw_ud_suffix);
    return UDSuffixBuf;
  }
  unsigned getUDSuffixOffset() const {
    assert(saw_ud_suffix);
    return SuffixBegin - ThisTokBegin;
  }

  static bool isValidUDSuffix(const LangOptions &LangOpts, StringRef Suffix);

  unsigned getRadix() const { return radix; }

  /// GetIntegerValue - Convert this numeric literal value to an APInt that
  /// matches Val's input width.  If there is an overflow (i.e., if the unsigned
  /// value read is larger than the APInt's bits will hold), set Val to the low
  /// bits of the result and return true.  Otherwise, return false.
  bool GetIntegerValue(llvm::APInt &Val);

  /// GetFloatValue - Convert this numeric literal to a floating value, using
  /// the specified APFloat fltSemantics (specifying float, double, etc).
  /// The optional bool isExact (passed-by-reference) has its value
  /// set to true if the returned APFloat can represent the number in the
  /// literal exactly, and false otherwise.
  llvm::APFloat::opStatus GetFloatValue(llvm::APFloat &Result);

private:

  void ParseNumberStartingWithZero(SourceLocation TokLoc);

  static bool isDigitSeparator(char C) { return C == '\''; }

  enum CheckSeparatorKind { CSK_BeforeDigits, CSK_AfterDigits };

  /// \brief Ensure that we don't have a digit separator here.
  void checkSeparator(SourceLocation TokLoc, const char *Pos,
                      CheckSeparatorKind IsAfterDigits);

  /// SkipHexDigits - Read and skip over any hex digits, up to End.
  /// Return a pointer to the first non-hex digit or End.
  const char *SkipHexDigits(const char *ptr) {
    while (ptr != ThisTokEnd && (isHexDigit(*ptr) || isDigitSeparator(*ptr)))
      ptr++;
    return ptr;
  }

  /// SkipOctalDigits - Read and skip over any octal digits, up to End.
  /// Return a pointer to the first non-hex digit or End.
  const char *SkipOctalDigits(const char *ptr) {
    while (ptr != ThisTokEnd &&
           ((*ptr >= '0' && *ptr <= '7') || isDigitSeparator(*ptr)))
      ptr++;
    return ptr;
  }

  /// SkipDigits - Read and skip over any digits, up to End.
  /// Return a pointer to the first non-hex digit or End.
  const char *SkipDigits(const char *ptr) {
    while (ptr != ThisTokEnd && (isDigit(*ptr) || isDigitSeparator(*ptr)))
      ptr++;
    return ptr;
  }

  /// SkipBinaryDigits - Read and skip over any binary digits, up to End.
  /// Return a pointer to the first non-binary digit or End.
  const char *SkipBinaryDigits(const char *ptr) {
    while (ptr != ThisTokEnd &&
           (*ptr == '0' || *ptr == '1' || isDigitSeparator(*ptr)))
      ptr++;
    return ptr;
  }

};


}  // end namespace clang

#endif
