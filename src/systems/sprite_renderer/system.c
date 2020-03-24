/*
** EPITECH PROJECT, 2020
** libgote_demo
** File description:
** Sprite system implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components.h"
#include "rpg/systems.h"

static bool sys_setup(void *self_raw, gt_world_t *world)
{
    rpg_sprite_sys_data_t *self = self_raw;

    (void)(world);
    self->sprite = sfSprite_create();
    return (self->sprite == NULL);
}

static bool sys_dispose(void *self_raw, gt_world_t *world)
{
    rpg_sprite_sys_data_t *self = self_raw;

    (void)(world);
    sfSprite_destroy(self->sprite);
    return (false);
}

gt_system_t *rpg_sprite_rendering_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->self = my_calloc(1, sizeof(rpg_sprite_sys_data_t));
    sys->destroy = &my_free;
    sys->setup = &sys_setup;
    sys->run = &rpg_sprite_rendering_system_run;
    sys->dispose = &sys_dispose;
    return (sys);
}
