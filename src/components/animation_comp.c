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

const gt_component_class_t ANIMATION_COMP = {
    .name = "animation_component",
    .destroyer = &my_free,
};

animation_comp_t *animation_component(f64_t frame_time, u16_t frames_count,
    const u32_t *frames)
{
    animation_comp_t *comp = my_malloc(sizeof(animation_comp_t));

    comp->frame_time = frame_time;
    comp->frames = frames;
    comp->frames_count = frames_count;
    comp->current_frame_index = 0;
    comp->t = 0.0;
    return (comp);
}
