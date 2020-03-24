/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** UI widget
*/

#ifndef RPG_UI_WIDGET_H
#define RPG_UI_WIDGET_H

#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_map.h"
#include "gote/gote.h"
#include "rpg/types.h"

typedef struct rpg_ui_widget rpg_ui_widget_t;

typedef struct {
    rpg_ui_widget_t *widget;
    const char *name;
    struct {
        rpg_vec2_t pos;
        rpg_vec2_t rel;
        rpg_vec2_t scroll;
        rpg_button_action_t action;
        rpg_button_t button;
    } mouse;
    void *data;
} rpg_ui_event_t;

struct rpg_ui_widget {
    rpg_ui_widget_t *parent;
    list_t *children;
    hash_map_t *listeners;
    u32_t background;
    u32_t foreground;
    char *text;
    gt_handle_t font;
    u32_t font_size;
    rpg_halign_t text_halign;
    rpg_valign_t text_valign;
    rpg_bounds_t bounds;
    rpg_bounds_t anchors;
    const rpg_bounds_t abs_bounds;
    struct {
        bool init;
        gt_world_t *world;
        gt_event_channel_t *event_chan;
        u64_t event_chan_id;
        gt_entity_t *entity;
    } priv;
    void *data;
};

typedef struct {
    bool (*handler)(const rpg_ui_event_t*, void*);
    void (*destroy)(void*);
    void *ptr;
} rpg_ui_event_handler_desc_t;

rpg_ui_widget_t *rpg_ui_widget_create(void);
void rpg_ui_widget_destroy(rpg_ui_widget_t *self);
void rpg_ui_widget_add(rpg_ui_widget_t *self, rpg_ui_widget_t *child);
void rpg_ui_widget_remove(rpg_ui_widget_t *self, rpg_ui_widget_t *child);
void rpg_ui_widget_on(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*));
void rpg_ui_widget_freed_on(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*), void *ptr);
void rpg_ui_widget_static_on(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*), void *ptr);
void rpg_ui_widget_add_event_handler(rpg_ui_widget_t *self,
    const char *event_name, const rpg_ui_event_handler_desc_t *desc);
void rpg_ui_widget_off(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*));
bool rpg_ui_widget_fire(rpg_ui_widget_t *self, const rpg_ui_event_t *event);

#endif /* RPG_UI_WIDGET_H */
