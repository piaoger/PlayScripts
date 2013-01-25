


// smcp
#include <BedRock/TestSupport/AutoTest.h>

// boost
#include <boost/asio.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>

// std
#include <iostream>
#include <string>

namespace tut 
{ 
    struct try_asio_callback_data
    {
        static void print(const boost::system::error_code& /*error*/, boost::asio::deadline_timer* timer, int* count)
        {
            if (*count < 5) {
                std::cout << *count << "\n";
                ++(*count);

                timer->expires_at(timer->expires_at() + boost::posix_time::seconds(1));
                timer->async_wait(boost::bind(print, boost::asio::placeholders::error, timer, count));
            }
        }

        class AnsycPrinter
        {
        public:
            AnsycPrinter(boost::asio::io_service& io)
                : m_timer(io, boost::posix_time::seconds(1))
                , m_count(0)
            {
                m_timer.async_wait(boost::bind(&AnsycPrinter::print, this));
            }

            ~AnsycPrinter()
            {
                std::cout << "Final count is " << m_count << "\n";
            }

            void print()
            {
                if (m_count < 5) {
                    std::cout << m_count << "\n";
                    ++m_count;

                    m_timer.expires_at(m_timer.expires_at() + boost::posix_time::seconds(1));
                    m_timer.async_wait(boost::bind(&AnsycPrinter::print, this));
                }
            }

        private:
            boost::asio::deadline_timer m_timer;
            int m_count;
        };
    };

    typedef test_group<try_asio_callback_data> TestGroup;
    TestGroup ThisTestGroup("Try boost asio callback");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("Try boost asio async callback");

        boost::asio::io_service io;

        int count = 0;
        boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
        t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));
        io.run();

        std::cout << "Final count is " << count << "\n";
    }

    template<> 
    template<> 
    void TestObject::test<2>() 
    {
        set_test_name("Try AsyncPrinter");

        boost::asio::io_service io;
        AnsycPrinter p(io);
        io.run();
    }
}; 
