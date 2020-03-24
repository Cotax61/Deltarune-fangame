/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI canvas implementation
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/ui.h"
#include "rpg/components.h"

static void destroy_canvas_component(void *ptr)
{
    rpg_ui_canvas_t *cvs = ptr;

    if (cvs == NULL)
        return;
    rpg_ui_widget_destroy(cvs->root);
    my_free(ptr);
}

gt_entity_t *rpg_ui_canvas_create(gt_world_t *world, rpg_ui_widget_t *root,
    f64_t depth)
{
    rpg_ui_canvas_t *cvs = my_malloc(sizeof(rpg_ui_canvas_t));

    cvs->root = root;
    return (gt_world_create_entity(
        world,
        2,
        &XFORM_COMP, xform_component(VEC3(0, 0, depth), 1, 0, NULL),
        &CANVAS_COMP, cvs
    ));
}

const gt_component_class_t CANVAS_COMP = {
    .name = "canvas_component",
    .destroyer = &destroy_canvas_component,
};
