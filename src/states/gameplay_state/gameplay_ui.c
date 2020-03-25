/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** gameplay_ui
*/

#include "rpg/game_entities.h"
#include "rpg/ui.h"

rpg_ui_widget_t *rpg_gameplay_create_ui(gt_world_t *world, gt_handle_t font)
{
    rpg_ui_widget_t *root = rpg_ui_widget_create();

    (void)(world);
    return (root);
}