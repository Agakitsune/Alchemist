/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "c++/vector.h"

bool vector_insert(void **this, uint64_t index, void *value)
{
    char *ptr = NULL;
    char *tmp = NULL;
    char *dest = NULL;
    uint64_t last = 0;

    if (!this || !(*this) || !value)
        return false;
    last = vector_back_index(*this);
    ASSERT(index <= (last + 1), "Index out of bound");
    if (last == (vector_size(*this) - 1))
        ASSERT(vector_resize(this), "Out of Memory");
    ptr = *this;
    tmp = ptr + index * vector_data_size(*this);
    if (last >= index) {
        dest = tmp + vector_data_size(*this);
        move_memory(tmp, dest, (last - index + 1) * vector_data_size(*this));
    }
    vector_set_back_index(*this, last + 1);
    copy_memory(tmp, value, vector_data_size(*this));
    return true;
}

bool vector_push_back(void **this, void *value)
{
    if (!this || !(*this) || !value)
        return false;
    return vector_insert(this, vector_back_index(*this) + 1, value);
}

void *vector_pop_back(void *this)
{
    uint64_t last = vector_back_index(this);
    void *hold = my_malloc(vector_data_size(this));

    if (!this || !hold)
        return NULL;
    copy_memory(hold, vector_at(this, last), vector_data_size(this));
    vector_erase(this, last);
    return hold;
}

void vector_erase(void *this, uint64_t index)
{
    char *ptr = this;
    char *tmp = NULL;
    char *src = NULL;
    uint64_t last = vector_back_index(this);
    uint64_t size = vector_data_size(this);

    if (!this)
        return;
    if (index > last)
        return;
    tmp = ptr + index * size;
    if (index != last) {
        src = tmp + size;
        move_memory(tmp, src, (last - index + 1) * size);
    }
    set_memory(ptr + last * size, 0, size);
    vector_set_back_index(this, last - 1);
}

void vector_clear(void *this)
{
    uint64_t last = vector_back_index(this);

    if (!this)
        return;
    set_memory(this, 0, (last + 1) * vector_data_size(this));
    vector_set_back_index(this, -1);
}
