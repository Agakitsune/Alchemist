/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** fast_set
*/

#ifndef FAST_SET_H_
    #define FAST_SET_H_

    #include <stdint.h>

    #include "alloc.h"
    #include "error.h"

    #define FAST_SET_NEW(size, type, cmp)\
    (type *)fast_set_ctor((size), sizeof(type),\
    ((int64_t (*)(void *, void *))(cmp)))

    #define FAST_SET_DESTROY(this)\
    fast_set_dtor((this))

    #define FAST_SET_SIZE(this)\
    fast_set_last((this)) + 1

    #define FAST_SET_INSERT(this, value)\
    fast_set_insert((void **)(&(this)), (__typeof__(*this)[]){(value)})

    #define FAST_SET_ERASE(this, value)\
    fast_set_erase((this), (__typeof__(*this)[]){(value)})

    #define FAST_SET_CLEAR(this)\
    fast_set_clear((this))

    #define FAST_SET_RESIZE(this)\
    fast_set_resize(void **)(&(this))

    #define FAST_SET_FIND(this, value)\
    (__typeof__(*this) *)fast_set_find((this), (__typeof__(*this)[]){(value)})

    #define FAST_SET_CONTAINS(this, value)\
    fast_set_contains((this), (__typeof__(*this)[]){(value)})

typedef struct fast_set fast_set_t;

struct fast_set {
    uint64_t data_size;
    uint64_t size;
    uint64_t last;
    int64_t (*cmp)(void *, void *);
};

void *fast_set_ctor(uint64_t size,
                uint64_t elem_size,
                int64_t (*cmp)(void *, void *));
void fast_set_dtor(void *this);

fast_set_t *fast_set_get_metadata(void *this);
uint64_t fast_set_size(void *this);
uint64_t fast_set_data_size(void *this);
uint64_t fast_set_last(void *this);
int64_t (*fast_set_cmp(void *this))(void *, void *);
void fast_set_set_size(void *this, uint64_t size);
void fast_set_set_last(void *this, uint64_t last);
void fast_set_sort(void *this);

bool fast_set_insert(void **this, void *value);
void fast_set_erase(void *this, void *value);
void fast_set_clear(void *this);
void fast_set_swap(void *this, uint64_t src, uint64_t dest);
bool fast_set_resize(void **this);

void *fast_set_find(void *this, void *value);
bool fast_set_contains(void *this, void *value);

#endif /* !FAST_SET_H_ */
