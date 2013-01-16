
#ifndef GUARD_SMCPCORE_BEDROCK_STRING_STRING_H
#define GUARD_SMCPCORE_BEDROCK_STRING_STRING_H

#include "../Global/Global.h"

BEGIN_NAMESPACE_BEDROCK

// WideString
//
typedef std::wstring    WideString;

// NarrowString
//
typedef std::string     NarrowString;


// Unicode support
typedef std::basic_string<BedRock::AsciiChar> AsciiString;
typedef std::basic_string<BedRock::Utf16Char> Utf16String;
typedef std::basic_string<BedRock::Utf32Char> Utf32String;

#if defined(SMCP_UNICODE)
typedef WideString String;
#else
typedef NarrowString String;
#endif

// StringTypeOf
//
template<typename CharT> struct StringTypeOf;

template<>
struct StringTypeOf<NarrowChar>
{
	typedef NarrowString Type;
};

template<>
struct StringTypeOf<WideChar>
{
	typedef WideString Type;
};

template<>
struct StringTypeOf<NarrowString>
{
	typedef NarrowString Type;
};

template<>
struct StringTypeOf<WideString>
{
	typedef WideString Type;
};

// CharTypeOf
//
template<typename StringT> struct CharTypeOf;

template<>
struct CharTypeOf<NarrowString>
{
	// In actual, we can also use value_type instead.
	// typedef string::value_type	Char_Type;
	//
	typedef NarrowChar Type;
};

template<>
struct CharTypeOf<WideString>
{
	typedef WideChar Type;
};


template<>
struct CharTypeOf<NarrowChar>
{
	// In actual, we can also use value_type instead.
	// typedef string::value_type	Char_Type;
	//
	typedef NarrowChar Type;
};

template<>
struct CharTypeOf<WideChar>
{
	typedef WideChar Type;
};


END_NAMESPACE_BEDROCK

#endif // GUARD_SMCPCORE_BEDROCK_STRING_STRING_H
