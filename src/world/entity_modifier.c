/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** entity_modifier
*/

#include "alchemist/world.h"

void world_stage_entity(world_t *this, entity_t entity, uint16_t stage)
{
    if (!this)
        return;
    for (uint64_t i = 0; i < VECTOR_SIZE(this->systems); i++)
        system_set_stage(&this->systems[i], entity, stage);
    // render_engine_set_stage(&this->render_engine, entity, stage);
}

void world_status_entity(world_t *this, entity_t entity, uint8_t status)
{
    if (!this)
        return;
    for (uint64_t i = 0; i < VECTOR_SIZE(this->systems); i++)
        system_set_status(&this->systems[i], entity, status);
    // render_engine_set_status(&this->render_engine, entity, status);
}
