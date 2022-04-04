/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** update
*/

#include "alchemist/world.h"

void system_update(system_t *this)
{
    uint16_t stage = ALCHEMIST_STAGE;

    if (!this)
        return;
    for (uint64_t i = 0; i < FAST_SET_SIZE(this->entities); i++) {
        if (!ENTITY_IS_STATUS(this->entities[i], ALIVE))
            continue;
        if (stage != ENTITY_GET_STAGE(this->entities[i]))
            continue;
        this->system(this->entities[i]);
    }
}
