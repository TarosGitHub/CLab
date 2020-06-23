#include <stddef.h>
#include <string.h>
#include "Stack.h"

int Stack_is_empty(struct Stack* stack)
{
	return stack->pointer == 0U;
}

int Stack_is_full(struct Stack* stack)
{
	return stack->capacity == stack->pointer;
}

unsigned int Stack_size(struct Stack* stack)
{
	return stack->pointer;
}

enum Stack_status Stack_push(struct Stack* stack, const void* elem)
{
	if (NULL == elem) {
		return STACK_FAILURE;
	}

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
