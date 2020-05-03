/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019 [WSL: Ubuntu]
** File description:
** events
*/

#include <SFML/Audio.h>
#include "rpg/ui.h"
#include "priv.h"

bool rpg_ui_menu_move_event_handler(const rpg_ui_event_t *event, void *ptr)
{
    struct state *state = ptr;

    if (my_cstrcmp(event->name, "mouseenter") == 0) {
        sfSound_play(state->beep_sound);
        state->name_label->foreground = BORDER_COLOR_ON;
        state->state_label->foreground = BORDER_COLOR_ON;
        state->time_label->foreground = BORDER_COLOR_ON;
        event->widget->foreground = BORDER_COLOR_ON;
        event->widget->border_color = BORDER_COLOR_ON;
    } else if (my_cstrcmp(event->name, "mouseleave") == 0) {
        event->widget->foreground = BORDER_COLOR_OFF;
        event->widget->border_color = BORDER_COLOR_OFF;   
        state->name_label->foreground = BORDER_COLOR_OFF;
        state->state_label->foreground = BORDER_COLOR_OFF;
        state->time_label->foreground = BORDER_COLOR_OFF;
        state->pressed = false;
    }
    return (false);
}

void rpg_ui_menu_btn_do_click(const rpg_ui_event_t *source_event)
{
    rpg_ui_event_t click_event = *source_event;

    click_event.name = "click";
    rpg_ui_widget_fire(click_event.widget, &click_event);
}

bool rpg_ui_menu_btn_event_handler(const rpg_ui_event_t *event, void *ptr)
{
    struct state *state = ptr;

    if (my_cstrcmp(event->name, "mousedown") == 0) {
        state->pressed = true;
        event->widget->foreground = BORDER_COLOR_ON;
        event->widget->border_color = BORDER_COLOR_ON;
    } else if (my_cstrcmp(event->name, "mouseup") == 0) {
        if (state->pressed)
            rpg_ui_menu_btn_do_click(event);
        state->pressed = false;
        event->widget->foreground = BORDER_COLOR_OFF;
        event->widget->border_color = BORDER_COLOR_OFF;  
    }
    return (false);
}

bool rpg_ui_menu_btn_on_destroy(const rpg_ui_event_t *event, void *ptr)
{
    struct state *state = ptr;

    (void)(event);
    my_free(state);
    return (false);
}