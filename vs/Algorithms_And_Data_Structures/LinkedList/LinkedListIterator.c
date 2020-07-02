#include <stddef.h>
#include "LinkedListIterator.h"

void LinkedListIterator_init(struct LinkedListIterator* iterator, struct LinkedListCell* current, struct LinkedListCell* previous)
{
	iterator->current = current;
	iterator->previous = previous;
}

enum Boolean LinkedListIterator_has_next(struct LinkedListIterator* iterator)
{
	return LinkedListCell_has_next(iterator->current);
}
