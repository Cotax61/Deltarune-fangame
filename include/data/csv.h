/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** CSV data parser and loader
*/

#ifndef RPG_DATA_CSV_H
#define RPG_DATA_CSV_H

#include "my/types.h"

typedef struct {
    i64_t *data;
    usize_t width;
    usize_t height;
} rpg_csv_t;

rpg_csv_t *rpg_csv_load(const char *path);
void rpg_csv_destroy(rpg_csv_t *self);

static inline OPT(i64) rpg_csv_get(const rpg_csv_t *self, usize_t x, usize_t y)
{
    return (
        x >= self->width || y >= self->height ?
            NONE(i64) :
            SOME(i64, self->data[y * self->width + x])
    );
}

static inline i64_t rpg_csv_get_or(const rpg_csv_t *self, usize_t x, usize_t y,
    i64_t default_value)
{
    return (
        x >= self->width || y >= self->height ?
            default_value :
            self->data[y * self->width + x]
    );
}

static inline void rpg_csv_set(const rpg_csv_t *self, usize_t x, usize_t y,
    i64_t val)
{
    if (x < self->width && y < self->height)
        self->data[y * self->width + x] = val;
}

#endif /* RPG_DATA_CSV_H */
