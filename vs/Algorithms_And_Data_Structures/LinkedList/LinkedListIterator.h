#if !defined(LINKEDLISTITERATOR_H)
#define LINKEDLISTITERATOR_H

#include "Common.h"

struct LinkedListCell;

/**
 * Linked list iterator structure.
 */
struct LinkedListIterator {
	struct LinkedListCell* current; /**< The pointer to the current cell element. */
	struct LinkedListCell* previous; /**< The pointer to the previous of the current cell element. */
};

extern enum Boolean LinkedListIterator_has_next(struct LinkedListIterator* iterator);

#endif /* LINKEDLISTITERATOR_H */
