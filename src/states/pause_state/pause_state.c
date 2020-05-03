/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pause_state
*/

#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/formats.h"
#include "rpg/states.h"
#include "rpg/ui.h"
#include "rpg/components.h"
#include "priv.h"

static const char *FONT_PATH = "./res/fonts/dev_font.ttf";

struct pause_state {
    gt_entity_t *canvas;
};

static rpg_ui_widget_t *create_ui(gt_world_t *world)
{
    rpg_ui_widget_t *root = rpg_ui_widget_create();
    rpg_ui_widget_t *resume_btn = rpg_ui_button_create("");
    rpg_ui_widget_t *qtt_btn = rpg_ui_button_create("");
    rpg_ui_widget_t *quit_btn = rpg_ui_button_create("");

    root->background = 0x80;
    root->bounds = BOUNDS(0, 0, 0, 0);
    root->anchors = BOUNDS(0, 0, 1, 1);
    rpg_paused_set_qgame_button(quit_btn);
    rpg_paused_set_qtt_button(qtt_btn);
    rpg_paused_set_resume_button(resume_btn);
    rpg_ui_widget_static_on(resume_btn, "click", &rpg_paused_res_clicked, world);
    rpg_ui_widget_static_on(qtt_btn, "click", &rpg_paused_qtt_clicked, world);
    rpg_ui_widget_static_on(quit_btn, "click", &rpg_paused_qgame_clicked, world);
    rpg_ui_widget_add(root, qtt_btn);
    rpg_ui_widget_add(root, quit_btn);
    rpg_ui_widget_add(root, resume_btn);
    return (root);
}

static void on_start(void *ptr, gt_world_t *data)
{
    gt_handle_t font = gt_load(FONT_PATH, &RPG_FONT_FORMAT, data);
    rpg_ui_widget_t *ui_root = create_ui(data);
    struct pause_state *self = ptr;

    ui_root->font = font;
    self->canvas = rpg_ui_canvas_create(data, ui_root, 1000.0);
}

static void on_stop(void *ptr, gt_world_t *data)
{
    struct pause_state *self = ptr;

    (void)(data);
    gt_world_remove_entity(data, self->canvas);
}

gt_state_t *rpg_pause_state(void)
{
    gt_state_t *self = my_calloc(1, sizeof(gt_state_t));

    self->self = my_calloc(1, sizeof(struct pause_state));
    self->on_start = &on_start;
    self->on_stop = &on_stop;
    self->destroy = &my_free;
    return (self);
}
