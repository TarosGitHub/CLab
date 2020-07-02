#include <stddef.h>
#include "LinkedListIterator.h"

void LinkedListIterator_init(struct LinkedListIterator* iterator, struct LinkedListCell* current)
{
	iterator->current = current;
}

enum Boolean LinkedListIterator_has_next(struct LinkedListIterator* iterator)
{
	return LinkedListCell_has_next(iterator->current);
}

void LinkedListIterator_next(struct LinkedListIterator* iterator)
{
	iterator->current = LinkedListCell_get_next(iterator->current);
}
