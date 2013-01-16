
#ifndef GUARD_SMCPCORE_BEDROCK_CONFIG_MORETYPES_H
#define GUARD_SMCPCORE_BEDROCK_CONFIG_MORETYPES_H

#if !defined(GUARD_SMCPCORE_BEDROCK_CONFIG_BASICTYPES_H)
#include "Basic_Types.h"
#endif

namespace AdSim
{
    namespace BedRock
    {

#if (_SMCP_WCHAR_MAX == _SMCP_SHRT_MAX)
        typedef char        AsciiChar;  // Utf8
        typedef wchar_t     Utf16Char;  // Utf16
        typedef UInt32      Utf32Char;  // UTF32
#else
        typedef char        AsciiChar;
        typedef UInt16      Utf16Char;
        typedef wchar_t     Utf32Char;
#endif

        typedef char        NarrowChar;
        typedef wchar_t     WideChar;
    }
}

#endif // GUARD_SMCPCORE_BEDROCK_CONFIG_MORETYPES_H
