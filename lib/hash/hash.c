/*
** EPITECH PROJECT, 2022
** lib
** File description:
** hash
*/

#include "hash.h"

uint64_t fnv_hash(const void *bytes, size_t size)
{
    uint64_t hash = FNV_OFFSET;
    const unsigned char *ptr = bytes;

    while (size--) {
        hash ^= *ptr++;
        hash *= FNV_PRIME;
    }
    return hash;
}

uint64_t djb2_hash(const void *bytes, size_t size)
{
    unsigned long long hash = 5381;
    const unsigned char *ptr = bytes;

    while (size--)
        hash = ((hash << 5) + hash) + *ptr++;
    return hash;
}

uint64_t sdbm_hash(const void *bytes, size_t size)
{
    unsigned long hash = 0;
    const unsigned char *ptr = bytes;

    while (size--)
        hash = *ptr++ + (hash << 6) + (hash << 16) - hash;
    return hash;
}
