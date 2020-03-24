/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Text rendering system declaration
*/

#ifndef RPG_TEXT_RENDERING_SYSTEM_H
#define RPG_TEXT_RENDERING_SYSTEM_H

#include <SFML/Graphics.h>
#include "gote/gote.h"

typedef struct {
    sfText *text;
} rpg_text_sys_data_t;

gt_system_t *rpg_text_rendering_system(void);
bool rpg_text_rendering_system_run(void*, gt_world_t*);

#endif /* RPG_TEXT_RENDERING_SYSTEM_H */
