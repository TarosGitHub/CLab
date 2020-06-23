#include <stddef.h>
#include "Stack.h"

enum Stack_status Stack_push(struct Stack* stack, void* elem)
{
	if (NULL == elem) {
		return STACK_FAILURE;
	}

	return STACK_SUCCESS;
}

enum Stack_status Stack_pop(struct Stack* stack, void* elem)
{


	return STACK_SUCCESS;
}