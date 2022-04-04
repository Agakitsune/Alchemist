/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "c++/stack.h"

void *stack_top(void *this)
{
    char *ptr = this;

    if (!this)
        return NULL;
    if (stack_last(this) == UINT64_MAX)
        return NULL;
    return ptr + stack_last(this) * stack_data_size(this);
}
