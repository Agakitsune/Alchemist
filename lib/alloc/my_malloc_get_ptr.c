/*
** EPITECH PROJECT, 2021
** my_malloc_get_ptr
** File description:
** my_malloc_get_ptr
*/

#include "alloc.h"

void *my_malloc_get_ptr(void *ptr)
{
    if (ptr == NULL)
        return NULL;
    return my_malloc_get_header(ptr)->ptr;
}
