#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

/**
 * Linked list processing status.
 */
enum LinkedListStatus {
	LINKED_LIST_SUCCESS, /**< Linked list processing success. */
	LINKED_LIST_FAILURE /**< Linked list processing failure. */
};

/**
 * Linked list cell structure.
 */
struct LinkedListCell {
	struct LinkedListCell* next; /**< The pointer to the next cell element. */
	char* value; /**< The value. */
};

/**
 * Create a cell for the linked list.
 * You must destroy the object created by this function with the destroy function.
 * @param next The pointer to the next cell.
 * @param value The value in the cell.
 * @param value_type_size The size of the value type.
 * @return Return NULL if memory allocation fails, otherwise return a cell object.
 */
extern struct LinkedListCell* LinkedListCell_create(struct LinkedListCell* next, void* value, unsigned int value_type_size);

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
 * @see Test_add
 * @param list The pointer to the linked list.
 * @param value The value to be added(You must not set NULL to this argument).
 * @return Return failure if memory allocation fails, otherwise return success.
 */
extern enum LinkedListStatus LinkedList_add(struct LinkedList* list, void* value);

#endif /* LINKEDLIST_H */
