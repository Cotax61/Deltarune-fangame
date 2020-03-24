/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tilemap
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/components.h"
#include "rpg/game_entities.h"

static gt_entity_t *create_entity_at(gt_world_t *world, rpg_vec2_t pos,
    xform_comp_t *root, tile_comp_t *tile)
{
    return (gt_world_create_entity(world, 2,
        &XFORM_COMP, xform_component(VEC3(pos.x, pos.y, -100), 1, 0, root),
        &TILE_COMP, tile
    ));
}

rpg_tilemap_t *rpg_tilemap_create(gt_world_t *world, const rpg_tilemap_def_t *def)
{
    rpg_tilemap_t *self = my_calloc(1, sizeof(rpg_tilemap_t));
    xform_comp_t *root = xform_component(VEC3(0, 0, 0), 1, 0, NULL);

    self->root = gt_world_create_entity(world, 1, &XFORM_COMP, root);
    self->entities = list_new();
    self->enemy_path = gt_handle_clone(def->enemy_path);
    self->tileset = gt_handle_clone(def->tileset);
    for (u64_t x = 0; x < def->width; x++) {
        for (u64_t y = 0; y < def->height; y++) {
            list_push_back(self->entities, create_entity_at(world,
                VEC2(
                    x * def->tile_width + def->tile_width / 2,
                    y * def->tile_height + def->tile_height / 2
                ),
                root,
                tile_component(def->tileset, def->tiles[x + y * def->width])
            ));
        }
    }
    return (self);
}

void rpg_tilemap_remove(rpg_tilemap_t *self, gt_world_t *world)
{
    gt_handle_drop(self->enemy_path);
    gt_handle_drop(self->tileset);
    gt_world_remove_entity(world, self->root);
    LIST_FOR_EACH(self->entities, iter)
        gt_world_remove_entity(world, iter.v);
    list_destroy(self->entities);
    my_free(self);
}
