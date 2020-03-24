/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** gameplay_events
*/

#include <SFML/Graphics.h>
#include "gote/gote.h"
#include "my/my.h"
#include "my/io.h"
#include "rpg/event_handlers.h"
#include "rpg/states.h"

static void handle_keypress(gt_world_t *world, sfKeyEvent *keyevt)
{
    u8_t *sel_turret = gt_world_get(world, "selected_turret");

    switch (keyevt->code) {
    case sfKeyNum1:
        *sel_turret = 1;
        break;
    case sfKeyNum2:
        *sel_turret = 2;
        break;
    case sfKeyNum3:
        *sel_turret = 3;
        break;
    case sfKeyQuote:
    case sfKeyNum4:
        *sel_turret = 4;
        break;
    default:
        break;
    }
}

void rpg_game_btn_pressed(gt_world_t *world, sfEvent *sf_evt, void *user_data)
{
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    void *is_paused = gt_world_get(world, "is_paused");
    sfKeyEvent evt = sf_evt->key;
    gt_state_trans_t trans;

    (void)(user_data);
    if (evt.code == sfKeyEscape && !is_paused) {
        trans = gt_state_trans_push(rpg_pause_state());
        gt_event_channel_push(trans_chan, &trans);
        gt_world_insert(world, "is_paused", (void*) 1, NULL);
    } else if (evt.code == sfKeyEscape && is_paused) {
        trans = gt_state_trans_pop();
        gt_event_channel_push(trans_chan, &trans);
        gt_world_insert(world, "is_paused", (void*) 0, NULL);
    }
    handle_keypress(world, &evt);
}
