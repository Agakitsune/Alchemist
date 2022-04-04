/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/engines/sprite.h"

sprite_t sprite_ctor(const char *filepath, sfVector2f size, float speed)
{
    sprite_t sprite = {{NULL, NULL}, {0, 0, 0, 0}, 0, NULL, NULL, 0};

    if (!filepath)
        return sprite;
    sprite.clock = sfClock_create();
    sprite.animations = VECTOR_NEW(4, animation_t);
    if (!sprite.clock || !sprite.animations)
        return sprite;
    sprite.renderable = renderable_ctor(filepath);
    if (!sprite.renderable.sprite)
        return sprite;
    sprite.texture_rect = IRECT(0, 0, size.x, size.y);
    sfSprite_setTextureRect(sprite.renderable.sprite, sprite.texture_rect);
    sfSprite_setOrigin(sprite.renderable.sprite,
    VECTOR2F(size.x / 2, size.y / 2));
    sprite.loaded_animation = -1;
    sprite.speed = speed;
    return sprite;
}

void sprite_dtor(sprite_t *this)
{
    if (!this)
        return;
    renderable_dtor(&this->renderable);
    VECTOR_DESTROY(this->animations);
    sfClock_destroy(this->clock);
}
