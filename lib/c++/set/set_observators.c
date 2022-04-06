/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
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

void *set_find(void *this, void *value)
{
    uint64_t index = 0;
    char *ptr = NULL;

    if (!this || !value)
        return NULL;
    index = dicho(this, value);
    if (index == UINT64_MAX)
        return NULL;
    ptr = this;
    return ptr + index * set_data_size(this);
}

bool set_contains(void *this, void *value)
{
    if (!this || !value)
        return false;
    if (!set_find(this, value))
        return false;
    return true;
}

