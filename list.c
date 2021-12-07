#include "list.h"
#include <stdlib.h>
#include <string.h>
list_t *create_list(size_t list_size)
{
    list_t *list = malloc(sizeof(list_t));
    list->elements = calloc(sizeof(LIST_TYPE), list_size);
    list->used = 0;
    list->size = list_size;
    return list;
}
void list_relloc(list_t *list)
{
    if (list->used >= list->size)
    {
        list->size += 10;
        list->elements = reallocarray(list->elements, sizeof(LIST_TYPE), list->size);
    }
}
void list_push(list_t *list, LIST_TYPE element)
{
    list_relloc(list);
    list->elements[list->used <= 0 ? 0 : list->used] = element;
    list->used++;

    list_relloc(list);
}
LIST_TYPE list_get(list_t *list, size_t element)
{
    if (list->size > element)
    {
        return list->elements[element];
    }
    return NULL;
}
int list_set(list_t *list, size_t at, LIST_TYPE element)
{
    if (list->size >= at)
    {
        list->elements[at] = element;
        return 1;
    }
    else
    {
        return 0;
    }
}
void list_resize(list_t *list, size_t to)
{
    list->size = to;
    list->elements = reallocarray(list->elements, sizeof(LIST_TYPE), to);
}
void list_free(list_t *list)
{
    free(list->elements);
    free(list);
}
char *display_list(list_t *list)
{
    if (list->used == 0)
    {
        return "[]";
    }
    char *buf = malloc(3);
    strcpy(buf, "");
    strcat(buf, "[ ");
    for (size_t i = 0; i < list->used; ++i)
    {
        LIST_TYPE element = list_get(list, i);
        char *s = (char *)element;
        if (element == NULL)
            continue;
        if (s != NULL)
        {
            buf = realloc(buf, strlen(buf) + sizeof(element));
            strcat(buf, s);
            buf = realloc(buf, strlen(buf) + sizeof(char));
            strcat(buf, " ");
        }
    }
    strcat(buf, "]");
    return buf;
}
