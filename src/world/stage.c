/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** stage
*/

#include "alchemist/world.h"

uint8_t world_get_stage(world_t *this)
{
    if (!this)
        return -1;
    return this->stage;
}

void world_load_stage(world_t *this, uint16_t stage)
{
    if (!this)
        return;
    this->stage = stage;
}
