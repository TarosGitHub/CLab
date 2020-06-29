#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

/**
 * Cell structure.
 */
struct Cell {
	struct Cell* next; /**< The pointer to the next cell element. */
	char* value; /**< The value. */
};

/**
 * Linked list data structure.
 */
struct LinkedList {
	unsigned int value_type_size; /**< The size of the value type. */
	struct Cell head; /**< The head element of the linked list. */
	struct Cell* tail; /**< The pointer of the linked list tail element. */
	unsigned int size; /**< The number of elements that stored in the linked list. */
};

/**
 * Create a linked list.
 * You must destroy the object created by this function with the destroy function.
 * @see LinkedList_destroy
 * @see Test_LinkedList_create_destroy
 * @param value_type_size The size of the value type.
 * @return Return a linked list object.
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

#endif /* LINKEDLIST_H */
