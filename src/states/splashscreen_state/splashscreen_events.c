/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** splashscreen_events
*/

#include <SFML/Graphics.h>
#include "gote/gote.h"
#include "rpg/states.h"

void rpg_sscreen_btn_pressed(gt_world_t *world, sfEvent *sf_evt, void *user_data)
{
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    sfKeyEvent evt = sf_evt->key;
    gt_state_trans_t trans;

    (void)(user_data);
    if (evt.code == sfKeySpace) {
        trans = gt_state_trans_switch(rpg_title_state());
        gt_event_channel_push(trans_chan, &trans);
    }
}