

// smcp
#include <BedRock/TestSupport/AutoTest.h>

// boost
#include <boost/asio.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// std
#include <iostream>
#include <string>

namespace tut 
{
    struct try_asio_async_data
    { 
    };

    typedef test_group<try_asio_async_data> TestGroup;
    TestGroup ThisTestGroup("Try boost asio aync");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("Try asio async timer");

        class LocalPrinter
        {
        public:
            static void print(const boost::system::error_code& /*error*/)
            {
                std::cout << "async printing!\n";
            }
        };

        std::cout << "begin.\n";

        boost::asio::io_service io;
        boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
        t.async_wait(LocalPrinter::print);
        io.run();

        std::cout << "finished.\n";
    }
};