#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

#include "LinkedListCell.h"

/**
 * Linked list processing status.
 */
enum LinkedListStatus {
	LINKED_LIST_SUCCESS, /**< Linked list processing success. */
	LINKED_LIST_FAILURE /**< Linked list processing failure. */
};

/**
 * Linked list data structure.
 */
struct LinkedList {
	unsigned int value_type_size; /**< The size of the value type. */
	struct LinkedListCell head; /**< The head element of the linked list. */
	struct LinkedListCell* tail; /**< The pointer of the linked list tail element. */
	unsigned int size; /**< The number of elements that stored in the linked list. */
};

/**
 * Create a linked list.
 * You must destroy the object created by this function with the destroy function.
 * @see LinkedList_destroy
 * @see Test_LinkedList_create_destroy
 * @param value_type_size The size of the value type.
 * @return Return NULL if memory allocation fails, otherwise return a linked list object.
 */
extern struct LinkedList* LinkedList_create(unsigned int value_type_size);

/**
 * Destroy the linked list.
 * This function destroy the object created by the create function.
 * @see LinkedList_create
 * @see Test_LinkedList_create_destroy
 * @param list The pointer of the linked list.
 */
extern void LinkedList_destroy(struct LinkedList* list);

/**
 * Delete all cells in the linked list.
 * @see Test_LinkedList_delete_all
 * @param list The pointer of the linked list.
 */
extern void LinkedList_delete_all(struct LinkedList* list);

/**
 * Add the value to the last of the linked list.
 * @see Test_LinkedList_add
 * @param list The pointer to the linked list.
 * @param value The value to be added(You must not set NULL to this argument).
 * @return Return failure if memory allocation fails, otherwise return success.
 */
extern enum LinkedListStatus LinkedList_add(struct LinkedList* list, void* value);

/**
 * Remove the value from the last of the linked list.
 * This function do nothing if the linked list is empty.
 * @see Test_LinkedList_remove
 * @param list The pointer to the linked list.
 */
extern void LinkedList_remove(struct LinkedList* list);

#endif /* LINKEDLIST_H */
