/**
 * Note:
 * This code use malloc and free functions.
 */

#include <stdlib.h>
#include <string.h>
#include "LinkedListCell.h"

struct LinkedListCell* LinkedListCell_create(struct LinkedListCell* next, void* value, unsigned int value_type_size)
{
	struct LinkedListCell* cell;

	cell = (struct LinkedListCell*)malloc(sizeof(struct LinkedListCell));

	if (NULL == cell) {
		return NULL;
	}

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

void LinkedListCell_destroy(struct LinkedListCell* cell)
{
	free(cell->value);
	free(cell);
}

enum Boolean LinkedListCell_has_next(struct LinkedListCell* cell)
{
	return NULL != cell->next ? TRUE : FALSE;
}

struct LinkedListCell* LinkedListCell_get_next(struct LinkedListCell* cell)
{
	return cell->next;
}

void LinkedListCell_set_next(struct LinkedListCell* cell, struct LinkedListCell* next)
{
	cell->next = next;
}

void LinkedListCell_get(struct LinkedListCell* cell, void* value)
{
	memcpy(value, cell->value, cell->value_type_size);
}

void LinkedListCell_set(struct LinkedListCell* cell, void* value)
{
	memcpy(cell->value, value, cell->value_type_size);
}
