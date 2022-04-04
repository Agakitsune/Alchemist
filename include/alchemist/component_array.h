/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** component_array
*/

#ifndef COMPONENT_ARRAY_H_
    #define COMPONENT_ARRAY_H_

    #include "component.h"
    #include "entity.h"

    #include "c++/array.h"

typedef struct component_array component_array_t;

struct component_array {
    uint32_t *entity_to_index;
    uint32_t *index_to_entity;
    void *data;
    void (*dtor)(void *data);
    uint64_t size;
};

bool component_array_ctor(component_array_t *this,
                            uint64_t size,
                            uint64_t elem_size,
                            void (*dtor)(void *data));
void component_array_dtor(component_array_t *this);

bool component_array_set(component_array_t *this,
                            entity_t entity,
                            void *value);
void component_array_remove(component_array_t *this, entity_t entity);

void *component_array_get(component_array_t *this, entity_t entity);

#endif /* !COMPONENT_ARRAY_H_ */
