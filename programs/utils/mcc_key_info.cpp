#include <fcc/blockchain/address.hpp>
#include <fcc/blockchain/pts_address.hpp>
#include <fcc/blockchain/types.hpp>
#include <fcc/utilities/key_conversion.hpp>
#include <fc/crypto/elliptic.hpp>
#include <fc/io/json.hpp>
#include <fc/reflect/variant.hpp>
#include <fc/filesystem.hpp>
#include <fc/variant_object.hpp>
#include <fc/exception/exception.hpp>

#include <iostream>


using namespace mcc::blockchain;

int main( int argc, char** argv )
{
    if( argc == 2 )
    {
        try
        {
            mcc::blockchain::public_key_type key(argv[1]);
            fc::mutable_variant_object obj;

            obj["public_key"] = key;
            obj["native_address"] = mcc::blockchain::address(key.operator fc::ecc::public_key_data());
            obj["pts_address"] = mcc::blockchain::pts_address(key.operator fc::ecc::public_key());

            std::cout << fc::json::to_pretty_string(obj);
            return 0;

        }
        catch (fc::exception e) 
        {
            std::cout << e.to_detail_string();
        }
    }
    return -1;
}
