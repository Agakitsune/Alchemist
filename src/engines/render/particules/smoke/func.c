/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** func
*/

#include "alchemist/engines/particules.h"

static float float_rand(void)
{
    int value = rand() % 1000;

    return (float)value / 1000;
}

particule_t smoke_emitter(particule_t *particule,
                        particule_machine_t *machine)
{
    static uint8_t cd = 0;
    particule_t emitted = {{{NULL, NULL}, {0, 0, 0, 0}, 0, NULL, NULL, 0},
    NULL, NULL, {0, 0}, sfBlack, 0};
    sfVector2f scale = {0, 0};

    if (cd > 0) {
        --cd;
        return emitted;
    }
    if (!particule || !machine)
        return emitted;
    scale = VECTOR2F(machine->scale, machine->scale);
    scale.x += float_rand() * ((rand() % 2 == 1) ? 1 : -1);
    scale.y = scale.x;
    emitted = particule_copy(particule);
    particule_set_scale(particule, scale);
    particule_set_position(particule, zone_rand(machine->zone));
    particule->velocity = VECTOR2F(0, machine->speed);
    cd = 20;
    return emitted;
}

void smoke_behaviour(particule_t *particule)
{
    sfVector2f pos = {0, 0};

    if (!particule)
        return;
    pos = particule_get_position(particule);
    pos.x += rand() % 2 * ((rand() % 2 == 1) ? -1 : 1);
    pos.y -= 1;
    particule_set_position(particule, pos);
    --particule->lifetime;
}
