/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata
*/

#include "c++/fast_set.h"

fast_set_t *fast_set_get_metadata(void *this)
{
    char *ptr = this;

    if (!this)
        return NULL;
    return (fast_set_t *)(ptr - sizeof(fast_set_t));
}

uint64_t fast_set_size(void *this)
{
    fast_set_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = fast_set_get_metadata(this);
    return metadata->size;
}

uint64_t fast_set_data_size(void *this)
{
    fast_set_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = fast_set_get_metadata(this);
    return metadata->data_size;
}

uint64_t fast_set_last(void *this)
{
    fast_set_t *metadata = NULL;

    if (!this)
        return -1;
    metadata = fast_set_get_metadata(this);
    return metadata->last;
}

int64_t (*fast_set_cmp(void *this))(void *, void *)
{
    fast_set_t *metadata = NULL;
    if (!this)
        return NULL;
    metadata = fast_set_get_metadata(this);
    return metadata->cmp;
}
