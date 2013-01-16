
#pragma once


#if defined(MYWORK_MODULE_TESTER)

#pragma comment(lib, "JavaScriptEngine.lib")
#include <JavaScript/JavaScriptEngine/Global/Global.h>
#include <JavaScript/JavaScriptEngine/Global/TestProxy.h>

using namespace SolidMCP;

struct MyWorkModuleTester
{
	static void Run()
	{
		JavaScriptEngine::TestProxy::Run();
	}
};

#endif
