/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** priv
*/

#ifndef PRIV_PAUSE_STATE_H
#define PRIV_PAUSE_STATE_H

#include "my/types.h"
#include "rpg/ui.h"

bool rpg_paused_qtt_clicked(const rpg_ui_event_t *event, void *ptr);
bool rpg_paused_qgame_clicked(const rpg_ui_event_t *event, void *ptr);
bool rpg_paused_res_clicked(const rpg_ui_event_t *event, void *ptr);
void rpg_paused_set_qtt_button(rpg_ui_widget_t *qtt_btn);
void rpg_paused_set_qgame_button(rpg_ui_widget_t *quit_btn);
void rpg_paused_set_resume_button(rpg_ui_widget_t *resume_btn);

#endif /* !PRIV_PAUSE_STATE_H */
