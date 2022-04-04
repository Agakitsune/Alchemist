/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "c++/fast_set.h"

void fast_set_erase(void *this, void *value)
{
    char *ptr = this;
    char *tmp = NULL;
    uint64_t last = 0;
    uint64_t index = 0;

    if (!this || !value)
        return;
    last = fast_set_last(this);
    if (last == UINT64_MAX)
        return;
    tmp = fast_set_find(this, value);
    if (!tmp)
        return;
    index = ((long)tmp - (long)this) / fast_set_data_size(this);
    move_memory(ptr + index * fast_set_data_size(this),
    ptr + (index + 1) * fast_set_data_size(this),
    (last - index) * fast_set_data_size(this));
    set_memory(ptr + last * fast_set_data_size(this), 0, fast_set_data_size(this));
    fast_set_set_last(this, last - 1);
}

void fast_set_clear(void *this)
{
    uint64_t last = fast_set_last(this);

    if (!this)
        return;
    set_memory(this, 0, (last + 1) * fast_set_data_size(this));
    fast_set_set_last(this, -1);
}

void fast_set_swap(void *this, uint64_t src, uint64_t dest)
{
    char *ptr = this;
    void *tmp_src = NULL;
    void *tmp_dest = NULL;
    uint64_t size = fast_set_data_size(this);
    uint64_t last = fast_set_last(this);
    char hold[size];

    if (!this)
        return;
    if ((src > last) || (dest > last))
        return;
    tmp_src = ptr + src * size;
    tmp_dest = ptr + dest * size;
    copy_memory(hold, tmp_src, size);
    copy_memory(tmp_src, tmp_dest, size);
    copy_memory(tmp_dest, hold, size);
}

bool fast_set_resize(void **this)
{
    char *tmp = NULL;
    fast_set_t *ptr = NULL;

    if (!this || !(*this))
        return false;
    ptr = fast_set_get_metadata(*this);
    if (ptr->size > 0)
        ptr->size <<= 1;
    else
        ptr->size = 32;
    tmp = my_realloc(ptr, sizeof(fast_set_t) + ptr->size * ptr->data_size);
    ASSERT(tmp != NULL, "Out of Memory");
    *this = tmp + sizeof(fast_set_t);
    return true;
}
