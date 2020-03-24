/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** CSV destroy implementation
*/

#include "my/my.h"
#include "rpg/data/csv.h"

void rpg_csv_destroy(rpg_csv_t *self)
{
    if (self == NULL)
        return;
    my_free(self->data);
    my_free(self);
}
