/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** boi
*/

#include "alchemist/engines/renderables.h"

map_t **get_atlas(void)
{
    static map_t *atlas = NULL;

    return &atlas;
}

void set_atlas(map_t *map)
{
    map_t **atlas = get_atlas();

    if (!map)
        return;
    *atlas = map;
}

void atlas_dtor(void)
{
    map_t **atlas = get_atlas();
    sfTexture **tmp = NULL;

    if (*atlas == NULL)
        return;
    tmp = (sfTexture **)(*atlas)->data;
    for (uint64_t i = 0; i < MAP_SIZE(*atlas); ++i)
        sfTexture_destroy(tmp[i]);
}

sfTexture *fetch_from_atlas(const char *key)
{
    map_t **atlas = get_atlas();
    sfTexture *tmp = NULL;

    if (*atlas == NULL)
        return NULL;
    tmp = MAP_FIND(*atlas, key);
    if (!tmp)
        return NULL;
    return tmp;
}

void add_to_atlas(const char *key, sfTexture *texture)
{
    map_t **atlas = get_atlas();

    if (*atlas == NULL)
        return;
    MAP_INSERT(*atlas, key, texture);
}
