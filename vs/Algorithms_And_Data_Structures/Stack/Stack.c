#include <string.h>
#include "Stack.h"

void Stack_init(struct Stack* stack, unsigned int elem_size, void* memory, unsigned int capacity)
{
	stack->elem_size = elem_size;
	stack->memory = (char*)memory;
	stack->capacity = capacity;
	stack->pointer = 0U;
}

enum Boolean Stack_is_empty(struct Stack* stack)
{
	return (stack->pointer == 0U ? TRUE : FALSE);
}

enum Boolean Stack_is_full(struct Stack* stack)
{
	return (stack->pointer == stack->capacity ? TRUE : FALSE);
}

unsigned int Stack_size(struct Stack* stack)
{
	return stack->pointer;
}

enum StackStatus Stack_push(struct Stack* stack, const void* elem)
{
	if (Stack_is_full(stack)) {
		return STACK_FAILURE;
	}

	memcpy(&stack->memory[stack->elem_size * stack->pointer], elem, stack->elem_size);
	stack->pointer++;

	return STACK_SUCCESS;
}

enum StackStatus Stack_pop(struct Stack* stack, void* elem)
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

void Stack_copy(struct Stack* dst, const struct Stack* src)
{
	unsigned int elem_size = src->elem_size;
	unsigned int capacity = min(dst->capacity, src->capacity);
	memcpy(dst->memory, src->memory, elem_size * capacity);
	dst->pointer = dst->capacity < src->pointer ? dst->capacity : src->pointer;
}
