/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "alchemist/component_array.h"
#include <stdio.h>

void *component_array_get(component_array_t *this, entity_t entity)
{
    uint32_t *index = NULL;

    if (!this)
        return NULL;
    index = ARRAY_GET(this->entity_to_index, ENTITY_GET_ID(entity));
    if (!index)
        return NULL;
    return array_get(this->data, *index);
}
