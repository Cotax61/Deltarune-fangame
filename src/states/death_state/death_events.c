/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** title_events
*/

#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/formats.h"
#include "rpg/states.h"
#include "rpg/ui.h"

bool rpg_death_qtt_clicked(const rpg_ui_event_t *event, void *ptr)
{
    gt_world_t *world = ptr;
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    gt_state_trans_t trans = gt_state_trans_switch(rpg_title_state());

    (void)(event);
    gt_event_channel_push(trans_chan, &trans);
    return (false);
}

bool rpg_death_exit_clicked(const rpg_ui_event_t *event, void *ptr)
{
    gt_world_t *world = ptr;
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    gt_state_trans_t trans = gt_state_trans_quit();

    (void)(event);
    gt_event_channel_push(trans_chan, &trans);
    return (false);
}