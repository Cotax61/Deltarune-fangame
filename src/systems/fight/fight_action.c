/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_action
*/

#include "gote/gote.h"
#include "my/io.h"
#include "rpg/types.h"
#include "rpg/formats/texture.h"
#include "rpg/render_queue.h"
#include "rpg/components.h"
#include "rpg/systems.h"
#include "./priv.h"

struct render_data {
    sfRenderWindow *win;
    sfRectangleShape *shape;
    sfText *text;
};

static bool sys_setup(void *self, gt_world_t *world)
{
    rpg_fight_channel_t *chan = self;
    gt_event_channel_t *sf_chan = gt_world_get(world, "sfml_channel");

    if (!sf_chan) {
        my_fprintf(2, "[Error] Couldn't bind input handler to sfml channel.\n");
        return (true);
    }
    chan->sf_chan_sub = gt_event_channel_sub(sf_chan);
    return (false);
}

static void process_component(rpg_fight_channel_t *chan,
    fight_action_comp_t *comp, gt_world_t *world, void *raw)
{
    rpg_fight_channel_t *self = raw;
 
    process_fight_evt(chan, comp, world);
}

static bool sys_run(void *ptr, gt_world_t *world)
{
    gt_storage_t *comp_string = gt_world_get(world, FIGHT_ACTION_COMP.name);
    fight_action_comp_t *comp = NULL;
    gt_entity_t *ent = NULL;
    rpg_fight_channel_t *chan = ptr;

    (void) ptr;
    LIST_FOR_EACH(world->entities, iter) {
        ent = iter.v;
        comp = gt_storage_get(comp_string, ent->id);
        if (comp == NULL)
            continue;
        process_component(chan, comp, world, ptr);
    }
    return (false);
}

gt_system_t *rpg_fight_action_system(void)
{
    rpg_fight_channel_t *channel = my_malloc(sizeof(rpg_fight_channel_t));
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->setup = &sys_setup;
    sys->self = channel;
    sys->run = &sys_run;
    return (sys);
}