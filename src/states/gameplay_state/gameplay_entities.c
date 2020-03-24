/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** gameplay_entities
*/

#include "gote/gote.h"
#include "rpg/game_entities.h"
#include "rpg/formats.h"
#include "rpg/components.h"
#include "rpg/states.h"

static void castle_death(gt_world_t *world, gt_entity_t *entity, void *ud)
{
    gt_event_channel_t *trans_chan = gt_world_get(world, "trans_channel");
    gt_state_trans_t trans = gt_state_trans_switch(rpg_death_state());

    (void)(entity);
    (void)(ud);
    gt_event_channel_push(trans_chan, &trans);
}

void rpg_game_init_values(gt_world_t *world)
{
    i64_t *money = my_malloc(sizeof(i64_t));
    u8_t *sel_turret = my_malloc(sizeof(u8_t));

    *money = 500;
    *sel_turret = 1;
    gt_world_insert(world, "is_paused", 0, NULL);
    gt_world_insert(world, "money", money, NULL);
    gt_world_insert(world, "selected_turret", sel_turret, NULL);
}

gt_entity_t *rpg_game_create_castle(gt_world_t *world, rpg_tilemap_t *tilemap)
{
    rpg_path2d_t* pths = tilemap->enemy_path->v->data;
    gt_handle_t text = gt_load("./res/img/castle.png", &RPG_TEXTURE_FORMAT,
        world);
    gt_entity_t *castle = gt_world_create_entity(world, 3,
        &XFORM_COMP, xform_component(VEC3(pths->points[pths->len - 1].x,
            pths->points[pths->len - 1].y, 1), 1, 0, NULL),
        &SPRITE_COMP, sprite_component(text, RECT(0, 0, 1, 1), 1),
        &HEALTH_COMP, health_component(10000, &castle_death, NULL));

    return (castle);
}