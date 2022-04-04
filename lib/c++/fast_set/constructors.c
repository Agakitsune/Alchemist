/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "c++/fast_set.h"
#include <stdio.h>

void *fast_set_ctor(uint64_t size,
                uint64_t elem_size,
                int64_t (*cmp)(void *, void *))
{
    char *ptr = my_malloc(sizeof(fast_set_t) + (size * elem_size));
    fast_set_t *set = (fast_set_t *)ptr;

    if (!set || !cmp)
        return NULL;
    set->data_size = elem_size;
    set->size = size;
    set->last = -1;
    set->cmp = cmp;
    return ptr + sizeof(fast_set_t);
}

void fast_set_dtor(void *this)
{
    fast_set_t *metadata = NULL;

    if (!this)
        return;
    metadata = fast_set_get_metadata(this);
    my_free(metadata);
}
