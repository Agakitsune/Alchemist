/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** metadata
*/

#include "c++/stack.h"

stack_t *stack_get_metadata(void *this)
{
    char *ptr = this;

    if (!this)
        return NULL;
    return (stack_t *)(ptr - sizeof(stack_t));
}

uint64_t stack_size(void *this)
{
    stack_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = stack_get_metadata(this);
    return metadata->size;
}

uint64_t stack_data_size(void *this)
{
    stack_t *metadata = NULL;

    if (!this)
        return 0;
    metadata = stack_get_metadata(this);
    return metadata->data_size;
}

uint64_t stack_last(void *this)
{
    stack_t *metadata = NULL;

    if (!this)
        return -1;
    metadata = stack_get_metadata(this);
    return metadata->last;
}
