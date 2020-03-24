/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tilemap
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/data/csv.h"
#include "rpg/data/properties.h"
#include "rpg/formats.h"
#include "rpg/components.h"
#include "rpg/game_entities.h"

static rpg_tilemap_def_t load_def(const rpg_props_t *props, gt_world_t *world)
{
    rpg_tilemap_def_t def;

    def.tile_width = rpg_props_get_nbr(props, "tile_width").v;
    def.tile_height = rpg_props_get_nbr(props, "tile_height").v;
    def.tileset = gt_load(rpg_props_get(props, "tileset"), &RPG_TILESET_FORMAT,
        world);
    def.enemy_path = gt_load(rpg_props_get(props, "enemy_path"),
        &RPG_PATH2D_FORMAT, world);
    return (def);
}

rpg_tilemap_t *rpg_tilemap_load(gt_world_t *world, const char *path)
{
    rpg_props_t *props = rpg_props_load(path);
    rpg_tilemap_def_t self_def = load_def(props, world);
    rpg_csv_t *tiles_csv = rpg_csv_load(rpg_props_get(props, "data"));
    rpg_tilemap_t *self = NULL;

    self_def.tiles = tiles_csv->data;
    self_def.width = tiles_csv->width;
    self_def.height = tiles_csv->height;
    if (!self_def.tiles || !self_def.tileset) {
        my_fprintf(2, "[Error] Couldn't load tilemap file.\n");
        return (NULL);
    }
    self = rpg_tilemap_create(world, &self_def);
    gt_handle_drop(self_def.tileset);
    gt_handle_drop(self_def.enemy_path);
    rpg_csv_destroy(tiles_csv);
    rpg_props_destroy(props);
    return (self);
}
