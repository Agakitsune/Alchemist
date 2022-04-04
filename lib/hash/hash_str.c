/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** hash_str
*/

#include "hash.h"

uint64_t fnv_hash_str(const char *str)
{
    uint64_t hash = FNV_OFFSET;

    while (*str) {
        hash ^= *str++;
        hash *= FNV_PRIME;
    }
    return hash;
}

uint64_t djb2_hash_str(const char *str)
{
    unsigned long long hash = 5381;

    while (*str)
        hash = ((hash << 5) + hash) + *str++;
    return hash;
}

uint64_t sdbm_hash_str(const char *str)
{
    unsigned long hash = 0;

    while (*str)
        hash = *str++ + (hash << 6) + (hash << 16) - hash;
    return hash;
}
