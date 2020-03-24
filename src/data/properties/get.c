/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rpg_props_get_* implementation
*/

#include "my/my.h"
#include "my/cstr.h"
#include "my/collections/hash_map.h"
#include "rpg/data.h"

const char *rpg_props_get(const rpg_props_t *self, const char *key)
{
    return (hash_map_get(self, key).v);
}

OPT(i32) rpg_props_get_nbr(const rpg_props_t *self, const char *key)
{
    const char *str = rpg_props_get(self, key);

    if (str == NULL)
        return (NONE(i32));
    return (SOME(i32, my_cstr_getnbr(str)));
}
