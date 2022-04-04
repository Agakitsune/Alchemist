/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** const
*/

#include "alchemist/world.h"

world_t *get_world(void)
{
    static world_t world;

    return &world;
}

void set_world(world_t world)
{
    world_t *tmp = get_world();

    *tmp = world;
}
