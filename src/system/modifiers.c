/*
** EPITECH PROJECT, 2022
** $
** File description:
** modifiers
*/

#include "alchemist/system.h"

bool system_add(system_t *this, entity_t entity)
{
    if (!this)
        return false;
    return SET_INSERT(this->entities, entity);
}
void system_remove(system_t *this, entity_t entity)
{
    if (!this)
        return;
    SET_ERASE(this->entities, entity);
}