/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** Splashscreen state implementation
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/components.h"
#include "rpg/formats.h"
#include "rpg/states.h"
#include "priv.h"

static const char *SPLASH_PATH = "./res/img/splash_screen.png";
static const char *SPINNER_PATH = "./res/spinnertileset.properties";

struct sscreen_state {
    gt_entity_t *back_image;
    gt_entity_t *spinner;
    sprite_comp_t *sprite;
    sfClock *timer;
};

const u32_t FRAMES[31] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30
};

static void on_start(void *self, gt_world_t *data)
{
    struct sscreen_state *this = self;
    gt_handle_t img = gt_load(SPLASH_PATH, &RPG_TEXTURE_FORMAT, data);
    gt_handle_t tsheet = gt_load(SPINNER_PATH, &RPG_TILESET_FORMAT, data);

    this->sprite = sprite_component(img, RECT(0, 0, 1, 1), 1.0);
    this->timer = sfClock_create();
    sfClock_restart(this->timer);
    this->back_image = gt_world_create_entity(data, 3,
        &SPRITE_COMP, this->sprite,
        &XFORM_COMP, xform_component(VEC3(1280 / 2, 720 / 2, 0), 1, 0, NULL),
        &INPUT_COMP, input_component(1,
            "keydown", &rpg_sscreen_btn_pressed, NULL, NULL));
    this->spinner = gt_world_create_entity(data, 3,
        &XFORM_COMP, xform_component(VEC3(50, 50, 100000), 1, 0, NULL),
        &TILE_COMP, tile_component(tsheet, 1),
        &ANIMATION_COMP, animation_component(0.2F, 31, FRAMES)
    );
    gt_handle_drop(img);
    gt_handle_drop(tsheet);
}

static void on_stop(void *self, gt_world_t *data)
{
    struct sscreen_state *this = self;

    sfClock_destroy(this->timer);
    gt_world_remove_entity(data, this->back_image);
    gt_world_remove_entity(data, this->spinner);
    my_free(this);
}

static gt_state_trans_t update(void *self, gt_world_t *data)
{
    struct sscreen_state *this = self;
    f64_t t = sfClock_getElapsedTime(this->timer).microseconds / 1000000.0;

    (void)(data);
    this->sprite->opacity = sqrt(1.0 - pow(t / 3.0, 2));
    if (t > 3.0)
        return (gt_state_trans_switch(rpg_title_state()));
    return (gt_state_trans_none());
}

gt_state_t *rpg_sscreen_state(void)
{
    gt_state_t *state = my_calloc(1, sizeof(gt_state_t));

    if (state == NULL)
        return (state);
    state->self = my_calloc(1, sizeof(struct sscreen_state));
    state->on_stop = &on_stop;
    state->on_start = &on_start;
    state->update = &update;
    return (state);
}
