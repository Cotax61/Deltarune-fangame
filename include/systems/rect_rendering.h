/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Rect rendering system declaration
*/

#ifndef RPG_RECT_RENDERING_SYSTEM_H
#define RPG_RECT_RENDERING_SYSTEM_H

#include <SFML/Graphics.h>
#include "gote/gote.h"

typedef struct {
    sfRectangleShape *shape;
} rpg_rect_sys_data_t;

gt_system_t *rpg_rect_rendering_system(void);
bool rpg_rect_rendering_system_run(void*, gt_world_t*);

#endif /* RPG_RECT_RENDERING_SYSTEM_H */
