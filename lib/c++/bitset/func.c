/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** func
*/

#include "c++/bitset.h"
#include <stdio.h>

void bitset_set(bitset_t *this, uint8_t index, bool value)
{
    bitset_t tmp = 0;

    if (!this)
        return;
    tmp = *this;
    tmp &= ~((uint64_t)1 << (63 - index));
    tmp += ((uint64_t)value << (63 - index));
    *this = tmp;
}

bool bitset_get(bitset_t *this, uint8_t index)
{
    bitset_t tmp = 0;

    if (!this)
        return false;
    tmp = *this;
    tmp >>= (63 - index);
    tmp &= 0b1;
    return tmp;
}

void bitset_flip(bitset_t *this)
{
    bitset_t tmp = 0;

    if (!this)
        return;
    tmp = *this;
    tmp = ~tmp;
    *this = tmp;
}

void bitset_reset(bitset_t *this)
{
    if (!this)
        return;
    *this = 0;
}
