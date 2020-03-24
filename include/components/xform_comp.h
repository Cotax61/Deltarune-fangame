/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Transform component
*/

#ifndef RPG_XFORM_COMP_H
#define RPG_XFORM_COMP_H

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"

extern const gt_component_class_t XFORM_COMP;

typedef struct xform_comp xform_comp_t;

struct xform_comp {
    rpg_vec2_t trans;
    rpg_vec2_t scale;
    f64_t rotation;
    f64_t depth;
    xform_comp_t *parent;
    sfTransform local;
    f64_t world_depth;
    sfTransform local_to_world;
    sfTransform world_to_local;
    bool local_to_world_dirty;
};

xform_comp_t *xform_component(rpg_vec3_t trans, f64_t scale, f64_t rot,
    xform_comp_t *parent);

#endif /* RPG_XFORM_COMP_H */
