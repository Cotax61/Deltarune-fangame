/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** priv
*/

#ifndef PRIV_DEATH_H_
#define PRIV_DEATH_H_

#include "gote/gote.h"

rpg_ui_widget_t *rpg_death_create_ui(gt_world_t *world, gt_handle_t font);
bool rpg_death_qtt_clicked(const rpg_ui_event_t *event, void *ptr);
bool rpg_death_exit_clicked(const rpg_ui_event_t *event, void *ptr);

#endif /* !PRIV_H_ */
