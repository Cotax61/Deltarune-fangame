/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rpg_ui_widget_add_event_handler and related functions
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_map.h"
#include "gote/gote.h"
#include "rpg/ui.h"

void rpg_ui_widget_on(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*))
{
    rpg_ui_widget_static_on(self, event_name, handler, NULL);
}

void rpg_ui_widget_freed_on(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*), void *ptr)
{
    rpg_ui_event_handler_desc_t desc;

    desc.handler = handler;
    desc.destroy = &my_free;
    desc.ptr = ptr;
    rpg_ui_widget_add_event_handler(self, event_name, &desc);
}

void rpg_ui_widget_static_on(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*), void *ptr)
{
    rpg_ui_event_handler_desc_t desc;

    desc.handler = handler;
    desc.destroy = NULL;
    desc.ptr = ptr;
    rpg_ui_widget_add_event_handler(self, event_name, &desc);
}

void rpg_ui_widget_add_event_handler(rpg_ui_widget_t *self,
    const char *event_name, const rpg_ui_event_handler_desc_t *desc)
{
    rpg_ui_event_handler_desc_t *holder =
        my_malloc(sizeof(rpg_ui_event_handler_desc_t));
    list_t *handlers = hash_map_get(self->listeners, event_name).v;

    if (holder == NULL)
        return;
    my_memcpy(holder, desc, sizeof(rpg_ui_event_handler_desc_t));
    if (handlers == NULL) {
        handlers = list_new();
        hash_map_insert(self->listeners, event_name, handlers);
    }
    list_push_back(handlers, holder);
}
