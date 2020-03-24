/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tilemap
*/

#ifndef RPG_TILEMAP_ENTITY_H
#define RPG_TILEMAP_ENTITY_H

#include "my/collections/list.h"
#include "gote/gote.h"

typedef struct {
    list_t *entities;
    gt_entity_t *root;
    gt_handle_t enemy_path;
    gt_handle_t tileset;
} rpg_tilemap_t;

typedef struct {
    usize_t width;
    usize_t height;
    usize_t tile_width;
    usize_t tile_height;
    i64_t *tiles;
    gt_handle_t tileset;
    gt_handle_t enemy_path;
} rpg_tilemap_def_t;

rpg_tilemap_t *rpg_tilemap_load(gt_world_t *world, const char *path);
rpg_tilemap_t *rpg_tilemap_create(gt_world_t *world, const rpg_tilemap_def_t *def);
void rpg_tilemap_remove(rpg_tilemap_t *self, gt_world_t *world);

#endif /* !RPG_TILEMAP_ENTITY_H */
