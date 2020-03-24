/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Transform system implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/systems.h"
#include "rpg/components.h"

static const f64_t CHILD_DEPTH_EPSILON = 0.0001;

struct feach_data {
    gt_world_t *world;
    gt_storage_t *xform_strg;
};

/*
** Compute the "local_to_world" matrix for the given component. Recursively
** computes all the parent matrices if they haven't been calculated yet.
*/
static void compute_world_coords(xform_comp_t *xform)
{
    if (!xform->local_to_world_dirty)
        return;
    xform->local_to_world = xform->local;
    xform->world_depth = xform->depth;
    xform->local_to_world_dirty = false;
    if (!xform->parent)
        return;
    compute_world_coords(xform->parent);
    xform->world_depth += xform->parent->world_depth + CHILD_DEPTH_EPSILON;
    xform->local_to_world = xform->parent->local;
    sfTransform_combine(&xform->local_to_world, &xform->local);
}

/*
** Compute the "local_to_world" matrix for every entity
*/
static OPT(i32) process_entity_world(void *ptr, void *element_ptr)
{
    struct feach_data *data = ptr;
    gt_entity_t *ent = element_ptr;
    xform_comp_t *xform = gt_storage_get(data->xform_strg, ent->id);

    if (!xform)
        return (NONE(i32));
    compute_world_coords(xform);
    xform->world_to_local = sfTransform_getInverse(&xform->local_to_world);
    return (NONE(i32));
}

/*
** Compute the "local" matrix.
*/
static OPT(i32) process_entity_local(void *ptr, void *element_ptr)
{
    struct feach_data *data = ptr;
    gt_entity_t *ent = element_ptr;
    xform_comp_t *xform = gt_storage_get(data->xform_strg, ent->id);

    if (!xform)
        return (NONE(i32));
    xform->local_to_world_dirty = true;
    xform->local = sfTransform_Identity;
    sfTransform_translate(&xform->local, xform->trans.x, xform->trans.y);
    sfTransform_rotate(&xform->local, xform->rotation);
    sfTransform_scale(&xform->local, xform->scale.x, xform->scale.y);
    return (NONE(i32));
}

static bool sys_run(void *ptr, gt_world_t *world)
{
    struct feach_data data = {
        world,
        gt_world_get(world, XFORM_COMP.name)
    };

    (void)(ptr);
    list_for_each(world->entities, &process_entity_local, &data);
    list_for_each(world->entities, &process_entity_world, &data);
    return (false);
}

gt_system_t *rpg_xform_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->run = &sys_run;
    return (sys);
}
