/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Tile system implementation
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/formats/tileset.h"
#include "rpg/types.h"
#include "rpg/components.h"
#include "rpg/systems.h"

struct process_data {
    gt_storage_t *tile_strg;
    gt_storage_t *sprt_strg;
};

static void update_sprite(tile_comp_t *tile, sprite_comp_t *sprt,
    rpg_tileset_t *tset)
{
    u32_t tile_row = 0;
    u32_t tile_col = 0;

    if (tset->columns == 0 || tset->rows == 0)
        return;
    tile_row = tile->tile_id / tset->columns;
    tile_col = tile->tile_id % tset->columns;
    sprt->sub.x = (f64_t) tile_col / tset->columns;
    sprt->sub.y = (f64_t) tile_row / tset->rows;
    sprt->sub.width = 1.0 / tset->columns;
    sprt->sub.height = 1.0 / tset->rows;
}

static OPT(i32) process_entity(void *ptr, void *element_ptr)
{
    struct process_data *data = ptr;
    gt_entity_t *ent = element_ptr;
    tile_comp_t *tile = gt_storage_get(data->tile_strg, ent->id);
    sprite_comp_t *sprt = gt_storage_get(data->sprt_strg, ent->id);
    rpg_tileset_t *tset = NULL;

    if (tile == NULL || tile->priv.tileset == NULL)
        return (NONE(i32));
    tset = tile->priv.tileset->v->data;
    if (sprt == NULL) {
        sprt = sprite_component(tset->texture, RECT(0, 0, 1, 1), 1.0);
        gt_storage_set(data->sprt_strg, ent->id, sprt);
    }
    update_sprite(tile, sprt, tset);
    return (NONE(i32));
}

static bool sys_run(void *ptr, gt_world_t *world)
{
    struct process_data data = {
        .tile_strg = gt_world_get(world, TILE_COMP.name),
        .sprt_strg = gt_world_get(world, SPRITE_COMP.name),
    };

    (void)(ptr);
    return (list_for_each(world->entities, &process_entity, &data).v);
}

gt_system_t *rpg_tile_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->run = &sys_run;
    return (sys);
}
