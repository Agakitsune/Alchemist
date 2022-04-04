/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** vector
*/

#ifndef VECTOR_H_
    #define VECTOR_H_

    #include <stdint.h>

    #include "alloc.h"
    #include "error.h"

    #define VECTOR_NEW(size, type)\
    ((type *)vector_ctor((size), sizeof(type)))

    #define VECTOR_DESTROY(this)\
    (vector_dtor((this)))

    #define VECTOR_SIZE(this)\
    (vector_back_index((this)) + 1)

    #define VECTOR_INSERT(this, index, value)\
    (vector_insert((void **)(&(this)), (index),\
    (__typeof__(*this)[]){(value)}))

    #define VECTOR_PUSH(this, value)\
    (vector_push_back((void **)(&(this)), (__typeof__(*this)[]){(value)}))

    #define VECTOR_POP(this)\
    (vector_pop_back((this)))

    #define VECTOR_ERASE(this, index)\
    (vector_erase((this), (index)))

    #define VECTOR_CLEAR(this)\
    (vector_clear((this)))

    #define VECTOR_SWAP(this, src, dest)\
    (vector_swap((this), (src), (dest)))

    #define VECTOR_RESIZE(this)\
    (vector_resize((void **)(&(this))))

    #define VECTOR_SORT(this, cmp)\
    (vector_sort((this), ((int64_t (*)(void *, void *))(cmp))))

    #define VECTOR_AT(this, index)\
    (__typeof__(*this) *)vector_at((this), (index))

    #define VECTOR_FRONT(this)\
    (__typeof__(*this) *)vector_front((this))

    #define VECTOR_BACK(this)\
    (__typeof__(*this) *)vector_back((this))

    #define VECTOR_COPY(this)\
    (__typeof__(*this) *)vector_copy((this))

typedef struct vector vector_t;

struct vector {
    uint64_t data_size;
    uint64_t size;
    uint64_t back;
};

void *vector_ctor(uint64_t size, uint64_t elem_size);
void vector_dtor(void *this);

vector_t *vector_get_metadata(void *this);
uint64_t vector_size(void *this);
uint64_t vector_data_size(void *this);
uint64_t vector_back_index(void *this);
void vector_set_size(void *this, uint64_t size);
void vector_set_back_index(void *this, uint64_t index);

bool vector_insert(void **this, uint64_t index, void *value);
bool vector_push_back(void **this, void *value);
void *vector_pop_back(void *this);
void vector_erase(void *this, uint64_t index);
void vector_clear(void *this);
void vector_swap(void *this, uint64_t src, uint64_t dest);
bool vector_resize(void **this);
void vector_sort(void *this, int64_t (*cmp)(void *a, void *b));

void *vector_at(void *this, uint64_t index);
void *vector_front(void *this);
void *vector_back(void *his);

void *vector_copy(void *this);

#endif /* !VECTOR_H_ */
