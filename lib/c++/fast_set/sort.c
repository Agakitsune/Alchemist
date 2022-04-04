/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** sort
*/

#include "c++/fast_set.h"

static void insert(void *this, void *elem, uint64_t index)
{
    char *ptr = this;
    uint64_t last = fast_set_last(this);
    uint64_t size = FAST_SET_SIZE(this);

    move_memory(ptr + (index + 1) * fast_set_data_size(this),
    ptr + index * fast_set_data_size(this),
    (size - index) * fast_set_data_size(this));
    copy_memory(ptr + index * fast_set_data_size(this), elem,
    fast_set_data_size(this));
    fast_set_set_last(this, last + 1);
}

static void f4st_boi(void *this,
                    void *value,
                    int64_t (*cmp)(void *, void *))
{
    char *ptr = this;
    uint64_t last = fast_set_last(this);
    int64_t res = 0;

    for (uint64_t i = 0; i < (last + 1); ++i) {
        res = cmp(value, ptr + i * fast_set_data_size(this));
        if (res == 0)
            return;
        if (res < 0) {
            insert(this, value, i);
            return;
        }
    }
}

bool fast_set_insert(void **this, void *value)
{
    char *ptr = NULL;
    uint64_t last = 0;
    int64_t res = 0;

    if (!this || !value || !(*this))
        return false;
    last = fast_set_last(*this);
    if (last == (fast_set_size(*this) - 1))
        ASSERT(fast_set_resize(this), "Out of Memory");
    ptr = *this;
    if (last == (uint64_t)-1)
        return insert(*this, value, last + 1), true;
    res = fast_set_cmp(*this)(value, ptr + last * fast_set_data_size(*this));
    if (res == 0)
        return true;
    if (res > 0)
        return insert(*this, value, last + 1), true;
    f4st_boi(*this, value, fast_set_cmp(*this));
    return true;
}
