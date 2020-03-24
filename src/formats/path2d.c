/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Path2D format definition
*/

#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/data/csv.h"
#include "rpg/types.h"
#include "rpg/formats/path2d.h"

static rpg_path2d_t *load(const char *path, gt_world_t *world)
{
    rpg_csv_t *csv = NULL;
    rpg_path2d_t *self = NULL;

    (void)(world);
    my_printf("Loading enemy path: %s\n", path);
    csv = rpg_csv_load(path);
    if (csv == NULL) {
        my_fprintf(2, "[Error] Failed to load enemy path: %s\n", self->name);
        return (NULL);
    }
    self = my_calloc(1, sizeof(rpg_path2d_t));
    self->name = my_cstrdup(path);
    self->len = csv->height;
    self->points = my_calloc(self->len, sizeof(rpg_vec2_t));
    for (usize_t i = 0; i < self->len; i++)
        self->points[i] = VEC2(csv->data[i * 2], csv->data[i * 2 + 1]);
    rpg_csv_destroy(csv);
    return (self);
}

static void destroy(rpg_path2d_t *self)
{
    my_printf("Destroying enemy path: %s\n", self->name);
    my_free(self->name);
    my_free(self->points);
    my_free(self);
}

const gt_format_t RPG_PATH2D_FORMAT = {
    .name = "asset_path2d",
    .load = (void *(*)(const char*, gt_world_t*)) &load,
    .destroy = (void (*)(void*)) &destroy,
};
