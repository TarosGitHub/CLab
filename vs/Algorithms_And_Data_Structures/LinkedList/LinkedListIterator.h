#if !defined(LINKEDLISTITERATOR_H)
#define LINKEDLISTITERATOR_H

#include "Common.h"
#include "LinkedListCell.h"

/**
 * Linked list iterator structure.
 */
struct LinkedListIterator {
	struct LinkedListCell* current; /**< The pointer to the current cell element. */
};

/**
 * Create a linked list iterator.
 * @see Test_LinkedListIterator_new
 * @param current The pointer to the current cell element.
 * @return Return a linked list iterator object.
 */
#define LinkedListIterator_new(current) {(current)}

/**
 * Initialize the linked list iterator.
 * @see Test_LinkedListIterator_init
 * @param iterator The pointer to the linked list iterator.
 * @param current The pointer to the current cell element.
 */
extern void LinkedListIterator_init(struct LinkedListIterator* iterator, struct LinkedListCell* current);

/**
 * Get the cell.
 * @see Test_LinkedListIterator_get_cell
 * @param iterator The pointer to the linked list iterator.
 * @return Return the cell object.
 */
extern struct LinkedListCell* LinkedListIterator_get_cell(struct LinkedListIterator* iterator);

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

/**
 * Get the value from the pointing cell.
 * You must not call this function if the iterator points the head of the list.
 * @see Test_LinkedListIterator_get
 * @param iterator The pointer to the linked list iterator.
 * @param value The getted value. The size of the value type must match the size set at list initialization.
 *              You must not set NULL to this argument.
 */
extern void LinkedListIterator_get(struct LinkedListIterator* iterator, void* value);

/**
 * Set the value to the pointing cell.
 * You must not call this function if the iterator points the head of the list.
 * @see Test_LinkedListIterator_set
 * @param iterator The pointer to the linked list iterator.
 * @param value The value to set. The size of the value type must match the size set at list initialization.
 *              You must not set NULL to this argument.
 */
extern void LinkedListIterator_set(struct LinkedListIterator* iterator, void* value);

#endif /* LINKEDLISTITERATOR_H */
