/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** death_ui
*/

#include "rpg/ui.h"
#include "priv.h"

static const char *DEATH_MESSAGE = "You lost, but I mean what did you\n"
    "expect of an unfinished game, lol\n\n"
    "Btw watch out for the coronavirus.";

static void set_values(rpg_ui_widget_t *quitt_btn, rpg_ui_widget_t *quit_btn)
{
    quitt_btn->font_size = 34;
    quitt_btn->bounds = BOUNDS(-100, -25, 100, 25);
    quitt_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
    quit_btn->font_size = 34;
    quit_btn->bounds = BOUNDS(-100, 50, 100, 100);
    quit_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
}

rpg_ui_widget_t *rpg_death_create_ui(gt_world_t *world, gt_handle_t font)
{
    rpg_ui_widget_t *root = rpg_ui_widget_create();
    rpg_ui_widget_t *quitt_btn = rpg_ui_button_create("QUIT TO TITLE");
    rpg_ui_widget_t *quit_btn = rpg_ui_button_create("QUIT GAME");

    root->text = my_cstrdup(DEATH_MESSAGE);
    root->font = font;
    root->font_size = 34;
    root->foreground = 0xFFFFFFFF;
    root->text_halign = RPG_CENTER;
    root->text_valign = RPG_BOTTOM;
    root->background = 0xFF;
    root->bounds = BOUNDS(0, 0, 0, 0);
    root->anchors = BOUNDS(0, 0, 1, 1);
    set_values(quitt_btn, quit_btn);
    rpg_ui_widget_static_on(quitt_btn, "click", &rpg_death_qtt_clicked, world);
    rpg_ui_widget_static_on(quit_btn, "click", &rpg_death_exit_clicked, world);
    rpg_ui_widget_add(root, quitt_btn);
    rpg_ui_widget_add(root, quit_btn);
    return (root);
}