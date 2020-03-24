/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Transform component implementation
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/components.h"

const gt_component_class_t XFORM_COMP = {
    .name = "transform_component",
    .destroyer = &my_free,
};

xform_comp_t *xform_component(rpg_vec3_t trans, f64_t scale, f64_t rot,
    xform_comp_t *parent)
{
    xform_comp_t *comp = my_calloc(1, sizeof(xform_comp_t));

    comp->trans = VEC2(trans.x, trans.y);
    comp->depth = trans.z;
    comp->scale = VEC2(scale, scale);
    comp->rotation = rot;
    comp->parent = parent;
    return (comp);
}
