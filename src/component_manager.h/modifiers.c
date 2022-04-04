/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "alchemist/component_manager.h"

bool component_manager_register(component_manager_t *this,
                                hash_t component,
                                uint64_t elem_size,
                                void (*dtor)(void *data))
{
    static short component_number = 0;
    component_array_t array;

    if (!this)
        return true;
    if (!VECTOR_PUSH(this->component_hash, component))
        return false;
    if (!component_array_ctor(&array, 65536, elem_size, dtor))
        return false;
    if (!ARRAY_SET(this->component_data, component_number, array))
        return false;
    component_number++;
    return true;
}

bool component_manager_set(component_manager_t *this,
                            entity_t entity,
                            hash_t component,
                            void *value)
{
    component_array_t *array = NULL;

    if (!this || !value)
        return false;
    array = get_component_array(this, component);
    if (!array)
        return false;
    return component_array_set(array, entity, value);
}

void component_manager_remove(component_manager_t *this,
                                entity_t entity)
{
    component_array_t *array = NULL;

    if (!this)
        return;
    for (uint64_t i = 0; i < VECTOR_SIZE(this->component_hash); i++) {
        array = ARRAY_GET(this->component_data, i);
        if (!array)
            return;
        component_array_remove(array, entity);
    }
}
