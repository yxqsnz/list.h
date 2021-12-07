#define  LIST_TYPE int
#include "../list.h"
#include <stdio.h>
int main()
{
    list_t *my_list = create_list(1);
    list_push(my_list, 1);
    list_push(my_list, 2);
    for (int i = 3; i < 30; ++i) 
    	list_push(my_list, i);
    printf("%d\n", list_get(my_list, 20));
    list_free(my_list);
}
