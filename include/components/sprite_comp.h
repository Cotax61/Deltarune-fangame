/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Sprite component definition
*/

#ifndef RPG_SPRITE_COMP_H
#define RPG_SPRITE_COMP_H

#include "gote/gote.h"
#include "rpg/types.h"

extern const gt_component_class_t SPRITE_COMP;

typedef struct {
    gt_handle_t texture;
    rpg_rect_t sub;
    u32_t tint;
    f64_t opacity;
} sprite_comp_t;

sprite_comp_t *sprite_component(gt_handle_t texture, rpg_rect_t sub,
    f64_t opacity);

#endif /* RPG_SPRITE_COMP_H */
