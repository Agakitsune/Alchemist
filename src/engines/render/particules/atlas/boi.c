/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** boi
*/

#include "alchemist/engines/particules.h"

map_t **get_particule_atlas(void)
{
    static map_t *atlas = NULL;

    return &atlas;
}

void set_particule_atlas(map_t *map)
{
    map_t **atlas = get_particule_atlas();

    if (!map)
        return;
    *atlas = map;
}

particule_t *fetch_particule(const char *key)
{
    map_t **atlas = get_particule_atlas();

    if (!key)
        return NULL;
    return MAP_FIND(*atlas, key);
}

void add_particule(const char *key, particule_t *particule)
{
    map_t **atlas = get_particule_atlas();

    if (!key || !particule)
        return;
    MAP_INSERT(*atlas, key, *particule);
}
