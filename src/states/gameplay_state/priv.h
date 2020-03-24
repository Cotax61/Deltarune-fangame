/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** priv
*/

#ifndef PRIV_GAMEPLAY_STATE_H
#define PRIV_GAMEPLAY_STATE_H

#include <SFML/Graphics.h>
#include "gote/gote.h"

void rpg_game_btn_pressed(gt_world_t *world, sfEvent *sf_evt, void *user_data);
gt_entity_t *rpg_game_create_castle(gt_world_t *world, rpg_tilemap_t *tilemap);
rpg_ui_widget_t *rpg_gameplay_create_ui(gt_world_t *world, gt_handle_t font);
void rpg_game_init_money(gt_world_t *world);
void rpg_game_init_values(gt_world_t *world);

#endif /* !PRIV_GAMEPLAY_STATE_H */
