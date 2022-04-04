/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** bitset
*/

#ifndef BITSET_H_
    #define BITSET_H_

    #include <stdint.h>
    #include <stdbool.h>

    #define BITSET_SET(this, index, value)\
    bitset_set(this, index, value)

    #define BITSET_GET(this, index)\
    bitset_get(this, index)

    #define BITSET_FLIP(this)\
    bitset_flip(this)

    #define BITSET_RESET(this)\
    bitset_reset(this)

typedef uint64_t bitset_t;

void bitset_set(bitset_t *this, uint8_t index, bool value);
bool bitset_get(bitset_t *this, uint8_t index);
void bitset_flip(bitset_t *this);
void bitset_reset(bitset_t *this);

#endif /* !BITSET_H_ */
