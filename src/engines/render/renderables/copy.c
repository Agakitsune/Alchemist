/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** copy
*/

#include "alchemist/engines/renderables.h"

renderable_t renderable_copy(renderable_t *this)
{
    renderable_t new = {NULL, NULL};

    if (!this)
        return new;
    new.texture = this->texture;
    new.sprite = sfSprite_copy(this->sprite);
    if (!new.sprite)
        return new;
    return new;
}
