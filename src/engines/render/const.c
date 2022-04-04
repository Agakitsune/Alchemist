/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** const
*/

#include "alchemist/engines/render_engine.h"

render_engine_t *get_render_engine(void)
{
    static render_engine_t engine = {NULL, NULL, NULL};

    return &engine;
}

void set_render_engine(render_engine_t engine)
{
    render_engine_t *ptr = get_render_engine();

    *ptr = engine;
}
