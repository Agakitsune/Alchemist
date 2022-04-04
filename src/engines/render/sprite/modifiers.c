/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "alchemist/engines/sprite.h"

void sprite_set_animation(sprite_t *this, uint64_t index)
{
    animation_t *tmp = NULL;
    sfVector2u texture_size = {0, 0};

    if (!this)
        return;
    tmp = VECTOR_AT(this->animations, index);
    if (!tmp)
        return;
    tmp->frame = 0;
    texture_size = sfTexture_getSize(this->renderable.texture);
    this->loaded_animation = index;
    if (texture_size.y >=
    this->texture_rect.height * index + this->texture_rect.height) {
        this->texture_rect.top = this->texture_rect.height * index;
        sfSprite_setTextureRect(this->renderable.sprite, this->texture_rect);
    }
}

bool sprite_add_animation(sprite_t *this, uint64_t sheet_index, uint64_t frames, bool loop)
{
    animation_t new = {0, frames, sheet_index, loop};

    if (!this)
        return false;
    if (frames == 0)
        new.frame_max = 1;
    return VECTOR_PUSH(this->animations, new);
}

static void set_texture_rect(sprite_t *this, sfVector2u texture_size)
{
    animation_t *animation = NULL;

    if (this->loaded_animation == (uint64_t)-1)
        return;
    animation = VECTOR_AT(this->animations, this->loaded_animation);
    if ((animation->frame == animation->frame_max - 1) && !animation->loop)
        return;
    ++animation->frame;
    if (texture_size.x >= (uint32_t)(this->texture_rect.left + this->texture_rect.width)) {
        if (animation->frame_max > animation->frame) {
            this->texture_rect.left += this->texture_rect.width;
        } else {
            this->texture_rect.left = 0;
            animation->frame = 0;
        }
    } else {
        if (animation->frame_max == animation->frame) {
            this->texture_rect.left = 0;
            animation->frame = 0;
        }
    }
}

void sprite_animate(sprite_t *this)
{
    sfTime time = {0};
    sfVector2u texture_size = {0, 0};

    if (!this)
        return;
    time = sfClock_getElapsedTime(this->clock);
    texture_size = sfTexture_getSize(this->renderable.texture);
    if (sfTime_asSeconds(time) >= this->speed) {
        set_texture_rect(this, texture_size);
        sfSprite_setTextureRect(this->renderable.sprite, this->texture_rect);
        sfClock_restart(this->clock);
    }
}
