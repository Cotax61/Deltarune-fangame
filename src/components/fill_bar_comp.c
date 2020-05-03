/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fill_bar_comp
*/

#include <stdlib.h>
#include "my/my.h"
#include "rpg/components.h"

static sfText *init_fillbar_text(fill_bar_comp_t *bar, fill_args_t args)
{
    sfText *new = sfText_create();
    
    sfText_setFont(new, args.font);
    sfText_setColor(new, sfWhite);
    sfText_setCharacterSize(new, 20);
    sfText_setOutlineThickness(new, 3);
    sfText_setOutlineColor(new, sfBlack);
    sfText_setPosition(new, (sfVector2f){args.text_pos.x, args.text_pos.y});
    bar->old_text = NULL;
    return (new);
}

fill_bar_comp_t *fill_bar_component(fill_args_t args)
{
    fill_bar_comp_t *new = malloc(sizeof(fill_bar_comp_t));
    sfFloatRect rect;
    
    new->empty_text = sfTexture_createFromFile(args.empty, NULL);
    new->full_text = sfTexture_createFromFile(args.full, NULL);
    new->fill_type = args.fill_type;
    new->full = sfSprite_create();
    new->empty = sfSprite_create();
    new->ref = args.ref;
    new->max_ref = args.max_ref;
    new->text = init_fillbar_text(new, args);
    sfSprite_setTexture(new->full, new->full_text, sfFalse);
    sfSprite_setTexture(new->empty, new->empty_text, sfFalse);
    sfSprite_setPosition(new->full, (sfVector2f){args.pos.x, args.pos.y});
    sfSprite_setPosition(new->empty, (sfVector2f){args.pos.x, args.pos.y});
    rect = sfSprite_getGlobalBounds(new->full);
    new->fill_rect = (sfIntRect){0, 0, rect.width, rect.height};
    return (new);
}

static void destroyer(void *ptr)
{
    fill_bar_comp_t *bar = ptr;

    sfSprite_destroy(bar->full);
    sfSprite_destroy(bar->empty);
    sfTexture_destroy(bar->empty_text);
    sfTexture_destroy(bar->full_text);
    my_free(bar);
}

const gt_component_class_t FILL_BAR_COMP = {
    .name = "fill_bar_component",
    .destroyer = &destroyer,
};