/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Health component implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components.h"

const gt_component_class_t HEALTH_COMP = {
    .name = "health_component",
    .destroyer = &my_free,
};

health_comp_t *health_component(f64_t base_health,
    void (*death_callback)(gt_world_t*, gt_entity_t*, void*),
    void *callback_data)
{
    health_comp_t *comp = my_malloc(sizeof(health_comp_t));

    comp->health = base_health;
    comp->death_callback = death_callback;
    comp->callback_data = callback_data;
    return (comp);
}
