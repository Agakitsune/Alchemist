/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers2
*/

#include "alchemist/engines/sprite.h"

void sprite_set_position(sprite_t *this, sfVector2f pos)
{
    if (!this)
        return;
    renderable_set_position(&this->renderable, pos);
}

void sprite_set_scale(sprite_t *this, sfVector2f scale)
{
    if (!this)
        return;
    renderable_set_scale(&this->renderable, scale);
}

void sprite_set_rotation(sprite_t *this, float angle)
{
    if (!this)
        return;
    renderable_set_rotation(&this->renderable, angle);
}
