/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_button
*/

#ifndef FIGHT_BUTTON_H_
#define FIGHT_BUTTON_H_

#include <SFML/Graphics.h>
#include "rpg/ui.h"

typedef struct rpg_fight_ui_s {
    sfText *display_text;
    sfFont *font;
    sfColor default_color;
    sfColor selected_color;
    sfRectangleShape *rect;
    rpg_vec2_t size;
    rpg_vec2_t pos;
} rpg_fight_ui_t;

void destroy_fight_button(void *self);

#endif /* !FIGHT_BUTTON_H_ */