/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "c++/map.h"

void *map_find(map_t *this, const char *key)
{
    hash_t hash = 0;
    hash_t *tmp = NULL;
    uint64_t index = 0;

    if (!this || !key)
        return NULL;
    hash = fnv_hash_str(key);
    tmp = SET_FIND(this->hashes, hash);
    if (!tmp)
        return NULL;
    index = (((uint64_t)tmp) - ((uint64_t)this->hashes)) / sizeof(hash_t);
    return VECTOR_AT(this->data, index);
}
