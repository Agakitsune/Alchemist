/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** utils
*/

#include "alchemist/engines/particules.h"

sfVector2f zone_rand(sfIntRect zone)
{
    sfVector2f pos = {zone.left - (float)zone.width / 2,
    zone.top - (float)zone.height / 2};

    pos.x += (zone.width > 0) ? rand() % (zone.width) : 0;
    pos.y += (zone.height > 0) ? rand() % (zone.height) : 0;
    return pos;
}
