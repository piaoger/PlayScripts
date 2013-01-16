#ifndef GUARD_SMCPCORE_BEDROCK_CONFIG_CROSSTHINGS_SELECTOR_H
#define GUARD_SMCPCORE_BEDROCK_CONFIG_CROSSTHINGS_SELECTOR_H

// Platform Selector
//



// Microsoft Windows
// 
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#	define SMCP_PLATFORM_HEADER "Platform/Windows.h"
#else
#	error("Not supported")
#endif


// Compiler Selector
//

// Microsoft Visual Studio C++
//
#if defined(_MSC_VER)
#	define SMCP_COMPILER_HEADER "Compiler/VC.h"
#else
#	error("Not supported")
#endif


#if defined(SMCP_COMPILER_HEADER)
#	include SMCP_COMPILER_HEADER
#endif


#if defined(SMCP_PLATFORM_HEADER)
#	include SMCP_PLATFORM_HEADER
#endif

#endif // GUARD_SMCPCORE_BEDROCK_CONFIG_CROSSTHINGS_SELECTOR_H
