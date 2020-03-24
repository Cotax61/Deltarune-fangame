/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Text component
*/

#ifndef RPG_RECT_COMP_H
#define RPG_RECT_COMP_H

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"

extern const gt_component_class_t RECT_COMP;
typedef struct {
    f64_t width;
    f64_t height;
    u32_t color;
} rect_comp_t;

rect_comp_t *rect_component(f64_t width, f64_t height, u32_t color);

#endif /* RPG_RECT_COMP_H */
