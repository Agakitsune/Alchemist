/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** array
*/

#ifndef ARRAY_H_
    #define ARRAY_H_

    #include <stdint.h>

    #include "bitset.h"
    #include "vector.h"
    #include "alloc.h"

    #define ARRAY_NEW(size, type)\
    (type *)array_ctor((size), sizeof(type))

    #define ARRAY_DESTROY(this)\
    array_dtor((this))

    #define ARRAY_SIZE(this)\
    array_size((this))

    #define ARRAY_SET(this, index, value)\
    array_set((void **)(&(this)), (index), (__typeof__(*this)[]){(value)})

    #define ARRAY_ERASE(this, index)\
    array_erase((this), (index))

    #define ARRAY_CLEAR(this)\
    array_clear((this))

    #define ARRAY_SWAP(this, src, dest)\
    array_swap((this), (src), (dest))

    #define ARRAY_RESIZE(this)\
    array_resize((void **)(&(this)))

    #define ARRAY_GET(this, index)\
    (__typeof__(*this) *)array_get((this), (index))

    #define ARRAY_IS_NULL(this, index)\
    array_is_null((this), (index))

typedef struct array array_t;

struct array {
    uint64_t data_size;
    uint64_t size;
    bitset_t *fslots;
};

void *array_ctor(uint64_t size, uint64_t elem_size);
void array_dtor(void *this);

array_t *array_get_metadata(void *this);
uint64_t array_size(void *this);
uint64_t array_data_size(void *this);
bitset_t *array_fslots(void *this);
void array_set_slot(void *this, uint64_t index, bool value);
void array_set_size(void *this, uint64_t size);

bool array_set(void **this, uint64_t index, void *value);
void array_erase(void *this, uint64_t index);
void array_clear(void *this);
void array_swap(void *this, uint64_t src, uint64_t dest);
bool array_resize(void **this);

bool array_is_null(void *this, uint64_t index);
void *array_get(void *this, uint64_t index);

#endif /* !ARRAY_H_ */
