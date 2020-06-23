#if !defined(STACK_H)
#define STACK_H

enum Stack_status {
	STACK_SUCCESS,
	STACK_FAILURE
};

struct Stack {
	unsigned int data_size;
	char* memory;
	unsigned int capacity;
	unsigned int size;
};

#define new_Stack(data_size, memory, capacity) {sizeof(data_size), (char*)(memory), (capacity), 0}
extern enum Stack_status Stack_push(struct Stack* stack, void* data);
extern enum Stack_status Stack_pop(struct Stack* stack, void* data);

#endif /* STACK_H */
