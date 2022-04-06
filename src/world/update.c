/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** update
*/

#include "alchemist/world.h"
#include <stdio.h>

bool world_update(world_t *this)
{
    if (!this)
        return false;
    // if (!sfRenderWindow_isOpen(this->render_engine.window))
    //     return false;
    for (uint64_t i = 0; i < VECTOR_SIZE(this->systems); i++)
        system_update(this->systems[i]);
    // render_engine_render(&this->render_engine);
    // render_engine_event(&this->render_engine);
    return true;
}
