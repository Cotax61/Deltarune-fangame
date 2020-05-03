/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019 [WSL: Ubuntu]
** File description:
** label
*/

#ifndef LABEL_H_
#define LABEL_H_

#include "rpg/ui/widget.h"

rpg_ui_widget_t *rpg_ui_label_create(u32_t color, const char *text);
rpg_ui_widget_t *rpg_ui_menu_label_create(rpg_ui_widget_t *button,
    const char *text, int x, int y);
    
#endif /* !LABEL_H_ */
