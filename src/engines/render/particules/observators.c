/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "alchemist/engines/particules.h"

sfVector2f particule_get_position(particule_t *this)
{
    if (!this)
        return VECTOR2F(0, 0);
    return sprite_get_position(&this->sprite);
}

sfVector2f particule_get_scale(particule_t *this)
{
    if (!this)
        return VECTOR2F(0, 0);
    return sprite_get_scale(&this->sprite);
}

float particule_get_rotation(particule_t *this)
{
    if (!this)
        return 0.f;
    return sprite_get_rotation(&this->sprite);
}

sfFloatRect particule_get_box(particule_t *this)
{
    if (!this)
        return FRECT(0, 0, 0, 0);
    return sprite_get_box(&this->sprite);
}

animation_t *particule_get_animation(particule_t *this)
{
    if (!this)
        return NULL;
    return sprite_get_animation(&this->sprite);
}
