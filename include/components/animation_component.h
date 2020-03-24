/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Animation component declaration
*/

#ifndef RPG_ANIMATION_COMP_H
#define RPG_ANIMATION_COMP_H

#include "my/my.h"
#include "gote/gote.h"

extern const gt_component_class_t ANIMATION_COMP;

typedef struct {
    f64_t frame_time;
    u16_t frames_count;
    const u32_t *frames;
    f64_t t;
    u16_t current_frame_index;
} animation_comp_t;

animation_comp_t *animation_component(f64_t frame_time, u16_t frames_count,
    const u32_t *frames);

#endif /* RPG_ANIMATION_COMP_H */