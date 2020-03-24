/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Button widget creator
*/

#include "my/my.h"
#include "my/cstr.h"
#include "rpg/ui.h"

static const u64_t DEFAULT_BACKGROUND = 0x444444FF;
static const u64_t HOVER_BACKGROUND = 0x333333FF;
static const u64_t PRESSED_BACKGROUND = 0x222222FF;

struct state {
    bool pressed;
};

static void do_click(const rpg_ui_event_t *source_event)
{
    rpg_ui_event_t click_event = *source_event;

    click_event.name = "click";
    rpg_ui_widget_fire(click_event.widget, &click_event);
}

static bool move_event_handler(const rpg_ui_event_t *event, void *ptr)
{
    struct state *state = ptr;

    if (my_cstrcmp(event->name, "mouseenter") == 0)
        event->widget->background = HOVER_BACKGROUND;
    else if (my_cstrcmp(event->name, "mouseleave") == 0) {
        event->widget->background = DEFAULT_BACKGROUND;
        state->pressed = false;
    }
    return (false);
}

static bool btn_event_handler(const rpg_ui_event_t *event, void *ptr)
{
    struct state *state = ptr;

    if (my_cstrcmp(event->name, "mousedown") == 0) {
        state->pressed = true;
        event->widget->background = PRESSED_BACKGROUND;
    } else if (my_cstrcmp(event->name, "mouseup") == 0) {
        if (state->pressed)
            do_click(event);
        state->pressed = false;
        event->widget->background = HOVER_BACKGROUND;
    }
    return (false);
}

static bool btn_on_destroy(const rpg_ui_event_t *event, void *ptr)
{
    struct state *state = ptr;

    (void)(event);
    my_free(state);
    return (false);
}

rpg_ui_widget_t *rpg_ui_button_create(const char *text)
{
    struct state *state = my_calloc(1, sizeof(struct state));
    rpg_ui_widget_t *self = rpg_ui_widget_create();

    self->text = my_cstrdup(text);
    self->background = DEFAULT_BACKGROUND;
    self->foreground = 0xFFFFFFFF;
    rpg_ui_widget_static_on(self, "mouseenter", &move_event_handler, state);
    rpg_ui_widget_static_on(self, "mouseleave", &move_event_handler, state);
    rpg_ui_widget_static_on(self, "mousemove", &move_event_handler, state);
    rpg_ui_widget_static_on(self, "mousedown", &btn_event_handler, state);
    rpg_ui_widget_static_on(self, "mouseup", &btn_event_handler, state);
    rpg_ui_widget_static_on(self, "destroy", &btn_on_destroy, state);
    return (self);
}
