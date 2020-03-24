/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** render_queue_create and render_queue_destroy implementation
*/

#include "my/my.h"
#include "rpg/render_queue.h"

render_queue_t *render_queue_create(void)
{
    render_queue_t *self = my_malloc(sizeof(render_queue_t));

    if (self == NULL)
        return (NULL);
    self->len = 0;
    self->capacity = 32;
    self->queue = my_calloc(self->capacity, sizeof(render_op_t));
    if (self->queue == NULL) {
        my_free(self);
        return (NULL);
    }
    return (self);
}

void render_queue_destroy(render_queue_t *self)
{
    if (self == NULL)
        return;
    else if (self->len)
        render_queue_flush(self, false);
    my_free(self->queue);
    my_free(self);
}
