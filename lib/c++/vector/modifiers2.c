/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers2
*/

#include "c++/vector.h"

void vector_swap(void *this, uint64_t src, uint64_t dest)
{
    void *tmp_src = NULL;
    void *tmp_dest = NULL;
    uint64_t size = vector_data_size(this);
    uint64_t last = vector_back_index(this);
    char hold[size];

    if (!this)
        return;
    if ((src > last) || (dest > last))
        return;
    tmp_src = vector_at(this, src);
    tmp_dest = vector_at(this, dest);
    copy_memory(hold, tmp_src, size);
    copy_memory(tmp_src, tmp_dest, size);
    copy_memory(tmp_dest, hold, size);
}

bool vector_resize(void **this)
{
    char *tmp = NULL;
    vector_t *ptr = NULL;

    if (!this || !(*this))
        return false;
    ptr = vector_get_metadata(*this);
    if (ptr->size > 0)
        ptr->size <<= 1;
    else
        ptr->size = 32;
    tmp = my_realloc(ptr, sizeof(vector_t) + ptr->size * ptr->data_size);
    ASSERT(tmp != NULL, "Out of Memory");
    *this = tmp + sizeof(vector_t);
    return true;
}
