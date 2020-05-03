/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019 [WSL: Ubuntu]
** File description:
** labels
*/

#include "my/cstr.h"
#include "rpg/ui.h"
#include "priv.h"

rpg_ui_widget_t *rpg_ui_menu_label_create(rpg_ui_widget_t *button,
    const char *text, int x, int y)
{
    rpg_ui_widget_t *self = rpg_ui_widget_create();

    self->parent = button;
    self->text = my_cstrdup(text);
    self->foreground = self->parent->foreground;
    self->bounds = BOUNDS(x, y, x, y);
    self->anchors = BOUNDS(0, 0, 1, 1);
    return (self);
}