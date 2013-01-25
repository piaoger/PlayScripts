
// smcp
#include <BedRock/TestSupport/AutoTest.h>

// boost
#include <boost/thread.hpp>

// std
#include <iostream>
#include <string>

namespace tut 
{
    struct try_boost_thread_functor_data
    {
        struct Run
        {
            void operator()(void)
            {
                std::cout<<__FUNCTION__<<std::endl;
            }
        };
    };

    typedef test_group<try_boost_thread_functor_data> TestGroup;
    TestGroup ThisTestGroup("Try boost thread functor");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("test boost thread functor 1");

        Run runner;
        boost::thread myThread(runner);
        myThread.join();
    }

    template<> 
    template<> 
    void TestObject::test<2>() 
    {
        set_test_name("test boost mutex");

        boost::mutex myMutex;
        myMutex.lock();
    }
}; 
