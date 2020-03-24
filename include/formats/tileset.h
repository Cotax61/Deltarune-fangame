/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Tileset format declaration
*/

#ifndef RPG_TILESET_FORMAT_H
#define RPG_TILESET_FORMAT_H

#include "gote/gote.h"

extern const gt_format_t RPG_TILESET_FORMAT;

typedef struct {
    char *name;
    gt_handle_t texture;
    u32_t rows;
    u32_t columns;
} rpg_tileset_t;

#endif /* RPG_TILESET_FORMAT_H */
