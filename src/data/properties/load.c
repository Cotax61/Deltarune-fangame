/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Properties loader
*/

#include "my/my.h"
#include "my/io.h"
#include "my/cstr.h"
#include "my/fmt.h"
#include "my/collections/hash_map.h"
#include "rpg/data.h"

static char *read_line(bufreader_t *reader)
{
    char buffer[128] = {0};
    char *line = NULL;
    char *line_tmp = NULL;
    usize_t buffer_i = 0;

    while (!reader->ended && bufreader_peekchar(reader) != '\n') {
        buffer[buffer_i++] = bufreader_getchar(reader);
        if (buffer_i == 128) {
            line_tmp = line;
            line = my_format("%s%.*s", line ? line : "", buffer_i, buffer);
            my_free(line_tmp);
            buffer_i = 0;
        }
    }
    if (bufreader_getchar(reader) == '\n' || buffer_i != 0) {
        line_tmp = line;
        line = my_format("%s%.*s", line ? line : "", buffer_i, buffer);
        my_free(line_tmp);
    }
    return (line);
}

static char *trim_whitespace(char *str)
{
    char *trimmed = NULL;
    usize_t start = 0;
    usize_t end = str ? my_cstrlen(str) : 0;

    if (str == NULL)
        return (NULL);
    while (str[start] && my_cstrchr("\t ", str[start]))
        start++;
    while (end > start + 1 && my_cstrchr("\t ", str[end - 1]))
        end--;
    if (end == start + 1) {
        my_free(str);
        return (my_cstrdup(""));
    }
    trimmed = my_cstrndup(&str[start], end - start);
    my_free(str);
    return (trimmed);
}

static void process_line(rpg_props_t *props, const char *line)
{
    const char *eq = my_cstrchr(line, '=');
    char *key = NULL;
    char *value = NULL;

    (void)(props);
    if (eq == NULL)
        return;
    key = trim_whitespace(my_cstrndup(line, eq - line));
    value = trim_whitespace(my_cstrdup(eq + 1));
    hash_map_insert(props, key, value);
    my_free(key);
}

rpg_props_t *rpg_props_load(const char *path)
{
    rpg_props_t *props = hash_map_new();
    bufreader_t *reader = filereader_open(path, 1024);
    char *line = trim_whitespace(read_line(reader));

    if (props == NULL || reader == NULL) {
        rpg_props_destroy(props);
        if (reader)
            bufreader_free(reader);
        return (NULL);
    }
    while (line) {
        if (my_cstrlen(line) > 0 && line[0] != '#')
            process_line(props, line);
        my_free(line);
        line = trim_whitespace(read_line(reader));
    }
    bufreader_free(reader);
    return (props);
}
