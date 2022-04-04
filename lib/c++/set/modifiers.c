/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "c++/set.h"

bool set_insert(void **this, void *value)
{
    char *ptr = NULL;
    char *tmp = NULL;
    uint64_t last = 0;

    if (!this || !value || !(*this))
        return false;
    last = set_last(*this);
    if (last == (set_size(*this) - 1))
        ASSERT(set_resize(this), "Out of Memory");
    ptr = *this;
    if (set_contains(*this, value))
        return true;
    tmp = ptr + (last + 1) * set_data_size(*this);
    set_set_last(*this, last + 1);
    copy_memory(tmp, value, set_data_size(*this));
    set_sort(*this);
    return true;
}

void set_erase(void *this, void *value)
{
    char *ptr = this;
    char *tmp = NULL;
    uint64_t last = 0;
    uint64_t index = 0;

    if (!this || !value)
        return;
    last = set_last(this);
    if (last == UINT64_MAX)
        return;
    tmp = set_find(this, value);
    if (!tmp)
        return;
    index = ((long)tmp - (long)this) / set_data_size(this);
    set_swap(this, index, last);
    set_memory(ptr + last * set_data_size(this), 0, set_data_size(this));
    set_set_last(this, last - 1);
    set_sort(this);
}

void set_clear(void *this)
{
    uint64_t last = set_last(this);

    if (!this)
        return;
    set_memory(this, 0, (last + 1) * set_data_size(this));
    set_set_last(this, -1);
}

void set_swap(void *this, uint64_t src, uint64_t dest)
{
    char *ptr = this;
    void *tmp_src = NULL;
    void *tmp_dest = NULL;
    uint64_t size = set_data_size(this);
    uint64_t last = set_last(this);
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

bool set_resize(void **this)
{
    char *tmp = NULL;
    set_t *ptr = NULL;

    if (!this || !(*this))
        return false;
    ptr = set_get_metadata(*this);
    if (ptr->size > 0)
        ptr->size <<= 1;
    else
        ptr->size = 32;
    tmp = my_realloc(ptr, sizeof(set_t) + ptr->size * ptr->data_size);
    ASSERT(tmp != NULL, "Out of Memory");
    *this = tmp + sizeof(set_t);
    return true;
}
