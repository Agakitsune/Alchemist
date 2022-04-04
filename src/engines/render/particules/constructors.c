/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** constructors
*/

#include "alchemist/engines/particules.h"

particule_t particule_ctor(sprite_t *sprite,
                        particule_t (*emit)(particule_t *particule,
                                            particule_machine_t *machine),
                        void (*behaviour)(particule_t *particule),
                        uint64_t lifetime)
{
    particule_t particule = {{{NULL, NULL}, {0, 0, 0, 0}, 0, NULL, NULL, 0},
    NULL, NULL, {0, 0}, sfBlack, 0};

    if (!sprite || !sprite->renderable.sprite || !sprite->animations)
        return particule;
    particule.sprite = *sprite;
    particule.emit = emit;
    particule.behaviour = behaviour;
    particule.velocity = VECTOR2F(0, 0);
    particule.color = sfWhite;
    particule.lifetime = lifetime;
    return particule;
}

void particule_dtor(particule_t *this)
{
    if (!this)
        return;
    sprite_dtor(&this->sprite);
}
