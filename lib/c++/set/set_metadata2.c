/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata2
*/

#include "c++/set.h"

void set_set_size(void *this, uint64_t size)
{
    set_t *metadata = NULL;

    if (!this)
        return;
    metadata = set_get_metadata(this);
    metadata->size = size;
}

void set_set_last(void *this, uint64_t last)
{
    set_t *metadata = NULL;

    if (!this)
        return;
    metadata = set_get_metadata(this);
    metadata->last = last;
}
