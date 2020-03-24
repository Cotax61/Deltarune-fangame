/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Tile component definition
*/

#ifndef RPG_TILE_COMP_H
#define RPG_TILE_COMP_H

#include "gote/gote.h"

extern const gt_component_class_t TILE_COMP;

typedef struct {
    u32_t tile_id;
    struct {
        gt_handle_t tileset;
    } priv;
} tile_comp_t;

tile_comp_t *tile_component(gt_handle_t tileset, u32_t tile_id);
void tile_comp_set_tileset(tile_comp_t *self, gt_handle_t tset);

#endif /* RPG_TILE_COMP_H */
