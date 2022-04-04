/*
** EPITECH PROJECT, 2022
** assets
** File description:
** garbage
*/

#include "alloc.h"
#include <stdio.h>

void **get_garbage(void)
{
    static void *garbage = NULL;

    return &garbage;
}

static void set_garbage(void *ptr)
{
    void **garbage = get_garbage();

    *garbage = ptr;
}

void add_to_garbage(void *ptr)
{
    void **garbage = get_garbage();
    malloc_header_t *header = my_malloc_get_header(ptr);

    if (!header)
        return;
    header->prev_ptr = *garbage;
    set_garbage(ptr);
}

void remove_from_garbage(void *ptr)
{
    void **garbage = get_garbage();
    malloc_header_t *header = my_malloc_get_header(*garbage);
    malloc_header_t *tmp = NULL;
    void *tmp2 = NULL;

    if (!ptr || !header)
        return;
    if ((ptrdiff_t)*garbage == (ptrdiff_t)ptr) {
        set_garbage(header->prev_ptr);
        return;
    }
    while (header) {
        tmp = header;
        tmp2 = header->prev_ptr;
        header = my_malloc_get_header(tmp2);
        if ((ptrdiff_t)tmp2 == (ptrdiff_t)ptr) {
            tmp->prev_ptr = header->prev_ptr;
            return;
        }
    }
}

void garbage_collector(void)
{
    void **garbage = get_garbage();
    malloc_header_t *header = my_malloc_get_header(*garbage);
    void *tmp = NULL;

    if (!header)
        return;
    while (header) {
        tmp = header;
        header = my_malloc_get_header(header->prev_ptr);
        free(tmp);
    }
}
