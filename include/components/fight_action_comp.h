/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_action_comp
*/

#ifndef FIGHT_ACTION_COMP_H_
#define FIGHT_ACTION_COMP_H_

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/ui/fight_button.h"

extern const gt_component_class_t FIGHT_ACTION_COMP;

enum {
    RPG_NONE = 0,
    RPG_ATTACK = 1,
    RPG_MAGIC = 2,
    RPG_ITEM = 3,
    RPG_GUARD = 4
} rpg_fight_action;

typedef struct {
    rpg_fight_ui_t **list;
    rpg_fight_ui_t *selected;
    sfBool show;
    sfBool is_player_turn;
    int current_act;
    int index;
} fight_action_comp_t;

fight_action_comp_t *fight_action_component(rpg_fight_ui_t **list);
void change_act_color(rpg_fight_ui_t *comp, sfColor color);
rpg_fight_ui_t **rpg_fight_create_ui();

#endif /* !FIGHT_ACTION_COMP_H_ */