/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "c++/map.h"

bool map_insert(map_t *this, const char *key, void *value)
{
    hash_t hash = 0;
    hash_t *tmp = NULL;
    uint64_t index = 0;

    if (!this || !key || !value)
        return false;
    hash = fnv_hash_str(key);
    if (!SET_INSERT(this->hashes, hash))
        return false;
    tmp = SET_FIND(this->hashes, hash);
    if (!tmp)
        return false;
    index = (((uint64_t)tmp) - ((uint64_t)this->hashes)) / sizeof(hash_t);
    return vector_insert(&this->data, index, value);
}

void map_erase(map_t *this, const char *key)
{
    hash_t hash = 0;
    hash_t *tmp = NULL;
    uint64_t index = 0;

    if (!this || !key )
        return;
    hash = fnv_hash_str(key);
    tmp = SET_FIND(this->hashes, hash);
    if (!tmp)
        return;
    SET_ERASE(this->hashes, hash);
    index = (((uint64_t)tmp) - ((uint64_t)this->hashes)) / sizeof(hash_t);
    VECTOR_ERASE(this->data, index);
}

void map_clear(map_t *this)
{
    if (!this)
        return;
    SET_CLEAR(this->hashes);
    VECTOR_CLEAR(this->data);
}
