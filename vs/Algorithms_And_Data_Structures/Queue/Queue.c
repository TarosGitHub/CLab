#include <string.h>
#include "Queue.h"

#define Queue_index(queue, distance) ((queue->front + (distance)) % queue->capacity)

void Queue_init(struct Queue* queue, unsigned int elem_size, void* memory, unsigned int capacity)
{
	queue->elem_size = elem_size;
	queue->memory = (char*)memory;
	queue->capacity = capacity;
	queue->front = 0U;
	queue->size = 0U;
}

enum Boolean Queue_is_empty(struct Queue* queue)
{
	return (queue->size == 0U ? TRUE : FALSE);
}

enum Boolean Queue_is_full(struct Queue* queue)
{
	return (queue->size == queue->capacity ? TRUE : FALSE);
}

unsigned int Queue_size(struct Queue* queue)
{
	return queue->size;
}

enum QueueStatus Queue_enqueue(struct Queue* queue, const void* elem)
{
	if (Queue_is_full(queue)) {
		return QUEUE_FAILURE;
	}

	memcpy(&queue->memory[queue->elem_size * Queue_index(queue, queue->size)], elem, queue->elem_size);
	queue->size++;

	return QUEUE_SUCCESS;
}

enum QueueStatus Queue_dequeue(struct Queue* queue, void* elem)
{
	if (Queue_is_empty(queue)) {
		return QUEUE_FAILURE;
	}

	if (NULL != elem) {
		memcpy(elem, &queue->memory[queue->elem_size * queue->front], queue->elem_size);
	}
	queue->front = Queue_index(queue, 1);
	queue->size--;

	return QUEUE_SUCCESS;
}
