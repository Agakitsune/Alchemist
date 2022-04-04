/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers2
*/

#include "alchemist/engines/particules.h"

bool particule_add_animation(particule_t *this, uint64_t sheet_index, uint64_t frames, bool loop)
{
    if (!this)
        return false;
    return sprite_add_animation(&this->sprite, sheet_index, frames, loop);
}

particule_t particule_copy(particule_t *this)
{
    particule_t copy = {{{NULL, NULL}, {0, 0, 0, 0}, 0, NULL, NULL, 0},
    NULL, NULL, {0, 0}, sfBlack, 0};

    if (!this)
        return copy;
    copy = *this;
    copy.sprite = sprite_copy(&this->sprite);
    return copy;
}

void particule_behave(particule_t *this)
{
    if (!this)
        return;
    this->behaviour(this);
}
