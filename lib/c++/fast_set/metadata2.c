/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata2
*/

#include "c++/fast_set.h"

void fast_set_set_size(void *this, uint64_t size)
{
    fast_set_t *metadata = NULL;

    if (!this)
        return;
    metadata = fast_set_get_metadata(this);
    metadata->size = size;
}

void fast_set_set_last(void *this, uint64_t last)
{
    fast_set_t *metadata = NULL;

    if (!this)
        return;
    metadata = fast_set_get_metadata(this);
    metadata->last = last;
}
