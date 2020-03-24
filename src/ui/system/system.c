/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI system implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/ui.h"
#include "rpg/components.h"
#include "priv.h"

static bool sys_run(void *ptr, gt_world_t *world)
{
    rpg_ui_sys_t storages = {0};
    rpg_rect_t *win_rect = gt_world_get(world, "window_rect");
    rpg_bounds_t win_bounds = BOUNDS(0, 0, win_rect->width, win_rect->height);
    rpg_ui_canvas_t *cvs = NULL;
    gt_entity_t *ent = NULL;

    (void)(ptr);
    storages.cvs_strg = gt_world_get(world, CANVAS_COMP.name);
    storages.rect_strg = gt_world_get(world, RECT_COMP.name);
    storages.xform_strg = gt_world_get(world, XFORM_COMP.name);
    storages.text_strg = gt_world_get(world, TEXT_COMP.name);
    LIST_FOR_EACH(world->entities, iter) {
        ent = iter.v;
        cvs = gt_storage_get(storages.cvs_strg, ent->id);
        if (cvs == NULL)
            continue;
        storages.cvs_xform = gt_storage_get(storages.xform_strg, ent->id);
        rpg_ui_system_update_widget(cvs->root, world, &storages, &win_bounds);
    }
    return (false);
}

gt_system_t *rpg_ui_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->run = &sys_run;
    return (sys);
}
