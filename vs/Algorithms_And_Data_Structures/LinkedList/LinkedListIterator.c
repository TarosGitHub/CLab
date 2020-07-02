#include <stddef.h>
#include "LinkedListIterator.h"

enum Boolean LinkedListIterator_has_next(struct LinkedListIterator* iterator)
{
	return NULL != iterator->current->next ? TRUE : FALSE;
}
