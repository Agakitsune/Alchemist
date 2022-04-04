/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "alchemist/engines/renderables.h"

sfVector2f renderable_get_position(renderable_t *this)
{
    if (!this)
        return VECTOR2F(0, 0);
    return sfSprite_getPosition(this->sprite);
}

sfVector2f renderable_get_scale(renderable_t *this)
{
    if (!this)
        return VECTOR2F(1, 1);
    return sfSprite_getScale(this->sprite);
}
float renderable_get_rotation(renderable_t *this)
{
    if (!this)
        return 0.f;
    return sfSprite_getRotation(this->sprite);
}
sfFloatRect renderable_get_box(renderable_t *this)
{
    if (!this)
        return FRECT(0, 0, 0, 0);
    return sfSprite_getGlobalBounds(this->sprite);
}
