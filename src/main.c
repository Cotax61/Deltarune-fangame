/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Program entry point
*/

#include "my/my.h"
#include "my/io.h"
#include "gote/gote.h"
#include "rpg/ui.h"
#include "rpg/states.h"
#include "rpg/systems.h"
#include "rpg/components.h"

static const struct {
    const gt_component_class_t *class;
    gt_storage_t *(*storage)(void (*)(void*));
} COMPONENTS[] = {
    {&RECT_COMP, &gt_vec_storage},
    {&TEXT_COMP, &gt_vec_storage},
    {&HEALTH_COMP, &gt_vec_storage},
    {&XFORM_COMP, &gt_vec_storage},
    {&SPRITE_COMP, &gt_vec_storage},
    {&TILE_COMP, &gt_vec_storage},
    {&CANVAS_COMP, &gt_vec_storage},
    {&INPUT_COMP, &gt_vec_storage},
    {&ANIMATION_COMP, &gt_vec_storage},
};

static gt_app_t *create_app(void)
{
    return (gt_app_create(rpg_root_state(),
        12,
        rpg_animation_system(),
        rpg_time_system(),
        rpg_ui_system(),
        rpg_xform_system(),
        rpg_tile_system(),
        rpg_text_rendering_system(),
        rpg_sprite_rendering_system(),
        rpg_rect_rendering_system(),
        rpg_clear_system(0x000000FF),
        rpg_render_system(),
        rpg_window_system("My Defender", 1280, 720),
        rpg_input_handler_system()));
}

int main(void)
{
    gt_app_t *app = create_app();

    for (usize_t i = 0; i < sizeof(COMPONENTS) / sizeof(COMPONENTS[0]); i++)
        gt_world_register_component(app->world, COMPONENTS[i].class,
            COMPONENTS[i].storage);
    gt_app_run(app);
    gt_app_destroy(app);
    return (0);
}
