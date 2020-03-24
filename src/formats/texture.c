/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Texture format definition
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/formats/texture.h"

static rpg_texture_t *load(const char *path, gt_world_t *world)
{
    rpg_texture_t *self = my_malloc(sizeof(rpg_texture_t));

    (void)(world);
    self->name = my_cstrdup(path);
    my_printf("Loading texture: %s\n", self->name);
    self->sf = sfTexture_createFromFile(path, NULL);
    return (self);
}

static void free_texture(rpg_texture_t *tex)
{
    my_printf("Destroying texture: %s\n", tex->name);
    my_free(tex->name);
    sfTexture_destroy(tex->sf);
    my_free(tex);
}

const gt_format_t RPG_TEXTURE_FORMAT = {
    .name = "asset_texture",
    .load = (void *(*)(const char*, gt_world_t*)) &load,
    .destroy = (void (*)(void*)) &free_texture,
};
