

// smcp
#include <BedRock/TestSupport/AutoTest.h>

// boost
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// std
#include <iostream>
#include <string>

namespace tut 
{
    struct try_asio_tcptimesync_data
    {
    };

    typedef test_group<try_asio_tcptimesync_data> TestGroup;
    TestGroup ThisTestGroup("Try asio tcptimesync");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("test asio tcptimesync");

        boost::asio::io_service io_service;

        boost::asio::ip::tcp::resolver resolver(io_service);
        boost::asio::ip::tcp::resolver::query query("time-a.nist.gov", "daytime");
        boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        boost::asio::ip::tcp::resolver::iterator end;

        boost::asio::ip::tcp::socket socket(io_service);
        boost::system::error_code error = boost::asio::error::host_not_found;
        while (error && endpoint_iterator != end) {
            socket.close();
            socket.connect(*endpoint_iterator++,  error );
        }

        if (error) {
            std::cout << "Connection failure" <<std::endl;
            throw error;
        }

        for (;;) {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf),  error );

            if (error == boost::asio::error::eof) {
                std::cout << "Connection closed cleanly by peer" <<std::endl;
                break;
            } else if (error) {
                std::cout << "Some other error." <<std::endl;
                throw error;
            }

            std::cout.write(buf.data(), len);
        }
    }

    template<> 
    template<> 
    void TestObject::test<2>() 
    {
        set_test_name("test asci tecptimesync server");

    //    struct LocalServer
    //    {
    //        static std::string make_daytime_string()
    //        {
    //            std::time_t now = std::time(0);
    //            return std::ctime(&now);
    //        }
    //    };

    //    boost::asio::io_service io_service;
    //    boost::asio::ip::tcp::acceptor acceptor(io_service,  boost::asio::ip::tcp::endpoint( boost::asio::ip::tcp::v4(), 13));

    //    for ( ; ; ) {
    //        boost::asio::ip::tcp::socket socket(io_service);
    //        acceptor.accept(socket);

    //        std::string message = LocalServer::make_daytime_string();
    //        boost::system::error_code error;
    //        boost::asio::write(socket, boost::asio::buffer(message),boost::asio::transfer_all(), error);
    //   }
    }
}; 
