#ifndef LIST_H
#include <stddef.h>
#ifndef LIST_TYPE
#define LIST_TYPE char* 
#endif
struct list_t {
	LIST_TYPE*    elements;
	size_t    size;
	size_t 	  used;
};

struct list_t* create_list(size_t list_size);
void   list_push(struct list_t* list, LIST_TYPE element);
char*  display_list(struct list_t* list);
int list_set(struct list_t* list, size_t at, LIST_TYPE element);
void list_resize(struct list_t* list, size_t to);
void list_free(struct list_t* list);
LIST_TYPE list_get(struct list_t* list, size_t element);

typedef struct list_t list_t;
#define LIST_H
#endif
