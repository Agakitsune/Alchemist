/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "c++/set.h"

static int64_t dicho(void *this, void *value)
{
    char *ptr = this;
    int64_t min = 0;
    int64_t max = set_last(this);
    int64_t mid = 0;
    int64_t res = 0;

    while (min <= max) {
        mid = (min + max) / 2;
        res = set_cmp(this)(ptr + mid * set_data_size(this), value);
        if (res == 0)
            return mid;
        if (res > 0)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return -1;
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
    index = dicho(this, value);
    if (index == UINT64_MAX)
        return;
    tmp = ptr + index * set_data_size(this);
    if (index != last)
        move_memory(tmp, tmp +
        set_data_size(this), (last - index + 1) * set_data_size(this));
    set_memory(ptr + last * set_data_size(this), 0, set_data_size(this));
    set_set_last(this, last - 1);
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
