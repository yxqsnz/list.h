#include <stdbool.h>
#include <string.h>
#include <malloc.h>
typedef char* string_t;

struct amugus_t 
{
	bool is_sus;
	string_t name;
};
typedef struct amugus_t amugus_t;
#define LIST_TYPE amugus_t*
#include "../list.h"
#include <stdio.h>
amugus_t* new_amugus(string_t name, bool is_sus)
{
	amugus_t *sus = malloc(sizeof(amugus_t));
	sus->is_sus = is_sus;
	sus->name = name;
	return sus;
}
int main() {
	list_t* my_list = create_list(4);
	list_push(my_list, new_amugus("AMUGUS", false));
	list_push(my_list, new_amugus("Pietro", true));
	list_push(my_list, new_amugus("yxqsnz", false));
	list_push(my_list, new_amugus("sexo.", false));
	list_foreach(amugus_t* sus, my_list)
	{
		printf("AMUGUS? %s %d\n", sus->name, sus->is_sus);
	}
	list_free(my_list);
}

