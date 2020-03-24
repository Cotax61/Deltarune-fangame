/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Sprite rendering system declaration
*/

#ifndef RPG_SPRITE_RENDERING_SYSTEM_H
#define RPG_SPRITE_RENDERING_SYSTEM_H

#include <SFML/Graphics.h>
#include "gote/gote.h"

typedef struct {
    sfSprite *sprite;
} rpg_sprite_sys_data_t;

gt_system_t *rpg_sprite_rendering_system(void);
bool rpg_sprite_rendering_system_run(void*, gt_world_t*);

#endif /* RPG_SPRITE_RENDERING_SYSTEM_H */
