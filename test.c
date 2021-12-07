#include "list.h"
#include <stdio.h>
int main()
{
    list_t *my_list = create_list(1);
    list_push(my_list, "Hello");
    list_push(my_list, ", ");
    list_push(my_list, "uwu");
    list_push(my_list, "Nothing");
    list_set(my_list, 2, "World");
    list_resize(my_list, 3);
    puts(display_list(my_list));
    for (size_t i = 0; i < 10000; ++i)
        list_push(my_list, (char *)i);
    list_free(my_list);
}
