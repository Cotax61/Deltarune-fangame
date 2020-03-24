/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Time system implementation
*/

#include <SFML/System.h>
#include "my/my.h"
#include "gote/gote.h"

static bool sys_run(void *ptr, gt_world_t *world)
{
    f64_t *time_ms = gt_world_get(world, "time_ms");
    f64_t *dt_ms = gt_world_get(world, "dt_ms");
    sfClock *clk = ptr;
    float now_ms = sfClock_getElapsedTime(clk).microseconds / 1000.0;

    if (time_ms == NULL || dt_ms == NULL)
        return (true);
    *dt_ms = now_ms - *time_ms;
    *time_ms = now_ms;
    return (false);
}

gt_system_t *rpg_time_system(void)
{
    gt_system_t *self = my_calloc(1, sizeof(gt_system_t));

    self->self = sfClock_create();
    self->destroy = (void (*)(void*)) &sfClock_destroy;
    self->run = &sys_run;
    return (self);
}
