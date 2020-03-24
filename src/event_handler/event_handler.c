/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_handler
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/io.h"
#include "rpg/event_handlers.h"

void rpg_dev_btn_pressed(void *user_data, void *sf_evt)
{
    sfMouseButtonEvent *evt = sf_evt;

    (void)(user_data);
    my_printf(
        "[Event] Mouse button %d pressed at coords X=%d Y=%d\n",
        evt->button,
        evt->x,
        evt->y
    );
}
