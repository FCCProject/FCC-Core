#pragma once

#define MCC_WALLET_VERSION                                  uint32_t( 113 )

#define MCC_WALLET_MIN_PASSWORD_LENGTH                      8
#define MCC_WALLET_MIN_BRAINKEY_LENGTH                      32

#define MCC_WALLET_DEFAULT_UNLOCK_TIME_SEC                  ( 60 * 60 )

#define MCC_WALLET_DEFAULT_TRANSACTION_FEE                  1 // XTS

#define MCC_WALLET_DEFAULT_TRANSACTION_EXPIRATION_SEC       ( 60 * 60 )

#define WALLET_DEFAULT_MARKET_TRANSACTION_EXPIRATION_SEC    ( 60 * 10 )
