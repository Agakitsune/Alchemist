/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata2
*/

#include "c++/array.h"

void array_set_slot(void *this, uint64_t index, bool value)
{
    bitset_t *tmp = NULL;

    if (!this)
        return;
    tmp = array_fslots(this);
    BITSET_SET(&tmp[(index >> 6)], index & 63, value);
}

void array_set_size(void *this, uint64_t size)
{
    array_t *metadata = NULL;

    if (!this)
        return;
    metadata = array_get_metadata(this);
    metadata->size = size;
}
