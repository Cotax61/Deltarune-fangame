/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** RenderQueue class declaration
*/

#ifndef RPG_RENDER_QUEUE_H
#define RPG_RENDER_QUEUE_H

//! \file include/render_queue.h

#include "my/my.h"
#include "my/collections/list.h"

typedef struct {
    f64_t depth;
    void (*run)(void*);
    void *ptr;
} render_op_t;

//! \brief A queue of drawing operations to be performed in a specific order.
typedef struct {
    render_op_t *queue;
    usize_t len;
    usize_t capacity;
} render_queue_t;

//! \brief Create a new render queue.
//! \return A new render queue.
render_queue_t *render_queue_create(void);

//! \brief Destroy a render queue.
//!
//! The queue is flushed if it isn't empty.
//! \param self The render queue to destroy.
void render_queue_destroy(render_queue_t *self);

//! \brief Push a drawing operation in a render queue at a given depth.
//! \param self The render queue.
//! \param depth The depth of the drawing operation.
//! \param run The function that actually draws the stuff (and frees \c ptr).
//! \param ptr An arbitrary pointer passed to \c draw.
//! \return \c true if an error occured, \c false otherwise.
bool render_queue_push(render_queue_t *self, f64_t depth, void (*run)(void*),
    void *ptr);

//! \brief Runs all drawing operations of a render queue, clearing it.
//! \param self The render queue.
//! \param ascending When \c true, draw elements with a smaller depth first.
void render_queue_flush(render_queue_t *self, bool ascending);

#endif /* RPG_RENDER_QUEUE_H */
