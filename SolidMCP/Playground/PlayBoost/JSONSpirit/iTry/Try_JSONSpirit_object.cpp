
#include <PlayBoost/JSONSpirit/json_spirit_writer.h>
#include <PlayBoost/JSONSpirit/json_spirit_reader.h>
#include <PlayBoost/JSONSpirit/json_spirit_value.h>

#include <BedRock/TestSupport/AutoTest.h>

#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <fstream>

using namespace json_spirit;
using namespace std;

namespace tut 
{ 
    struct try_json_spirit_data
    {
        struct Address
        {
            int house_number_;
            std::string road_;
            std::string town_;
            std::string county_;
            std::string country_;
        };

        friend bool operator == ( const Address& a1, const Address& a2 )
        {
            return ( a1.house_number_ == a2.house_number_ ) &&
                ( a1.road_         == a2.road_ ) &&
                ( a1.town_         == a2.town_ ) &&
                ( a1.county_       == a2.county_ ) &&
                ( a1.country_      == a2.country_ );
        }

        static void writeAddress( Array& a, const Address& addr )
        {
            Object addr_obj;

            addr_obj.push_back( Pair( "house_number", addr.house_number_ ) );
            addr_obj.push_back( Pair( "road",         addr.road_ ) );
            addr_obj.push_back( Pair( "town",         addr.town_ ) );
            addr_obj.push_back( Pair( "county",       addr.county_ ) );
            addr_obj.push_back( Pair( "country",      addr.country_ ) );

            a.push_back( addr_obj );
        }

        // Read address Information from input Json Object
        static Address readAddress( const Object& obj )
        {
            Address addr;

            for( Object::size_type i = 0; i != obj.size(); ++i ) {

                const Pair& pair = obj[i];

                const string& name  = pair.name_;
                const Value&  value = pair.value_;

                if( name == "house_number" ) {
                    addr.house_number_ = value.get_int();
                } else if( name == "road" ) {
                    addr.road_ = value.get_str();
                } else if( name == "town" ) {
                    addr.town_ = value.get_str();
                } else if( name == "county" ) {
                    addr.county_ = value.get_str();
                } else if( name == "country" ) {
                    addr.country_ = value.get_str();
                } else {
                    assert( false );
                }
            }

            return addr;
        }

        static void write_addrs( const char* file_name, const Address addrs[] )
        {
            Array addr_array;

            for( int i = 0; i < 5; ++i ) {
                writeAddress( addr_array, addrs[i] );
            }

            ofstream os( file_name );
            write_formatted( addr_array, os );

            os.close();
        }

        static std::vector< Address > read_addrs( const char* file_name )
        {
            ifstream is( file_name );

            Value value;

            read( is, value );

            const Array& addr_array = value.get_array();

            std::vector< Address > addrs;

            for( unsigned int i = 0; i < addr_array.size(); ++i )
            {
                addrs.push_back( readAddress( addr_array[i].get_obj() ) );
            }

            return addrs;
        }

    };

    typedef test_group<try_json_spirit_data> TestGroup;
    TestGroup ThisTestGroup("Try  json_spirit");

    typedef TestGroup::object TestObject;

    template<>
    template<>
    void TestObject::test<1>() 
    {
        set_test_name("Try JSON Spirit");

        const Address addrs[5] = {
            { 42, "East Street",  "Newtown",     "Essex",         "England" },
            { 1,  "West Street",  "Hull",        "Yorkshire",     "England" },
            { 12, "South Road",   "Aberystwyth", "Dyfed",         "Wales"   },
            { 45, "North Road",   "Paignton",    "Devon",         "England" },
            { 78, "Upper Street", "Ware",        "Hertfordshire", "England" } };

            const char* file_name( "c:\\demo.txt" );

            write_addrs( file_name, addrs );

            vector< Address > new_addrs = read_addrs( file_name );

            assert( new_addrs.size() == 5 );

            for( int i = 0; i < 5; ++i )
            {
                assert( new_addrs[i] == addrs[i] );
            }

    }
}; 
