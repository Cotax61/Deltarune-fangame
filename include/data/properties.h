/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Properties data file loader and parser
*/

#ifndef RPG_DATA_PROPERTIES_H
#define RPG_DATA_PROPERTIES_H

#include "my/collections/hash_map.h"

typedef hash_map_t rpg_props_t;

rpg_props_t *rpg_props_load(const char *path);
void rpg_props_destroy(rpg_props_t *self);
const char *rpg_props_get(const rpg_props_t *self, const char *key);
OPT(i32) rpg_props_get_nbr(const rpg_props_t *self, const char *key);

#endif /* RPG_DATA_PROPERTIES_H */
