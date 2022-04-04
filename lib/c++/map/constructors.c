/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "c++/map.h"
#include <stdio.h>

int64_t hash_cmp(hash_t *a, hash_t *b)
{
    hash_t tmp_a = *a;
    hash_t tmp_b = *b;

    return tmp_a - tmp_b;
}

map_t *map_ctor(uint64_t size, uint64_t data_size)
{
    map_t *ptr = my_malloc(sizeof(map_t));

    ptr->hashes = FAST_SET_NEW(size, hash_t, &hash_cmp);
    ptr->data = vector_ctor(size, data_size);
    if (!ptr->hashes || !ptr->data)
        return NULL;
    return ptr;
}

void map_dtor(map_t *this)
{
    if (!this)
        return;
    FAST_SET_DESTROY(this->hashes);
    VECTOR_DESTROY(this->data);
}
