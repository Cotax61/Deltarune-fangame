/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** render_queue_push implementation
*/

#include "my/my.h"
#include "rpg/render_queue.h"

static const usize_t GROW_CHUNK_SIZE = 32;

static bool grow(render_queue_t *self)
{
    usize_t new_capacity = self->capacity + GROW_CHUNK_SIZE;
    render_op_t *new_queue = my_malloc(new_capacity * sizeof(render_op_t));

    if (new_queue == NULL)
        return (true);
    my_memcpy(new_queue, self->queue, self->len * sizeof(render_op_t));
    my_free(self->queue);
    self->queue = new_queue;
    self->capacity = new_capacity;
    return (false);
}

static bool insert(render_queue_t *self, usize_t index, const render_op_t *op)
{
    usize_t moved_count = self->len - index;

    if (self->len >= self->capacity && grow(self))
        return (true);
    self->len++;
    my_memmove(&self->queue[index + 1], &self->queue[index],
        moved_count * sizeof(render_op_t));
    self->queue[index] = *op;
    return (false);
}

bool render_queue_push(render_queue_t *self, f64_t depth, void (*run)(void*),
    void *ptr)
{
    usize_t index = 0;
    render_op_t op;

    op.depth = depth;
    op.run = run;
    op.ptr = ptr;
    while (index < self->len && self->queue[index].depth < depth)
        index++;
    return (insert(self, index, &op));
}
