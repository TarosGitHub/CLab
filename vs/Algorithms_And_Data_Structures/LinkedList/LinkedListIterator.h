#if !defined(LINKEDLISTITERATOR_H)
#define LINKEDLISTITERATOR_H

#include "Common.h"
#include "LinkedListCell.h"

/**
 * Linked list iterator structure.
 */
struct LinkedListIterator {
	struct LinkedListCell* current; /**< The pointer to the current cell element. */
	struct LinkedListCell* previous; /**< The pointer to the previous of the current cell element. */
};

/**
 * Create a linked list iterator.
 * @see Test_LinkedListIterator_new
 * @param current The pointer to the current cell element.
 * @param previous The pointer to the previous of the current cell element.
 * @return Return a linked list iterator object.
 */
#define LinkedListIterator_new(current, previous) {(current), (previous)}

/**
 * Initialize the linked list iterator.
 * @see Test_LinkedListIterator_init
 * @param iterator The pointer to the linked list iterator.
 * @param current The pointer to the current cell element.
 * @param previous The pointer to the previous of the current cell element.
 */
extern void LinkedListIterator_init(struct LinkedListIterator* iterator, struct LinkedListCell* current, struct LinkedListCell* previous);

/**
 * Judge if the iterator has the next pointer or not.
 * @see Test_LinkedListIterator_has_next
 * @param iterator The pointer to the linked list iterator.
 * @return Return true if the iterator has the next pointer, otherwise return false.
 */
extern enum Boolean LinkedListIterator_has_next(struct LinkedListIterator* iterator);

/**
 * Move to the next cell element.
 * If this function is called while pointing to the end of the list, the iterator points to invalid.
 * To avoid that, check if the next cell exists. Or if that happens, initialize it. 
 * @see LinkedListIterator_has_next
 * @see LinkedListIterator_init
 * @see Test_LinkedListIterator_next
 * @param iterator The pointer to the linked list iterator.
 */
extern void LinkedListIterator_next(struct LinkedListIterator* iterator);

#endif /* LINKEDLISTITERATOR_H */
