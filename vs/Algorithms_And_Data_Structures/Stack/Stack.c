#include <stddef.h>
#include <string.h>
#include "Stack.h"

enum Stack_bool Stack_is_empty(struct Stack* stack)
{
	return (stack->pointer == 0U ? STACK_TRUE : STACK_FALSE);
}

enum Stack_bool Stack_is_full(struct Stack* stack)
{
	return (stack->pointer == stack->capacity ? STACK_TRUE : STACK_FALSE);
}

unsigned int Stack_size(struct Stack* stack)
{
	return stack->pointer;
}

enum Stack_status Stack_push(struct Stack* stack, const void* elem)
{
	if (Stack_is_full(stack)) {
		return STACK_FAILURE;
	}

	memcpy(&stack->memory[stack->elem_size * stack->pointer], elem, stack->elem_size);
	stack->pointer++;

	return STACK_SUCCESS;
}

enum Stack_status Stack_pop(struct Stack* stack, void* elem)
{
	if (Stack_is_empty(stack)) {
		return STACK_FAILURE;
	}

	stack->pointer--;
	if (NULL != elem) {
		memcpy(elem, &stack->memory[stack->elem_size * stack->pointer], stack->elem_size);
	}

	return STACK_SUCCESS;
}
