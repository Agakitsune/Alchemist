/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** cmp
*/

#include "alchemist/entity.h"

int64_t entity_cmp_id(entity_t *a, entity_t *b)
{
    int64_t tmp_a = ENTITY_GET_ID(*a);
    int64_t tmp_b = ENTITY_GET_ID(*b);

    return tmp_a - tmp_b;
}

int64_t entity_cmp_layer(entity_t *a, entity_t *b)
{
    int64_t tmp_a = ENTITY_GET_LAYER(*a);
    int64_t tmp_b = ENTITY_GET_LAYER(*b);

    return tmp_a - tmp_b;
}
