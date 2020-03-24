/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** priv
*/

#ifndef RPG_TITLE_STATE_PRIV_H
#define RPG_TITLE_STATE_PRIV_H

#include "gote/gote.h"
#include "rpg/ui.h"

bool rpg_title_play_clicked(const rpg_ui_event_t *event, void *ptr);
bool rpg_title_exit_clicked(const rpg_ui_event_t *event, void *ptr);
rpg_ui_widget_t *rpg_title_create_ui(gt_world_t *world);

#endif /* RPG_TITLE_STATE_PRIV_H */
