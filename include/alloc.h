/*
** EPITECH PROJECT, 2021
** alloc
** File description:
** alloc
*/

#ifndef ALLOC_H_
    #define ALLOC_H_

    #include <stdlib.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdbool.h>

    #include "memory.h"

typedef struct malloc_header malloc_header_t;

struct malloc_header {
    uint64_t rc;
    uint64_t size;
    void *prev_ptr;
    void *ptr;
};

malloc_header_t *my_malloc_get_header(void *ptr);
size_t my_malloc_get_size(void *ptr);
void *my_malloc_get_ptr(void *ptr);

void *my_malloc(size_t size);
void *my_malloc_copy(void *base);
void *my_realloc(void *ptr, size_t n);
void *my_calloc(size_t nmemb, size_t size);
void my_free(void *ptr);

void *my_malloc_shared(void *ptr);

void **get_garbage(void);
void garbage_collector(void);
void add_to_garbage(void *ptr);
void remove_from_garbage(void *ptr);

#endif /* ALLOCATE_H_ */
