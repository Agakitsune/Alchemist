/*
** EPITECH PROJECT, 2021
** my_free
** File description:
** my_free
*/

#include "alloc.h"

void my_free(void *ptr)
{
    uint8_t *tmp = ptr;

    if (tmp == NULL)
        return;
    if (--my_malloc_get_header(ptr)->rc == 0) {
        remove_from_garbage(ptr);
        free(tmp - sizeof(malloc_header_t));
    }
}
