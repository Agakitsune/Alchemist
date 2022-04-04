/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** system
*/

#include "alchemist/world.h"

bool world_add_system(world_t *this,
                    void (*func)(entity_t entity),
                    const char *str)
{
    system_t system;

    if (!this || !func)
        return false;
    if (!system_ctor(&system, func))
        return false;
    if (!system_set_signature(&system, str))
        return false;
    return VECTOR_PUSH(this->systems, system);
}
