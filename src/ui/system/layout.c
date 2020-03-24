/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI Layout computing
*/

#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/ui.h"
#include "priv.h"

void rpg_ui_system_do_layout(rpg_ui_widget_t *widget,
    const rpg_bounds_t *container)
{
    rpg_bounds_t *abs_bounds = (rpg_bounds_t*) &widget->abs_bounds;
    rpg_rect_t container_rect = BOUNDS2RECT(*container);
    rpg_bounds_t abs_anchors = BOUNDS(
        widget->anchors.left * container_rect.width,
        widget->anchors.top * container_rect.height,
        widget->anchors.right * container_rect.width,
        widget->anchors.bottom * container_rect.height
    );

    abs_bounds->left = abs_anchors.left + widget->bounds.left;
    abs_bounds->top = abs_anchors.top + widget->bounds.top;
    abs_bounds->right = abs_anchors.right + widget->bounds.right;
    abs_bounds->bottom = abs_anchors.bottom + widget->bounds.bottom;
}
