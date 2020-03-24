/*
** EPITECH PROJECT, 2020
** libgote_demo
** File description:
** Window system implementation
*/

#include <SFML/Graphics.h>
#include "my/my.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/systems.h"
#include "rpg/components.h"

struct win_sys {
    char *title;
    rpg_rect_t win_rect;
    sfRenderWindow *win;
    gt_event_channel_t *sfml_channel;
};

static bool sys_setup(void *self_raw, gt_world_t *world)
{
    struct win_sys *self = self_raw;
    sfVideoMode mode = {0, 0, 32};

    mode.width = self->win_rect.width;
    mode.height = self->win_rect.height;
    self->sfml_channel = gt_event_channel_create(sizeof(sfEvent));
    self->win = sfRenderWindow_create(mode, self->title, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(self->win, 60);
    gt_world_insert(world, "window", self->win, NULL);
    gt_world_insert(world, "sfml_channel", self->sfml_channel, NULL);
    gt_world_insert(world, "window_rect", &self->win_rect, NULL);
    return (false);
}

static bool sys_run(void *ptr, gt_world_t *world)
{
    struct win_sys *self = ptr;
    sfView *view = NULL;
    sfFloatRect rect = {0};
    sfEvent e;

    (void)(world);
    sfRenderWindow_display(self->win);
    while (sfRenderWindow_pollEvent(self->win, &e)) {
        gt_event_channel_push(self->sfml_channel, &e);
        if (e.type == sfEvtResized) {
            rect = (sfFloatRect) {0, 0, e.size.width, e.size.height};
            view = sfView_createFromRect(rect);
            sfRenderWindow_setView(self->win, view);
            sfView_destroy(view);
            self->win_rect.width = e.size.width;
            self->win_rect.height = e.size.height;
        }
    }
    return (false);
}

static bool sys_dispose(void *ptr, gt_world_t *world)
{
    struct win_sys *self = ptr;

    my_free(self->title);
    sfRenderWindow_destroy(self->win);
    gt_event_channel_destroy(self->sfml_channel);
    gt_world_remove(world, "window");
    gt_world_remove(world, "sfml_channel");
    gt_world_remove(world, "window_rect");
    return (false);
}

gt_system_t *rpg_window_system(const char *title, u64_t width, u64_t height)
{
    gt_system_t *sys = my_calloc(1, sizeof(gt_system_t));
    struct win_sys *self = my_calloc(1, sizeof(struct win_sys));

    self->title = my_cstrdup(title);
    self->win_rect = RECT(0, 0, width, height);
    sys->self = self;
    sys->destroy = &my_free;
    sys->setup = &sys_setup;
    sys->run = &sys_run;
    sys->dispose = &sys_dispose;
    return (sys);
}
