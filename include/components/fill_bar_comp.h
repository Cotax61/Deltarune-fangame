/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fill_bar_comp
*/

#ifndef FILL_BAR_COMP_H_
#define FILL_BAR_COMP_H_

#include "SFML/Graphics/Sprite.h"
#include "my/my.h"
#include "gote/gote.h"

extern const gt_component_class_t FILL_BAR_COMP;

enum {
    FILL_D_TO_UP = 0,
    FILL_UP_TO_D = 1,
    FILL_L_TO_R = 2,
    FILL_R_TO_L = 3,
};

typedef struct {
    rpg_vec2_t pos;
    rpg_vec2_t text_pos;
    sfFont *font;
    char *empty;
    char *full;
    int fill_type;
    float *ref;
    float *max_ref;
} fill_args_t;

typedef struct {
    sfTexture *empty_text;
    sfTexture *full_text;
    sfSprite *empty;
    sfSprite *full;
    char *old_text;
    int fill_type;
    float *ref;
    float *max_ref;
    sfText *text;
    sfIntRect fill_rect;
} fill_bar_comp_t;

fill_bar_comp_t *fill_bar_component(fill_args_t args);
gt_entity_t *create_hp_bar(gt_world_t *world, float *ref, float *max_ref,
    sfFont *font);
gt_entity_t *create_tp_bar(gt_world_t *world, float *ref, float *max_ref,
    sfFont *font);

#endif /* !FILL_BAR_COMP_H_ */