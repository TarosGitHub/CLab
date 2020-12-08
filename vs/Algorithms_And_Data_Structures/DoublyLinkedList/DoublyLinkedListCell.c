/**
 * Note: This code uses malloc and free functions.
 */

#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedListCell.h"

struct DoublyLinkedListCell* DoublyLinkedListCell_create(struct DoublyLinkedListCell* prev, struct DoublyLinkedListCell* next, void* value, unsigned int value_type_size)
{
	struct DoublyLinkedListCell* cell;

	cell = (struct DoublyLinkedListCell*)malloc(sizeof(struct DoublyLinkedListCell));

	if (NULL == cell) {
		return NULL;
	}

	cell->prev = prev;
	cell->next = next;
	cell->value_type_size = value_type_size;
	cell->value = (char*)malloc(cell->value_type_size);

	if (NULL == cell->value) {
		free(cell);
		return NULL;
	}

	memcpy(cell->value, value, cell->value_type_size);

	return cell;
}

void DoublyLinkedListCell_destroy(struct DoublyLinkedListCell* cell)
{
	free(cell->value);
	free(cell);
}

enum Boolean DoublyLinkedListCell_has_prev(struct DoublyLinkedListCell* cell)
{
	return NULL != cell->prev ? TRUE : FALSE;
}

enum Boolean DoublyLinkedListCell_has_next(struct DoublyLinkedListCell* cell)
{
	return NULL != cell->next ? TRUE : FALSE;
}

struct DoublyLinkedListCell* DoublyLinkedListCell_get_prev(struct DoublyLinkedListCell* cell)
{
	return cell->prev;
}

struct DoublyLinkedListCell* DoublyLinkedListCell_get_next(struct DoublyLinkedListCell* cell)
{
	return cell->next;
}

void DoublyLinkedListCell_set_prev(struct DoublyLinkedListCell* cell, struct DoublyLinkedListCell* prev)
{
	cell->prev = prev;
}

void DoublyLinkedListCell_set_next(struct DoublyLinkedListCell* cell, struct DoublyLinkedListCell* next)
{
	cell->next = next;
}

void DoublyLinkedListCell_get(struct DoublyLinkedListCell* cell, void* value)
{
	memcpy(value, cell->value, cell->value_type_size);
}

void DoublyLinkedListCell_set(struct DoublyLinkedListCell* cell, void* value)
{
	memcpy(cell->value, value, cell->value_type_size);
}
