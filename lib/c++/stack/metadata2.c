/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata2
*/

#include "c++/stack.h"

void stack_set_size(void *this, uint64_t size)
{
    stack_t *metadata = NULL;

    if (!this)
        return;
    metadata = stack_get_metadata(this);
    metadata->size = size;
}

void stack_set_last(void *this, uint64_t last)
{
    stack_t *metadata = NULL;

    if (!this)
        return;
    metadata = stack_get_metadata(this);
    metadata->last = last;
}
