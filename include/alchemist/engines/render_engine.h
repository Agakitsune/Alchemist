/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** render_engine
*/

#ifndef RENDER_ENGINE_H_
    #define RENDER_ENGINE_H_

    #include "CSFML.h"
    #include "memory.h"
    #include "debug.h"

    #include "../entity.h"
    #include "../component.h"
    #include "particules.h"
    #include "sprite.h"

    #include "c++/vector.h"
    #include "c++/array.h"

    #define RENDER_ENGINE_INIT(width, height, pixel_depth, title, framerate)\
    render_engine_ctor(get_render_engine(),\
    &((window_desc_t){(width), (height), (pixel_depth), (title), (framerate)}))

    #define RENDER_ENGINE_DESTROY\
    render_engine_dtor(get_render_engine())

    #define RENDER_ENGINE_SET_SPRITE(entity, name)\
    render_engine_add(get_render_engine(), (entity), fetch_sprite(#name))\

    #define RENDER_ENGINE_REMOVE(entity)\
    render_engine_remove(get_render_engine(), (entity))

    #define RENDER_ENGINE_EMIT(name, x, y, width, height, count, size, speed)\
    render_engine_emit(get_render_engine(),\
    fetch_particule(#name),\
    &((particule_machine_t){IRECT(x, y, width, height), (count), (size), (speed)}))

    #define RENDER_ENGINE_ENTITY_SET_STATUS(entity, status)\
    render_engine_set_status(get_render_engine(), (status))

    #define RENDER_ENGINE_ENTITY_SET_STAGE(entity, stage)\
    render_engine_set_stage(get_render_engine(), (stage))

    #define RENDER_ENGINE_ENTITY_SET_LAYER(entity, layer)\
    render_engine_set_layer(get_render_engine(), (layer))

    #define RENDER_ENGINE_RENDER\
    render_engine_render(get_render_engine())

    #define RENDER_ENGINE_UPDATE\
    render_engine_update(get_render_engine())

    #define RENDER_ENGINE_OPEN\
    sfRenderWindow_isOpen(get_render_engine()->window)

    #define RENDER_ENGINE_ENTITY_ANIMATE(entity, sheet_index, frames)\
    sprite_add_animation(render_engine_get_sprite(get_render_engine(),\
    (entity)),\
    (sheet_index),\
    (frames))

    #define RENDER_ENGINE_ENTITY_SET_ANIMATION(entity, anim_id)\
    sprite_set_animation(render_engine_get_sprite(get_render_engine(),\
    (entity)),\
    (anim_id))


typedef struct sprite_handle sprite_handle_t;

struct sprite_handle {
    entity_t entity;
    sprite_t sprite;
};

typedef struct window_desc window_desc_t;

struct window_desc {
    unsigned int width;
    unsigned int height;
    unsigned int bpp;
    const char *name;
    unsigned int framerate;
};

typedef struct render_engine render_engine_t;

struct render_engine {
    sfRenderWindow *window;
    sprite_handle_t **sprites;
    particule_t *particules;
};

bool render_engine_ctor(render_engine_t *this, window_desc_t *desc);
void render_engine_dtor(render_engine_t *this);

bool render_engine_add(render_engine_t *this,
                        entity_t entity,
                        sprite_t *sprite);
bool render_engine_emit(render_engine_t *this,
                        particule_t *particule,
                        particule_machine_t *machine);
void render_engine_remove(render_engine_t *this, entity_t entity);
void render_engine_set_status(render_engine_t *this,
                                entity_t entity,
                                uint8_t status);
void render_engine_set_stage(render_engine_t *this,
                                entity_t entity,
                                uint8_t stage);
void render_engine_set_layer(render_engine_t *this,
                                entity_t entity,
                                uint16_t layer);

sprite_t *render_engine_get_sprite(render_engine_t *this, entity_t entity);

void render_engine_render(render_engine_t *this);
void render_engine_update(render_engine_t *this);

render_engine_t *get_render_engine(void);
void set_render_engine(render_engine_t engine);

int64_t handle_cmp(sprite_handle_t *a, sprite_handle_t *b);

#endif /* !RENDER_ENGINE_H_ */
