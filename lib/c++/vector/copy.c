/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** copy
*/

#include "c++/vector.h"

void *vector_copy(void *this)
{
    vector_t *metadata = NULL;
    char *ptr = NULL;

    if (!this)
        return NULL;
    metadata = vector_get_metadata(this);
    ptr = my_malloc_copy(metadata);
    return ptr + sizeof(vector_t);
}
