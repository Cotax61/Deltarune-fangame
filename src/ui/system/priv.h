/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Private functions used by the implementation of the UI system
*/

#ifndef RPG_UI_SYSTEM_PRIV_H
#define RPG_UI_SYSTEM_PRIV_H

#include "gote/gote.h"
#include "rpg/ui.h"
#include "rpg/components.h"

typedef struct {
    xform_comp_t *cvs_xform;
    gt_storage_t *cvs_strg;
    gt_storage_t *rect_strg;
    gt_storage_t *xform_strg;
    gt_storage_t *text_strg;
} rpg_ui_sys_t;

void rpg_ui_system_process_events(rpg_ui_widget_t *widget);
void rpg_ui_system_init_widget(rpg_ui_widget_t *widget, gt_world_t *world);
void rpg_ui_system_update_widget(rpg_ui_widget_t *widget, gt_world_t *world,
    rpg_ui_sys_t *sys, const rpg_bounds_t *container);
void rpg_ui_system_do_layout(rpg_ui_widget_t *widget,
    const rpg_bounds_t *container);

#endif /* RPG_UI_SYSTEM_PRIV_H */
