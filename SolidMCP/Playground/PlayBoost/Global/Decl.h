
#ifndef SMCPCORE_DEC_PLAYBOOST_H
#define SMCPCORE_DEC_PLAYBOOST_H 

 #include <BedRock/Config.h>

#ifdef SMCP_DLL
    #ifdef SMCPCORE_PLAYBOOST_DECL
        #define EXPORT_CORE_PLAYBOOST __declspec(dllexport)
    #else
        #define EXPORT_CORE_PLAYBOOST __declspec(dllimport)
    #endif
#else
    #define EXPORT_CORE_PLAYBOOST
#endif

// Macros for namespace
// SolidMCP::PlayBoost
//
#define BEGIN_NAMESPACE_PLAYBOOST SMCP_BEGIN_NAMESPACE(SolidMCP) \
                                 SMCP_BEGIN_NAMESPACE(PlayBoost)

#define END_NAMESPACE_PLAYBOOST SMCP_END_NAMESPACE(SolidMCP) \
                               SMCP_END_NAMESPACE(PlayBoost)



#endif //SMCPCORE_DEC_PLAYBOOST_H