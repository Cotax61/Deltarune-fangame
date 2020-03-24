/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Health system
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components.h"
#include "rpg/systems.h"

struct process_data {
    gt_world_t *world;
    gt_storage_t *health_strg;
};

static bool sys_run(void *ptr, gt_world_t *world)
{
    gt_storage_t *health_strg = gt_world_get(world, HEALTH_COMP.name);
    health_comp_t *comp = NULL;
    gt_entity_t *ent = NULL;
    gt_entity_t *deads[128];
    usize_t dead_count = 0;

    (void)(ptr);
    LIST_FOR_EACH_AND(world->entities, iter, dead_count < 128) {
        ent = iter.v;
        comp = gt_storage_get(health_strg, ent->id);
        if (comp == NULL || comp->health > 0)
            continue;
        deads[dead_count++] = ent;
    }
    for (usize_t i = 0; i < dead_count; i++) {
        comp = gt_storage_get(health_strg, deads[i]->id);
        if (comp->death_callback)
            comp->death_callback(world, deads[i], comp->callback_data);
    }
    return (false);
}

gt_system_t *rpg_health_system(void)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));

    sys->run = &sys_run;
    return (sys);
}