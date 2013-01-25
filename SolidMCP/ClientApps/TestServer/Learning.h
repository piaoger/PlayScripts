#pragma once

#if defined(LEARNING_MODULE_TESTER)

#include <PlayBoost/Global/Global.h>
#include <PlayBoost/Global/TestProxy.h>

#pragma comment(lib, "PlayBoost.lib")

struct LearningModuleTester
{
    static void Run()
    {
        SolidMCP::PlayBoost::TestProxy::Run();
    }
};

#endif