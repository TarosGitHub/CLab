/**
 * Note:
 * This code use malloc and free functions.
 */

#include <stdlib.h>
#include "LinkedList.h"

struct LinkedList* LinkedList_create(unsigned int value_type_size)
{
	struct LinkedList* list;

	list = (struct LinkedList*)malloc(sizeof(struct LinkedList));

	if (NULL == list) {
		return NULL;
	}

	list->head = LinkedListCell_create(NULL, NULL, 0U);

	if (NULL == list->head) {
		free(list);
		return NULL;
	}

	list->value_type_size = value_type_size;
	list->size = 0U;

	return list;
}

void LinkedList_destroy(struct LinkedList* list)
{
	LinkedList_delete_all(list);
	LinkedListCell_destroy(list->head);
	free(list);
}

void LinkedList_delete_all(struct LinkedList* list)
{
	struct LinkedListCell* deleted_cell;
	for (deleted_cell = LinkedListCell_get_next(list->head); NULL != deleted_cell; deleted_cell = LinkedListCell_get_next(list->head)) {
		LinkedListCell_set_next(list->head, LinkedListCell_get_next(deleted_cell));
		free(deleted_cell);
	}

	list->size = 0U;
}

void LinkedList_begin(struct LinkedList* list, struct LinkedListIterator* iterator)
{
	LinkedListIterator_init(iterator, list->head);
}

#if 0
enum LinkedListStatus LinkedList_add(struct LinkedList* list, void* value)
{
	struct LinkedListCell* cell;

	cell = LinkedListCell_create(NULL, value, list->value_type_size);

	if (NULL == cell) {
		return LINKED_LIST_FAILURE;
	}

	list->tail->next = cell;
	list->tail = cell;
	list->size++;

	return LINKED_LIST_SUCCESS;
}

void LinkedList_remove(struct LinkedList* list)
{
	//TODO
}
#endif