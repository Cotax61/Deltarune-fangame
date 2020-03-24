/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** render_queue_flush implementation
*/

#include "my/my.h"
#include "rpg/render_queue.h"

void render_queue_flush(render_queue_t *self, bool ascending)
{
    if (ascending)
        for (usize_t i = self->len; i > 0; i--)
            self->queue[i - 1].run(self->queue[i - 1].ptr);
    else
        for (usize_t i = 0; i < self->len; i++)
            self->queue[i].run(self->queue[i].ptr);
    self->len = 0;
}
