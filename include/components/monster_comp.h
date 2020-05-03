/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** monster_comp
*/

#ifndef MONSTER_COMP_H_
#define MONSTER_COMP_H_

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/ui/fight_button.h"

typedef struct {
    int health;
    int attack;
    sfBool is_monster_turn;
} monster_comp_t;

monster_comp_t monster_componenet(int health, int attack);

#endif /* !MONSTER_COMP_H_ */