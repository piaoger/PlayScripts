
#include <BedRock/TestSupport/AutoTest.h>

#include <boost/regex.hpp>
#include <string>
#include <iostream>

namespace tut
{
    struct try_boost_regex_data
    {
        struct Run
        {
            void operator()(void)
            {
                std::cout<<__FUNCTION__<<std::endl;
            }
        };
    };

    typedef test_group<try_boost_regex_data> TestGroup;
    TestGroup ThisTestGroup("Try boost_regex");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("boost::regex - Parsing IP address");

        // This example is copied from following page
        // http://www.cnblogs.com/hucn/archive/2011/05/09/regex_search.html

        // IP Address policy
        boost::regex expression("([0-9]+).([0-9]+).([0-9]+)");

        std::string ipAddress = "192.168.1.1";
        boost::smatch what;
        if ( boost::regex_search(ipAddress, what, expression) ) {
            std::cout << what.size() << std::endl;
            for (size_t i = 0; i < what.size(); ++i) {
                if (what[i].matched)
                    std::cout << what[i] << std::endl;
            }
        }
    }
}; 
