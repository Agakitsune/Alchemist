/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** stack
*/

#ifndef STACK_H_
    #define STACK_H_

    #include <stdint.h>

    #include "alloc.h"
    #include "error.h"

    #define STACK_NEW(size, type)\
    (type *)stack_ctor((size), sizeof(type))

    #define STACK_DESTROY(this)\
    stack_dtor((this))

    #define STACK_SIZE(this)\
    stack_last((this)) + 1

    #define STACK_PUSH(this, value)\
    stack_push((void **)(&(this)), (__typeof__(*this)[]){(value)})

    #define STACK_POP(this)\
    (__typeof__(*this) *)stack_pop((this))

    #define STACK_RESIZE(this)\
    stack_resize((void **)(&(this)))

    #define STACK_TOP(this)\
    (__typeof__(*this) *)stack_top((this));

typedef struct stack stack_t;

struct stack {
    uint64_t data_size;
    uint64_t size;
    uint64_t last;
};

void *stack_ctor(uint64_t size, uint64_t elem_size);
void stack_dtor(void *this);

stack_t *stack_get_metadata(void *this);
uint64_t stack_size(void *this);
uint64_t stack_data_size(void *this);
uint64_t stack_last(void *this);
void stack_set_size(void *this, uint64_t size);
void stack_set_last(void *this, uint64_t last);

bool stack_push(void **this, void *value);
void *stack_pop(void *this);
bool stack_resize(void **this);

void *stack_top(void *this);

#endif /* !STACK_H_ */
