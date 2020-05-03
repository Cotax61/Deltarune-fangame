/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Animation component declaration
*/

#ifndef FIGHT_PLAYER_COMP_H
#define FIGHT_PLAYER_COMP_H

#include "my/my.h"
#include "gote/gote.h"

extern const gt_component_class_t PLAYER_FIGHT_COMP;

typedef struct {
    void *hover_button;
    int chosen_action;
} player_fight_comp_t;

player_fight_comp_t *player_fight_comp(void *default_choice);

#endif