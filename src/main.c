/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Program entry point
*/

#include "my/my.h"
#include "my/io.h"

int main(void)
{
    i32_t a = 8;
    i32_t b = -5;
    i32_t sum = rpg_add(a, b);

    my_printf("%d + %d = %d\n", a, b, sum);
    return (0);
}
