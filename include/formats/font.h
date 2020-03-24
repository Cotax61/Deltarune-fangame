/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Font format declaration
*/

#ifndef RPG_FONT_FORMAT_H
#define RPG_FONT_FORMAT_H

#include <SFML/Graphics.h>
#include "gote/gote.h"

extern const gt_format_t RPG_FONT_FORMAT;

typedef struct {
    char *name;
    sfFont *sf;
} rpg_font_t;

#endif /* RPG_FONT_FORMAT_H */
