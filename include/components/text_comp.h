/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Text component
*/

#ifndef RPG_TEXT_COMP_H
#define RPG_TEXT_COMP_H

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"

extern const gt_component_class_t TEXT_COMP;

typedef struct {
    u32_t color;
    u32_t size;
    rpg_vec2_t pos;
    rpg_halign_t halign;
    rpg_valign_t valign;
    struct {
        char *text;
        gt_handle_t font;
    } priv;
} text_comp_t;

text_comp_t *text_component(const char *text, gt_handle_t font, u32_t size,
    u32_t clr);
void text_comp_set_font(text_comp_t *self, gt_handle_t font);
void text_comp_set_text(text_comp_t *self, const char *text);

#endif /* RPG_TEXT_COMP_H */
