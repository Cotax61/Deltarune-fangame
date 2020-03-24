/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI system rpg_ui_system_process_events() implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "rpg/ui.h"
#include "priv.h"

void rpg_ui_system_process_events(rpg_ui_widget_t *widget)
{
    rpg_ui_event_t event = { .name = "sf_event" };
    gt_event_channel_t *event_chan = widget->priv.event_chan;
    u64_t event_chan_sub = widget->priv.event_chan_id;
    sfEvent sf_event;

    event.data = &sf_event;
    event.widget = widget;
    while (gt_event_channel_poll(event_chan, event_chan_sub, &sf_event))
        rpg_ui_widget_fire(widget, &event);
}
