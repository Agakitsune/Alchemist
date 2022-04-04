/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** observators2
*/

#include "alchemist/engines/particules.h"

sfColor particule_get_color(particule_t *this)
{
    if (!this)
        return sfBlack;
    return this->color;
}
