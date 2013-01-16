#ifndef GUARD_SMCPCORE_BEDROCK_SUFFIX_H
#define GUARD_SMCPCORE_BEDROCK_SUFFIX_H

#include "Support.h"

// Include Guard + pragma once + Redundant Include Guards
// 
// #ifndef GUARD_SMCPCORE_BEDROCK_SUFFIX_H
// // MS compatible compilers support #pragma once
// #if defined(_MSC_VER) && (_MSC_VER >= 1020)
// # pragma once
// #endif
// #endif
// 
// #if SMCP_NOGUARD(GUARD_SMCPCORE_BEDROCK_SUFFIX_H)
// #include "Suffix.h"
// #endif
//
#define SMCP_NOGUARD(FileGuard) ( !defined(##FileGuard))

//  #if SMCP_COMPILER(MSVC) && SMCP_PLATFORM(WINDOWS)
//  #endif
#define SMCP_COMPILER(name) ( defined SMCP_COMPILER_##name && SMCP_COMPILER_##name)
#define SMCP_PLATFORM(name) (defined SMCP_PLATFORM_##name && SMCP_PLATFORM_##name)

//  #define SMCP_ENABLE_REVOLUTION 1
//  #if SMCP_ENABLED(REVOLUTION)
//  #endif
#define SMCP_ENABLED(name) (defined SMCP_ENABLE_##name && SMCP_ENABLE_##name)

// #define SMCP_HAVE_SOLDIER 1
// #if SMCP_HAVE(SOLDIER)
// #endif
#define SMCP_HAVE(name) (defined SMCP_HAVE_##name && SMCP_HAVE_##name)


// Token Concatenation(##)
// The ## preprocessor operator is used to concatenate two tokens into a third valid token:
// #define Glue(a,b) a ## b
// Glue(whole,num) ---> wholenum

// Helper macro SMCP_STRINGIZE:
// Converts the parameter X to a string after macro replacement
// on X has been performed.
//
#define SMCP_STRINGIZE(X) SMCP_DO_STRINGIZE(X)
#define SMCP_DO_STRINGIZE(X) #X

// Helper macro SMCP_JOIN:
// The following piece of macro magic joins the two
// arguments together
//
#define SMCP_JOIN(X, Y ) SMCP_DO_JOIN( X, Y )
#define SMCP_DO_JOIN(X, Y ) X##Y


#define _SMCP_FORCE_WSTRING_(s)       L ## s
#define _SMCP_FORCE_NSTRING_(s)       (s)

#ifdef _UNICODE
#   define _SMCP_FORCE_STRING_(s)        _SMCP_FORCE_WSTRING_(s)
#else
#	ifdef _MBCS
#		define _SMCP_FORCE_STRING_(s)    _SMCP_FORCE_NSTRING_(s)
#	else
//#pragma SMCP_REMINDER("_MBCS/_UNICODE Not Defined, Make MBCS As the default")
#		define _MBCS
#		define _SMCP_FORCE_STRING_(s)    _SMCP_FORCE_NSTRING_(s)
#	endif
#endif


#define _DNTS(s)            _SMCP_FORCE_STRING_(s)    // Do Not Translate SMCP String.
#define _DNTW(s)            _SMCP_FORCE_WSTRING_(s)   // Do Not Translate Wide String.
#define _DNTN(s)            _SMCP_FORCE_NSTRING_(s)   // Do Not Translate Narrow String.


// Plateform/Compiler Selecting.Using following Macro in your applications.
// SMCP_PLATFORM_WINDOWS
// SMCP_PLATFORM_MACOSX
// SMCP_PLATFORM_LINUX
#include "Details/CrossThings_Selector.h"

// Only support MSVC currently
//
#if !defined(SMCP_COMPILER_MSVC) && !defined(SMCP_COMPILER_GCC)
#	error("Notice: Only working on MSVC and GCC now, Compatiable? You bet it!")
#endif


// Deal with Pre-processors: Character Set / 
//
#include "Details/Preprocessor.h"

// Standard C/C++ Library
//
#include "Details/Stdlib/Stdlib.h"

// Basic Types 
//
#include "Details/Basic_Types.h"
#include "Details/More_Types.h"

// Debugging Macros or Utilites
//
#include "Details/Debugging.h"

// Copied from ..\Microsoft Visual Studio 9.0\VC\include\stdlib.h
// Define NULL pointer value
// 
#ifndef NULL
#	ifdef __cplusplus
#		define NULL    0
#	else
#		define NULL    ((void *)0)
#	endif
#endif

// Workaround for names overridden by defined Macros
// One known example is max/min:
// In windows, max/min are defined if you include <windows.h>
// so, you will encounter problem while using std::max or std::min if you include it before std's <algorithm>
// In Boost, there is a workaround by adding an empty Macro BOOST_PREVENT_MACRO_SUBSTITUTION  after max or min,
// so that max and min are not recognized as the ones defined by macors, but std::max/min instead.
// Just borrow it from boost.
//
#define SMCP_WORKAROUND_NAME_OVERRIDE 

// Macros for namespace
//
//#if defined(SMCP_NO_NAMESPACE)
//#   define SMCP_BEGIN_NAMESPACE(ns)
//#   define SMCP_END_NAMESPACE(ns)
//#else
//#   define SMCP_BEGIN_NAMESPACE(ns) namespace ns {
//#   define SMCP_END_NAMESPACE(ns)                }
//#endif
//
#   define SMCP_BEGIN_NAMESPACE(ns) namespace ns {
#   define SMCP_END_NAMESPACE(ns)                }
#   define BEGIN_ANONYMOUS_NAMESPACE  namespace {
#   define END_ANONYMOUS_NAMESPACE              }

// -------------------------------------------------------------------------------
// Error Returns
// -------------------------------------------------------------------------------
#define SMCP_ERROR_LEAVE(condition) \
    if (condition) return;

#define SMCP_ERROR_BREAK(condition) \
    if (condition) break;

#define SMCP_ERROR_RETURN(condition, retval) \
    if (condition) return retval;

#define SMCP_ASSERT(condition)		do {assert(condition) ;} while(0)


// Avoid "unused parameter" warnings
//
#if !defined(SMCP_COMPILER_MSVC)
template <typename T> inline void SMCP_UNREF_PARAMETER(T& p) { (void)p; }
#  define SMCP_UNREF_PARAMETER(p) SMCP_UNREF_PARAMETER(x);
#else
#  define SMCP_UNREF_PARAMETER(p) (void)p;
#endif


#define ENABLE_CPP11_SUPPORT

#endif // GUARD_SMCPCORE_BEDROCK_SUFFIX_H