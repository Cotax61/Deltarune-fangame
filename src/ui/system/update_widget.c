/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI system rpg_ui_system_update_widget() implementation
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/components.h"
#include "rpg/ui.h"
#include "priv.h"

static void update_xform(rpg_ui_widget_t *widget, rpg_ui_sys_t *sys)
{
    xform_comp_t *xform = gt_storage_get(sys->xform_strg,
        widget->priv.entity->id);

    xform->trans.x = widget->abs_bounds.left;
    xform->trans.y = widget->abs_bounds.top;
    xform->depth = 0;
    xform->parent = widget->parent ?
        gt_storage_get(sys->xform_strg, widget->parent->priv.entity->id) :
        sys->cvs_xform;
}

static void update_rect(rpg_ui_widget_t *widget, rpg_ui_sys_t *sys)
{
    rect_comp_t *rect = gt_storage_get(sys->rect_strg, widget->priv.entity->id);
    rpg_bounds_t abs_bounds = widget->abs_bounds;

    rect->color = widget->background;
    rect->width = abs_bounds.right - abs_bounds.left;
    rect->height = abs_bounds.bottom - abs_bounds.top;
}

static void align_text(rpg_ui_widget_t *widget, text_comp_t *text)
{
    rpg_bounds_t abs_bounds = widget->abs_bounds;

    text->pos = VEC2(0, 0);
    text->halign = widget->text_halign;
    if (widget->text_halign == RPG_CENTER)
        text->pos.x = (abs_bounds.right - abs_bounds.left) / 2.0;
    else if (widget->text_halign == RPG_RIGHT)
        text->pos.x = abs_bounds.right - abs_bounds.left;
    text->valign = widget->text_valign;
    if (widget->text_valign == RPG_BOTTOM)
        text->pos.y = abs_bounds.bottom - abs_bounds.top;
    else if (widget->text_valign != RPG_TOP)
        text->pos.y = (abs_bounds.bottom - abs_bounds.top) / 2.0;
}

static void update_text(rpg_ui_widget_t *widget, rpg_ui_sys_t *sys)
{
    text_comp_t *text = gt_storage_get(sys->text_strg, widget->priv.entity->id);
    const rpg_ui_widget_t *font_holder = widget;

    while (font_holder->font == NULL && font_holder->parent != NULL)
        font_holder = font_holder->parent;
    text->color = widget->foreground;
    text->size = widget->font_size;
    text_comp_set_text(text, widget->text);
    text_comp_set_font(text, font_holder->font);
    align_text(widget, text);
}

void rpg_ui_system_update_widget(rpg_ui_widget_t *widget, gt_world_t *world,
    rpg_ui_sys_t *sys, const rpg_bounds_t *container)
{
    rpg_ui_system_do_layout(widget, container);
    if (!widget->priv.init)
        rpg_ui_system_init_widget(widget, world);
    update_xform(widget, sys);
    update_rect(widget, sys);
    update_text(widget, sys);
    rpg_ui_system_process_events(widget);
    LIST_FOR_EACH(widget->children, iter)
        rpg_ui_system_update_widget(iter.v, world, sys, &widget->abs_bounds);
}
