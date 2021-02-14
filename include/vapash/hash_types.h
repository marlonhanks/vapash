/* vapash: C/C++ implementation of Vapash, the Vapory Proof of Work algorithm.
 * Copyright 2018 Pawel Bylica.
 * Licensed under the Apache License, Version 2.0. See the LICENSE file.
 */

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

union vapash_hash256
{
    uint64_t word64s[4];
    uint32_t word32s[8];
    uint8_t bytes[32];
};

union vapash_hash512
{
    uint64_t word64s[8];
    uint32_t word32s[16];
    uint8_t bytes[64];
};

union vapash_hash1024
{
    union vapash_hash512 hash512s[2];
    uint64_t word64s[16];
    uint32_t word32s[32];
    uint8_t bytes[128];
};

union vapash_hash2048
{
    union vapash_hash512 hash512s[4];
    uint64_t word64s[32];
    uint32_t word32s[64];
    uint8_t bytes[256];
};

#ifdef __cplusplus
}
#endif
