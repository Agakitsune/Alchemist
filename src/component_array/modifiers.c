/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "alchemist/component_array.h"
#include <stdio.h>
#include "debug.h"

void display(void *this, uint64_t size)
{
    char *tmp = this;

    printf("[");
    for (uint64_t i = 0; i < size; i++) {
        printf(" %#hhx", *tmp++);
    }
    printf(" ]\n");
}

bool component_array_set(component_array_t *this,
                            entity_t entity,
                            void *value)
{
    uint64_t entity_id = ENTITY_GET_ID(entity);
    uint32_t *index = NULL;
    void *tmp = NULL;

    if (!this || !value)
        return false;
    index = ARRAY_GET(this->entity_to_index, entity_id);
    if (index) {
        tmp = ARRAY_GET(this->data, *index);
        if (!tmp)
            return false;
        copy_memory(tmp, value, array_data_size(this->data));
        return true;
    }
    index = (uint32_t *)&this->size;
    array_set((void **)&this->entity_to_index, ENTITY_GET_ID(entity), index);
    ARRAY_SET(this->index_to_entity, *index, ENTITY_GET_ID(entity));
    array_set((void **)&this->data, *index, value);
    ++this->size;
    return true;
}

void component_array_remove(component_array_t *this, entity_t entity)
{
    uint32_t *rm_index = NULL;
    uint32_t last_index = 0;
    uint32_t *last_entity = NULL;

    if (!this)
        return;
    rm_index = ARRAY_GET(this->entity_to_index, ENTITY_GET_ID(entity));
    if (!rm_index)
        return;
    last_index = this->size - 1;
    last_entity = ARRAY_GET(this->index_to_entity, last_index);
    if (!last_entity)
        return;
    (this->dtor != NULL) ? this->dtor(ARRAY_GET(this->data, *rm_index)) : 0;
    if (!array_set((void **)(&this->data), *rm_index, array_get(this->data, last_index)))
        return;
    ARRAY_SET(this->entity_to_index, *last_entity, *rm_index);
    ARRAY_SET(this->index_to_entity, *rm_index, *last_entity);
    ARRAY_ERASE(this->entity_to_index, ENTITY_GET_ID(entity));
    ARRAY_ERASE(this->index_to_entity, last_index);
    --this->size;
}
