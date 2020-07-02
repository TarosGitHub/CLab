#if !defined(LINKEDLISTCELL_H)
#define LINKEDLISTCELL_H

#include "Common.h"

/**
 * Linked list cell structure.
 */
struct LinkedListCell {
	struct LinkedListCell* next; /**< The pointer to the next cell element. */
	char* value; /**< The value. */
};

/**
 * Create a linked list cell.
 * You must destroy the object created by this function with the destroy function.
 * @see LinkedListCell_destroy
 * @see Test_LinkedListCell_create_destroy
 * @param next The pointer to the next cell element.
 * @param value The value to be stored the cell.
 * @param value_type_size The size of the value type.
 * @return Return NULL if memory allocation fails, otherwise return a linked list object.
 */
extern struct LinkedListCell* LinkedListCell_create(struct LinkedListCell* next, void* value, unsigned int value_type_size);

/**
 * Destroy the linked list cell.
 * This function destroy the object created by the create function.
 * @see LinkedListCell_create
 * @see Test_LinkedListCell_create_destroy
 * @param cell The pointer of the linked list cell.
 */
extern void LinkedListCell_destroy(struct LinkedListCell* cell);

/**
 * Judge if the cell has the next pointer or not.
 * @see Test_LinkedListCell_has_next
 * @param cell The pointer of the linked list cell.
 */
extern enum Boolean LinkedListCell_has_next(struct LinkedListCell* cell);

#endif /* LINKEDLISTCELL_H */
