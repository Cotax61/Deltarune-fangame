/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_evt
*/

#include "gote/gote.h"
#include "rpg/formats/texture.h"
#include "rpg/render_queue.h"
#include "rpg/components.h"
#include "rpg/systems.h"
#include "./priv.h"

static void do_fight_selection(fight_action_comp_t *comp)
{
    if (comp->index == 0) {
        comp->current_act = RPG_ATTACK;
    }
}

static void process_keys(fight_action_comp_t *comp, sfKeyCode key)
{
    if (key == sfKeyLeft) {
        change_act_color(comp->list[comp->index],
        comp->list[comp->index]->default_color);
        comp->index = comp->index == 0 ? 3 : comp->index - 1;
        change_act_color(comp->list[comp->index],
        comp->list[comp->index]->selected_color);
    } else if (key == sfKeyRight) {
        change_act_color(comp->list[comp->index],
        comp->list[comp->index]->default_color);
        comp->index = comp->index == 3 ? 0 : comp->index + 1;
        change_act_color(comp->list[comp->index],
        comp->list[comp->index]->selected_color);
    }
    if (key == sfKeyZ)
        do_fight_selection(comp);
}

void process_fight_evt(rpg_fight_channel_t *sub, fight_action_comp_t *comp,
    gt_world_t *world)
{
    gt_event_channel_t *sf_chan = gt_world_get(world, "sfml_channel");
    sfEvent evt;

    while (gt_event_channel_poll(sf_chan, sub->sf_chan_sub, &evt)) {
        if (evt.type == sfEvtKeyPressed) {
            process_keys(comp, evt.key.code);
        }
    }
}
