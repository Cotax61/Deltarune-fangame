/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Widget event related methods implementation
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_map.h"
#include "gote/gote.h"
#include "rpg/ui.h"

static bool holder_cmp_iter(void *ptr, void *element_ptr)
{
    rpg_ui_event_handler_desc_t *ref = ptr;
    rpg_ui_event_handler_desc_t *this = element_ptr;

    return (ref->handler == this->handler);
}

void rpg_ui_widget_off(rpg_ui_widget_t *self, const char *event_name,
    bool (*handler)(const rpg_ui_event_t*, void*))
{
    list_t *handlers = hash_map_get(self->listeners, event_name).v;
    rpg_ui_event_handler_desc_t holder_ref;
    rpg_ui_event_handler_desc_t *holder = NULL;

    if (handlers == NULL)
        return;
    holder_ref.handler = handler;
    holder = list_remove_element(handlers, &holder_ref, &holder_cmp_iter).v;
    if (holder == NULL)
        return;
    if (holder->destroy)
        holder->destroy(holder->ptr);
    my_free(holder);
}

bool rpg_ui_widget_fire(rpg_ui_widget_t *self, const rpg_ui_event_t *event)
{
    bool ret = false;
    list_t *handlers = hash_map_get(self->listeners, event->name).v;
    rpg_ui_event_handler_desc_t *holder = NULL;

    if (handlers == NULL)
        return (false);
    LIST_FOR_EACH(handlers, iter) {
        holder = iter.v;
        ret |= holder->handler(event, holder->ptr);
    }
    return (ret);
}
