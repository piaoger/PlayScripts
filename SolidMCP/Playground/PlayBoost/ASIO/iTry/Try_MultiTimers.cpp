

// smcp
#include <BedRock/TestSupport/AutoTest.h>

// boost
#include <boost/asio.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

// std
#include <iostream>
#include <string>

namespace tut 
{
    struct try_asio_multitimers_data
    {
        class AsyncPrinter
        {
        public:
            AsyncPrinter(boost::asio::io_service& io)
                : m_strand(io)
                , m_firstTimer(io, boost::posix_time::seconds(1))
                , m_secondTimer(io, boost::posix_time::seconds(1))
                ,  m_count(0)
            {
                m_firstTimer.async_wait(m_strand.wrap(boost::bind(&AsyncPrinter::firstPrint, this)));
                m_secondTimer.async_wait(m_strand.wrap(boost::bind(&AsyncPrinter::secondPrint, this)));
            }

            ~AsyncPrinter()
            {
                std::cout << "Final count is " << m_count << "\n";
            }

            void firstPrint()
            {
                if (m_count < 10) {
                    std::cout << "First timer: " << m_count << "\n";
                    ++m_count;

                    m_firstTimer.expires_at(m_firstTimer.expires_at() + boost::posix_time::seconds(1));
                    m_firstTimer.async_wait(m_strand.wrap(boost::bind(&AsyncPrinter::firstPrint, this)));
                }
            }

            void secondPrint()
            {
                if (m_count < 10) {
                    std::cout << "Second Timer: " << m_count << "\n";
                    ++m_count;

                    m_secondTimer.expires_at(m_secondTimer.expires_at() + boost::posix_time::seconds(1));
                    m_secondTimer.async_wait(m_strand.wrap(boost::bind(&AsyncPrinter::secondPrint, this)));
                }
            }

        private:
            boost::asio::strand m_strand;
            boost::asio::deadline_timer m_firstTimer;
            boost::asio::deadline_timer m_secondTimer;
            int m_count;
        };
    };

    typedef test_group<try_asio_multitimers_data> TestGroup;
    TestGroup ThisTestGroup("Try asio multitimers");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("Test asio multiple timers");

        boost::asio::io_service io;
        AsyncPrinter printer(io);
        boost::thread printThread(boost::bind(&boost::asio::io_service::run, &io));
        io.run();
        printThread.join();
    }
}; 
