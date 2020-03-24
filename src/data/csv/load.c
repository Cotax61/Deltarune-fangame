/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** CSV load implementation
*/

#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "rpg/data/csv.h"

static const usize_t VALUE_BUFFER_SIZE = 64;

struct i64_buffer {
    usize_t len;
    usize_t cap;
    i64_t *data;
};

static i64_t read_num(bufreader_t *reader)
{
    char c = '\0';
    char digits[256] = {0};

    for (usize_t i = 0; i < 255 && !reader->ended; i++) {
        c = bufreader_peekchar(reader);
        if (!my_cstrchr("-0123456789", c))
            break;
        digits[i] = c;
        bufreader_getchar(reader);
    }
    return (my_cstr_getnbr(digits));
}

static void flush_into(struct i64_buffer *dest, struct i64_buffer *src)
{
    i64_t *data = my_calloc(dest->len + src->len, sizeof(i64_t));

    if (src->len == 0)
        return;
    if (dest->len > 0)
        my_memcpy(data, dest->data, dest->len * sizeof(i64_t));
    my_memcpy(&data[dest->len], src->data, src->len * sizeof(i64_t));
    my_free(dest->data);
    dest->data = data;
    dest->len += src->len;
    dest->cap = dest->len + src->len;
    src->len = 0;
}

rpg_csv_t *rpg_csv_load(const char *path)
{
    rpg_csv_t *self = my_calloc(1, sizeof(rpg_csv_t));
    struct i64_buffer data = {0};
    struct i64_buffer buffer = {0, VALUE_BUFFER_SIZE,
        my_calloc(VALUE_BUFFER_SIZE, sizeof(i64_t))};
    bufreader_t *reader = filereader_open(path, 1024);

    while (!reader->ended) {
        if (self->height == 0)
            self->width++;
        buffer.data[buffer.len++] = read_num(reader);
        if (buffer.len >= buffer.cap)
            flush_into(&data, &buffer);
        if (bufreader_getchar(reader) == '\n')
            self->height++;
    }
    flush_into(&data, &buffer);
    bufreader_free(reader);
    my_free(buffer.data);
    self->data = data.data;
    return (self);
}
