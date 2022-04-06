/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** update
*/

#include "alchemist/world.h"

void system_update(system_t *this)
{
    if (!this)
        return;
    this->system(this->entities);
}
