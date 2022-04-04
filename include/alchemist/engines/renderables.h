/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** renderables
*/

#ifndef RENDERABLES_H_
    #define RENDERABLES_H_

    #include "CSFML.h"

    #include "alloc.h"

    #include "c++/map.h"

typedef struct renderable renderable_t;

struct renderable {
    sfTexture *texture;
    sfSprite *sprite;
};

renderable_t renderable_ctor(const char *filepath);
void renderable_dtor(renderable_t *this);

sfVector2f renderable_get_position(renderable_t *this);
sfVector2f renderable_get_scale(renderable_t *this);
float renderable_get_rotation(renderable_t *this);
sfFloatRect renderable_get_box(renderable_t *this);

void renderable_set_position(renderable_t *this, sfVector2f pos);
void renderable_set_scale(renderable_t *this, sfVector2f scale);
void renderable_set_rotation(renderable_t *this, float angle);

renderable_t renderable_copy(renderable_t *this);

map_t **get_atlas(void);
void set_atlas(map_t *map);
void atlas_dtor(void);
sfTexture *fetch_from_atlas(const char *key);
void add_to_atlas(const char *key, sfTexture *texture);

#endif /* !RENDERABLES_H_ */
