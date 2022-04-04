/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/system.h"

bool system_ctor(system_t *this, void (*func)(entity_t entity))
{
    if (!this || !func)
        return false;
    this->entities = FAST_SET_NEW(65536, entity_t, &entity_cmp_id);
    if (!this->entities)
        return false;
    this->signature = 0;
    this->system = func;
    return true;
}

void system_dtor(system_t *this)
{
    if (!this)
        return;
    FAST_SET_DESTROY(this->entities);
}
