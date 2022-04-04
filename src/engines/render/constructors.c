/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/engines/render_engine.h"

bool render_engine_ctor(render_engine_t *this, window_desc_t *desc)
{
    sfVideoMode mode = {0, 0, 0};

    if (!this || !desc)
        return false;
    mode = (sfVideoMode){desc->width, desc->height, desc->bpp};
    this->window = sfRenderWindow_create(mode, desc->name, sfClose, NULL);
    this->sprites = ARRAY_NEW(64, sprite_handle_t *);
    this->particules = VECTOR_NEW(4096, particule_t);
    if (!this->window ||
    !this->sprites || !this->particules)
        return false;
    sfRenderWindow_setPosition(this->window, VECTOR2I(0, 0));
    sfRenderWindow_setFramerateLimit(this->window, desc->framerate);
    return true;
}

#include <stdio.h>

void render_engine_dtor(render_engine_t *this)
{
    sprite_handle_t *tmp = NULL;

    if (!this)
        return;
    sfRenderWindow_destroy(this->window);
    for (uint64_t i = 0; i < ARRAY_SIZE(this->sprites); ++i) {
        tmp = this->sprites[i];
        if (tmp == NULL)
            continue;
        for (uint64_t j = 0; j < FAST_SET_SIZE(tmp); ++j)
            sprite_dtor(&tmp[i].sprite);
    }
    for (uint64_t i = 0; i < VECTOR_SIZE(this->particules); ++i)
        particule_dtor(&this->particules[i]);
    ARRAY_DESTROY(this->sprites);
    VECTOR_DESTROY(this->particules);
}
