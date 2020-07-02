#if !defined(LINKEDLISTCELL_H)
#define LINKEDLISTCELL_H

#include "Common.h"

/**
 * Linked list cell structure.
 */
struct LinkedListCell {
	struct LinkedListCell* next; /**< The pointer to the next cell element. */
	unsigned int value_type_size; /**< The size of the value type. */
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
 * @param cell The pointer to the linked list cell.
 */
extern void LinkedListCell_destroy(struct LinkedListCell* cell);

/**
 * Judge if the cell has the next pointer or not.
 * @see Test_LinkedListCell_has_next
 * @param cell The pointer to the linked list cell.
 */
extern enum Boolean LinkedListCell_has_next(struct LinkedListCell* cell);

/**
 * Get the pointer to the next cell element.
 * @see Test_LinkedListCell_get_next
 * @param cell The pointer to the linked list cell.
 * @return Return the pointer to the next cell element. If the cell doesn't have it, return NULL.
 */
extern struct LinkedListCell* LinkedListCell_get_next(struct LinkedListCell* cell);

/**
 * Set the pointer to the next cell element.
 * @see Test_LinkedListCell_set_next
 * @param cell The pointer to the linked list cell.
 * @param next The pointer to the next cell element.
 */
extern void LinkedListCell_set_next(struct LinkedListCell* cell, struct LinkedListCell* next);

/**
 * Get the value.
 * @see Test_LinkedListCell_get
 * @param cell The pointer to the linked list cell.
 * @param value The getted value. The size of the value type should match the size set at initialization.
 *              You must not set NULL to this argument. 
 */
extern void LinkedListCell_get(struct LinkedListCell* cell, void* value);

/**
 * Set the value.
 * @see Test_LinkedListCell_set
 * @param cell The pointer to the linked list cell.
 * @param value The value to set. The size of the value type should match the size set at initialization.
 *              You must not set NULL to this argument.
 */
extern void LinkedListCell_set(struct LinkedListCell* cell, void* value);

#endif /* LINKEDLISTCELL_H */
