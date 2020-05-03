/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_ui
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg/components.h"
#include "rpg/ui.h"

static const char *FONT_PATH = "./res/fonts/dev_font.ttf";

void destroy_fight_button(void *self)
{
    rpg_fight_ui_t *but = (rpg_fight_ui_t *){self};

    sfFont_destroy(but->font);
    sfText_destroy(but->display_text);
    sfRectangleShape_destroy(but->rect);
    free(but);
}

static void set_button_text(char *text, rpg_fight_ui_t *but, int nb,
    rpg_vec2_t size)
{
    sfFont *font = sfFont_createFromFile(FONT_PATH);

    sfText_setString(but->display_text, text);
    sfText_setFont(but->display_text, font);
    sfText_setColor(but->display_text, but->default_color);
    sfText_setCharacterSize(but->display_text, 60);
    sfText_setPosition(but->display_text,
    (sfVector2f){100 + size.x * nb + 25, 720 - size.y - 100});
    sfText_move(but->display_text, (sfVector2f){39 * nb, 0});
}

rpg_fight_ui_t *set_button_fight_values(char *name, rpg_vec2_t size, int nb)
{
    rpg_fight_ui_t *but = malloc(sizeof(rpg_fight_ui_t));

    but->display_text = sfText_create();
    but->default_color = (sfColor){239, 255, 20, 255};
    but->selected_color = (sfColor){194, 136, 0, 255};
    but->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(but->rect, sfBlack);
    sfRectangleShape_setSize(but->rect, (sfVector2f){size.x, size.y});
    sfRectangleShape_setOutlineThickness(but->rect, 6);
    sfRectangleShape_setOutlineColor(but->rect, but->default_color);
    sfRectangleShape_setPosition(but->rect,
    (sfVector2f){100 + size.x * nb + (10 * nb), 720 - size.y - 100});
    sfRectangleShape_move(but->rect, (sfVector2f){30 * nb, 0});
    set_button_text(name, but, nb, size);
    return (but);
}

rpg_fight_ui_t **rpg_fight_create_ui()
{
    rpg_fight_ui_t **list = malloc(sizeof(rpg_fight_ui_t) * 5);

    list[0] = set_button_fight_values("Fight", VEC2(200, 100), 0);
    list[1] = set_button_fight_values("Magic", VEC2(200, 100), 1);
    list[2] = set_button_fight_values("Item", VEC2(200, 100), 2);
    list[3] = set_button_fight_values("Defend", VEC2(200, 100), 3);
    list[4] = NULL;
    return (list);
}