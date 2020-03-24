/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI system rpg_ui_system_init_widget() implementation
*/

#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/components.h"
#include "rpg/ui.h"
#include "priv.h"

void rpg_ui_system_init_widget(rpg_ui_widget_t *widget, gt_world_t *world)
{
    widget->priv.init = true;
    widget->priv.world = world;
    widget->priv.event_chan = gt_world_get(world, "sfml_channel");
    widget->priv.event_chan_id = gt_event_channel_sub(widget->priv.event_chan);
    widget->priv.entity = gt_world_create_entity(
        world,
        3,
        &RECT_COMP, rect_component(1, 1, 0x000000FF),
        &XFORM_COMP, xform_component(VEC3(0, 0, 0), 1, 0, NULL),
        &TEXT_COMP, text_component(widget->text, NULL, 20, 0xFFFFFFFF)
    );
}
