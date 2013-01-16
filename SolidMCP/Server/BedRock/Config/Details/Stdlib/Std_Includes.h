
#ifndef GUARD_SMCPCORE_BEDROCK_STDLIB_STDINCLUDES_H
#define GUARD_SMCPCORE_BEDROCK_STDLIB_STDINCLUDES_H


#include <sys/types.h>
#include <sys/timeb.h>
#include <sys/stat.h>


// ANSI C Library
//
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <cassert>

#include <fcntl.h>




// STL containers
//
#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>

// C++ Stream related
//
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <streambuf>
#include <numeric>

// C++ Versatiled
//
#include <locale>
#include <typeinfo>

#include <functional>
#include <exception>
#include <stdexcept>
#include <locale>
#include <memory>
#include <new>

#include <algorithm>
#include <limits>


// TR1
#include <tuple>


//#include <stdio.h>
#ifndef os_snprintf
#	ifdef SMCP_COMPILER_MSVC
#		define os_snprintf _snprintf
#	else
#		define os_snprintf snprintf
#	endif
#endif


#endif // GUARD_SMCPCORE_BEDROCK_STDLIB_STDINCLUDES_H
