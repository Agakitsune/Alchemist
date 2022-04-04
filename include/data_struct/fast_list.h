/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** fast_list
*/

#ifndef FAST_LIST_H_
    #define FAST_LIST_H_

    #include <stdbool.h>
    #include <stdarg.h>

    #include "alloc.h"

typedef struct fl_slot fl_slot_t;
typedef struct fl_list fl_list_t;

struct fl_slot {
    uint64_t index;
    uint64_t *last_empty_index;
    bool is_empty;
    void *data;
};

struct fl_list {
    uint64_t last_empty_index;
    fl_slot_t *slots;
    uint64_t size;
    uint64_t slots_full;
};

// Constructors and dtorer
bool fl_ctor(fl_list_t *this);
bool fl_ctor_with_size(fl_list_t *this, uint64_t size);
bool fl_ctor_with_values(fl_list_t *this, uint64_t n_elem, ...);
void fl_dtor(fl_list_t *this);

// Transformators
bool fl_add(fl_list_t *this, void *value);
bool fl_remove(fl_list_t *this, uint64_t index);
bool fl_set(fl_list_t *this, uint64_t index, void *value);

// Observators
void *fl_get(fl_list_t *this, uint64_t index);
void fl_display(fl_list_t *this, bool show_slot);

#endif /* !FAST_LIST_H_ */
