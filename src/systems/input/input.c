/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** input_handler
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "gote/gote.h"
#include "rpg/systems.h"
#include "rpg/components.h"
#include "priv.h"

static bool sys_run(void *self_raw, gt_world_t *world)
{
    gt_storage_t *input_comps = gt_world_get(world, INPUT_COMP.name);
    sfRenderWindow *win = gt_world_get(world, "window");
    input_sys_t *self = self_raw;
    gt_event_channel_t *sf_chan = gt_world_get(world, "sfml_channel");
    sfEvent e;

    if (!win || !self)
        return (win == NULL);
    while (gt_event_channel_poll(sf_chan, self->sf_chan_sub, &e))
        rpg_input_process_event(world, input_comps, &e);
    return (false);
}

static bool sys_setup(void *self, gt_world_t *world)
{
    input_sys_t *this = self;
    gt_event_channel_t *sf_chan = gt_world_get(world, "sfml_channel");

    if (!sf_chan) {
        my_fprintf(2, "[Error] Couldn't bind input handler to sfml channel.\n");
        return (true);
    }
    this->sf_chan_sub = gt_event_channel_sub(sf_chan);
    return (false);
}

static bool sys_dispose(void *self, gt_world_t *world)
{
    input_sys_t *this = self;
    gt_event_channel_t *sf_chan = gt_world_get(world, "sfml_channel");

    if (sf_chan)
        gt_event_channel_unsub(sf_chan, this->sf_chan_sub);
    return (false);
}

gt_system_t *rpg_input_handler_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));
    input_sys_t *self = my_malloc(sizeof(input_sys_t));

    sys->self = self;
    sys->setup = &sys_setup;
    sys->destroy = &my_free;
    sys->dispose = &sys_dispose;
    sys->run = &sys_run;
    return (sys);
}
