/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "hash.h"

    #include "fast_set.h"
    #include "vector.h"

    #define MAP_NEW(size, type)\
    map_ctor((size), sizeof(type))

    #define MAP_DESTROY(map)\
    map_dtor((map))

    #define MAP_SIZE(map)\
    VECTOR_SIZE((map)->data)

    #define MAP_INSERT(map, key, value)\
    map_insert((map), (key), (__typeof__(value) []){(value)})

    #define MAP_ERASE(map, key)\
    map_erase((map), (key))

    #define MAP_CLEAR(map)\
    map_clear((map))

    #define MAP_FIND(map, key)\
    map_find((map), (key))

typedef struct map map_t;

struct map {
    hash_t *hashes;
    void *data;
};

map_t *map_ctor(uint64_t size, uint64_t data_size);
void map_dtor(map_t *this);

bool map_insert(map_t *this, const char *key, void *value);
void map_erase(map_t *this, const char *key);
void map_clear(map_t *this);

void *map_find(map_t *this, const char *key);

#endif /* !MAP_H_ */
