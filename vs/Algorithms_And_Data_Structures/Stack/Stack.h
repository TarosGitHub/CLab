#if !defined(STACK_H)
#define STACK_H

#include "Common.h"

/**
 * Stack processing status.
 */
enum StackStatus {
	STACK_SUCCESS, /**< Stack processing success. */
	STACK_FAILURE /**< Stack processing failure. */
};

/**
 * Stack data structure.
 */
struct Stack {
	unsigned int elem_size; /**< The size of an element. */
	char* memory; /**< The memory area of the stack. */
	unsigned int capacity; /**< The maximum number of elements on the stack. */
	unsigned int pointer; /**< The pointer to the top of the stack. */
};

/**
 * Creates a stack.
 *
 * @see Test_Stack_new
 * @param elem_type The type of the element.
 * @param memory The memory area of the stack.
 * @param capacity The maximum number of elements on the stack.
 * @return Return a stack object.
 */
#define Stack_new(elem_type, memory, capacity) {sizeof(elem_type), (char*)(memory), (capacity), 0U}

/**
 * Initializes the stack.
 *
 * @see Test_Stack_init
 * @param stack The pointer to the stack.
 * @param elem_size The size of an element.
 * @param memory The memory area of the stack.
 * @param capacity The maximum number of elements on the stack.
 */
extern void Stack_init(struct Stack* stack, unsigned int elem_size, void* memory, unsigned int capacity);

/**
 * Judges whether the stack is empty.
 *
 * @see Test_Stack_is_empty
 * @param stack The pointer to the stack.
 * @return Return true if the stack is empty, otherwise return false.
 */
extern enum Boolean Stack_is_empty(struct Stack* stack);

/**
 * Judges whether the stack is full.
 *
 * @see Test_Stack_is_full
 * @param stack The pointer to the stack.
 * @return Return true if the stack is full, otherwise return false.
 */
extern enum Boolean Stack_is_full(struct Stack* stack);

/**
 * Gets the number of elements on the stack.
 *
 * @see Test_Stack_size
 * @param stack The pointer to the stack.
 * @return Return the number of elements on the stack.
 */
extern unsigned int Stack_size(struct Stack* stack);

/**
 * Pushes an element to the stack.
 *
 * @see Test_Stack_push
 * @param stack The pointer to the stack.
 * @param elem An element that is pushed to the stack(You must not set NULL to this argument).
 * @return Return failure if the stack is full, otherwise return success.
 */
extern enum StackStatus Stack_push(struct Stack* stack, const void* elem);

/**
 * Pops an element from the stack.
 *
 * @see Test_Stack_pop
 * @param stack The pointer to the stack.
 * @param elem An element that is popped from the stack(You can set NULL to this argument. In that case, the popped value is discarded).
 * @return Return failure if the stack is empty, otherwise return success.
 */
extern enum StackStatus Stack_pop(struct Stack* stack, void* elem);

/**
 * Copies a stack.
 * This function makes a deep copy of the stack memory area.
 * The element size of the destination stack must be as large as the element size of the source stack.
 * If the size of the memory area is different, it will be copied to fit the smaller memory area.
 *
 * @see Test_Stack_copy
 * @param dst A destination stack
 * @param src A source stack
 */
extern void Stack_copy(struct Stack* dst, const struct Stack* src);

#endif
