/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "c++/stack.h"

bool stack_push(void **this, void *value)
{
    char *ptr = NULL;
    char *tmp = NULL;
    uint64_t last = 0;

    if (!this || !value || !(*this))
        return false;
    last = stack_last(*this);
    if (last == (stack_size(*this) - 1))
        ASSERT(stack_resize(this), "Out of Memory");
    ptr = *this;
    tmp = ptr + (last + 1) * stack_data_size(*this);
    stack_set_last(*this, last + 1);
    copy_memory(tmp, value, stack_data_size(*this));
    return true;
}

void *stack_pop(void *this)
{
    uint64_t last = stack_last(this);
    void *hold = my_malloc(stack_data_size(this));

    if (!this || !hold)
        return NULL;
    copy_memory(hold, stack_top(this), stack_data_size(this));
    set_memory(stack_top(this), 0, stack_data_size(this));
    stack_set_last(this, last - 1);
    return hold;
}

bool stack_resize(void **this)
{
    char *tmp = NULL;
    stack_t *ptr = NULL;

    if (!this || !(*this))
        return false;
    ptr = stack_get_metadata(this);
    if (ptr->size > 0)
        ptr->size <<= 1;
    else
        ptr->size = 32;
    tmp = my_realloc(ptr, sizeof(stack_t) + ptr->size * ptr->data_size);
    ASSERT(tmp != NULL, "Out of Memory");
    *this = tmp + sizeof(stack_t);
    return true;
}
