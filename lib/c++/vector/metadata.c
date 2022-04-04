/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata
*/

#include "c++/vector.h"

vector_t *vector_get_metadata(void *this)
{
    char *ptr = this;

    if (!this)
        return NULL;
    return (vector_t *)(ptr - sizeof(vector_t));
}

uint64_t vector_size(void *this)
{
    vector_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = vector_get_metadata(this);
    return metadata->size;
}

uint64_t vector_data_size(void *this)
{
    vector_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = vector_get_metadata(this);
    return metadata->data_size;
}

uint64_t vector_back_index(void *this)
{
    vector_t *metadata = NULL;

    if (!this)
        return -1;
    metadata = vector_get_metadata(this);
    return metadata->back;
}
