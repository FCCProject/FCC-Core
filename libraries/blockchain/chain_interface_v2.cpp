#include <fcc/blockchain/chain_interface.hpp>
#include <fcc/blockchain/fork_blocks.hpp>

namespace mcc { namespace blockchain {

share_type chain_interface::get_asset_registration_fee_v2( uint8_t symbol_length )const
{
    if( get_head_block_num() < MCC_V0_4_24_FORK_BLOCK_NUM )
        return get_asset_registration_fee_v1();

    static const share_type long_symbol_price = 500 * MCC_BLOCKCHAIN_PRECISION;
    static const share_type short_symbol_price = 1000 * long_symbol_price;
    FC_ASSERT( long_symbol_price > 0 );
    FC_ASSERT( short_symbol_price > long_symbol_price );
    return symbol_length <= 5 ? short_symbol_price : long_symbol_price;
}

} } // mcc::blockchain
