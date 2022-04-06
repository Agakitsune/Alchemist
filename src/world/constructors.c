/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/world.h"

bool world_ctor(world_t *this)
{
    if (!this)
        return false;
    if (!component_manager_ctor(&this->c_manager))
        return false;
    this->signature = ARRAY_NEW(65536, signature_t);
    this->systems = VECTOR_NEW(1024, system_t *);
    this->deleted_entities = STACK_NEW(32768, uint32_t);
    if (!this->signature || !this->deleted_entities)
        return false;
    this->stage = 0;
    return true;
}

void world_dtor(world_t *this)
{
    if (!this)
        return;
    component_manager_dtor(&this->c_manager);
    ARRAY_DESTROY(this->signature);
    for (uint64_t i = 0; i < VECTOR_SIZE(this->systems); i++)
        system_dtor(this->systems[i]);
    VECTOR_DESTROY(this->systems);
    STACK_DESTROY(this->deleted_entities);
}
