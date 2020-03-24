/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pause_ui
*/

#include "rpg/ui.h"

void rpg_paused_set_resume_button(rpg_ui_widget_t *resume_btn)
{
    resume_btn->font_size = 34;
    resume_btn->bounds = BOUNDS(-100, -100, 100, -50);
    resume_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
}

void rpg_paused_set_qtt_button(rpg_ui_widget_t *qtt_btn)
{
    qtt_btn->font_size = 34;
    qtt_btn->bounds = BOUNDS(-100, -25, 100, 25);
    qtt_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
}

void rpg_paused_set_qgame_button(rpg_ui_widget_t *quit_btn)
{
    quit_btn->font_size = 34;
    quit_btn->bounds = BOUNDS(-100, 50, 100, 100);
    quit_btn->anchors = BOUNDS(0.5, 0.5, 0.5, 0.5);
}