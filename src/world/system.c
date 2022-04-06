/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** system
*/

#include "alchemist/world.h"

bool world_add_system(world_t *this,
                    system_t *system,
                    const char *str)
{
    if (!this || !system)
        return false;
    if (!system_set_signature(system, str))
        return false;
    return VECTOR_PUSH(this->systems, system);
}
