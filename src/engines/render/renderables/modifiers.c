/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "alchemist/engines/renderables.h"

void renderable_set_position(renderable_t *this, sfVector2f pos)
{
    if (!this)
        return;
    return sfSprite_setPosition(this->sprite, pos);
}

void renderable_set_scale(renderable_t *this, sfVector2f scale)
{
    if (!this)
        return;
    return sfSprite_setScale(this->sprite, scale);
}

void renderable_set_rotation(renderable_t *this, float angle)
{
    if (!this)
        return;
    return sfSprite_setRotation(this->sprite, angle);
}
