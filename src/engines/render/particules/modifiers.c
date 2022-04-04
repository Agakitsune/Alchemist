/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "alchemist/engines/particules.h"

void particule_set_position(particule_t *this, sfVector2f pos)
{
    if (!this)
        return;
    sprite_set_position(&this->sprite, pos);
}

void particule_set_scale(particule_t *this, sfVector2f scale)
{
    if (!this)
        return;
    sprite_set_scale(&this->sprite, scale);
}

void particule_set_rotation(particule_t *this, float angle)
{
    if (!this)
        return;
    sprite_set_rotation(&this->sprite, angle);
}

void particule_set_color(particule_t *this, sfColor color)
{
    if (!this)
        return;
    this->color = color;
    sfSprite_setColor(this->sprite.renderable.sprite, color);
}

void particule_set_animation(particule_t *this, uint64_t index)
{
    if (!this)
        return;
    sprite_set_animation(&this->sprite, index);
}
