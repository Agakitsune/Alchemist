/*
** EPITECH PROJECT, 2022
** Alchemist
** File description:
** set_modifier2
*/

#include "c++/set.h"

static uint64_t dicho(void *this, void *value)
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
            max = mid - 1;
        else
            min = mid + 1;
    }
    return mid;
}

static bool plague(char *ptr, void *value, uint64_t index)
{
    uint64_t last = 0;
    int64_t res = 0;
    char *tmp = ptr;

    if (!ptr || !value)
        return false;
    tmp += index * set_data_size(ptr);
    last = set_last(ptr);
    res = set_cmp(ptr)(tmp, value);
    if (res == 0)
        return true;
    if (res > 0) {
        move_memory(tmp + set_data_size(ptr), tmp, (last - index + 1) * set_data_size(ptr));
    } else {
        index += 1;
        tmp += set_data_size(ptr);
        move_memory(tmp + set_data_size(ptr), tmp, (last - index + 1) * set_data_size(ptr));
    }
    copy_memory(tmp, value, set_data_size(ptr));
    set_set_last(ptr, last + 1);
    return true;
}

bool fast_insert(char *ptr, void *value)
{
    uint64_t index = 0;

    if (!ptr || !value)
        return false;
    index = dicho(ptr, value);
    return plague(ptr, value, index);
}

bool set_insert(void **this, void *value)
{
    char *ptr = NULL;
    uint64_t last = 0;

    if (!this || !value || !(*this))
        return false;
    last = set_last(*this);
    if (last == (set_size(*this) - 1))
        ASSERT(set_resize(this), "Out of Memory");
    ptr = *this;
    if (last + 1 == 0) {
        copy_memory(ptr, value, set_data_size(*this));
        set_set_last(*this, last + 1);
        return true;
    }
    return fast_insert(ptr, value);
}
