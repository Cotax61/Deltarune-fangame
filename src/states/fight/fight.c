/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#include "gote/gote.h"
#include "rpg/ui.h"
#include "rpg/formats.h"
#include "rpg/components.h"
#include "rpg/fight.h"

static const char *FONT_PATH = "./res/fonts/stat.ttf";
static const char *ABIENT_PATH = "./res/audio/battle_ambient.wav";

struct fight_state {
    gt_dispatcher_t *dispatcher;
    gt_entity_t *player_hp_bar;
    gt_entity_t *player_tp_bar;
    gt_entity_t *player;
    sfFont *font;
    float hp;
    float tp;
    float max_hp;
    float max_tp;
    sfMusic *ambient;
};

static void on_start(void *ptr, gt_world_t *world)
{
    struct fight_state *self = ptr;
    
    self->font = sfFont_createFromFile(FONT_PATH);
    self->hp = 0.0f;
    self->max_hp = 110.0f;
    self->tp = 10.0f;
    self->max_tp = 100.0f;
    create_hp_bar(world, &self->hp, &self->max_hp, self->font);
    create_tp_bar(world, &self->tp, &self->max_tp, self->font);
    gt_world_create_entity(world, 1,
    &FIGHT_ACTION_COMP, fight_action_component(rpg_fight_create_ui()));
    self->ambient = sfMusic_createFromFile(ABIENT_PATH);
    sfMusic_setLoop(self->ambient, true);
    sfMusic_play(self->ambient);
    self->player = init_fight_player(world);
}

static gt_state_trans_t update(void *self, gt_world_t *data)
{
    struct fight_state *this = self;    

    (void) this;
    (void) data;
    return (gt_state_trans_none());
}

static void on_stop(void *ptr, gt_world_t *world)
{
    struct fight_state *self = ptr;

    (void) self;
    (void) world;
}

gt_state_t *rpg_fight_state(void)
{
    gt_state_t *state = my_calloc(1, sizeof(gt_state_t));

    if (state == NULL)
        return (NULL);
    state->self = my_calloc(1, sizeof(struct fight_state));
    state->destroy = &my_free;
    state->update = &update;
    state->on_start = (void (*)(void*, gt_world_t*)) &on_start;
    state->on_stop = (void (*)(void*, gt_world_t*)) &on_stop;
    return (state);
}