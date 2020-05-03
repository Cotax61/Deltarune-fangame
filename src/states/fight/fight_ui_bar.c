/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_ui_bar
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg/components.h"
#include "rpg/ui.h"

gt_entity_t *create_hp_bar(gt_world_t *world, float *ref, float *max_ref,
sfFont *font)
{
    gt_entity_t *entity = gt_world_create_entity(world, 1,
    &FILL_BAR_COMP, fill_bar_component((fill_args_t) {
        VEC2(100, 10),
        VEC2(170, 30),
        font,
        "./res/img/health_bar_empty.png",
        "./res/img/health_bar_full.png",
        FILL_L_TO_R,
        ref,
        max_ref
    }));

    return (entity);
}

gt_entity_t *create_tp_bar(gt_world_t *world, float *ref, float *max_ref,
sfFont *font)
{
    gt_entity_t *entity = gt_world_create_entity(world, 1,
        &FILL_BAR_COMP, fill_bar_component((fill_args_t){
        VEC2(10, 100),
        VEC2(75, 215),
        font,
        "./res/img/tp_bar_empty.png",
        "./res/img/tp_bar_full.png",
        FILL_D_TO_UP,
        ref,
        max_ref
    }));
    
    return (entity);
}