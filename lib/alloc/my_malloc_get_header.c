/*
** EPITECH PROJECT, 2021
** my_malloc_get_header
** File description:
** my_malloc_get_header
*/

#include "alloc.h"

malloc_header_t *my_malloc_get_header(void *ptr)
{
    if (ptr == NULL)
        return NULL;
    return (malloc_header_t *)((char *)ptr - sizeof(malloc_header_t));
}
