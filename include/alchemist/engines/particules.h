/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** particules
*/

#ifndef PARTICULES_H_
    #define PARTICULES_H_

    #include "sprite.h"

    #define NEW_PARTICULE(name, filepath, size, anim_speed, emit, behaviour, lifetime)\
    add_particule(#name,\
    (particule_t []){particule_ctor(\
        (sprite_t []){sprite_ctor(\
            (filepath),\
            VECTOR2F((size), (size)),\
            (anim_speed))},\
        (emit),\
        (behaviour),\
        (lifetime))})

    #define PARTICULE_ANIMATE(name, sheet_index, frames, loop)\
    particule_add_animation(fetch_particule(#name),\
    (sheet_index),\
    (frames),\
    (loop))

    #define PARTICULE_SET_ANIMATION(name, anim_id)\
    particule_set_animation(fetch_particule(#name),\
    (anim_id))

typedef struct particule_machine particule_machine_t;
typedef struct particule particule_t;

struct particule_machine {
    sfIntRect zone;
    uint64_t count;
    float scale;
    float speed;
};

struct particule {
    sprite_t sprite;
    particule_t (*emit)(particule_t *particule, particule_machine_t *machine);
    void (*behaviour)(particule_t *particule);
    sfVector2f velocity;
    sfColor color;
    uint64_t lifetime;
};

particule_t particule_ctor(sprite_t *sprite,
                        particule_t (*emit)(particule_t *particule,
                                            particule_machine_t *machine),
                        void (*behaviour)(particule_t *particule),
                        uint64_t lifetime);
void particule_dtor(particule_t *this);

sfVector2f particule_get_position(particule_t *this);
sfVector2f particule_get_scale(particule_t *this);
float particule_get_rotation(particule_t *this);
sfFloatRect particule_get_box(particule_t *this);
sfColor particule_get_color(particule_t *this);
animation_t *particule_get_animation(particule_t *this);

void particule_set_position(particule_t *this, sfVector2f pos);
void particule_set_scale(particule_t *this, sfVector2f scale);
void particule_set_rotation(particule_t *this, float angle);
void particule_set_color(particule_t *this, sfColor color);
void particule_set_animation(particule_t *this, uint64_t index);

bool particule_add_animation(particule_t *this, uint64_t sheet_index, uint64_t frames, bool loop);

particule_t particule_copy(particule_t *this);

void particule_behave(particule_t *this);

map_t **get_particule_atlas(void);
void set_particule_atlas(map_t *map);
void add_particule(const char *key, particule_t *particule);
particule_t *fetch_particule(const char *key);

sfVector2f zone_rand(sfIntRect zone);

particule_t flame_emitter(particule_t *particule,
                        particule_machine_t *machine);
void flame_behaviour(particule_t *particule);

particule_t soul_flame_emitter(particule_t *particule,
                        particule_machine_t *machine);
void soul_flame_behaviour(particule_t *particule);

particule_t smoke_emitter(particule_t *particule,
                        particule_machine_t *machine);
void smoke_behaviour(particule_t *particule);

#endif /* !PARTICULES_H_ */
