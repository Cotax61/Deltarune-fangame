/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Texture format declaration
*/

#ifndef RPG_TEXTURE_FORMAT_H
#define RPG_TEXTURE_FORMAT_H

#include <SFML/Graphics.h>
#include "gote/gote.h"

extern const gt_format_t RPG_TEXTURE_FORMAT;

typedef struct {
    char *name;
    sfTexture *sf;
} rpg_texture_t;

#endif /* RPG_TEXTURE_FORMAT_H */
