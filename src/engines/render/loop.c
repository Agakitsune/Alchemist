/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** render
*/

#include "alchemist/engines/render_engine.h"
#include "alchemist/world.h"

#include <stdio.h>

static void sprites_update(sprite_handle_t *this)
{
    uint8_t stage = ALCHEMIST_STAGE;
    transform_t *transform = NULL;

    for (uint64_t i = 0; i < FAST_SET_SIZE(this); ++i) {
        if ((stage != ENTITY_GET_STAGE(this[i].entity)) ||
        ENTITY_IS_STATUS(this[i].entity, DEAD) ||
        ENTITY_IS_STATUS(this[i].entity, MARKER))
            continue;
        transform = ALCHEMIST_GET(this[i].entity, transform_t);
        if (!transform)
            continue;
        sprite_set_position(&this[i].sprite, transform->pos);
        sprite_set_scale(&this[i].sprite, transform->scale);
        sprite_set_rotation(&this[i].sprite, transform->angle);
        sprite_animate(&this[i].sprite);
    }
}

static void on_event(render_engine_t *this)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(this->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(this->window);
    }
}

static void go_trough(render_engine_t *this, sprite_handle_t *array)
{
    uint8_t stage = ALCHEMIST_STAGE;

    for (uint64_t i = 0; i < FAST_SET_SIZE(array); ++i) {
        if ((stage != ENTITY_GET_STAGE(array[i].entity)) ||
        ENTITY_IS_STATUS(array[i].entity, DEAD) ||
        ENTITY_IS_STATUS(array[i].entity, MARKER))
            continue;
        sfRenderWindow_drawSprite(this->window,
        array[i].sprite.renderable.sprite, NULL);
    }
}

void render_engine_render(render_engine_t *this)
{
    if (!this)
        return;
    sfRenderWindow_clear(this->window, sfBlack);
    for (uint64_t i = 0; i < ARRAY_SIZE(this->sprites); ++i) {
        if (ARRAY_GET(this->sprites, i))
            go_trough(this, this->sprites[i]);
    }
    for (uint64_t i = 0; i < VECTOR_SIZE(this->particules); ++i)
        sfRenderWindow_drawSprite(this->window,
        this->particules[i].sprite.renderable.sprite, NULL);
    sfRenderWindow_display(this->window);
}

void render_engine_update(render_engine_t *this)
{
    if (!this)
        return;
    on_event(this);
    for (uint64_t i = 0; i < ARRAY_SIZE(this->sprites); ++i) {
        if (ARRAY_GET(this->sprites, i))
            sprites_update(this->sprites[i]);
    }
    for (uint64_t i = 0; i < VECTOR_SIZE(this->particules); ++i) {
        sprite_animate(&this->particules[i].sprite);
        particule_behave(&this->particules[i]);
        if (this->particules[i].lifetime == 0)
            VECTOR_ERASE(this->particules, i);
    }
}

