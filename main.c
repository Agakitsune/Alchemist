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
#include "alchemist/component.h"

void update_pos(entity_t *entity)
{
    uint8_t stage = ALCHEMIST_STAGE;
    position_t *pos = NULL;
    velocity_t *vel = NULL;

    // printf("System\n");
    if (!entity)
        return;
    for (uint64_t i = 0; i < SET_SIZE(entity); ++i) {
        if ((stage != ENTITY_GET_STAGE(entity[i])) ||
        (ENTITY_IS_STATUS(entity[i], ALIVE) == false))
            continue;
        pos = ALCHEMIST_GET(entity[i], position_t);
        vel = ALCHEMIST_GET(entity[i], velocity_t);
        pos->x += vel->x;
        pos->y += vel->y;
        // printf("Position: %ld x %ld\n", pos->x, pos->y);
    }
}

void box(entity_t *entity)
{
    uint8_t stage = ALCHEMIST_STAGE;
    position_t *pos = NULL;
    velocity_t *vel = NULL;
    entity_t entoty = 0;

    // printf("System\n");
    if (!entity)
        return;
    for (uint64_t i = 0; i < SET_SIZE(entity); ++i) {
        if ((stage != ENTITY_GET_STAGE(entity[i])) ||
        (ENTITY_IS_STATUS(entity[i], ALIVE) == false))
            continue;
        pos = ALCHEMIST_GET(entity[i], position_t);
        vel = ALCHEMIST_GET(entity[i], velocity_t);
        if (pos->x < 0) {
            printf("Hit\n");
            vel->x = -vel->x;
            entoty = ALCHEMIST_NEW_ENTITY(4);
            ALCHEMIST_SET(entoty, position_t, {4, 4});
            ALCHEMIST_SET(entoty, velocity_t, {1, 1});
        }
        if (pos->x > 1000) {
            printf("Hit\n");
            vel->x = -vel->x;
            entoty = ALCHEMIST_NEW_ENTITY(4);
            ALCHEMIST_SET(entoty, position_t, {4, 4});
            ALCHEMIST_SET(entoty, velocity_t, {1, 1});
        }
        if (pos->y < 0) {
            printf("Hit\n");
            vel->y = -vel->y;
            entoty = ALCHEMIST_NEW_ENTITY(4);
            ALCHEMIST_SET(entoty, position_t, {4, 4});
            ALCHEMIST_SET(entoty, velocity_t, {1, 1});
        }
        if (pos->y > 1000) {
            printf("Hit\n");
            vel->y = -vel->y;
            entoty = ALCHEMIST_NEW_ENTITY(4);
            ALCHEMIST_SET(entoty, position_t, {4, 4});
            ALCHEMIST_SET(entoty, velocity_t, {1, 1});
        }
        // printf("Position: %ld x %ld\n", pos->x, pos->y);
    }
}

int main(void)
{
    entity_t entity = 0;

    ALCHEMIST_INIT;
    ALCHEMIST_COMPONENT(position_t, NULL);
    ALCHEMIST_COMPONENT(velocity_t, NULL);
    ALCHEMIST_SYSTEM(&update_pos, NULL, position_t, velocity_t);
    ALCHEMIST_SYSTEM(&box, NULL, position_t, velocity_t);
    entity = ALCHEMIST_NEW_ENTITY(4);
    ALCHEMIST_SET(entity, position_t, {4, 4});
    ALCHEMIST_SET(entity, velocity_t, {1, 1});
    while (ALCHEMIST_UPDATE);
    ALCHEMIST_END;
    return 0;
}
