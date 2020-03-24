/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Input component implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "my/collections/hash_map.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/components.h"

static void parse_subevents(input_comp_t *self, va_list ap, u8_t evt_number)
{
    rpg_input_handler_t *handler = NULL;
    const char *name = NULL;

    for (usize_t i = 0; i < evt_number; i++) {
        handler = my_calloc(1, sizeof(rpg_input_handler_t));
        name = va_arg(ap, const char*);
        handler->callback = va_arg(ap, void (*)(gt_world_t*, sfEvent*, void*));
        handler->ptr = va_arg(ap, void*);
        handler->destroy_ptr = va_arg(ap, void (*)(void*));
        hash_map_insert(self->listeners, name, handler);
    }
}

static OPT(i32) destroy_handler_callback(void *ptr, hash_map_pair_t *pair)
{
    rpg_input_handler_t *handler = pair->value;

    (void)(ptr);
    if (handler->destroy_ptr)
        handler->destroy_ptr(handler->ptr);
    my_free(handler);
    return (NONE(i32));
}

static void destroyer(input_comp_t *self)
{
    hash_map_destroy_with(self->listeners, &destroy_handler_callback, NULL);
    my_free(self);
}

input_comp_t *input_component(usize_t events_number, ...)
{
    input_comp_t *self = my_calloc(1, sizeof(input_comp_t));
    va_list ap;

    self->listeners = hash_map_new();
    va_start(ap, events_number);
    parse_subevents(self, ap, events_number);
    va_end(ap);
    return (self);
}

const gt_component_class_t INPUT_COMP = {
    .name = "input_component",
    .destroyer = (void (*)(void*)) &destroyer,
};
