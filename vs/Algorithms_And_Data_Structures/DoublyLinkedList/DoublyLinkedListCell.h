#if !defined(DOUBLYLINKEDLISTCELL_H)
#define DOUBLYLINKEDLISTCELL_H

#include "Common.h"

/**
 * Doubly Linked list cell structure.
 */
struct DoublyLinkedListCell {
	struct DoublyLinkedListCell* prev; /**< The pointer to the previous cell element. */
	struct DoublyLinkedListCell* next; /**< The pointer to the next cell element. */
	unsigned int value_type_size; /**< The size of the value type. */
	char* value; /**< The value. */
};

/**
 * Creates a doubly linked list cell.
 * You must destroy the object created by this function with the destroy function.
 *
 * @see DoublyLinkedListCell_destroy
 * @see Test_DoublyLinkedListCell_create_destroy
 * @param prev The pointer to the previous cell element.
 * @param next The pointer to the next cell element.
 * @param value The value to be stored the cell.
 * @param value_type_size The size of the value type.
 * @return Return NULL if memory allocation fails, otherwise return a doubly linked list object.
 */
extern struct DoublyLinkedListCell* DoublyLinkedListCell_create(struct DoublyLinkedListCell* prev, struct DoublyLinkedListCell* next, void* value, unsigned int value_type_size);

/**
 * Destroys the doubly linked list cell.
 * This function destroy the object created by the create function.
 *
 * @see DoublyLinkedListCell_create
 * @see Test_DoublyLinkedListCell_create_destroy
 * @param cell The pointer to the doubly linked list cell.
 */
extern void DoublyLinkedListCell_destroy(struct DoublyLinkedListCell* cell);

/**
 * Judges whether the cell has the previous pointer.
 *
 * @see Test_DoublyLinkedListCell_has_prev
 * @param cell The pointer to the doubly linked list cell.
 * @return Return true if the cell has the previous pointer, otherwise return false.
 */
extern enum Boolean DoublyLinkedListCell_has_prev(struct DoublyLinkedListCell* cell);

/**
 * Judges whether the cell has the next pointer.
 *
 * @see Test_DoublyLinkedListCell_has_next
 * @param cell The pointer to the doubly linked list cell.
 * @return Return true if the cell has the next pointer, otherwise return false.
 */
extern enum Boolean DoublyLinkedListCell_has_next(struct DoublyLinkedListCell* cell);

/**
 * Gets the pointer to the previous cell element.
 *
 * @see Test_DoublyLinkedListCell_get_prev
 * @param cell The pointer to the doubly linked list cell.
 * @return Return the pointer to the previous cell element. If the cell doesn't have it, return NULL.
 */
extern struct DoublyLinkedListCell* DoublyLinkedListCell_get_prev(struct DoublyLinkedListCell* cell);

/**
 * Gets the pointer to the next cell element.
 *
 * @see Test_DoublyLinkedListCell_get_next
 * @param cell The pointer to the doubly linked list cell.
 * @return Return the pointer to the next cell element. If the cell doesn't have it, return NULL.
 */
extern struct DoublyLinkedListCell* DoublyLinkedListCell_get_next(struct DoublyLinkedListCell* cell);

/**
 * Sets the pointer to the previous cell element.
 *
 * @see Test_DoublyLinkedListCell_set_prev
 * @param cell The pointer to the doubly linked list cell.
 * @param next The pointer to the previous cell element.
 */
extern void DoublyLinkedListCell_set_prev(struct DoublyLinkedListCell* cell, struct DoublyLinkedListCell* prev);

/**
 * Sets the pointer to the next cell element.
 *
 * @see Test_DoublyLinkedListCell_set_next
 * @param cell The pointer to the doubly linked list cell.
 * @param next The pointer to the next cell element.
 */
extern void DoublyLinkedListCell_set_next(struct DoublyLinkedListCell* cell, struct DoublyLinkedListCell* next);

/**
 * Gets the value.
 *
 * @see Test_DoublyLinkedListCell_get
 * @param cell The pointer to the doubly linked list cell.
 * @param value The getted value. The size of the value type must match the size set at initialization.
 *              You must not set NULL to this argument.
 */
extern void DoublyLinkedListCell_get(struct DoublyLinkedListCell* cell, void* value);

/**
 * Sets the value.
 *
 * @see Test_DoublyLinkedListCell_set
 * @param cell The pointer to the doubly linked list cell.
 * @param value The value to set. The size of the value type must match the size set at initialization.
 *              You must not set NULL to this argument.
 */
extern void DoublyLinkedListCell_set(struct DoublyLinkedListCell* cell, void* value);

#endif
