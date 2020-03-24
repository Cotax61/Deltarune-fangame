/*
** EPITECH PROJECT, 2020
** libgote_demo
** File description:
** Game states
*/

#ifndef RPG_STATES_H
#define RPG_STATES_H

#include "gote/gote.h"

gt_state_t *rpg_root_state(void);
gt_state_t *rpg_title_state(void);
gt_state_t *rpg_dev_state(void);
gt_state_t *rpg_sprite_dev_state(void);
gt_state_t *rpg_gameplay_state(void);
gt_state_t *rpg_sscreen_state(void);
gt_state_t *rpg_pause_state(void);
gt_state_t *rpg_death_state(void);

#endif /* RPG_STATES_H */
