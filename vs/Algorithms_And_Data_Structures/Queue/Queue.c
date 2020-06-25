#include "Queue.h"

void Queue_init(struct Queue* queue, unsigned int elem_size, void* memory, unsigned int capacity)
{
	queue->elem_size = elem_size;
	queue->memory = (char*)memory;
	queue->capacity = capacity;
	queue->front = 0U;
	queue->rear = 0U;
	queue->is_empty = QUEUE_TRUE;
}
