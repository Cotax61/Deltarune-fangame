/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Systems declarations
*/

#ifndef RPG_WINDOW_SYSTEM_H
#define RPG_WINDOW_SYSTEM_H

#include "gote/gote.h"
#include "rpg/systems/rect_rendering.h"
#include "rpg/systems/sprite_rendering.h"
#include "rpg/systems/text_rendering.h"

gt_system_t *rpg_time_system(void);
gt_system_t *rpg_window_system(const char *title, u64_t width, u64_t height);
gt_system_t *rpg_render_system(void);
gt_system_t *rpg_clear_system(u32_t clear_color);
gt_system_t *rpg_xform_system(void);
gt_system_t *rpg_health_system(void);
gt_system_t *rpg_tile_system(void);
gt_system_t *rpg_input_handler_system(void);
gt_system_t *rpg_enemy_system(void);
gt_system_t *rpg_enemy_spawner_system(void);
gt_system_t *rpg_animation_system(void);

#endif /* RPG_WINDOW_SYSTEM_H */
