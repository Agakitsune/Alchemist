/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** component
*/

#ifndef COMPONENT_H_
    #define COMPONENT_H_

    #include "CSFML.h"

typedef struct transform transform_t;
typedef struct cooldown cooldown_t;
typedef struct damage damage_t;
typedef struct velocity velocity_t;
typedef struct path path_t;
typedef struct spawn spawn_t;

struct transform {
    sfVector2f pos;
    sfVector2f scale;
    float angle;
};

struct cooldown {
    uint32_t value;
    uint32_t max;
};

struct damage {
    uint32_t value;
};

struct velocity {
    float speed;
    float angle;
};

struct path {
    uint32_t next_pos;
    sfVector2f pos[4];
};

struct spawn {
    uint8_t t;
};

#endif /* !COMPONENT_H_ */
