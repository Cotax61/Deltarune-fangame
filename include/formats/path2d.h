/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Path 2D format declaration
*/

#ifndef RPG_PATH2D_FORMAT_H
#define RPG_PATH2D_FORMAT_H

#include "gote/gote.h"
#include "rpg/types.h"

extern const gt_format_t RPG_PATH2D_FORMAT;

typedef struct {
    char *name;
    usize_t len;
    rpg_vec2_t *points;
} rpg_path2d_t;

#endif /* RPG_PATH2D_FORMAT_H */
