/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_action
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components.h"

static void destroyer(void *raw)
{
    fight_action_comp_t *self = raw;

    for (int i = 0; self->list[i]; i++)
        my_free(self->list[i]);
    my_free(self->list);
    my_free(self);
}

void change_act_color(rpg_fight_ui_t *comp, sfColor color)
{
    sfText_setColor(comp->display_text, color);
    sfRectangleShape_setOutlineColor(comp->rect, color);
}

fight_action_comp_t *fight_action_component(rpg_fight_ui_t **list)
{
    fight_action_comp_t *new = my_malloc(sizeof(fight_action_comp_t));

    new->index = 0;
    new->current_act = RPG_NONE;
    new->is_player_turn = true;
    new->list = list;
    new->selected = list[0];
    new->show = true;
    return (new);
}

const gt_component_class_t FIGHT_ACTION_COMP = {
    .name = "fight_action_component",
    .destroyer = &destroyer,
};
