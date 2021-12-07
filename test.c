#include "list.h"
#include <stdio.h>
int main() {
	list_t* my_list = create_list(1);
	list_push(my_list, "Hello");
	list_push(my_list, ", ");
	list_push(my_list, "World");
	puts(display_list(my_list));
}
