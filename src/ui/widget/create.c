/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rpg_ui_widget_create implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/collections/hash_map.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/components.h"
#include "rpg/ui.h"

struct event_handler_data {
    bool hover;
    rpg_ui_widget_t *widget;
    xform_comp_t *xform;
    sfVector2f mouse_mov;
    sfVector2f mouse_pos;
};

static bool widget_contains_local(const rpg_ui_widget_t *wdgt, f64_t x, f64_t y)
{
    bool contains = true;

    contains = contains && x > 0;
    contains = contains && y > 0;
    contains = contains && x <= wdgt->abs_bounds.right - wdgt->abs_bounds.left;
    contains = contains && y <= wdgt->abs_bounds.bottom - wdgt->abs_bounds.top;
    return (contains);
}

static bool handle_sf_mouse_move(sfEvent *sfe, struct event_handler_data *data)
{
    rpg_ui_event_t ui_event = {.widget = data->widget, .mouse.action = RPG_MOVED};
    sfVector2f mouse_pos = sfTransform_transformPoint(
        &data->xform->world_to_local,
        (sfVector2f) { sfe->mouseMove.x, sfe->mouseMove.y });
    bool hover = widget_contains_local(data->widget, mouse_pos.x, mouse_pos.y);

    data->mouse_mov.x = mouse_pos.x - data->mouse_pos.x;
    data->mouse_mov.y = mouse_pos.y - data->mouse_pos.y;
    data->mouse_pos = mouse_pos;
    if (data->hover == hover && !hover)
        return (false);
    ui_event.name = data->hover && !hover ? "mouseleave" : "mousemove";
    ui_event.name = !data->hover && hover ? "mouseenter" : ui_event.name;
    ui_event.mouse.pos = VEC2(mouse_pos.x, mouse_pos.y);
    ui_event.mouse.rel = VEC2(data->mouse_mov.x, data->mouse_mov.y);
    data->hover = hover;
    return (rpg_ui_widget_fire(data->widget, &ui_event));
}

static bool handle_sf_mouse_btn(sfEvent *sfe, struct event_handler_data *data)
{
    rpg_ui_event_t ui_event = {.widget = data->widget, .mouse.action =
        sfe->type == sfEvtMouseButtonPressed ? RPG_PRESSED : RPG_RELEASED};
    sfVector2f mouse_pos = sfTransform_transformPoint(
        &data->xform->world_to_local,
        (sfVector2f) { sfe->mouseButton.x, sfe->mouseButton.y });
    bool hover = widget_contains_local(data->widget, mouse_pos.x, mouse_pos.y);

    if (!hover)
        return (false);
    data->mouse_pos = mouse_pos;
    if (ui_event.mouse.action == RPG_PRESSED)
        ui_event.name = "mousedown";
    else
        ui_event.name = "mouseup";
    ui_event.mouse.pos = VEC2(mouse_pos.x, mouse_pos.y);
    ui_event.mouse.button = (rpg_button_t) sfe->mouseButton.button;
    return (rpg_ui_widget_fire(data->widget, &ui_event));
}

static bool sf_event_handler(const rpg_ui_event_t *event, void *ptr)
{
    sfEvent *sfe = event->data;
    struct event_handler_data *data = ptr;

    data->widget = event->widget;
    data->xform = gt_storage_get(gt_world_get(data->widget->priv.world,
        XFORM_COMP.name), data->widget->priv.entity->id);
    switch (sfe->type) {
    case sfEvtMouseMoved:
        return (handle_sf_mouse_move(sfe, data));
    case sfEvtMouseButtonPressed:
    case sfEvtMouseButtonReleased:
        return (handle_sf_mouse_btn(sfe, data));
    default:
        return (false);
    }
}

rpg_ui_widget_t *rpg_ui_widget_create(void)
{
    rpg_ui_widget_t *self = my_calloc(1, sizeof(rpg_ui_widget_t));

    self->listeners = hash_map_new();
    self->children = list_new();
    self->text_halign = RPG_CENTER;
    self->text_valign = RPG_MIDDLE;
    self->font_size = 20;
    self->bounds.right = 10;
    self->bounds.bottom = 10;
    rpg_ui_widget_freed_on(self, "sf_event", &sf_event_handler,
        my_calloc(1, sizeof(struct event_handler_data)));
    return (self);
}
