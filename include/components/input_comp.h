/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** input_comp
*/

#ifndef INPUT_COMP_H
#define INPUT_COMP_H

#include <SFML/Graphics.h>
#include "my/collections/hash_map.h"
#include "gote/gote.h"

extern const gt_component_class_t INPUT_COMP;

typedef struct {
    void (*callback)(gt_world_t*, sfEvent*, void*);
    void (*destroy_ptr)(void*);
    void *ptr;
} rpg_input_handler_t;

typedef struct {
    hash_map_t *listeners;
} input_comp_t;

input_comp_t *input_component(usize_t events_number, ...);

#endif /* !INPUT_COMP_H */
