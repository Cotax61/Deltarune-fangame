/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Health component declaration
*/

#ifndef RPG_HEALTH_COMP_H
#define RPG_HEALTH_COMP_H

#include "my/my.h"
#include "gote/gote.h"

extern const gt_component_class_t HEALTH_COMP;

typedef struct {
    f64_t health;
    void (*death_callback)(gt_world_t*, gt_entity_t*, void*);
    void *callback_data;
} health_comp_t;

health_comp_t *health_component(f64_t base_health,
    void (*death_callback)(gt_world_t*, gt_entity_t*, void*),
    void *callback_data);

#endif /* RPG_HEALTH_COMP_H */
