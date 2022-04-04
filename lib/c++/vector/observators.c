/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "c++/vector.h"

void *vector_at(void *this, uint64_t index)
{
    char *ptr = this;

    if (!this)
        return NULL;
    if (index > vector_back_index(this))
        return NULL;
    return ptr + index * vector_data_size(this);
}

void *vector_front(void *this)
{
    if (!this)
        return NULL;
    return vector_at(this, 0);
}

void *vector_back(void *this)
{
    if (!this)
        return NULL;
    return vector_at(this, vector_back_index(this));
}
