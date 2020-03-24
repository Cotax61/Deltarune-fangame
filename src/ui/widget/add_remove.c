/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rpg_ui_widget_add implementation
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/ui.h"

void rpg_ui_widget_add(rpg_ui_widget_t *self, rpg_ui_widget_t *child)
{
    if (child->parent)
        rpg_ui_widget_remove(child->parent, child);
    list_push_back(self->children, child);
    child->parent = self;
}

void rpg_ui_widget_remove(rpg_ui_widget_t *self, rpg_ui_widget_t *child)
{
    if (child->parent != self)
        return;
    list_remove_element(self->children, (void*) child, NULL);
    child->parent = NULL;
}
