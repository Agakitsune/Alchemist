/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** component
*/

#ifndef COMPONENT_H_
    #define COMPONENT_H_

    #include "CSFML.h"

typedef struct position position_t;
typedef struct velocity velocity_t;

struct position {
    int64_t x;
    int64_t y;
};

struct velocity {
    int64_t x;
    int64_t y;
};

#endif /* !COMPONENT_H_ */
