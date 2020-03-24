/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Font format definition
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/formats/font.h"

static rpg_font_t *load(const char *path, gt_world_t *world)
{
    rpg_font_t *self = my_calloc(1, sizeof(rpg_font_t));

    (void)(world);
    self->name = my_cstrdup(path);
    my_printf("Loading font: %s\n", self->name);
    self->sf = sfFont_createFromFile(path);
    return (self);
}

static void free_font(rpg_font_t *tex)
{
    my_printf("Destroying font: %s\n", tex->name);
    my_free(tex->name);
    sfFont_destroy(tex->sf);
    my_free(tex);
}

const gt_format_t RPG_FONT_FORMAT = {
    .name = "asset_font",
    .load = (void *(*)(const char*, gt_world_t*)) &load,
    .destroy = (void (*)(void*)) &free_font,
};
