/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** world
*/

#ifndef WORLD_H_
    #define WORLD_H_

    #include "CSFML.h"

    #include "entity.h"
    #include "signature.h"
    #include "component_manager.h"
    #include "system.h"

    #include "c++/set.h"
    #include "c++/array.h"
    #include "c++/stack.h"

    #define ALCHEMIST_INIT\
    world_ctor(get_world())

    #define ALCHEMIST_END\
    world_dtor(get_world())

    #define ALCHEMIST_COMPONENT(component, dtor)\
    COMPONENT_MANAGER_REGISTER(&get_world()->c_manager,\
    component,\
    ((void (*)(void *))(dtor)))

    #define ALCHEMIST_NEW_ENTITY(layer)\
    world_new_entity(get_world(), (layer))

    #define ALCHEMIST_COPY(entity, layer)\
    world_copy_entity(get_world(), (entity), (layer))

    #define ALCHEMIST_KILL(entity)\
    world_kill_entity(get_world(), (entity))

    #define ALCHEMIST_SET(entity, component, ...)\
    world_set_component(get_world(),\
    (entity),\
    fnv_hash_str(#component),\
    &(component)__VA_ARGS__)

    #define ALCHEMIST_GET(entity, component)\
    (__typeof__(component) *)world_get_component(get_world(),\
    (entity),\
    fnv_hash_str(#component))

    #define ALCHEMIST_SYSTEM(system, ...)\
    world_add_system(get_world(), (system), #__VA_ARGS__)

    #define ALCHEMIST_STAGE\
    world_get_stage(get_world())

    #define ALCHEMIST_LOAD_STAGE(stage)\
    world_get_stage(get_world(), (stage));

    #define ALCHEMIST_UPDATE\
    world_update(get_world())

typedef struct world world_t;

struct world {
    component_manager_t c_manager;
    signature_t *signature;
    system_t *systems;
    uint32_t *deleted_entities;
    uint8_t stage;
};

bool world_ctor(world_t *this);
void world_dtor(world_t *this);

entity_t world_new_entity(world_t *this, uint16_t layer);
entity_t world_copy_entity(world_t *this, entity_t entity, uint16_t layer);
signature_t world_get_entity_signature(world_t *this, entity_t entity);
void world_kill_entity(world_t *this, entity_t entity);
void world_stage_entity(world_t *this, entity_t entity, uint16_t stage);
void world_status_entity(world_t *this, entity_t entity, uint8_t status);
bool world_system_entity(world_t *this, entity_t entity);

bool world_set_component(world_t *this,
                        entity_t entity,
                        hash_t component,
                        void *value);
void *world_get_component(world_t *this, entity_t entity, hash_t component);

bool world_add_system(world_t *this,
                    void (*func)(entity_t entity),
                    const char *str);

uint8_t world_get_stage(world_t *this);
void world_load_stage(world_t *this, uint16_t stage);

bool world_update(world_t *this);

world_t *get_world(void);
void set_world(world_t world);

#endif /* !WORLD_H_ */
