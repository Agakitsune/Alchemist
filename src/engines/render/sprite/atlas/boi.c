/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** boi
*/

#include "alchemist/engines/sprite.h"

map_t **get_sprite_atlas(void)
{
    static map_t *atlas = NULL;

    return &atlas;
}

void set_sprite_atlas(map_t *map)
{
    map_t **atlas = get_sprite_atlas();

    if (!map)
        return;
    *atlas = map;
}

sprite_t *fetch_sprite(const char *key)
{
    map_t **atlas = get_sprite_atlas();

    if (!key)
        return NULL;
    return MAP_FIND(*atlas, key);
}

void add_sprite(const char *key, sprite_t *sprite)
{
    map_t **atlas = get_sprite_atlas();

    if (!key || !sprite)
        return;
    MAP_INSERT(*atlas, key, *sprite);
}
