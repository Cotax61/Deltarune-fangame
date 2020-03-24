/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Properties destroy implementation
*/

#include "my/my.h"
#include "my/collections/hash_map.h"
#include "rpg/data.h"

static OPT(i32) free_value(void *ptr, hash_map_pair_t *pair)
{
    (void)(ptr);
    my_free(pair->value);
    return (NONE(i32));
}

void rpg_props_destroy(rpg_props_t *self)
{
    hash_map_destroy_with(self, &free_value, NULL);
}
