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
	char* memory; /**< Memory area of stack. */
	unsigned int capacity; /**< Maximum number of elements on stack. */
	unsigned int pointer; /**< Pointer to top of stack. */
};

/**
 * Create a stack.
 * @see Test_Stack_new
 * @param elem_size Size of an element.
 * @param memory Memory area of stack.
 * @param capacity Maximum number of elements on stack.
 * @return Return a stack object.
 */
#define Stack_new(elem_size, memory, capacity) {sizeof(elem_size), (char*)(memory), (capacity), 0U}

/**
 * Initialize the stack.
 * @see Test_Stack_init
 * @param stack Pointer to stack.
 * @param elem_size Size of an element.
 * @param memory Memory area of stack.
 * @param capacity Maximum number of elements on stack.
 */
extern void Stack_init(struct Stack* stack, unsigned int elem_size, void* memory, unsigned int capacity);

/**
 * Determine if stack is empty.
 * @see Test_Stack_is_empty
 * @param stack Pointer to stack.
 * @return Return true if stack is empty, otherwise return false.
 */
extern enum Stack_bool Stack_is_empty(struct Stack* stack);

/**
 * Determine if stack is full.
 * @see Test_Stack_is_full
 * @param stack Pointer to stack.
 * @return Return true if stack is full, otherwise return false.
 */
extern enum Stack_bool Stack_is_full(struct Stack* stack);

/**
 * Get the number of elements on stack.
 * @see Test_Stack_size
 * @param stack Pointer to stack.
 * @return Return the number of elements on stack.
 */
extern unsigned int Stack_size(struct Stack* stack);

/**
 * Push an element to stack.
 * @see Test_Stack_push
 * @param stack Pointer to stack.
 * @param elem An element that is pushed to stack(You must not set NULL to this argument).
 * @return Return STACK_FAILURE if stack is full, otherwise return STACK_SUCCESS.
 */
extern enum Stack_status Stack_push(struct Stack* stack, const void* elem);

/**
 * Pop an element from stack.
 * @see Test_Stack_pop
 * @param stack Pointer to stack.
 * @param elem An element that is popped from stack(You can set NULL to this argument. In that case, no value is set to this argument).
 * @return Return STACK_FAILURE if stack is empty, otherwise return STACK_SUCCESS.
 */
extern enum Stack_status Stack_pop(struct Stack* stack, void* elem);

/**
 * Copy stack.
 * This function makes a deep copy of stack memory area.
 * The element size of destination stack must be as large as the element size of source stack.
 * If the size of the memory area is different, it will be copied to fit the smaller memory area.
 * @see Test_Stack_copy
 * @param dst Destination stack
 * @param src Source stack
 */
extern void Stack_copy(struct Stack* dst, const struct Stack* src);

#endif /* STACK_H */
