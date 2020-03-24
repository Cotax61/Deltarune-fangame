/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Tile component definition
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components/tile_comp.h"

tile_comp_t *tile_component(gt_handle_t tileset, u32_t tile_id)
{
    tile_comp_t *self = my_calloc(1, sizeof(tile_comp_t));

    self->tile_id = tile_id;
    tile_comp_set_tileset(self, tileset);
    return (self);
}

void tile_comp_set_tileset(tile_comp_t *self, gt_handle_t tset)
{
    if (self->priv.tileset)
        gt_handle_drop(self->priv.tileset);
    self->priv.tileset = tset ? gt_handle_clone(tset) : NULL;
}

static void tile_component_destroy(tile_comp_t *self)
{
    if (self->priv.tileset)
        gt_handle_drop(self->priv.tileset);
    my_free(self);
}

const gt_component_class_t TILE_COMP = {
    .name = "tile_component",
    .destroyer = (void (*)(void*)) &tile_component_destroy,
};
