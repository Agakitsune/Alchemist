/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata2
*/

#include "c++/vector.h"

void vector_set_size(void *this, uint64_t size)
{
    vector_t *metadata = NULL;

    if (!this)
        return;
    metadata = vector_get_metadata(this);
    metadata->size = size;
}

void vector_set_back_index(void *this, uint64_t index)
{
    vector_t *metadata = NULL;

    if (!this)
        return;
    metadata = vector_get_metadata(this);
    metadata->back = index;
}
