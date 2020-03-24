/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rpg_ui_widget_destroy implementation
*/

#include "my/my.h"
#include "my/collections/hash_map.h"
#include "my/collections/list.h"
#include "gote/gote.h"
#include "rpg/ui.h"

static OPT(i32) destroy_handler_callback(void *ptr, hash_map_pair_t *pair)
{
    rpg_ui_event_handler_desc_t *handler = NULL;

    (void)(ptr);
    LIST_FOR_EACH(pair->value, iter) {
        handler = iter.v;
        if (handler->destroy)
            handler->destroy(handler->ptr);
        my_free(handler);
    }
    list_destroy(pair->value);
    return (NONE(i32));
}

void rpg_ui_widget_destroy(rpg_ui_widget_t *self)
{
    rpg_ui_event_t event = {.widget = self, .name = "destroy"};

    rpg_ui_widget_fire(self, &event);
    if (self->parent)
        rpg_ui_widget_remove(self->parent, self);
    while (self->children->len > 0)
        rpg_ui_widget_destroy(list_pop_front(self->children).v);
    if (self->priv.init) {
        gt_event_channel_unsub(self->priv.event_chan, self->priv.event_chan_id);
        gt_world_remove_entity(self->priv.world, self->priv.entity);
    }
    hash_map_destroy_with(self->listeners, &destroy_handler_callback, NULL);
    list_destroy(self->children);
    if (self->font)
        gt_handle_drop(self->font);
    my_free(self->text);
    my_free(self);
}
