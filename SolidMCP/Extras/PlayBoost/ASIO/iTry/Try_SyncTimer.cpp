
// smcp
#include <BedRock/TestSupport/AutoTest.h>

// boost
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// std
#include <iostream>
#include <string>

namespace tut 
{ 
    struct try_asio_sync_data
    {
    };

    typedef test_group<try_asio_sync_data> TestGroup;
    TestGroup ThisTestGroup("Try asio sync timer");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("test asio sync timer");

        boost::asio::io_service io;
        boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
        t.wait();

        std::cout << "sync timer finished.\n";
    }

};