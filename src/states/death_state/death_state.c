/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** Death state implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/states.h"
#include "rpg/components.h"
#include "rpg/types.h"
#include "rpg/game_entities.h"
#include "rpg/formats.h"
#include "rpg/entities/tilemap.h"
#include "rpg/ui.h"
#include "rpg/event_handlers.h"
#include "priv.h"

static const char *FONT_PATH = "./res/fonts/dev_font.ttf";

struct gameplay_state {
    gt_entity_t *ui;
};

static void on_start(struct gameplay_state *self, gt_world_t *world)
{
    gt_handle_t font = gt_load(FONT_PATH, &RPG_FONT_FORMAT, world);

    self->ui = rpg_ui_canvas_create(world, rpg_death_create_ui(world,
        font), 1000);
}

static void on_stop(struct gameplay_state *self, gt_world_t *world)
{
    gt_world_remove_entity(world, self->ui);
}

gt_state_t *rpg_death_state(void)
{
    gt_state_t *state = my_calloc(1, sizeof(gt_state_t));

    if (state == NULL)
        return (NULL);
    state->self = my_calloc(1, sizeof(struct gameplay_state));
    state->destroy = &my_free;
    state->on_start = (void (*)(void*, gt_world_t*)) &on_start;
    state->on_stop = (void (*)(void*, gt_world_t*)) &on_stop;
    return (state);
}
