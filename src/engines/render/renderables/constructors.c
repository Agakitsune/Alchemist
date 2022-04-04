/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/engines/renderables.h"

renderable_t renderable_ctor(const char *filepath)
{
    renderable_t new = {NULL, NULL};
    sfFloatRect bounds = {0, 0, 0, 0};

    if (!filepath)
        return new;
    new.texture = fetch_from_atlas(filepath);
    if (!new.texture) {
        new.texture = sfTexture_createFromFile(filepath, NULL);
        if (!new.texture)
            return new;
        add_to_atlas(filepath, new.texture);
    }
    new.sprite = sfSprite_create();
    sfSprite_setTexture(new.sprite, new.texture, sfFalse);
    bounds = sfSprite_getGlobalBounds(new.sprite);
    sfSprite_setOrigin(new.sprite,
    VECTOR2F(bounds.width / 2.0, bounds.height / 2.0));
    return new;
}

void renderable_dtor(renderable_t *this)
{
    if (!this)
        return;
    sfSprite_destroy(this->sprite);
}
