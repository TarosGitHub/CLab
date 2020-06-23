#if !defined(STACK_H)
#define STACK_H

enum Stack_status {
	STACK_SUCCESS,
	STACK_FAILURE
};

struct Stack {
	unsigned int elem_size;
	char* memory;
	unsigned int capacity;
	unsigned int pointer;
};

#define new_Stack(elem_size, memory, capacity) {sizeof(elem_size), (char*)(memory), (capacity), 0U}
extern int Stack_is_empty(struct Stack* stack);
extern int Stack_is_full(struct Stack* stack);
extern unsigned int Stack_size(struct Stack* stack);
extern enum Stack_status Stack_push(struct Stack* stack, const void* elem);
extern enum Stack_status Stack_pop(struct Stack* stack, void* elem);

#endif /* STACK_H */
