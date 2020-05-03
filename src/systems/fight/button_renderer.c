/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_renderer
*/
#include "gote/gote.h"
#include "my/io.h"
#include "rpg/types.h"
#include "rpg/formats/texture.h"
#include "rpg/components.h"
#include "rpg/systems.h"
#include "./priv.h"

static void process_component(rpg_fight_channel_t *chan,
    fight_action_comp_t *comp, gt_world_t *world, void *raw)
{
    rpg_fight_channel_t *self = raw;
    sfRenderWindow *win = gt_world_get(world, "window");
 
    change_act_color(comp->list[comp->index],
    comp->list[comp->index]->selected_color);
    for (int i = 0; comp->list[i]; i++) {
        sfRenderWindow_drawRectangleShape(win, comp->list[i]->rect, NULL);
        sfRenderWindow_drawText(win, comp->list[i]->display_text, NULL);        
    }
}


static bool sys_run(void *ptr, gt_world_t *world)
{
    gt_storage_t *comp_string = gt_world_get(world, FIGHT_ACTION_COMP.name);
    fight_action_comp_t *comp = NULL;
    gt_entity_t *ent = NULL;
    rpg_fight_channel_t *chan = ptr;

    (void) ptr;
    LIST_FOR_EACH(world->entities, iter) {
        ent = iter.v;
        comp = gt_storage_get(comp_string, ent->id);
        if (comp == NULL)
            continue;
        process_component(chan, comp, world, ptr);
    }
    return (false);
}

gt_system_t *rpg_act_button_renderer(void)
{
    gt_system_t *sys = my_malloc(sizeof(gt_system_t));

    sys->run = &sys_run;
    return (sys);
}