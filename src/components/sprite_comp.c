/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Sprite component definition
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/components.h"

sprite_comp_t *sprite_component(gt_handle_t texture, rpg_rect_t sub,
    f64_t opacity)
{
    sprite_comp_t *self = my_malloc(sizeof(sprite_comp_t));

    self->texture = gt_handle_clone(texture);
    self->sub = sub;
    self->opacity = opacity;
    self->tint = 0xFFFFFFFF;
    return (self);
}

static void sprite_component_destroy(sprite_comp_t *self)
{
    if (self->texture)
        gt_handle_drop(self->texture);
    my_free(self);
}

const gt_component_class_t SPRITE_COMP = {
    .name = "sprite_component",
    .destroyer = (void (*)(void*)) &sprite_component_destroy,
};
