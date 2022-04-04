/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "c++/array.h"
#include <stdio.h>

bool array_is_null(void *this, uint64_t index)
{
    bitset_t *tmp = NULL;

    if (!this)
        return false;
    tmp = array_fslots(this);
    if (!tmp)
        return true;
    if (index >= array_size(this))
        return true;
    return !(BITSET_GET(&tmp[(index >> 6)], index & 63));
}

void *array_get(void *this, uint64_t index)
{
    char *ptr = this;

    if (!this)
        return NULL;
    if (array_is_null(this, index))
        return NULL;
    return ptr + index * array_data_size(this);
}
