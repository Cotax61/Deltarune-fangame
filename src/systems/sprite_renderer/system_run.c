/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Sprite renderer running function
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/formats/texture.h"
#include "rpg/render_queue.h"
#include "rpg/components.h"
#include "rpg/systems.h"

struct process_data {
    sfRenderWindow *win;
    render_queue_t *rqueue;
    gt_storage_t *sprite_strg;
    gt_storage_t *xform_strg;
    rpg_sprite_sys_data_t *sys;
};

struct render_data {
    sfRenderWindow *win;
    sfSprite *sprite;
    rpg_texture_t *tex;
    sprite_comp_t *sprite_comp;
    xform_comp_t *xform;
    rpg_rect_t sub;
};

static void render_callback(void *ptr)
{
    struct render_data *data = ptr;
    sfRenderStates rstates = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfVector2u tex_size = sfTexture_getSize(data->tex->sf);
    sfColor tint = sfColor_fromInteger(data->sprite_comp->tint);

    if (data->xform)
        rstates.transform = data->xform->local_to_world;
    tint.a *= data->sprite_comp->opacity;
    sfSprite_setTexture(data->sprite, data->tex->sf, false);
    sfSprite_setColor(data->sprite, tint);
    sfSprite_setTextureRect(data->sprite, (sfIntRect) {
        data->sub.x * tex_size.x, data->sub.y * tex_size.y,
        data->sub.width * tex_size.x, data->sub.height * tex_size.y,
    });
    sfSprite_setOrigin(data->sprite, (sfVector2f) {
        data->sub.width * tex_size.x / 2.0, data->sub.height * tex_size.y / 2.0,
    });
    sfRenderWindow_drawSprite(data->win, data->sprite, &rstates);
    my_free(data);
}

static void process_entity(struct process_data *data, gt_entity_t *ent)
{
    struct render_data *rdata = NULL;
    sprite_comp_t *sprite_comp = gt_storage_get(data->sprite_strg, ent->id);
    xform_comp_t *xform = gt_storage_get(data->xform_strg, ent->id);
    f64_t depth = xform ? xform->world_depth : 0.0;

    if (sprite_comp == NULL)
        return;
    rdata = my_malloc(sizeof(struct render_data));
    rdata->win = data->win;
    rdata->sprite = data->sys->sprite;
    rdata->tex = sprite_comp->texture->v->data;
    rdata->sprite_comp = sprite_comp;
    rdata->xform = xform;
    rdata->sub = sprite_comp->sub;
    render_queue_push(data->rqueue, depth, &render_callback, rdata);
}

bool rpg_sprite_rendering_system_run(void *self_raw, gt_world_t *world)
{
    struct process_data data = {
        .win = gt_world_get(world, "window"),
        .rqueue = gt_world_get(world, "render_queue"),
        .sprite_strg = gt_world_get(world, SPRITE_COMP.name),
        .xform_strg = gt_world_get(world, XFORM_COMP.name),
        .sys = self_raw
    };

    LIST_FOR_EACH(world->entities, iter)
        process_entity(&data, iter.v);
    return (false);
}
