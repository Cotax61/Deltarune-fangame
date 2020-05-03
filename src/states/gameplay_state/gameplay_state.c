/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** Dev state implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/fmt.h"
#include "gote/gote.h"
#include "rpg/states.h"
#include "rpg/systems.h"
#include "rpg/components.h"
#include "rpg/types.h"
#include "rpg/game_entities.h"
#include "rpg/formats.h"
#include "rpg/ui.h"
#include "rpg/event_handlers.h"
#include "priv.h"

static const char *FONT_PATH = "./res/fonts/dev_font.ttf";
static const char *TILEMAP_PATH = "./res/maps/desert/map.properties";

struct gameplay_state {
    gt_dispatcher_t *gameplay_systems_dispatcher;
    rpg_ui_widget_t *widget;
    gt_entity_t *text;
    gt_entity_t *pause_hdlr;
    gt_entity_t *canvas;
    rpg_tilemap_t *map;
};

static void on_start(struct gameplay_state *self, gt_world_t *data)
{
    gt_handle_t font = gt_load(FONT_PATH, &RPG_FONT_FORMAT, data);

    rpg_game_init_values(data);
    self->widget = rpg_gameplay_create_ui(data, font);
    self->canvas = rpg_ui_canvas_create(data, self->widget, 1000);
    self->map = rpg_tilemap_load(data, TILEMAP_PATH);
    gt_world_insert(data, "current_map", self->map, NULL);
}

static gt_state_trans_t update(struct gameplay_state *self,
    gt_world_t *data)
{
    (void) self;
    (void) data;
    return (gt_state_trans_none());
}

static bool remove_enemy(gt_world_t *world, gt_entity_t *ent,
    gt_storage_t *enemy_strg)
{
    if (gt_storage_get(enemy_strg, ent->id) != NULL) {
        gt_world_remove_entity(world, ent);
        return (true);
    }
    return (false);
}

static void on_stop(struct gameplay_state *self, gt_world_t *data)
{
    gt_dispatcher_dispose(self->gameplay_systems_dispatcher, data);
    gt_dispatcher_destroy(self->gameplay_systems_dispatcher);
    gt_world_remove(data, "is_paused");
    gt_world_remove_entity(data, self->text);
    gt_world_remove_entity(data, self->pause_hdlr);
    gt_world_remove_entity(data, self->canvas);
    rpg_tilemap_remove(self->map, data);
}

gt_state_t *rpg_gameplay_state(void)
{
    gt_state_t *state = my_calloc(1, sizeof(gt_state_t));

    if (state == NULL)
        return (NULL);
    state->self = my_calloc(1, sizeof(struct gameplay_state));
    state->destroy = &my_free;
    state->on_start = (void (*)(void*, gt_world_t*)) &on_start;
    state->update = (gt_state_trans_t (*)(void*, gt_world_t*)) &update;
    state->on_stop = (void (*)(void*, gt_world_t*)) &on_stop;
    return (state);
}