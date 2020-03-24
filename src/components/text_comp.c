/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Rectangle component implementation
*/

#include "my/my.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/components.h"

static void destroyer(text_comp_t *self)
{
    if (self->priv.font)
        gt_handle_drop(self->priv.font);
    my_free(self->priv.text);
    my_free(self);
}

text_comp_t *text_component(const char *text, gt_handle_t font, u32_t size,
    u32_t clr)
{
    text_comp_t *self = my_calloc(1, sizeof(text_comp_t));

    self->size = size;
    self->color = clr;
    text_comp_set_font(self, font);
    text_comp_set_text(self, text);
    return (self);
}

void text_comp_set_font(text_comp_t *self, gt_handle_t font)
{
    if (self->priv.font)
        gt_handle_drop(self->priv.font);
    self->priv.font = font ? gt_handle_clone(font) : NULL;
}

void text_comp_set_text(text_comp_t *self, const char *text)
{
    if (!text || (self->priv.text && my_cstrcmp(text, self->priv.text) == 0))
        return;
    my_free(self->priv.text);
    self->priv.text = text ? my_cstrdup(text) : NULL;
}

const gt_component_class_t TEXT_COMP = {
    .name = "text_component",
    .destroyer = (void (*)(void*)) &destroyer,
};
