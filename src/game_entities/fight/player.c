/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "gote/gote.h"
#include "rpg/components.h"
#include "rpg/formats.h"

static const char *PLAYER_PATH = "./res/img/player_fight.png";

gt_entity_t *init_fight_player(gt_world_t *world)
{
    gt_handle_t handle = gt_load(PLAYER_PATH, &RPG_TEXTURE_FORMAT, world); 

    return (gt_world_create_entity(world, 2,
        &XFORM_COMP, xform_component(VEC3(500, 200, 300), 2, 0, NULL),
        &SPRITE_COMP, sprite_component(handle, RECT(0, 0, 0.16, 0.5), 1)));
}