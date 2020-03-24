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
#include "rpg/formats.h"
#include "rpg/components.h"
#include "rpg/types.h"

static const char *FONT_PATH = "./res/fonts/dev_font.ttf";

struct dev_state {
    gt_entity_t *rect1;
    gt_entity_t *rect2;
    gt_entity_t *text;
};

static void on_start(struct dev_state *self, gt_world_t *world)
{
    xform_comp_t *r1xfrm = xform_component(VEC3(80, 50, 1), 1, 0, NULL);
    gt_handle_t font = gt_load(FONT_PATH, &RPG_FONT_FORMAT, world);

    self->rect1 = gt_world_create_entity(world, 2,
        &RECT_COMP, rect_component(50, 50, 0x66AAFFFF),
        &XFORM_COMP, r1xfrm);
    self->rect2 = gt_world_create_entity(world, 2,
        &RECT_COMP, rect_component(50, 50, 0xFF66AAFF),
        &XFORM_COMP, xform_component(VEC3(25, 25, 2), 1, 0, r1xfrm));
    self->text = gt_world_create_entity(world, 2,
        &TEXT_COMP, text_component("Hello World!", font, 50, 0xFFFFFFFF),
        &XFORM_COMP, xform_component(VEC3(50, 50, 2), 1, 0, NULL));
    gt_handle_drop(font);
}

static void on_stop(struct dev_state *self, gt_world_t *world)
{
    gt_world_remove_entity(world, self->rect1);
    gt_world_remove_entity(world, self->rect2);
    gt_world_remove_entity(world, self->text);
}

gt_state_t *rpg_dev_state(void)
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
