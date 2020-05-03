/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** title_ui
*/

#include "rpg/ui.h"
#include "priv.h"

static void set_values(rpg_ui_widget_t *btn, int row_index)
{
    switch (row_index) {
    case 0:
        btn->bounds = BOUNDS(-200 * 2, -200 * 1.3, 200 * 2, -100 * 1.3);
        btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
        break;
    case 1:
        btn->bounds = BOUNDS(-200 * 2, -50 * 1.3, 200 * 2, 50 * 1.3);
        btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
        break;
    case 2:
        btn->bounds = BOUNDS(-200 * 2, 100 * 1.3, 200 * 2, 200 * 1.3);
        btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
        break;
    default:
        break;
    }
}

static rpg_ui_widget_t *create_menu_button(rpg_ui_widget_t *root, 
    rpg_ui_menu_button_args_t args, int row_index, sfSound *beep)
{
    rpg_ui_widget_t *btn = rpg_ui_menu_button_create(&args, beep);

    set_values(btn, row_index);
    return (btn);
}

rpg_ui_widget_t *rpg_title_create_ui(gt_world_t *world, sfSound *beep)
{
    rpg_ui_widget_t *root = rpg_ui_widget_create();
    rpg_ui_widget_t *save_one = create_menu_button(root, 
        (rpg_ui_menu_button_args_t) { false, "Julien", 
        0, "Chapter I - Intro"}, 0, beep);
    rpg_ui_widget_t *save_two = create_menu_button(root, 
        (rpg_ui_menu_button_args_t) { true, "", 0, ""}, 1, beep);
    rpg_ui_widget_t *save_three = create_menu_button(root, 
        (rpg_ui_menu_button_args_t) { true, "", 0, ""}, 2, beep);

    root->background = 0x0;
    root->bounds = BOUNDS(0, 0, 0, 0);
    root->anchors = BOUNDS(0, 0, 1, 1);
    rpg_ui_widget_add(root, save_one);
    rpg_ui_widget_add(root, save_two);
    rpg_ui_widget_add(root, save_three);
    rpg_ui_widget_static_on(save_one, "click", &rpg_title_play_clicked, world);
    return (root);
}