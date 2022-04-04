/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "c++/array.h"
#include <stdio.h>

bool array_set(void **this, uint64_t index, void *value)
{
    char *ptr = NULL;
    char *tmp = NULL;

    if (!this || !value || !(*this))
        return false;
    while (index >= array_size(*this))
        ASSERT(array_resize(this), "Out of Memory");
    ptr = *this;
    tmp = ptr + index * array_data_size(*this);
    copy_memory(tmp, value, array_data_size(*this));
    array_set_slot(*this, index, true);
    return true;
}

void array_erase(void *this, uint64_t index)
{
    char *ptr = this;
    char *tmp = NULL;
    uint64_t size = 0;

    if (!this)
        return;
    size = array_data_size(this);
    if (index >= array_size(this))
        return;
    tmp = ptr + index * size;
    set_memory(tmp, 0, size);
    array_set_slot(this, index, false);
}

void array_clear(void *this)
{
    if (!this)
        return;
    set_memory(this, 0, array_size(this) * array_data_size(this));
    VECTOR_CLEAR(array_fslots(this));
}

void array_swap(void *this, uint64_t src, uint64_t dest)
{
    uint64_t size = array_size(this);
    char hold[size];

    if (!this)
        return;
    if ((src >= size) || (dest >= size))
        return;
    copy_memory(hold, array_get(this, src), size);
    copy_memory(array_get(this, dest), array_get(this, src), size);
    copy_memory(array_get(this, dest), hold, size);
}

bool array_resize(void **this)
{
    char *tmp = NULL;
    array_t *ptr = NULL;

    if (!this || !(*this))
        return false;
    ptr = array_get_metadata(*this);
    if (ptr->size > 0)
        ptr->size <<= 1;
    else
        ptr->size = 32;
    ptr = my_realloc(ptr, sizeof(array_t) + ptr->size * ptr->data_size);
    ASSERT(ptr != NULL, "Out of Memory");
    printf("%ld\n", (ptr->size >> 7) + ((ptr->size & 63) != 0));
    for (uint64_t i = 0; i < ((ptr->size >> 7) + ((ptr->size & 63) != 0)); i++)
        ASSERT(VECTOR_PUSH(ptr->fslots, 0), NULL);
    tmp = (char *)ptr;
    *this = tmp + sizeof(array_t);
    return true;
}
