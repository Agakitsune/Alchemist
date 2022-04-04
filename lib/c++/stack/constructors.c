/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "c++/stack.h"
#include <stdio.h>

void *stack_ctor(uint64_t size, uint64_t elem_size)
{
    char *ptr = my_malloc(sizeof(stack_t) + (size * elem_size));
    stack_t *stack = (stack_t *)ptr;

    if (!stack)
        return NULL;
    stack->data_size = elem_size;
    stack->size = size;
    stack->last = -1;
    return ptr + sizeof(stack_t);
}

void stack_dtor(void *this)
{
    stack_t *metadata = NULL;

    if (!this)
        return;
    metadata = stack_get_metadata(this);
    my_free(metadata);
}
