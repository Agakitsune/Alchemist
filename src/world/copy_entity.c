/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** copy_entity
*/

#include "alchemist/world.h"
#include "alchemist/engines/render_engine.h"

static bool copy_component(world_t *this, entity_t base, entity_t copy)
{
    void *tmp = NULL;
    uint8_t index = 0;
    signature_t base_signature = world_get_entity_signature(this, base);
    signature_t extract = 0;

    while ((base_signature >> index) > 0) {
        extract = ((base_signature >> index) & 0b1) << index;
        tmp = world_get_component(this, base, extract);
        if (!world_set_component(this, copy, extract, tmp))
            return false;
    }
    return true;
}

entity_t world_copy_entity(world_t *this, entity_t entity, uint16_t layer)
{
    entity_t new;

    if (!this)
        return ENTITY_NEW(0, 0, 0, DEAD);
    new = world_new_entity(this, layer);
    if (ENTITY_IS_STATUS(new, DEAD))
        return ENTITY_NEW(0, 0, 0, DEAD);
    if (!copy_component(this, entity, new))
        return ENTITY_NEW(0, 0, 0, DEAD);
    if (!world_system_entity(this, new))
        return ENTITY_NEW(0, 0, 0, DEAD);
    return new;
}
