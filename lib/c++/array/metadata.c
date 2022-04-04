/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata
*/

#include "c++/array.h"

array_t *array_get_metadata(void *this)
{
    char *ptr = this;

    if (!this)
        return NULL;
    return (array_t *)(ptr - sizeof(array_t));
}

uint64_t array_size(void *this)
{
    array_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = array_get_metadata(this);
    return metadata->size;
}

uint64_t array_data_size(void *this)
{
    array_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = array_get_metadata(this);
    return metadata->data_size;
}

bitset_t *array_fslots(void *this)
{
    array_t *metadata = NULL;

    if (!this)
        return NULL;
    metadata = array_get_metadata(this);
    return metadata->fslots;
}
