
#include "Global/Precompiled.h"

#include "TestProxy.h"
#include <BedRock/TestSupport/AutoTest.h>

#include <exception>
#include <iostream>

using tut::runner;

using std::exception;
using std::cout;
using std::cerr;
using std::endl;

#include <iostream>
using namespace std;

 namespace tut
{
   test_runner_singleton runner;
}

BEGIN_NAMESPACE_JAVASCRIPTENGINE

int TestProxy::Run()
{

 int i['0'];
	i[0]= 9;
	tut::console_reporter reporter;

	bool bOK = true;

	try
	{
		runner.get().set_callback(&reporter);
		runner.get().run_tests();

		if (!reporter.all_ok())
		{
			cout << endl;
			cout << "*********************************************************"
				<< endl;
			cout << "WARNING: THIS VERSION OF TUT IS UNUSABLE DUE TO ERRORS!!!"
				<< endl;
			cout << "*********************************************************"
				<< endl;
		}
		else
		{
			cout << endl;
			cout << "THIS VERSION OF TUT IS CORRECT" << endl;
		}
	}
	catch (const std::exception& ex)
	{
		cerr << "tut raised ex: " << ex.what() << endl;
		return 1;
	}
	catch( ... )
	{
		cerr << "tut raised unknown exception" << endl;
		return 1;
	}

	return !reporter.all_ok();
}

END_NAMESPACE_JAVASCRIPTENGINE