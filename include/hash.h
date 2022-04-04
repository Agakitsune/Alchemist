/*
** EPITECH PROJECT, 2022
** lib
** File description:
** hash
*/

#ifndef HASH_H_
    #define HASH_H_

    #include <stdint.h>
    #include <stddef.h>

    #define FNV_OFFSET 14695981039346656037UL
    #define FNV_PRIME 1099511628211UL

typedef uint64_t hash_t;

hash_t fnv_hash(const void *bytes, size_t size);
hash_t djb2_hash(const void *bytes, size_t size);
hash_t sdbm_hash(const void *bytes, size_t size);

hash_t fnv_hash_str(const char *str);
hash_t djb2_hash_str(const char *str);
hash_t sdbm_hash_str(const char *str);

#endif /* !UTILS_H_ */
