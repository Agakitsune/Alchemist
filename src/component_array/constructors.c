/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/component_array.h"
#include <stdio.h>

bool component_array_ctor(component_array_t *this,
                            uint64_t size,
                            uint64_t elem_size,
                            void (*dtor)(void *data))
{
    if (!this)
        return false;
    this->entity_to_index = ARRAY_NEW(size, uint32_t);
    this->index_to_entity = ARRAY_NEW(size, uint32_t);
    this->data = array_ctor(size, elem_size);
    if (!this->entity_to_index || !this->index_to_entity || !this->data)
        return false;
    this->size = 0;
    this->dtor = dtor;
    return true;
}

void component_array_dtor(component_array_t *this)
{
    void *ptr = NULL;

    if (!this)
        return;
    ARRAY_DESTROY(this->entity_to_index);
    ARRAY_DESTROY(this->index_to_entity);
    for (uint64_t i = 0; (i < ARRAY_SIZE(this->data)) && (this->dtor); ++i) {
        ptr = ARRAY_GET(this->data, i);
        if (!ptr)
            break;
        this->dtor(ptr);
    }
    ARRAY_DESTROY(this->data);
}
