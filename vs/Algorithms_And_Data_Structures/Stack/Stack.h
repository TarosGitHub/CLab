#if !defined(STACK_H)
#define STACK_H

/**
 * Boolean type.
 */
enum Stack_bool {
	STACK_FALSE, /**< False is zero. */
	STACK_TRUE /**< True is not zero. */
};

/**
 * Stack processing status.
 */
enum Stack_status {
	STACK_SUCCESS, /**< Stack processing success. */
	STACK_FAILURE /**< Stack processing failure. */
};

/**
 * Stack data structure.
 */
struct Stack {
	unsigned int elem_size; /**< Size of an element. */
	char* memory; /**< Memory area of Stack. */
	unsigned int capacity; /**< Maximum number of elements on Stack. */
	unsigned int pointer; /**< Pointer to top of Stack. */
};

/**
 * Create Stack.
 * @see Test_Stack_new
 * @param elem_size Size of an element.
 * @param memory Memory area of Stack.
 * @param capacity Maximum number of elements on Stack.
 * @return Return one Stack object.
 */
#define Stack_new(elem_size, memory, capacity) {sizeof(elem_size), (char*)(memory), (capacity), 0U}

/**
 * Initialize Stack.
 * @see Test_Stack_init
 * @param stack Pointer to Stack.
 * @param elem_size Size of an element.
 * @param memory Memory area of Stack.
 * @param capacity Maximum number of elements on Stack.
 */
extern void Stack_init(struct Stack* stack, unsigned int elem_size, void* memory, unsigned int capacity);

/**
 * Determine if Stack is empty.
 * @see Test_Stack_is_empty
 * @param stack Pointer to Stack.
 * @return Return true if Stack is empty, otherwise return false.
 */
extern enum Stack_bool Stack_is_empty(struct Stack* stack);

/**
 * Determine if Stack is full.
 * @see Test_Stack_is_full
 * @param stack Pointer to Stack.
 * @return Return true if Stack is full, otherwise return false.
 */
extern enum Stack_bool Stack_is_full(struct Stack* stack);

/**
 * Get the number of elements on Stack.
 * @see Test_Stack_size
 * @param stack Pointer to Stack.
 * @return Return the number of elements on Stack.
 */
extern unsigned int Stack_size(struct Stack* stack);

/**
 * Push an element to Stack.
 * @see Test_Stack_push
 * @param stack Pointer to Stack.
 * @param elem An element that is pushed to Stack(You must not set NULL to this argument).
 * @return Return STACK_FAILURE if Stack is full, otherwise return STACK_SUCCESS.
 */
extern enum Stack_status Stack_push(struct Stack* stack, const void* elem);

/**
 * Pop an element from Stack.
 * @see Test_Stack_pop
 * @param stack Pointer to Stack.
 * @param elem An element that is popped from Stack(You can set NULL to this argument. In that case, no value is set to this argument).
 * @return Return STACK_FAILURE if Stack is empty, otherwise return STACK_SUCCESS.
 */
extern enum Stack_status Stack_pop(struct Stack* stack, void* elem);

/**
 * Copy Stack.
 * This function makes a deep copy of Stack memory area.
 * The copy destination stack memory area must be larger than or equal to the copy source stack memory area.
 * @see Test_Stack_copy
 * @param dst Destination to copy
 * @param src Source of copy
 */
extern void Stack_copy(struct Stack* dst, const struct Stack* src);

#endif /* STACK_H */
