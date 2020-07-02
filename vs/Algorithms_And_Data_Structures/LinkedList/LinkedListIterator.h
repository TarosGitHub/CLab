#if !defined(LINKEDLISTITERATOR_H)
#define LINKEDLISTITERATOR_H

struct LinkedListCell;

/**
 * Linked list iterator structure.
 */
struct LinkedListIterator {
	struct LinkedListCell* current; /**< The pointer to the current cell element. */
	struct LinkedListCell* previous; /**< The pointer to the previous of the current cell element. */
};

#endif /* LINKEDLISTITERATOR_H */
