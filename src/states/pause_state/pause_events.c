/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pause_events
*/

#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/formats.h"
#include "rpg/states.h"
#include "rpg/ui.h"

bool rpg_paused_qtt_clicked(const rpg_ui_event_t *event, void *ptr)
{
    gt_world_t *world = ptr;
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    gt_state_trans_t trans_pop = gt_state_trans_pop();
    gt_state_trans_t trans_swi = gt_state_trans_switch(rpg_title_state());

    (void)(event);
    gt_event_channel_push(trans_chan, &trans_pop);
    gt_event_channel_push(trans_chan, &trans_swi);
    return (false);
}

bool rpg_paused_qgame_clicked(const rpg_ui_event_t *event, void *ptr)
{
    gt_world_t *world = ptr;
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    gt_state_trans_t trans_quit = gt_state_trans_quit();

    (void)(event);
    gt_event_channel_push(trans_chan, &trans_quit);
    return (false);
}

bool rpg_paused_res_clicked(const rpg_ui_event_t *event, void *ptr)
{
    gt_world_t *world = ptr;
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    gt_state_trans_t trans_pop = gt_state_trans_pop();

    (void)(event);
    gt_world_insert(world, "is_paused", (void*) 0, NULL);
    gt_event_channel_push(trans_chan, &trans_pop);
    return (false);
}
