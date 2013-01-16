
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
    _set_error_mode(_OUT_TO_STDERR);

#if defined(MYWORK_MODULE_TESTER)
    MyWorkModuleTester::Run();
#endif

#if defined(LEARNING_MODULE_TESTER)
    LearningModuleTester::Run();
#endif

    return 1;
}
