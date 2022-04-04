/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "c++/vector.h"
#include <stdio.h>

void *vector_ctor(uint64_t size, uint64_t elem_size)
{
    char *ptr = my_malloc(sizeof(vector_t) + (size * elem_size));
    vector_t *vector = (vector_t *)ptr;

    if (!vector)
        return NULL;
    vector->data_size = elem_size;
    vector->size = size;
    vector->back = -1;
    return ptr + sizeof(vector_t);
}

void vector_dtor(void *this)
{
    vector_t *metadata = NULL;

    if (!this)
        return;
    metadata = vector_get_metadata(this);
    my_free(metadata);
}
