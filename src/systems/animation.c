/*
** EPITECH PROJECT, 2020
** libgote_demo
** File description:
** Window system implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/systems.h"
#include "rpg/components.h"

static void next_frame(animation_comp_t *comp, tile_comp_t *tile_comp)
{
    if (comp->t > comp->frame_time) {
        if (++comp->current_frame_index >= comp->frames_count)
            comp->current_frame_index = 0;
        tile_comp->tile_id = comp->current_frame_index;
    }
}

static bool sys_run(void *ptr, gt_world_t *world)
{
    gt_storage_t *anim_strg = gt_world_get(world, ANIMATION_COMP.name);
    gt_storage_t *tile_strg = gt_world_get(world, TILE_COMP.name);
    f64_t *dt_ms = gt_world_get(world, "dt_ms");
    gt_entity_t *ent = NULL;
    animation_comp_t *comp = NULL;
    tile_comp_t *tile_comp = NULL;

    (void)(ptr);
    LIST_FOR_EACH(world->entities, iter) {
        ent = iter.v;
        comp = gt_storage_get(anim_strg, ent->id);
        tile_comp = gt_storage_get(tile_strg, ent->id);
        if (comp == NULL || tile_comp == NULL)
            continue;
        comp->t += *dt_ms / 1000.0F;
        next_frame(comp, tile_comp);
    }
    return (false);
}

gt_system_t *rpg_animation_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->run = &sys_run;
    return (sys);
}
