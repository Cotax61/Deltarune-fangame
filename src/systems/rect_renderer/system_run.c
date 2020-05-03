/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Rect renderer running function
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/render_queue.h"
#include "rpg/components.h"
#include "rpg/systems.h"

struct process_data {
    sfRenderWindow *win;
    render_queue_t *rqueue;
    gt_storage_t *rect_strg;
    gt_storage_t *xform_strg;
    rpg_rect_sys_data_t *sys;
};

struct render_data {
    sfRenderWindow *win;
    sfRectangleShape *shape;
    rect_comp_t *rect;
    xform_comp_t *xform;
};

static void render_callback(void *ptr)
{
    struct render_data *data = ptr;
    sfRenderStates rstates = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    sfRectangleShape_setOutlineThickness(data->shape, 
        data->rect->border_thickness);
    sfRectangleShape_setOutlineColor(data->shape, 
        sfColor_fromInteger(data->rect->border_color));
    sfRectangleShape_setFillColor(data->shape,
        sfColor_fromInteger(data->rect->color));
    sfRectangleShape_setSize(data->shape, (sfVector2f) {
        data->rect->width,
        data->rect->height
    });
    if (data->xform)
        rstates.transform = data->xform->local_to_world;
    sfRenderWindow_drawRectangleShape(data->win, data->shape, &rstates);
    my_free(data);
}

static void process_entity(struct process_data *data, gt_entity_t *ent)
{
    struct render_data *rdata = NULL;
    rect_comp_t *rect = gt_storage_get(data->rect_strg, ent->id);
    xform_comp_t *xform = gt_storage_get(data->xform_strg, ent->id);
    f64_t depth = 0.0;

    if (rect == NULL)
        return;
    rdata = my_malloc(sizeof(struct render_data));
    rdata->shape = data->sys->shape;
    rdata->win = data->win;
    rdata->rect = rect;
    rdata->xform = xform;
    depth = xform ? xform->world_depth : 0.0;
    render_queue_push(data->rqueue, depth, &render_callback, rdata);
}

bool rpg_rect_rendering_system_run(void *self_raw, gt_world_t *world)
{
    struct process_data data = {
        gt_world_get(world, "window"),
        gt_world_get(world, "render_queue"),
        gt_world_get(world, RECT_COMP.name),
        gt_world_get(world, XFORM_COMP.name),
        self_raw
    };

    LIST_FOR_EACH(world->entities, iter)
        process_entity(&data, iter.v);
    return (false);
}
