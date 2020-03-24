/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI canvas
*/

#ifndef RPG_UI_CANVAS_H
#define RPG_UI_CANVAS_H

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/ui/widget.h"

extern const gt_component_class_t CANVAS_COMP;

typedef struct {
    rpg_ui_widget_t *root;
} rpg_ui_canvas_t;

gt_entity_t *rpg_ui_canvas_create(gt_world_t *world, rpg_ui_widget_t *root,
    f64_t depth);
gt_system_t *rpg_ui_system(void);

#endif /* RPG_UI_CANVAS_H */
