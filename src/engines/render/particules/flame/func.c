/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** func
*/

#include "alchemist/engines/particules.h"

particule_t flame_emitter(particule_t *particule,
                        particule_machine_t *machine)
{
    particule_t emitted = {{{NULL, NULL}, {0, 0, 0, 0}, 0, NULL, NULL, 0},
    NULL, NULL, {0, 0}, sfBlack, 0};

    if (!particule || !machine)
        return emitted;
    emitted = particule_copy(particule);
    particule_set_scale(particule, VECTOR2F(machine->scale, machine->scale));
    particule_set_color(particule, sfColor_fromRGBA(255, 127, 0, 255));
    particule_set_position(particule, zone_rand(machine->zone));
    particule->velocity = VECTOR2F(0, machine->speed);
    return emitted;
}

void flame_behaviour(particule_t *particule)
{
    sfVector2f pos = {0, 0};
    sfColor color = sfBlack;

    if (!particule)
        return;
    pos = particule_get_position(particule);
    pos.x += rand() % 5 * ((rand() % 2 == 1) ? -1 : 1);
    pos.y -= particule->velocity.y;
    particule_set_position(particule, pos);
    particule_set_scale(particule,
    VECTOR_FACTOR(particule_get_scale(particule), 0.95));
    color = particule_get_color(particule);
    color.r *= 0.95;
    color.g *= 0.9;
    color.a *= 0.99;
    particule_set_color(particule, color);
    --particule->lifetime;
}
