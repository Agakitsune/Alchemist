/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "c++/set.h"
#include <stdio.h>

void *set_ctor(uint64_t size,
                uint64_t elem_size,
                int64_t (*cmp)(void *, void *))
{
    char *ptr = my_malloc(sizeof(set_t) + (size * elem_size));
    set_t *set = (set_t *)ptr;

    if (!set || !cmp)
        return NULL;
    set->data_size = elem_size;
    set->size = size;
    set->last = -1;
    set->cmp = cmp;
    return ptr + sizeof(set_t);
}

void set_dtor(void *this)
{
    set_t *metadata = NULL;

    if (!this)
        return;
    metadata = set_get_metadata(this);
    my_free(metadata);
}
