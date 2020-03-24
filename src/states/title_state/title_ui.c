/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** title_ui
*/

#include "rpg/ui.h"
#include "priv.h"

static void set_values(rpg_ui_widget_t *play_btn, rpg_ui_widget_t *sett_btn,
    rpg_ui_widget_t *quit_btn)
{
    play_btn->font_size = 34;
    play_btn->bounds = BOUNDS(-100, -100, 100, -50);
    play_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
    sett_btn->font_size = 34;
    sett_btn->bounds = BOUNDS(-100, -25, 100, 25);
    sett_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
    quit_btn->font_size = 34;
    quit_btn->bounds = BOUNDS(-100, 50, 100, 100);
    quit_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
}

rpg_ui_widget_t *rpg_title_create_ui(gt_world_t *world)
{
    rpg_ui_widget_t *root = rpg_ui_widget_create();
    rpg_ui_widget_t *play_btn = rpg_ui_button_create("NEW GAME");
    rpg_ui_widget_t *sett_btn = rpg_ui_button_create("SETTINGS");
    rpg_ui_widget_t *quit_btn = rpg_ui_button_create("EXIT GAME");

    root->background = 0x888888FF;
    root->bounds = BOUNDS(0, 0, 0, 0);
    root->anchors = BOUNDS(0, 0, 1, 1);
    set_values(play_btn, sett_btn, quit_btn);
    rpg_ui_widget_static_on(play_btn, "click", &rpg_title_play_clicked, world);
    rpg_ui_widget_static_on(quit_btn, "click", &rpg_title_exit_clicked, world);
    rpg_ui_widget_add(root, play_btn);
    rpg_ui_widget_add(root, sett_btn);
    rpg_ui_widget_add(root, quit_btn);
    return (root);
}