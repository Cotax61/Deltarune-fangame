/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fill_bar
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/fmt.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/formats/texture.h"
#include "rpg/render_queue.h"
#include "rpg/components.h"
#include "rpg/systems.h"

static void fill_rect(fill_bar_comp_t *bar)
{
    if (*bar->ref <= 0 || *bar->max_ref <= 0) {
        bar->fill_rect.left = bar->fill_rect.width;
        bar->fill_rect.top = bar->fill_rect.height;
        return;
    }
    if (bar->fill_type == FILL_D_TO_UP) {
        bar->fill_rect.left = 0;
        bar->fill_rect.top = (((*bar->ref / *bar->max_ref) * bar->fill_rect.height) -
        bar->fill_rect.height) * - 1;
    } else if (bar->fill_type == FILL_L_TO_R) {
        bar->fill_rect.left = (((*bar->ref / *bar->max_ref) * bar->fill_rect.width) -
        bar->fill_rect.width) * -1;
        bar->fill_rect.top = 0;
    }
}

static void prosses_components(fill_bar_comp_t *bar, gt_world_t *world)
{
    sfRenderWindow *win = gt_world_get(world, "window");

    if (*bar->ref < *bar->max_ref)
        *bar->ref += 1;
    fill_rect(bar);
    my_free(bar->old_text);
    if (bar->fill_type == FILL_L_TO_R)
       bar->old_text = my_format("%i / %i", (int)*bar->ref, (int)*bar->max_ref);
    else 
       bar->old_text = my_format("%i TP", (int)*bar->ref);
    sfText_setString(bar->text, bar->old_text);
    sfSprite_setTextureRect(bar->full, bar->fill_rect);
    sfRenderWindow_drawSprite(win, bar->empty, NULL);
    sfRenderWindow_drawSprite(win, bar->full, NULL);
    sfRenderWindow_drawText(win, bar->text, NULL);
}

static bool sys_run(void *ptr, gt_world_t *world)
{
    gt_storage_t *fill_bar_string = gt_world_get(world, FILL_BAR_COMP.name);
    fill_bar_comp_t *comp = NULL;
    gt_entity_t *ent = NULL;

    (void) ptr;
    LIST_FOR_EACH(world->entities, iter) {
        ent = iter.v;
        comp = gt_storage_get(fill_bar_string, ent->id);
        if (comp == NULL)
            continue;
        prosses_components(comp, world);
    }
    return (false);
}

gt_system_t *rpg_fill_bar_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->run = &sys_run;
    return (sys);
}