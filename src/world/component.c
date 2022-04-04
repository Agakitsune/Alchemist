/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** component
*/

#include "alchemist/world.h"

bool world_set_component(world_t *this,
                                entity_t entity,
                                hash_t component,
                                void *value)
{
    signature_t ent_signature = 0;

    if (!this || !value)
        return false;
    if (!component_manager_set(&this->c_manager, entity, component, value))
        return false;
    ent_signature = world_get_entity_signature(this, entity);
    ent_signature |= get_component_signature(&this->c_manager, component);
    if (!ARRAY_SET(this->signature, ENTITY_GET_ID(entity), ent_signature))
        return false;
    return world_system_entity(this, entity);
}

void *world_get_component(world_t *this, entity_t entity, hash_t component)
{
    if (!this)
        return NULL;
    return component_manager_get(&this->c_manager, entity, component);
}
