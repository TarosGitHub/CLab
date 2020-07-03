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

enum LinkedListStatus LinkedList_insert(struct LinkedList* list, struct LinkedListIterator* iterator, void* value)
{
	struct LinkedListCell* new_cell = LinkedListCell_create(NULL, value, list->value_type_size);

	if (NULL == new_cell) {
		return LINKED_LIST_FAILURE;
	}

	struct LinkedListCell* current_cell = LinkedListIterator_get_cell(iterator);
	struct LinkedListCell* next_cell = LinkedListCell_get_next(current_cell);

	LinkedListCell_set_next(new_cell, next_cell);
	LinkedListCell_set_next(current_cell, new_cell);
	list->size++;

	return LINKED_LIST_SUCCESS;
}

enum LinkedListStatus LinkedList_remove(struct LinkedList* list, struct LinkedListIterator* iterator, void* value)
{
	struct LinkedListCell* current_cell = LinkedListIterator_get_cell(iterator);
	struct LinkedListCell* removed_cell = LinkedListCell_get_next(current_cell);

	if (NULL == removed_cell) {
		return LINKED_LIST_FAILURE;
	}

	struct LinkedListCell* next_cell = LinkedListCell_get_next(removed_cell);

	LinkedListCell_set_next(current_cell, next_cell);
	list->size--;

	if (NULL != value) {
		LinkedListCell_get(removed_cell, value);
	}

	LinkedListCell_destroy(removed_cell);

	return LINKED_LIST_SUCCESS;
}
