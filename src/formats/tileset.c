/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Tileset format definition
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "my/collections/hash_map.h"
#include "gote/gote.h"
#include "rpg/data.h"
#include "rpg/formats/texture.h"
#include "rpg/formats/tileset.h"

static bool load_from_props(rpg_tileset_t *ts, rpg_props_t *props,
    gt_world_t *world)
{
    const char *texture = rpg_props_get(props, "texture");
    OPT(i32) columns = rpg_props_get_nbr(props, "columns");
    OPT(i32) rows = rpg_props_get_nbr(props, "rows");

    if (texture == NULL || !columns.is_some || !rows.is_some) {
        if (texture == NULL)
            my_fprintf(2, "Tileset error: no texture\n");
        else if (!columns.is_some)
            my_fprintf(2, "Tileset error: invalid 'columns'\n");
        else
            my_fprintf(2, "Tileset error: invalid 'rows'\n");
        return (true);
    }
    ts->texture = gt_load(texture, &RPG_TEXTURE_FORMAT, world);
    ts->columns = columns.v;
    ts->rows = rows.v;
    return (false);
}

static rpg_tileset_t *load(const char *path, gt_world_t *world)
{
    rpg_props_t *props = rpg_props_load(path);
    rpg_tileset_t *ts = my_malloc(sizeof(rpg_tileset_t));

    my_printf("Loading tileset: %s\n", path);
    if (ts)
        ts->name = my_cstrdup(path);
    if (props == NULL || ts == NULL || load_from_props(ts, props, world)) {
        my_free(ts);
        rpg_props_destroy(props);
        my_fprintf(2, "Couldn't load tileset \"%s\"!\n", path);
        return (NULL);
    }
    my_printf("Loaded tileset, size W=%d H=%d\n", ts->columns, ts->rows);
    rpg_props_destroy(props);
    return (ts);
}

static void free_tileset(rpg_tileset_t *self)
{
    my_printf("Destroying tileset: %s\n", self->name);
    my_free(self->name);
    gt_handle_drop(self->texture);
    my_free(self);
}

const gt_format_t RPG_TILESET_FORMAT = {
    .name = "asset_tileset",
    .load = (void *(*)(const char*, gt_world_t*)) &load,
    .destroy = (void (*)(void*)) &free_tileset,
};