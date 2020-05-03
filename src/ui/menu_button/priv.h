/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019 [WSL: Ubuntu]
** File description:
** priv
*/

#ifndef PRIV_BUTTON_H_
#define PRIV_BUTTON_H_

#include "my/types.h"

extern const u32_t BORDER_COLOR_ON;
extern const u32_t BORDER_COLOR_OFF;

struct state {
    rpg_ui_widget_t *name_label;
    rpg_ui_widget_t *state_label;
    rpg_ui_widget_t *time_label;
    sfSound *beep_sound;
    bool pressed;
};

bool rpg_ui_menu_move_event_handler(const rpg_ui_event_t *event, void *ptr);
bool rpg_ui_menu_btn_event_handler(const rpg_ui_event_t *event, void *ptr);
void rpg_ui_menu_btn_do_click(const rpg_ui_event_t *source_event);
bool rpg_ui_menu_btn_on_destroy(const rpg_ui_event_t *event, void *ptr);

#endif /* !PRIV_H_ */
