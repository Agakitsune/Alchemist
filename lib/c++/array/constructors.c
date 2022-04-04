/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "c++/array.h"

void *array_ctor(uint64_t size, uint64_t elem_size)
{
    char *ptr = my_calloc(1, sizeof(array_t) + (size * elem_size));
    array_t *array = (array_t *)ptr;

    if (!array)
        return NULL;
    array->data_size = elem_size;
    array->size = size;
    array->fslots = VECTOR_NEW((size >> 6), bitset_t);
    if (!array->fslots)
        return my_free(ptr), NULL;
    for (uint64_t i = 0; i < (size >> 6); i++) {
        if (!VECTOR_PUSH(array->fslots, 0))
            return my_free(ptr), NULL;
    }
    return ptr + sizeof(array_t);
}

void array_dtor(void *this)
{
    array_t *metadata = NULL;

    if (!this)
        return;
    metadata = array_get_metadata(this);
    VECTOR_DESTROY(metadata->fslots);
    my_free(metadata);
}
