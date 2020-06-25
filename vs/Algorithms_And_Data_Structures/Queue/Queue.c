#include "Queue.h"

#define next(queue) ((queue->front + queue->size) % queue->capacity)

void Queue_init(struct Queue* queue, unsigned int elem_size, void* memory, unsigned int capacity)
{
	queue->elem_size = elem_size;
	queue->memory = (char*)memory;
	queue->capacity = capacity;
	queue->front = 0U;
	queue->size = 0U;
}

enum Queue_bool Queue_is_empty(struct Queue* queue)
{
	return (queue->size == 0U ? QUEUE_TRUE : QUEUE_FALSE);
}

enum Queue_bool Queue_is_full(struct Queue* queue)
{
	return (queue->size == queue->capacity ? QUEUE_TRUE : QUEUE_FALSE);
}
