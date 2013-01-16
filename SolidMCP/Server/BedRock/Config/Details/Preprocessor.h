
#ifndef GUARD_SMCPCORE_BEDROCK_CONFIG_PREPROCESSOR_H
#define GUARD_SMCPCORE_BEDROCK_CONFIG_PREPROCESSOR_H

// Unicode or MBCS
//
#if defined(UNICODE) || defined(_UNICODE) || defined(SMCP_UNICODE)
#	define CHARACTER_SET "Unicode"
#	ifndef SMCP_UNICODE
#		define SMCP_UNICODE		// Internal unicde flag used in AdSim
#	endif
#	ifndef UNICODE
#		define UNICODE			// UNICODE is used by Windows headers
#	endif
#	ifndef _UNICODE
#		define _UNICODE			// _UNICODE is used by C-runtime/MFC headers
#	endif
#else
#	define CHARACTER_SET "Non-Unicode(MBCS)"
#endif


// Debug Flag
//
#if defined(DEBUG) || defined(_DEBUG)
#	define BUILD_CONFIGURATON "Debug"
#	ifndef SMCP_DEBUG
#		define SMCP_DEBUG		// Internal debug flag used in AdSim
#	endif
#	ifndef DEBUG
#		define DEBUG         // _DEBUGUNICODE is used by Windows headers
#	endif
#	ifndef _DEBUG
#		define _DEBUG        // _UNICODE is used by C-runtime/MFC headers
#	endif
#else
#	define BUILD_CONFIGURATON "Optimize"
#endif

#endif // GUARD_SMCPCORE_BEDROCK_CONFIG_PREPROCESSOR_H
