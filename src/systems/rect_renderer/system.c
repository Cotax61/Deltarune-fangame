/*
** EPITECH PROJECT, 2020
** libgote_demo
** File description:
** Rectangle system implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components.h"
#include "rpg/systems.h"

static bool sys_setup(void *self_raw, gt_world_t *world)
{
    rpg_rect_sys_data_t *self = self_raw;

    (void)(world);
    self->shape = sfRectangleShape_create();
    return (self->shape == NULL);
}

static bool sys_dispose(void *self_raw, gt_world_t *world)
{
    rpg_rect_sys_data_t *self = self_raw;

    (void)(world);
    sfRectangleShape_destroy(self->shape);
    return (false);
}

gt_system_t *rpg_rect_rendering_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->self = my_calloc(1, sizeof(rpg_rect_sys_data_t));
    sys->destroy = &my_free;
    sys->setup = &sys_setup;
    sys->run = &rpg_rect_rendering_system_run;
    sys->dispose = &sys_dispose;
    return (sys);
}
