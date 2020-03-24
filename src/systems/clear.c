/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Clear system
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/systems.h"

static bool sys_run(void *ptr, gt_world_t *world)
{
    sfRenderWindow *win = gt_world_get(world, "window");
    u32_t *clear_color = ptr;

    if (!win)
        return (false);
    sfRenderWindow_clear(win, sfColor_fromInteger(*clear_color));
    return (false);
}

gt_system_t *rpg_clear_system(u32_t clear_color)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->self = my_malloc(sizeof(u32_t));
    *((u32_t*) sys->self) = clear_color;
    sys->destroy = &my_free;
    sys->run = &sys_run;
    return (sys);
}
