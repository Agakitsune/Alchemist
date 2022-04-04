/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** sprite
*/

#ifndef SPRITE_H_
    #define SPRITE_H_

    #include "alloc.h"

    #include "renderables.h"

    #include "c++/vector.h"

    #define NEW_SPRITE(name, filepath, size, anim_speed)\
    add_sprite(#name,\
    (sprite_t []){sprite_ctor(\
        (filepath),\
        (size),\
        (anim_speed))})

    #define SPRITE_ANIMATE(name, sheet_index, frames, loop)\
    sprite_add_animation(fetch_sprite(#name),\
    (sheet_index),\
    (frames),\
    (loop))

    #define SPRITE_SET_ANIMATION(name, anim_id)\
    sprite_set_animation(fetch_sprite(#name),\
    (anim_id))

typedef struct animation animation_t;
typedef struct sprite sprite_t;

struct animation {
    uint64_t frame;
    uint64_t frame_max;
    uint64_t sheet_index;
    bool loop;
};

struct sprite {
    renderable_t renderable;
    sfIntRect texture_rect;
    uint64_t loaded_animation;
    animation_t *animations;
    sfClock *clock;
    float speed;
};

sprite_t sprite_ctor(const char *filepath, sfVector2f size, float anim_speed);
void sprite_dtor(sprite_t *this);

sfVector2f sprite_get_position(sprite_t *this);
sfVector2f sprite_get_scale(sprite_t *this);
float sprite_get_rotation(sprite_t *this);
sfFloatRect sprite_get_box(sprite_t *this);
animation_t *sprite_get_animation(sprite_t *this);

void sprite_set_position(sprite_t *this, sfVector2f pos);
void sprite_set_scale(sprite_t *this, sfVector2f scale);
void sprite_set_rotation(sprite_t *this, float angle);
void sprite_set_animation(sprite_t *this, uint64_t index);

bool sprite_add_animation(sprite_t *this, uint64_t sheet_index, uint64_t frames, bool loop);

map_t **get_sprite_atlas(void);
void set_sprite_atlas(map_t *map);
void add_sprite(const char *key, sprite_t *sprite);
sprite_t *fetch_sprite(const char *key);

sprite_t sprite_copy(sprite_t *this);

void sprite_animate(sprite_t *this);

#endif /* !SPRITE_H_ */
