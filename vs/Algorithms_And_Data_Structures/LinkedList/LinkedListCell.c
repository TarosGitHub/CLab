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
	cell->value = (char*)malloc(value_type_size);

	if (NULL == cell->value) {
		free(cell);
		return NULL;
	}

	memcpy(cell->value, value, value_type_size);

	return cell;
}

void LinkedListCell_destroy(struct LinkedListCell* cell)
{
	free(cell->value);
	free(cell);
}
