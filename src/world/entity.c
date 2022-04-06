/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** entity
*/

#include "alchemist/world.h"
#include <stdio.h>

static bool register_entity(world_t *this, entity_t entity)
{
    signature_t signature = 0;

    if (!ARRAY_SET(this->signature, ENTITY_GET_ID(entity), signature))
        return false;
    return true;
}

entity_t world_new_entity(world_t *this, uint16_t layer)
{
    static uint32_t new_index = 0;
    uint32_t *tmp = NULL;
    entity_t entity = 0;
    uint16_t stage = ALCHEMIST_STAGE;

    if (!this)
        return ENTITY_NEW(0, 0, 0, DEAD);
    if (STACK_SIZE(this->deleted_entities) > 0) {
        tmp = STACK_POP(this->deleted_entities);
        if (!tmp)
            return ENTITY_NEW(0, 0, 0, DEAD);
        entity = ENTITY_NEW(*tmp, layer, stage, ALIVE);
        my_free(tmp);
    } else {
        entity = ENTITY_NEW(new_index, layer, stage, ALIVE);
        new_index++;
    }
    register_entity(this, entity);
    printf("%u\n", new_index);
    return entity;
}

void world_kill_entity(world_t *this, entity_t entity)
{
    if (!this)
        return;
    if (!STACK_PUSH(this->deleted_entities, ENTITY_GET_ID(entity)))
        return;
    ARRAY_ERASE(this->signature, ENTITY_GET_ID(entity));
    COMPONENT_MANAGER_REMOVE(&this->c_manager, entity);
    for (uint64_t i = 0; i < VECTOR_SIZE(this->systems); i++)
        system_remove(this->systems[i], entity);
    // render_engine_remove(&this->render_engine, entity);
}

signature_t world_get_entity_signature(world_t *this, entity_t entity)
{
    if (!this)
        return 0;
    return this->signature[ENTITY_GET_ID(entity)];
}

bool world_system_entity(world_t *this, entity_t entity)
{
    uint32_t id = ENTITY_GET_ID(entity);
    signature_t sys_signature = 0;

    if (!this)
        return false;
    for (uint64_t i = 0; i < VECTOR_SIZE(this->systems); i++) {
        sys_signature = this->systems[i]->signature;
        if (((sys_signature & this->signature[id]) == sys_signature)) {
            if (!system_add(this->systems[i], entity))
                return false;
        } else {
            system_remove(this->systems[i], entity);
        }
    }
    return true;
}
