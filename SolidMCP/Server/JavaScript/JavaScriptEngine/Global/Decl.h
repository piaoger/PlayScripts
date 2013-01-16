
#ifndef GUARD_SMCPCORE_JAVASCRIPTENGINE_GLOBAL_DECL_H
#define GUARD_SMCPCORE_JAVASCRIPTENGINE_GLOBAL_DECL_H 

#pragma once

#include <BedRock/Config.h>

#ifdef SMCP_DLL
#ifdef SMCPCORE_JAVASCRIPTENGINE_DECL
#define EXPORT_CORE_JAVASCRIPTENGINE __declspec(dllexport)
#else
#define EXPORT_CORE_JAVASCRIPTENGINE __declspec(dllimport)
#endif
#else
#define EXPORT_CORE_JAVASCRIPTENGINE
#endif


#endif //GUARD_SMCPCORE_JAVASCRIPTENGINE_GLOBAL_DECL_H