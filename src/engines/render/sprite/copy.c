/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** copy
*/

#include "alchemist/engines/sprite.h"

sprite_t sprite_copy(sprite_t *this)
{
    sprite_t new = {{NULL, NULL}, {0, 0, 0, 0}, 0, NULL, NULL, 0};

    if (!this)
        return new;
    new.clock = sfClock_create();
    new.animations = VECTOR_COPY(this->animations);
    if (!new.clock || !new.animations)
        return new;
    new.renderable = renderable_copy(&this->renderable);
    if (!new.renderable.sprite)
        return new;
    new.texture_rect = this->texture_rect;
    new.loaded_animation = this->loaded_animation;
    new.speed = this->speed;
    return new;
}
