/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** Dev state implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/states.h"
#include "rpg/components.h"
#include "rpg/types.h"
#include "rpg/formats.h"
#include "rpg/game_entities.h"

static const char *TILESET_PATH = "./res/maps/tileset.properties";
static const char *TILEMAP_PATH = "./res/maps/desert/tilemap.properties";

struct dev_state {
    gt_entity_t *sprite1;
    gt_entity_t *sprite2;
    rpg_tilemap_t *map;
};

static void on_sprite2_die(gt_world_t *world, gt_entity_t *sprite2, void *ptr)
{
    struct dev_state *self = ptr;

    gt_world_remove_entity(world, sprite2);
    self->sprite2 = NULL;
}

static void on_start(struct dev_state *self, gt_world_t *world)
{
    gt_handle_t tset = gt_load(TILESET_PATH, &RPG_TILESET_FORMAT, world);

    self->sprite1 = gt_world_create_entity(
        world, 3,
        &XFORM_COMP, xform_component(VEC3(100, 100, 0), 1, 45, NULL),
        &RECT_COMP, rect_component(200, 50, 0x00FF00FF),
        &TILE_COMP, tile_component(tset, 271)
    );
    self->sprite2 = gt_world_create_entity(
        world, 3,
        &XFORM_COMP, xform_component(VEC3(400, 100, 0), 1, 90, NULL),
        &HEALTH_COMP, health_component(0.0, &on_sprite2_die, self),
        &TILE_COMP, tile_component(tset, 205)
    );
    self->map = rpg_tilemap_load(world, TILEMAP_PATH);
    gt_handle_drop(tset);
}

static void on_stop(struct dev_state *self, gt_world_t *world)
{
    rpg_tilemap_remove(self->map, world);
    gt_world_remove_entity(world, self->sprite1);
    if (self->sprite2)
        gt_world_remove_entity(world, self->sprite2);
}

gt_state_t *rpg_sprite_dev_state(void)
{
    gt_state_t *state = my_calloc(1, sizeof(gt_state_t));

    if (state == NULL)
        return (state);
    state->self = my_calloc(1, sizeof(struct dev_state));
    state->destroy = &my_free;
    state->on_start = (void (*)(void*, gt_world_t*)) &on_start;
    state->on_stop = (void (*)(void*, gt_world_t*)) &on_stop;
    return (state);
}
