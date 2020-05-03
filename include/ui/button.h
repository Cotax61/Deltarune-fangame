/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Button widget
*/

#ifndef RPG_UI_BUTTON_H
#define RPG_UI_BUTTON_H

#include <SFML/Audio.h>
#include "rpg/ui/widget.h"

typedef struct {
    bool is_empty;
    const char *character_name;
    const long time_played;
    const char *current_state;
} rpg_ui_menu_button_args_t;

rpg_ui_widget_t *rpg_ui_button_create(const char *text);
rpg_ui_widget_t *rpg_ui_menu_button_create(rpg_ui_menu_button_args_t *args,
    sfSound *beep_sound);

#endif /* RPG_UI_BUTTON_H */
