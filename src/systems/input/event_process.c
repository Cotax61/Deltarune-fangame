/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_process
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "my/collections/list.h"
#include "my/collections/hash_map.h"
#include "gote/gote.h"
#include "rpg/systems.h"
#include "rpg/components.h"

static rpg_input_handler_t *get_handler(sfEvent *e, input_comp_t *comp)
{
    switch (e->type) {
    case sfEvtKeyPressed:
        return (hash_map_get(comp->listeners, "keydown").v);
    case sfEvtKeyReleased:
        return (hash_map_get(comp->listeners, "keyup").v);
    case sfEvtMouseButtonPressed:
        return (hash_map_get(comp->listeners, "mousedown").v);
    case sfEvtMouseButtonReleased:
        return (hash_map_get(comp->listeners, "mouseup").v);
    case sfEvtMouseMoved:
        return (hash_map_get(comp->listeners, "mousemove").v);
    default:
        return (NULL);
    }
}

void rpg_input_process_event(gt_world_t *world, gt_storage_t *input_comps,
    sfEvent *e)
{
    input_comp_t *comp = NULL;
    rpg_input_handler_t *handler = NULL;

    LIST_FOR_EACH(world->entities, iter) {
        comp = gt_storage_get(input_comps, ((gt_entity_t*) iter.v)->id);
        if (!comp)
            continue;
        handler = get_handler(e, comp);
        if (handler == NULL)
            continue;
        handler->callback(world, e, handler->ptr);
    }
}
