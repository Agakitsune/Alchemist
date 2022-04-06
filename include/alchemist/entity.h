/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include <stdint.h>
    #include <stdbool.h>

    #define DEAD 0
    #define ALIVE 1
    #define SLEEP 2
    #define MARKER 3
    #define REFERENCE 4

    #define ENTITY_NEW(id, layer, stage, status)\
    ((entity_t)((uint32_t)(id)) << 32) +\
    ((entity_t)((uint16_t)(layer)) << 16) +\
    ((entity_t)((uint8_t)(stage)) << 8) +\
    ((entity_t)((uint8_t)(status)))

    #define ENTITY_GET_ID(entity)\
    (uint32_t)(((entity_t)(entity) >> 32) & UINT32_MAX)

    #define ENTITY_GET_LAYER(entity)\
    (uint16_t)(((entity_t)(entity) >> 16) & UINT16_MAX)

    #define ENTITY_GET_STAGE(entity)\
    (uint8_t)(((entity_t)(entity) >> 8) & UINT8_MAX)

    #define ENTITY_GET_STATUS(entity)\
    (uint8_t)(((entity_t)(entity) ) & UINT8_MAX)

    #define ENTITY_SET_LAYER(entity, layer)\
    (entity) = ((entity_t)(entity)) | (((entity_t)(layer) & UINT16_MAX) << 16)

    #define ENTITY_SET_STAGE(entity, stage)\
    (entity) = ((entity_t)(entity)) | (((entity_t)(stage) & UINT8_MAX) << 8)

    #define ENTITY_SET_STATUS(entity, status)\
    (entity) = ((entity_t)(entity)) | (((entity_t)(status) & UINT8_MAX))

    #define ENTITY_IS_STATUS(entity, status)\
    (((ENTITY_GET_STATUS(entity)) == (status)) ? true : false)

typedef uint64_t entity_t;

int64_t entity_cmp_id(entity_t *a, entity_t *b);
int64_t entity_cmp_layer(entity_t *a, entity_t *b);

#endif /* !ENTITY_H_ */
