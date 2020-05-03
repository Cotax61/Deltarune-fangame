/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include <SFML/Graphics.h>
#include "gote/gote.h"

gt_entity_t *init_fight_player(gt_world_t *world);
gt_entity_t *create_hp_bar(gt_world_t *world, float *ref, float *max_ref,
    sfFont *font);
gt_entity_t *create_tp_bar(gt_world_t *world, float *ref, float *max_ref,
    sfFont *font);

#endif /* !FIGHT_H_ */