/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/component_manager.h"

bool component_manager_ctor(component_manager_t *this)
{
    if (!this)
        return false;
    this->component_hash = VECTOR_NEW(64, hash_t);
    this->component_data = ARRAY_NEW(64, component_array_t);
    if (!this->component_hash || !this->component_data)
        return false;
    return true;
}

void component_manager_dtor(component_manager_t *this)
{
    component_array_t *tmp = NULL;

    if (!this)
        return;
    VECTOR_DESTROY(this->component_hash);
    for (uint64_t i = 0; i < 64; i++) {
        tmp = ARRAY_GET(this->component_data, i);
        if (!tmp)
            break;
        component_array_dtor(tmp);
    }
    ARRAY_DESTROY(this->component_data);
}
