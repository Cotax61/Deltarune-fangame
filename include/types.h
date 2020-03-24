/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Data structures and types used by the game.
*/

#ifndef RPG_TYPES_H
#define RPG_TYPES_H

#include "my/types.h"

#define VEC2(x, y) ((rpg_vec2_t) {x, y})
#define VEC3(x, y, z) ((rpg_vec3_t) {x, y, z})
#define VEC4(x, y, z, w) ((rpg_vec4_t) {x, y, z, w})
#define RECT(x, y, w, h) ((rpg_rect_t) {x, y, w, h})
#define BOUNDS(l, t, r, b) ((rpg_bounds_t) {l, t, r, b})
#define RECT2BOUNDS(r) \
    BOUNDS((r).x, (r).y, (r).x + (r).width, (r).y + (r).height)
#define BOUNDS2RECT(b) \
    RECT((b).left, (b).top, (b).right - (b).left, (b).bottom - (b).top)

typedef struct {
    f64_t x;
    f64_t y;
} rpg_vec2_t;

typedef struct {
    f64_t x;
    f64_t y;
    f64_t z;
} rpg_vec3_t;

typedef struct {
    f64_t x;
    f64_t y;
    f64_t z;
    f64_t w;
} rpg_vec4_t;

typedef struct {
    f64_t x;
    f64_t y;
    f64_t width;
    f64_t height;
} rpg_rect_t;

typedef struct {
    f64_t left;
    f64_t top;
    f64_t right;
    f64_t bottom;
} rpg_bounds_t;

typedef enum {
    RPG_BUTTON_LEFT,
    RPG_BUTTON_RIGHT,
    RPG_BUTTON_MIDDLE,
    RPG_BUTTON_BACK,
    RPG_BUTTON_FORWARD,
} rpg_button_t;

typedef enum {
    RPG_RELEASED,
    RPG_PRESSED,
    RPG_MOVED,
} rpg_button_action_t;

typedef enum {
    RPG_LEFT,
    RPG_CENTER,
    RPG_RIGHT,
} rpg_halign_t;

typedef enum {
    RPG_TOP,
    RPG_MIDDLE,
    RPG_BOTTOM,
    RPG_BASELINE,
} rpg_valign_t;

#endif /* RPG_TYPES_H */
