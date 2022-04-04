/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** modifiers
*/

#include "alchemist/engines/render_engine.h"
#include <math.h>
#include <stdio.h>

bool render_engine_emit(render_engine_t *this,
                        particule_t *particule,
                        particule_machine_t *machine)
{
    particule_t emitted;

    if (!this || !particule || !machine)
        return false;
    if (!particule->emit)
        return false;
    for (uint64_t i = 0; i < machine->count; ++i) {
        emitted = particule->emit(particule, machine);
        if (emitted.sprite.renderable.sprite)
            VECTOR_PUSH(this->particules, emitted);
    }
    return true;
}

void render_engine_remove(render_engine_t *this, entity_t entity)
{
    uint16_t layer = ENTITY_GET_LAYER(entity);
    sprite_handle_t **array = NULL;
    sprite_handle_t tmp;

    FLAG;
    if (!this)
        return;
    array = ARRAY_GET(this->sprites, layer);
    FLAG;
    if (!array)
        return;
    tmp = (*array)[ENTITY_GET_ID(entity)];
    sprite_dtor(&tmp.sprite);
    FAST_SET_ERASE(*array, tmp);
}

void render_engine_set_status(render_engine_t *this,
                                entity_t entity,
                                uint8_t status)
{
    uint16_t layer = ENTITY_GET_LAYER(entity);
    sprite_handle_t **array = NULL;

    FLAG;
    if (!this)
        return;
    array = ARRAY_GET(this->sprites, layer);
    FLAG;
    if (!array)
        return;
    ENTITY_SET_STATUS((*array)[ENTITY_GET_ID(entity)].entity, status);
}

void render_engine_set_stage(render_engine_t *this,
                                entity_t entity,
                                uint8_t stage)
{
    uint16_t layer = ENTITY_GET_LAYER(entity);
    sprite_handle_t **array = NULL;

    FLAG;
    if (!this)
        return;
    array = ARRAY_GET(this->sprites, layer);
    FLAG;
    if (!array)
        return;
    ENTITY_SET_STAGE((*array)[ENTITY_GET_ID(entity)].entity, stage);
}

void render_engine_set_layer(render_engine_t *this,
                                entity_t entity,
                                uint16_t layer)
{
    uint16_t ent_layer = ENTITY_GET_LAYER(entity);
    sprite_handle_t **array = NULL;
    sprite_handle_t tmp;

    FLAG;
    if (!this)
        return;
    array = ARRAY_GET(this->sprites, ent_layer);
    if (!array)
        return;
    tmp = (*array)[ENTITY_GET_ID(entity)];
    ENTITY_SET_LAYER(tmp.entity, layer);
    FAST_SET_ERASE(*array, tmp);
    array = ARRAY_GET(this->sprites, layer);
    if (!array) {
        *array = FAST_SET_NEW(8192, sprite_handle_t, &handle_cmp);
        if (!(*array))
            return;
        if (!ARRAY_SET(this->sprites, ent_layer, *array))
            return;
    }
    tmp = (*array)[ENTITY_GET_ID(entity)];
    FAST_SET_INSERT(*array, tmp);
}
