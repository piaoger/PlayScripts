 
#include <iostream>
#include <boost/filesystem.hpp>
 

#include <BedRock/TestSupport/AutoTest.h>
#include <string>

namespace tut 
{ 
    struct try_boost_filesystem_data
    {
 struct Run
    {
    void operator()(void)
        {
   
        std::cout<<__FUNCTION__<<std::endl;
        }
    };
    };

    typedef test_group<try_boost_filesystem_data> TestGroup;
    TestGroup ThisTestGroup("Try boost_filesystem");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("Try boost_filesystem");

 
    } 

 

}; 
