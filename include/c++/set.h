/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** set
*/

#ifndef SET_H_
    #define SET_H_

    #include <stdint.h>

    #include "alloc.h"
    #include "error.h"

    #define SET_NEW(size, type, cmp)\
    (type *)set_ctor((size), sizeof(type),\
    ((int64_t (*)(void *, void *))(cmp)))

    #define SET_DESTROY(this)\
    set_dtor((this))

    #define SET_SIZE(this)\
    set_last((this)) + 1

    #define SET_INSERT(this, value)\
    set_insert((void **)(&(this)), (__typeof__(*this)[]){(value)})

    #define SET_ERASE(this, value)\
    set_erase((this), (__typeof__(*this)[]){(value)})

    #define SET_CLEAR(this)\
    set_clear((this))

    #define SET_RESIZE(this)\
    set_resize((void **)(&(this)))

    #define SET_FIND(this, value)\
    (__typeof__(*this) *)set_find((this), (__typeof__(*this)[]){(value)})

    #define SET_CONTAINS(this, value)\
    set_contains((this), (__typeof__(*this)[]){(value)})

typedef struct set set_t;

struct set {
    uint64_t data_size;
    uint64_t size;
    uint64_t last;
    int64_t (*cmp)(void *, void *);
};

void *set_ctor(uint64_t size,
                uint64_t elem_size,
                int64_t (*cmp)(void *, void *));
void set_dtor(void *this);

set_t *set_get_metadata(void *this);
uint64_t set_size(void *this);
uint64_t set_data_size(void *this);
uint64_t set_last(void *this);
int64_t (*set_cmp(void *this))(void *, void *);
void set_set_size(void *this, uint64_t size);
void set_set_last(void *this, uint64_t last);
void set_sort(void *this);

bool set_insert(void **this, void *value);
void set_erase(void *this, void *value);
void set_clear(void *this);
void set_swap(void *this, uint64_t src, uint64_t dest);
bool set_resize(void **this);

void *set_find(void *this, void *value);
bool set_contains(void *this, void *value);

#endif /* !SET_H_ */
