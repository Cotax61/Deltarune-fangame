/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Title screen state
*/

#include <SFML/Audio.h>
#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "gote/gote.h"
#include "rpg/types.h"
#include "rpg/formats.h"
#include "rpg/states.h"
#include "rpg/ui.h"
#include "priv.h"

static const char *FONT_PATH = "./res/fonts/dev_font.ttf";

struct title_state {
    gt_entity_t *canvas;
    sfMusic *menu_music;
    sfSound *beep_sound;
};

static void on_start(void *ptr, gt_world_t *data)
{
    gt_handle_t font = gt_load(FONT_PATH, &RPG_FONT_FORMAT,
        data);
    struct title_state *self = ptr;
    self->beep_sound = sfSound_create();
    sfSound_setBuffer(self->beep_sound, 
        sfSoundBuffer_createFromFile("./res/audio/ui_bleep.wav"));
    rpg_ui_widget_t *ui_root = rpg_title_create_ui(data, self->beep_sound);
    
    self->menu_music = sfMusic_createFromFile("./res/audio/mus_menu.ogg");
    //sfMusic_setLoop(self->menu_music, sfTrue);
    //sfMusic_setVolume(self->menu_music, 30.0F);
    //sfMusic_play(self->menu_music);
    ui_root->font = font;
    ui_root->background = 0x0;
    self->canvas = rpg_ui_canvas_create(data, ui_root, 1000.0);
}

static void on_stop(void *ptr, gt_world_t *data)
{
    struct title_state *self = ptr;

    (void)(data);
    sfMusic_destroy(self->menu_music);
    sfSound_destroy(self->beep_sound);
    gt_world_remove_entity(data, self->canvas);
}

gt_state_t *rpg_title_state(void)
{
    gt_state_t *self = my_calloc(1, sizeof(gt_state_t));

    self->self = my_calloc(1, sizeof(struct title_state));
    self->on_start = &on_start;
    self->on_stop = &on_stop;
    self->destroy = &my_free;
    return (self);
}
