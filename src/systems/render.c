/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** RenderQueue manager
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/render_queue.h"
#include "rpg/systems.h"

static bool sys_setup(void *ptr, gt_world_t *world)
{
    render_queue_t *queue = render_queue_create();

    (void)(ptr);
    if (queue == NULL)
        return (true);
    return (gt_world_insert(world, "render_queue", queue,
        (void (*)(void*)) &render_queue_destroy));
}

static bool sys_dispose(void *ptr, gt_world_t *world)
{
    (void)(ptr);
    gt_world_remove(world, "render_queue");
    return (false);
}

static bool sys_run(void *ptr, gt_world_t *world)
{
    render_queue_t *queue = gt_world_get(world, "render_queue");

    (void)(ptr);
    if(queue == NULL)
        return (true);
    render_queue_flush(queue, false);
    return (false);
}

gt_system_t *rpg_render_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->setup = &sys_setup;
    sys->dispose = &sys_dispose;
    sys->run = &sys_run;
    return (sys);
}
