/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "alchemist/component_manager.h"
#include <stdio.h>

void *component_manager_get(component_manager_t *this,
                            entity_t entity,
                            hash_t component)
{
    component_array_t *array = NULL;

    if (!this)
        return NULL;
    array = get_component_array(this, component);
    if (!array)
        return NULL;
    return component_array_get(array, entity);
}
