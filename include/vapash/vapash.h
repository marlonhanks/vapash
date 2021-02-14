/* vapash: C/C++ implementation of Vapash, the Vapory Proof of Work algorithm.
 * Copyright 2018 Pawel Bylica.
 * Licensed under the Apache License, Version 2.0. See the LICENSE file.
 */

#pragma once

#include <vapash/hash_types.h>

#include <stdint.h>

#ifdef __cplusplus
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The Vapash algorithm revision implemented as specified in the Vapash spec
 * https://github.com/vaporyco/wiki/wiki/Vapash.
 */
#define VAPASH_REVISION "23"

#define VAPASH_EPOCH_LENGTH 30000
#define VAPASH_LIGHT_CACHE_ITEM_SIZE 64
#define VAPASH_FULL_DATASET_ITEM_SIZE 128
#define VAPASH_NUM_DATASET_ACCESSES 64


struct vapash_epoch_context
{
    const int epoch_number;
    const int light_cache_num_items;
    const union vapash_hash512* const light_cache;
    const uint32_t* const l1_cache;
    const int full_dataset_num_items;
};


struct vapash_epoch_context_full;


/**
 * Calculates the number of items in the light cache for given epoch.
 *
 * This function will search for a prime number matching the criteria given
 * by the Vapash so the execution time is not constant. It takes ~ 0.01 ms.
 *
 * @param epoch_number  The epoch number.
 * @return              The number items in the light cache.
 */
int vapash_calculate_light_cache_num_items(int epoch_number) NOEXCEPT;


/**
 * Calculates the number of items in the full dataset for given epoch.
 *
 * This function will search for a prime number matching the criteria given
 * by the Vapash so the execution time is not constant. It takes ~ 0.05 ms.
 *
 * @param epoch_number  The epoch number.
 * @return              The number items in the full dataset.
 */
int vapash_calculate_full_dataset_num_items(int epoch_number) NOEXCEPT;

/**
 * Calculates the epoch seed hash.
 * @param epoch_number  The epoch number.
 * @return              The epoch seed hash.
 */
union vapash_hash256 vapash_calculate_epoch_seed(int epoch_number) NOEXCEPT;


struct vapash_epoch_context* vapash_create_epoch_context(int epoch_number) NOEXCEPT;

/**
 * Creates the epoch context with the full dataset initialized.
 *
 * The memory for the full dataset is only allocated and marked as "not-generated".
 * The items of the full dataset are generated on the fly when hit for the first time.
 *
 * The memory allocated in the context MUST be freed with vapash_destroy_epoch_context_full().
 *
 * @param epoch_number  The epoch number.
 * @return  Pointer to the context or null in case of memory allocation failure.
 */
struct vapash_epoch_context_full* vapash_create_epoch_context_full(int epoch_number) NOEXCEPT;

void vapash_destroy_epoch_context(struct vapash_epoch_context* context) NOEXCEPT;

void vapash_destroy_epoch_context_full(struct vapash_epoch_context_full* context) NOEXCEPT;

#ifdef __cplusplus
}
#endif
