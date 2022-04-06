/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** entity
*/

#include "alchemist/system.h"

void system_set_status(system_t *this, entity_t entity, uint8_t status)
{
    entity_t *tmp = NULL;

    if (!this)
        return;
    tmp = SET_FIND(this->entities, entity);
    if (!tmp)
        return;
    ENTITY_SET_STATUS(*tmp, status);
}

void system_set_stage(system_t *this, entity_t entity, uint16_t stage)
{
    entity_t *tmp = NULL;

    if (!this)
        return;
    tmp = SET_FIND(this->entities, entity);
    if (!tmp)
        return;
    ENTITY_SET_STAGE(*tmp, stage);
}
