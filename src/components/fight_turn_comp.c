/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_turn_comp
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components.h"

const gt_component_class_t FIGHT_TURN_COMP = {
    .name = "fight_turn_component",
    .destroyer = "my_free"
};

fight_turn_comp_t *fight_turn_component(void)
{
    fight_turn_comp_t *new = my_malloc(sizeof(health_comp_t));

    new->turn = RPG_PLAYER_TURN_CALL;
}