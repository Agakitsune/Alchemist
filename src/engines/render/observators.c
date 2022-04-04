/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators
*/

#include "alchemist/engines/render_engine.h"

sprite_t *render_engine_get_sprite(render_engine_t *this, entity_t entity)
{
    uint16_t layer = ENTITY_GET_LAYER(entity);
    sprite_handle_t **array = NULL;
    sprite_handle_t handle;
    sprite_handle_t *tmp = NULL;

    if (!this)
        return NULL;
    handle.entity = entity;
    array = ARRAY_GET(this->sprites, layer);
    if (!array)
        return NULL;
    tmp = FAST_SET_FIND(*array, handle);
    if (!tmp)
        return NULL;
    return &tmp->sprite;
}
