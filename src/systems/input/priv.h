/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Input system private functions
*/

#ifndef RPG_INPUT_SYSTEM_PRIV_H
#define RPG_INPUT_SYSTEM_PRIV_H

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"

typedef struct {
    u64_t sf_chan_sub;
} input_sys_t;

void rpg_input_process_event(gt_world_t *world, gt_storage_t *input_comps,
    sfEvent *e);

#endif /* !RPG_INPUT_SYSTEM_PRIV_H */
