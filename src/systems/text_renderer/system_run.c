/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Text rendering running function
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/fmt.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/render_queue.h"
#include "rpg/types.h"
#include "rpg/formats.h"
#include "rpg/components.h"
#include "rpg/systems.h"

struct process_data {
    sfText *text;
    sfRenderWindow *win;
    render_queue_t *rqueue;
    gt_storage_t *text_strg;
    gt_storage_t *xform_strg;
};

struct render_data {
    sfText *text;
    sfRenderWindow *win;
    text_comp_t *txt_comp;
    xform_comp_t *xform;
    rpg_font_t *font;
};

static sfVector2f compute_text_pos(rpg_halign_t halign, rpg_valign_t valign,
    const sfFloatRect *bounds, const rpg_vec2_t *origin)
{
    sfVector2f pos = {origin->x - bounds->left, origin->y - bounds->top};

    if (halign == RPG_CENTER || halign == RPG_RIGHT)
        pos.x -= bounds->width / (halign == RPG_RIGHT ? 1.0 : 2.0);
    if (valign == RPG_MIDDLE || valign == RPG_BOTTOM)
        pos.y -= bounds->height / (valign == RPG_BOTTOM ? 1.0 : 2.0);
    return (pos);
}

static void render_callback(void *ptr)
{
    struct render_data *data = ptr;
    sfRenderStates states = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfFloatRect sfbounds = {0};

    sfText_setFont(data->text, data->font->sf);
    sfText_setColor(data->text, sfColor_fromInteger(data->txt_comp->color));
    sfText_setCharacterSize(data->text, data->txt_comp->size);
    if (data->txt_comp->priv.text)
        sfText_setString(data->text, data->txt_comp->priv.text);
    else
        sfText_setString(data->text, "");
    sfbounds = sfText_getLocalBounds(data->text);
    sfText_setPosition(data->text, compute_text_pos(data->txt_comp->halign,
        data->txt_comp->valign, &sfbounds, &data->txt_comp->pos));
    if (data->xform)
        states.transform = data->xform->local_to_world;
    sfRenderWindow_drawText(data->win, data->text, &states);
    my_free(data);
}

static void process_entity(struct process_data *data, gt_entity_t *ent)
{
    struct render_data *rdata = NULL;
    text_comp_t *txt_comp = gt_storage_get(data->text_strg, ent->id);
    xform_comp_t *xform = gt_storage_get(data->xform_strg, ent->id);
    rpg_font_t *font = NULL;
    f64_t depth = 0.0;

    if (!txt_comp || !txt_comp->priv.font)
        return;
    font = txt_comp->priv.font->v->data;
    rdata = my_calloc(1, sizeof(struct render_data));
    rdata->txt_comp = txt_comp;
    rdata->xform = xform;
    rdata->win = data->win;
    rdata->text = data->text;
    rdata->font = font;
    depth = xform == NULL ? 0.0 : xform->world_depth;
    render_queue_push(data->rqueue, depth, &render_callback, rdata);
}

bool rpg_text_rendering_system_run(void *self_raw, gt_world_t *world)
{
    rpg_text_sys_data_t *self = self_raw;
    struct process_data data = {
        .text = self->text,
        .win = gt_world_get(world, "window"),
        .rqueue = gt_world_get(world, "render_queue"),
        .text_strg = gt_world_get(world, TEXT_COMP.name),
        .xform_strg = gt_world_get(world, XFORM_COMP.name),
    };

    if (data.win == NULL || data.text_strg == NULL || data.rqueue == NULL)
        return (false);
    LIST_FOR_EACH(world->entities, iter)
        process_entity(&data, iter.v);
    return (false);
}
