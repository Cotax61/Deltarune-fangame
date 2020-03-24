/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** Root state implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/states.h"

struct root_state {
    u64_t sf_chan_sub;
};

static void on_start(void *self, gt_world_t *data)
{
    struct root_state *this = self;
    gt_event_channel_t *sf_chan = gt_world_get(data, "sfml_channel");

    if (!sf_chan)
        return;
    this->sf_chan_sub = gt_event_channel_sub(sf_chan);
}

static void shadow_update(void *self, gt_world_t *data)
{
    struct root_state *this = self;
    gt_event_channel_t *sf_chan = gt_world_get(data, "sfml_channel");
    gt_event_channel_t *trans_chan = gt_world_get(data, "trans_channel");
    gt_state_trans_t trans;
    sfEvent e;

    if (!sf_chan || !trans_chan || !this->sf_chan_sub)
        return;
    while (gt_event_channel_poll(sf_chan, this->sf_chan_sub, &e))
        switch (e.type) {
        case sfEvtClosed:
            trans = gt_state_trans_quit();
            gt_event_channel_push(trans_chan, &trans);
            break;
        default:
            break;
        }
}

static gt_state_trans_t update(void *self, gt_world_t *data)
{
    (void)(self);
    (void)(data);
    return (gt_state_trans_push(rpg_sscreen_state()));
}

static void on_stop(void *self, gt_world_t *data)
{
    struct root_state *this = self;
    gt_event_channel_t *sf_chan = gt_world_get(data, "sfml_channel");

    if (!sf_chan || !this->sf_chan_sub)
        return;
    gt_event_channel_unsub(sf_chan, this->sf_chan_sub);
    this->sf_chan_sub = 0;
}

gt_state_t *rpg_root_state(void)
{
    gt_state_t *state = my_calloc(1, sizeof(gt_state_t));

    if (state == NULL)
        return (state);
    state->self = my_calloc(1, sizeof(struct root_state));
    state->destroy = &my_free;
    state->on_start = &on_start;
    state->on_stop = &on_stop;
    state->shadow_update = &shadow_update;
    state->update = &update;
    return (state);
}
