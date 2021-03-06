

// smcp
#include <BedRock/TestSupport/AutoTest.h>

// boost
#include <PlayBoost/JSONSpirit/json_spirit_writer.h>
#include <PlayBoost/JSONSpirit/json_spirit_reader.h>
#include <PlayBoost/JSONSpirit/json_spirit_value.h>

// std
#include <string>
#include <iostream>
#include <fstream>

namespace tut 
{ 
    struct try_json_spiritw_data
    {
        struct Address
        {
            int house_number_;
            std::wstring road_;
            std::wstring town_;
            std::wstring county_;
            std::wstring country_;
        };

        friend bool operator==( const Address& a1, const Address& a2 )
        {
            return
                ( a1.house_number_ == a2.house_number_ ) &&
                ( a1.road_         == a2.road_ ) &&
                ( a1.town_         == a2.town_ ) &&
                ( a1.county_       == a2.county_ ) &&
                ( a1.country_      == a2.country_ );
        }

        static void write_address(json_spirit::wArray& a, const Address& addr )
        {
            json_spirit::wObject addr_obj;

            addr_obj.push_back(json_spirit::wPair( L"house_number", addr.house_number_ ) );
            addr_obj.push_back(json_spirit::wPair( L"road",         addr.road_ ) );
            addr_obj.push_back(json_spirit::wPair( L"town",         addr.town_ ) );
            addr_obj.push_back(json_spirit::wPair( L"county",       addr.county_ ) );
            addr_obj.push_back(json_spirit::wPair( L"country",      addr.country_ ) );

            a.push_back( addr_obj );
        }

        static Address read_address( const json_spirit::wObject& obj )
        {
            Address addr;

            for(json_spirit::wObject::size_type i = 0; i != obj.size(); ++i )
            {
                const json_spirit::wPair& pair = obj[i];

                const std::wstring& name  = pair.name_;
                const json_spirit::wValue&  value = pair.value_;

                if( name == L"house_number" )
                {
                    addr.house_number_ = value.get_int();
                }
                else if( name == L"road" )
                {
                    addr.road_ = value.get_str();
                }
                else if( name == L"town" )
                {
                    addr.town_ = value.get_str();
                }
                else if( name == L"county" )
                {
                    addr.county_ = value.get_str();
                }
                else if( name == L"country" )
                {
                    addr.country_ = value.get_str();
                }
                else
                {
                    assert( false );
                }
            }

            return addr;
        }

        static void write_addrs( const char* file_name, const Address addrs[] )
        {
            json_spirit::wArray addr_array;

            for( int i = 0; i < 5; ++i ) {
                write_address( addr_array, addrs[i] );
            }

            std::wofstream os( file_name );

            write_formatted( addr_array, os );

            os.close();
        }

        static std::vector< Address > read_addrs( const char* file_name )
        {
            std::wifstream is( file_name );

            json_spirit::wValue value;

            read( is, value );

            const json_spirit::wArray& addr_array = value.get_array();

            std::vector< Address > addrs;

            for( unsigned int i = 0; i < addr_array.size(); ++i ) {
                addrs.push_back( read_address( addr_array[i].get_obj() ) );
            }

            return addrs;
        }

    };

    typedef test_group<try_json_spiritw_data> TestGroup;
    TestGroup ThisTestGroup("Try  json_spiritw");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("Try JSON Spirit");

        const Address addrs[5] = {
            { 42, L"East Road",  L"Newtown",     L"Essex",         L"England" },
            { 1,  L"West Road",  L"Hull",        L"Yorkshire",     L"England" },
            { 12, L"South Road",   L"Aberystwyth", L"Dyfed",         L"Wales"   },
            { 45, L"North Road",   L"Paignton",    L"Devon",         L"England" },
            { 78, L"Upper Street", L"Ware",        L"Hertfordshire", L"England" } };

            const char* file_name( "c:\\demow.txt" );

            write_addrs( file_name, addrs );

            std::vector< Address > new_addrs = read_addrs( file_name );

            assert( new_addrs.size() == 5 );

            for( int i = 0; i < 5; ++i ) {
                assert( new_addrs[i] == addrs[i] );
            }

    } 
}; 
