/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "c++/set.h"

uint64_t search(void *this, void *value, int64_t (*cmp)(void *, void *))
{
    char *ptr = this;
    uint64_t min = 0;
    uint64_t max = set_last(this) + 1;
    uint64_t mid = 0;
    int64_t res = 0;

    while (min < max) {
        mid = (min + max) / 2;
        res = cmp(ptr + mid * set_data_size(this), value);
        if (res == 0)
            return mid;
        else if (res > 0)
            max = mid;
        else
            min = mid + 1;
    }
    return -1;
}

void *set_find(void *this, void *value)
{
    uint64_t index = 0;
    char *ptr = NULL;

    if (!this || !value)
        return NULL;
    index = search(this, value, set_cmp(this));
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

