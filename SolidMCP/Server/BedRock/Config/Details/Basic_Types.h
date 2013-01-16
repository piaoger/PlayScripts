
// Add #includes of Standard C++/C headers are encouraged to be placed here.
// length of some types on different plateforms are not same, so typedef can be good idea here.
//
#ifndef GUARD_SMCPCORE_BEDROCK_CONFIG_BASICTYPES_H
#define GUARD_SMCPCORE_BEDROCK_CONFIG_BASICTYPES_H

#if defined(GUARD_SMCPCORE_BEDROCK_CONFIG_CROSSTHINGS_SELECTOR_H)
#include "CrossThings_Selector.h"
#endif

#if defined(GUARD_SMCPCORE_BEDROCK_CONFIG_PREPROCESSOR_H)
#include "Preprocessor.h"
#endif


namespace AdSim
{
	namespace BedRock
	{
		typedef float Float32;
		typedef double Float64;


		// For General usage.
		//
		typedef int Int;
		typedef unsigned int UInt;

		typedef long Long;
		typedef unsigned long ULong;

		//  8-bit types
		//
#if defined (SMCP_COMPILER_MSVC)
		typedef signed char Int8;
		typedef unsigned char UInt8;
# else
#	error defaults not correct; 
# endif

		typedef unsigned char Byte;


		//  16-bit types
		//
#if defined (SMCP_COMPILER_MSVC)
		typedef short			Int16;
		typedef unsigned short	UInt16;
# else
#	error defaults not correct;
# endif


		//  32-bit types
		//
#if defined (SMCP_COMPILER_MSVC)
		typedef long			Int32;
		typedef unsigned long	UInt32;
#else
#	error defaults not correct;
#endif

		//  64-bit types
		//
#if defined (SMCP_COMPILER_MSVC)
		typedef __int64              Int64;
		typedef unsigned __int64     UInt64;
#else
#	error defaults not correct;
#endif

	}
}

#endif // GUARD_SMCPCORE_BEDROCK_CONFIG_BASICTYPES_H
