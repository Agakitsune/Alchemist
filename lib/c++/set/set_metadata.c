/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata
*/

#include "c++/set.h"

set_t *set_get_metadata(void *this)
{
    char *ptr = this;

    if (!this)
        return NULL;
    return (set_t *)(ptr - sizeof(set_t));
}

uint64_t set_size(void *this)
{
    set_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = set_get_metadata(this);
    return metadata->size;
}

uint64_t set_data_size(void *this)
{
    set_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = set_get_metadata(this);
    return metadata->data_size;
}

uint64_t set_last(void *this)
{
    set_t *metadata = NULL;

    if (!this)
        return -1;
    metadata = set_get_metadata(this);
    return metadata->last;
}

int64_t (*set_cmp(void *this))(void *, void *)
{
    set_t *metadata = NULL;
    if (!this)
        return NULL;
    metadata = set_get_metadata(this);
    return metadata->cmp;
}
