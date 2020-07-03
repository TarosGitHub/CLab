#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

#include "LinkedListCell.h"
#include "LinkedListIterator.h"

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
	struct LinkedListCell* head; /**< The head element of the linked list. */
	unsigned int value_type_size; /**< The size of the value type. */
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
 * @param list The pointer to the linked list.
 */
extern void LinkedList_destroy(struct LinkedList* list);

/**
 * Delete all cells in the linked list.
 * @see Test_LinkedList_delete_all
 * @param list The pointer to the linked list.
 */
extern void LinkedList_delete_all(struct LinkedList* list);

/**
 * Set the iterator at the head of the list.
 * The head is not the first cell element of the list. The next cell element of the head is the first cell element of the list.
 * @see Test_LinkedList_begin
 * @param list The pointer to the linked list.
 * @param iterator The pointer to the iterator to set.
 */
extern void LinkedList_begin(struct LinkedList* list, struct LinkedListIterator* iterator);

/**
 * Insert the value after the cell pointed to by the iterator.
 * @see Test_LinkedList_insert
 * @param list The pointer to the linked list.
 * @param iterator The pointer to the iterator.
 * @param value The value to be inserted(You must not set NULL to this argument).
 * @return Return failure if memory allocation fails, otherwise return success.
 */
extern enum LinkedListStatus LinkedList_insert(struct LinkedList* list, struct LinkedListIterator* iterator, void* value);

/**
 * Remove the value from the last of the linked list.
 * This function do nothing if the linked list is empty.
 * @see Test_LinkedList_remove
 * @param list The pointer to the linked list.
 */
extern void LinkedList_remove(struct LinkedList* list);

#endif /* LINKEDLIST_H */
