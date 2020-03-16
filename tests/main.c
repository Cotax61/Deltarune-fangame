/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include "rpg/rpg.h"

Test(MUL_my_rpg_2019, it_works)
{
    cr_assert_eq(rpg_add(2, 2), 4);
}
