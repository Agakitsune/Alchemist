/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** insert
*/

#include "alchemist/engines/render_engine.h"

// static uint64_t explode(entity_t *data, entity_t entity, uint64_t index)
// {
//     int64_t res = entity_cmp_layer(&data[index], &entity);

//     if (res == 0)
//         return 0;
//     if (res > 0) {
//         if (index == 0)
//             return 1;
//         res = entity_cmp_layer(&data[index - 1], &entity);
//         if (res < 0)
//             return 0;
//     } else {
//         if (index == UINT64_MAX)
//             return -1;
//         res = entity_cmp_layer(&data[index + 1], &entity);
//         if (res > 0)
//             return 0;
//     }
//     return -1;
// }

// static uint64_t search(entity_t *data, entity_t entity)
// {
//     uint64_t min = 0;
//     uint64_t max = VECTOR_SIZE(data);
//     uint64_t mid = 0;
//     int64_t res = 0;

//     while (min < max) {
//         mid = (min + max) / 2;
//         res = explode(data, entity, mid);
//         if (res == 0)
//             return mid;
//         else if (res > 0)
//             max = mid;
//         else
//             min = mid + 1;
//     }
//     return -1;
// }

// static bool brush(entity_t *array, entity_t entity, uint64_t index)
// {
//     uint64_t res_f = 0;
//     uint64_t res_b = 0;
//     uint64_t forward = 1;
//     uint64_t backward = 1;

//     do {
//         res_f = entity_cmp_layer(&array[index + forward], &entity);
//         res_b = entity_cmp_layer(&array[index + backward], &entity);
//         if (entity_cmp_id(&array[index + forward], &entity) == 0)
//             return true;
//         if (entity_cmp_id(&array[index + backward], &entity) == 0)
//             return true;
//         forward += (res_f == 0);
//         backward += (res_b == 0);
//     } while ((res_f == 0) || (res_b == 0));
//     return false;
// }

// static bool vector_fast_insert(entity_t *array, entity_t entity)
// {
//     uint64_t index = search(array, entity);

//     if (index == UINT64_MAX)
//         return false;
//     // if (brush(array, entity, index))
//     //     return true;
//     return VECTOR_INSERT(array, index, entity);
// }

int64_t handle_cmp(sprite_handle_t *a, sprite_handle_t *b)
{
    if (!a && !b)
        return 0;
    return entity_cmp_id(&a->entity, &b->entity);
}

bool render_engine_add(render_engine_t *this,
                        entity_t entity,
                        sprite_t *sprite)
{
    uint16_t layer = ENTITY_GET_LAYER(entity);
    sprite_handle_t **array = NULL;
    sprite_handle_t *tmp = NULL;
    sprite_handle_t handle;

    if (!this || !sprite)
        return false;
    handle.entity = entity;
    handle.sprite = *sprite;
    array = ARRAY_GET(this->sprites, layer);
    if (!array) {
        tmp = FAST_SET_NEW(8192, sprite_handle_t, &handle_cmp);
        if (!tmp)
            return false;
        if (!ARRAY_SET(this->sprites, layer, tmp))
            return false;
        return FAST_SET_INSERT(tmp, handle);
    }
    return FAST_SET_INSERT(*array, handle);
}
