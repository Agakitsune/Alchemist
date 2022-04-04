/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** main
*/

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#include "CSFML.h"
#include "alchemist/engines/render_engine.h"
#include "alchemist/world.h"

sfSprite *sprt = NULL;

void cooldown(entity_t entity)
{
    cooldown_t *cd = ALCHEMIST_GET(entity, cooldown_t);

    if (!cd)
        return;
    if (cd->value > 0)
        --cd->value;
}

void shoot(entity_t entity)
{
    damage_t *dmg = ALCHEMIST_GET(entity, damage_t);
    cooldown_t *cd = ALCHEMIST_GET(entity, cooldown_t);

    if (!dmg || !cd)
        return;
    if (cd->value == 0) {
        flog(INFO, "Shoot");
        cd->value = cd->max;
    }
}

void move(entity_t entity)
{
    transform_t *transform = ALCHEMIST_GET(entity, transform_t);
    velocity_t *vel = ALCHEMIST_GET(entity, velocity_t);
    float rad = 0;

    if (!transform || !vel)
        return;
    printf("Move[%u]: {%f, %f}\n", ENTITY_GET_ID(entity), vel->angle, vel->speed);
    rad = vel->angle * (3.14159265358979323846264338 / 180.0);
    transform->pos = VECTOR_ADD(transform->pos,
    VECTOR2F(vel->speed * cos(rad), vel->speed * sin(rad)));
}

float my_atan2(sfVector2f origin, sfVector2f dest)
{
    float dx = origin.x - dest.x;
    float dy = origin.y - dest.y;
    float angle = atan(dy / dx);
    return angle;
}

void follow_path(entity_t entity)
{
    path_t *path = ALCHEMIST_GET(entity, path_t);
    transform_t *transform = ALCHEMIST_GET(entity, transform_t);
    velocity_t *vel = ALCHEMIST_GET(entity, velocity_t);
    sfFloatRect zone = {0, 0, 0, 0};

    if (!path || !transform || !vel)
        return;
    zone.left = path->pos[path->next_pos].x - vel->speed;
    zone.top = path->pos[path->next_pos].y - vel->speed;
    zone.width = vel->speed * 2;
    zone.height = vel->speed * 2;
    if (sfFloatRect_contains(&zone, transform->pos.x, transform->pos.y)) {
        if (path->next_pos < 3) {
            path->next_pos += 1;
            vel->angle = atan2(
                path->pos[path->next_pos].y - transform->pos.y,
                path->pos[path->next_pos].x - transform->pos.x
            ) * (180 / 3.14159265358979323846264338);
        } else {
            ALCHEMIST_KILL(entity);
            // RENDER_ENGINE_REMOVE(entity);
            // BREAKPOINT;
        }
    }
}

void spawn(entity_t entity)
{
    cooldown_t *cd = ALCHEMIST_GET(entity, cooldown_t);
    entity_t new = 0;

    if (!cd)
        return;
    if (cd->value == 0) {
        new = ALCHEMIST_NEW_ENTITY(5);
        if (ENTITY_IS_STATUS(new, DEAD))
            return;
        ALCHEMIST_SET(new, transform_t, {{100, 100}, {1, 1}, 0});
        ALCHEMIST_SET(new, velocity_t, {2, 45});
        ALCHEMIST_SET(new, path_t, {0, {{250, 250}, {250, 400}, {100, 250}, {100, 500}}});
        // RENDER_ENGINE_SET_SPRITE(new, sprt, {0, 0, 16, 16});
        cd->value = cd->max;
    }
}

int main(void)
{
    sfVector2i mouse = {0, 0};
    entity_t n = ENTITY_NEW(0, 0, 0, ALIVE);
    (void)n;
    ALCHEMIST_INIT;
    ALCHEMIST_COMPONENT(transform_t, NULL);
    // ALCHEMIST_COMPONENT(cooldown_t, NULL);
    // ALCHEMIST_COMPONENT(damage_t, NULL);
    // ALCHEMIST_COMPONENT(velocity_t, NULL);
    // ALCHEMIST_COMPONENT(path_t, NULL);
    // ALCHEMIST_COMPONENT(spawn_t, NULL);
    // ALCHEMIST_SYSTEM(&cooldown, cooldown_t);
    // ALCHEMIST_SYSTEM(&shoot, cooldown_t, damage_t);
    // ALCHEMIST_SYSTEM(&move, transform_t, velocity_t);
    // ALCHEMIST_SYSTEM(&follow_path, transform_t, velocity_t, path_t);
    // ALCHEMIST_SYSTEM(&spawn, cooldown_t, spawn_t);
    n = ALCHEMIST_NEW_ENTITY(4);
    ALCHEMIST_SET(n, transform_t, {{100, 100}, {1, 1}, 0});
    // ALCHEMIST_SET(spawner, cooldown_t, {15, 10});
    // ALCHEMIST_SET(spawner, spawn_t, {0});
    set_atlas(MAP_NEW(64, sfTexture *));
    set_particule_atlas(MAP_NEW(64, particule_t));
    set_sprite_atlas(MAP_NEW(64, sprite_t));
    NEW_PARTICULE(FLAME, "assets/textures/particules/flame.png", 16, 0.1, &flame_emitter, &flame_behaviour, 100);
    NEW_PARTICULE(SOUL_FLAME, "assets/textures/particules/flame.png", 16, 0.1, &soul_flame_emitter, &soul_flame_behaviour, 100);
    NEW_PARTICULE(SMOKE, "assets/textures/particules/smoke.png", 16, 0.3, &smoke_emitter, &smoke_behaviour, 100);
    PARTICULE_ANIMATE(SMOKE, 0, 5, false);
    PARTICULE_SET_ANIMATION(SMOKE, 0);
    NEW_SPRITE(SPIN, "assets/textures/enemies/spin.png", VECTOR2F(16, 16), 0.1);
    SPRITE_ANIMATE(SPIN, 0, 4, true);
    SPRITE_ANIMATE(SPIN, 1, 2, true);
    SPRITE_SET_ANIMATION(SPIN, 0);
    RENDER_ENGINE_INIT(800, 600, 32, "Render Engine Test", 60);
    RENDER_ENGINE_SET_SPRITE(n, SPIN);
    RENDER_ENGINE_ENTITY_SET_ANIMATION(n, 0);
    sfRenderWindow_setMouseCursorVisible(get_render_engine()->window, sfFalse);
    do {
        ALCHEMIST_UPDATE;
        mouse = sfMouse_getPositionRenderWindow(get_render_engine()->window);
        RENDER_ENGINE_EMIT(SMOKE, mouse.x, mouse.y, 0, 0, 1, 1, 1);
        RENDER_ENGINE_EMIT(FLAME, mouse.x, mouse.y, 0, 0, 1, 1, 1);
        RENDER_ENGINE_RENDER;
        RENDER_ENGINE_UPDATE;
    } while (RENDER_ENGINE_OPEN);
    RENDER_ENGINE_DESTROY;
    // ALCHEMIST_END;
    return 0;
}
