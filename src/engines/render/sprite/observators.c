/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "alchemist/engines/sprite.h"

sfVector2f sprite_get_position(sprite_t *this)
{
    if (!this)
        return VECTOR2F(0, 0);
    return renderable_get_position(&this->renderable);
}

sfVector2f sprite_get_scale(sprite_t *this)
{
    if (!this)
        return VECTOR2F(1, 1);
    return renderable_get_scale(&this->renderable);
}

float sprite_get_rotation(sprite_t *this)
{
    if (!this)
        return 0.f;
    return renderable_get_rotation(&this->renderable);
}

sfFloatRect sprite_get_box(sprite_t *this)
{
    if (!this)
        return FRECT(0, 0, 0, 0);
    return renderable_get_box(&this->renderable);
}

animation_t *sprite_get_animation(sprite_t *this)
{
    if (!this)
        return NULL;
    return VECTOR_AT(this->animations, this->loaded_animation);
}
