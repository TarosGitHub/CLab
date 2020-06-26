#if !defined(QUEUE_H)
#define QUEUE_H

/**
 * Boolean type.
 */
enum Queue_bool {
	QUEUE_FALSE, /**< False is zero. */
	QUEUE_TRUE /**< True is not zero. */
};

/**
 * Queue processing status.
 */
enum Queue_status {
	QUEUE_SUCCESS, /**< Queue processing success. */
	QUEUE_FAILURE /**< Queue processing failure. */
};

/**
 * Queue data structure.
 */
struct Queue {
	unsigned int elem_size; /**< The size of an element. */
	char* memory; /**< The memory area of the queue. */
	unsigned int capacity; /**< The maximum number of elements on the queue. */
	unsigned int front; /**< The pointer to front of the queue. */
	unsigned int size; /**< The number of elements on the queue. */
};

/**
 * Create a queue.
 * @see Test_Queue_new
 * @param elem_size The size of an element.
 * @param memory The memory area of the queue.
 * @param capacity The maximum number of elements on the queue.
 * @return Return a queue object.
 */
#define Queue_new(elem_size, memory, capacity) {sizeof(elem_size), (char*)(memory), (capacity), 0U, 0U}

 /**
  * Initialize the queue.
  * @see Test_Queue_init
  * @param queue The pointer to the queue.
  * @param elem_size The size of an element.
  * @param memory The memory area of the queue.
  * @param capacity The maximum number of elements on the queue.
  */
extern void Queue_init(struct Queue* queue, unsigned int elem_size, void* memory, unsigned int capacity);

/**
 * Determine if the queue is empty.
 * @see Test_Queue_is_empty
 * @param queue The pointer to the queue.
 * @return Return true if the queue is empty, otherwise return false.
 */
extern enum Queue_bool Queue_is_empty(struct Queue* queue);

/**
 * Determine if the queue is full.
 * @see Test_Queue_is_full
 * @param queue The pointer to the queue.
 * @return Return true if the queue is full, otherwise return false.
 */
extern enum Queue_bool Queue_is_full(struct Queue* queue);

/**
 * Get the number of elements on the queue.
 * @see Test_Queue_size
 * @param queue The pointer to the queue.
 * @return Return the number of elements on the queue.
 */
extern unsigned int Queue_size(struct Queue* queue);

/**
 * Enqueue an element to the queue.
 * @see Test_Queue_enqueue_dequeue
 * @param queue The pointer to the queue.
 * @param elem An element that is enqueued to the queue(You must not set NULL to this argument).
 * @return Return failure if the queue is full, otherwise return success.
 */
extern enum Queue_status Queue_enqueue(struct Queue* queue, const void* elem);

/**
 * Dequeue an element from the queue.
 * @see Test_Queue_enqueue
 * @see Test_Queue_enqueue_dequeue
 * @param queue The pointer to the queue.
 * @param elem An element that is dequeued from the queue(You can set NULL to this argument. In that case, no value is set to this argument).
 * @return Return failure if the queue is empty, otherwise return success.
 */
extern enum Queue_status Queue_dequeue(struct Queue* queue, void* elem);

#endif /* QUEUE_H */
