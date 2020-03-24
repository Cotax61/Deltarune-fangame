/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Rectangle component implementation
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/components.h"

const gt_component_class_t RECT_COMP = {
    .name = "rectangle_component",
    .destroyer = &my_free,
};

rect_comp_t *rect_component(f64_t width, f64_t height, u32_t color)
{
    rect_comp_t *comp = my_calloc(1, sizeof(rect_comp_t));

    comp->width = width;
    comp->height = height;
    comp->color = color;
    return (comp);
}
