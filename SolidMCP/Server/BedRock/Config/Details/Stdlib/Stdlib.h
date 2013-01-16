#ifndef GUARD_SMCPCORE_BEDROCK_STD_H
#define GUARD_SMCPCORE_BEDROCK_STD_H

#include "Std_Includes.h"

// After changing the implementation to the nexe one, there is a build error in StringBuilder
// I have to disable a couple of Append methods. so, let's disable following override for now.

// snprintf / swnprintf
//
#ifndef snprintf
#	ifdef SMCP_COMPILER_MSVC
#		ifndef _snprintf
#			define snprintf _snprintf
#		else
#			error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
#		endif
#	else
#		error ("snprintf is not defined.")
#	endif
#endif

#ifndef snwprintf
#	ifdef SMCP_COMPILER_MSVC
#		ifndef _snwprintf
#			define snwprintf _snwprintf
#		else
#			error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
#		endif
#	else
#		error ("snwprintf is not defined.")
#	endif
#endif


#if defined(SMCP_COMPILER_MSVC)
#   define wcsicmp _wcsicmp
#   define stricmp _stricmp
#endif

#endif // GUARD_SMCPCORE_BEDROCK_STD_H
