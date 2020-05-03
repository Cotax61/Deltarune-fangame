/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Button widget creator
*/

#include <SFML/Audio.h>
#include "my/my.h"
#include "my/cstr.h"
#include "rpg/ui.h"
#include "priv.h"

const u32_t BORDER_COLOR_ON = 0xDE26CFFF;
const u32_t BORDER_COLOR_OFF = 0x471343FF;

static void set_widget_properties(rpg_ui_widget_t *self)
{
    self->background = 0x0;
    self->foreground = BORDER_COLOR_OFF;
    self->border_color = BORDER_COLOR_OFF;
    self->border_thickness = 2;
}

static void set_label_values(rpg_ui_widget_t *name_sublabel,
    rpg_ui_widget_t *stage_sublabel, rpg_ui_widget_t *time_sublabel)
{
    name_sublabel->text_halign = RPG_LEFT;
    name_sublabel->text_valign = RPG_TOP;
    stage_sublabel->text_halign = RPG_LEFT;
    stage_sublabel->text_valign = RPG_TOP;
    time_sublabel->text_halign = RPG_RIGHT;
    time_sublabel->text_valign = RPG_TOP;
    name_sublabel->font_size = 34;
    stage_sublabel->font_size = 34;
    time_sublabel->font_size = 34;
}   

static void add_button_sublabels(rpg_ui_widget_t *btn,
    rpg_ui_menu_button_args_t *args, struct state *state)
{
    rpg_ui_widget_t *name_sublabel = rpg_ui_menu_label_create(btn, 
        args->is_empty ? "[EMPTY]" : args->character_name, 20, 20);
    rpg_ui_widget_t *stage_sublabel = rpg_ui_menu_label_create(btn, 
        args->is_empty ? "------------------" : args->current_state, 
        20, 100);
    rpg_ui_widget_t *time_sublabel = rpg_ui_menu_label_create(btn, "00:00", 
        -20, 20);
        
    set_label_values(name_sublabel, stage_sublabel, time_sublabel);
    state->name_label = name_sublabel;
    state->state_label = stage_sublabel;
    state->time_label = time_sublabel;
    rpg_ui_widget_add(btn, stage_sublabel);
    rpg_ui_widget_add(btn, name_sublabel);
    rpg_ui_widget_add(btn, time_sublabel);
}

rpg_ui_widget_t *rpg_ui_menu_button_create(rpg_ui_menu_button_args_t *args,
    sfSound *beep_sound)
{
    struct state *state = my_calloc(1, sizeof(struct state));
    rpg_ui_widget_t *self = rpg_ui_widget_create();

    state->beep_sound = beep_sound;
    set_widget_properties(self);
    add_button_sublabels(self, args, state);
    rpg_ui_widget_static_on(self, "mouseenter", 
        &rpg_ui_menu_move_event_handler, state);
    rpg_ui_widget_static_on(self, "mouseleave", 
        &rpg_ui_menu_move_event_handler, state);
    rpg_ui_widget_static_on(self, "mousemove", 
        &rpg_ui_menu_move_event_handler, state);
    rpg_ui_widget_static_on(self, "mousedown", 
        &rpg_ui_menu_btn_event_handler, state);
    rpg_ui_widget_static_on(self, "mouseup", 
        &rpg_ui_menu_btn_event_handler, state);
    rpg_ui_widget_static_on(self, "destroy", 
        &rpg_ui_menu_btn_on_destroy, state);
    return (self);
}
