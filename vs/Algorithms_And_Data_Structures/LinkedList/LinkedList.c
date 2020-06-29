/**
 * Note:
 * This code use malloc and free functions.
 */

#include <stdlib.h>
#include "LinkedList.h"

struct LinkedList* LinkedList_create(unsigned int value_type_size)
{
	struct LinkedList* list;

	list = malloc(sizeof(struct LinkedList));

	list->value_type_size = value_type_size;
	list->head.next = NULL;
	list->head.value = NULL;
	list->tail = &list->head;
	list->size = 0U;

	return list;
}

void LinkedList_destroy(struct LinkedList* list)
{
	LinkedList_delete_all(list);
	free(list);
}

void LinkedList_delete_all(struct LinkedList* list)
{
	struct Cell* deleted_cell;
	for (deleted_cell = list->head.next; NULL != deleted_cell; deleted_cell = list->head.next) {
		list->head.next = deleted_cell->next;
		free(deleted_cell);
	}

	list->tail = &list->head;
	list->size = 0U;
}

