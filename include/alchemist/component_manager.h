/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** component_manager
*/

#ifndef COMPONENT_MANAGER_H_
    #define COMPONENT_MANAGER_H_

    #include "entity.h"
    #include "component_array.h"
    #include "signature.h"

    #include "c++/array.h"
    #include "c++/vector.h"

    #include "hash.h"

    #define COMPONENT_MANAGER_REGISTER(this, type, dtor)\
    component_manager_register((this),\
    fnv_hash_str(#type),\
    sizeof(type),\
    (dtor))

    #define COMPONENT_MANAGER_SET(this, entity, component, value)\
    component_manager_set((this),\
    (entity),\
    fnv_hash_str(#component),\
    value)

    #define COMPONENT_MANAGER_REMOVE(this, entity)\
    component_manager_remove((this), (entity))

    #define COMPONENT_MANAGER_GET(this, entity, component)\
    (__typeof__(component) *)component_manager_get((this), (entity), fnv_hash_str(#component))

typedef struct component_manager component_manager_t;

struct component_manager {
    hash_t *component_hash;
    component_array_t *component_data;
};

bool component_manager_ctor(component_manager_t *this);
void component_manager_dtor(component_manager_t *this);

bool component_manager_register(component_manager_t *this,
                                hash_t component,
                                uint64_t elem_size,
                                void (*dtor)(void *data));
bool component_manager_set(component_manager_t *this,
                            entity_t entity,
                            hash_t component,
                            void *value);
void component_manager_remove(component_manager_t *this,
                                entity_t entity);

void *component_manager_get(component_manager_t *this,
                            entity_t entity,
                            hash_t component);
component_array_t *get_component_array(component_manager_t *this,
                                        hash_t component);
signature_t get_component_signature(component_manager_t *this,
                                        hash_t component);

#endif /* !COMPONENT_MANAGER_H_ */
