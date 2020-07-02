/**
 * Note:
 * This code use malloc and free functions.
 */

#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

struct LinkedListCell* LinkedListCell_create(struct LinkedListCell* next, void* value, unsigned int value_type_size)
{
	struct LinkedListCell* cell;

	cell = malloc(sizeof(struct LinkedListCell));

	if (NULL == cell) {
		return NULL;
	}

	cell->next = next;
	cell->value = (char*)malloc(value_type_size);

	if (NULL == cell->value) {
		free(cell);
		return NULL;
	}

	memcpy(cell->value, value, value_type_size);

	return cell;
}

struct LinkedList* LinkedList_create(unsigned int value_type_size)
{
	struct LinkedList* list;

	list = malloc(sizeof(struct LinkedList));

	if (NULL == list) {
		return NULL;
	}

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
	struct LinkedListCell* deleted_cell;
	for (deleted_cell = list->head.next; NULL != deleted_cell; deleted_cell = list->head.next) {
		list->head.next = deleted_cell->next;
		free(deleted_cell);
	}

	list->tail = &list->head;
	list->size = 0U;
}

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
