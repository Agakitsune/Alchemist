/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** system
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include "entity.h"
    #include "signature.h"

    #include "c++/set.h"

typedef struct system system_t;

struct system {
    entity_t *entities;
    signature_t signature;
    void (*system)(entity_t *entity);
    bool has_extra;
};

system_t *system_ctor(void (*func)(entity_t *entity),
                    void *extra,
                    size_t extra_size);
void system_dtor(system_t *this);

bool system_set_signature(system_t *this, const char *str);

bool system_add(system_t *this, entity_t entity);
void system_remove(system_t *this, entity_t entity);

void system_set_status(system_t *this, entity_t entity, uint8_t status);
void system_set_stage(system_t *this, entity_t entity, uint16_t stage);

void *system_get_extra(system_t *this);

void system_update(system_t *this);

#endif /* !SYSTEM_H_ */
