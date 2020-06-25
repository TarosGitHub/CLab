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
	unsigned int elem_size; /**< Size of an element. */
	char* memory; /**< Memory area of queue. */
	unsigned int capacity; /**< Maximum number of elements on queue. */
	unsigned int front; /**< Pointer to front of queue. */
	unsigned int size; /**< Number of elements on queue. */
};

/**
 * Create a queue.
 * @see Test_Queue_new
 * @param elem_size Size of an element.
 * @param memory Memory area of queue.
 * @param capacity Maximum number of elements on queue.
 * @return Return a queue object.
 */
#define Queue_new(elem_size, memory, capacity) {sizeof(elem_size), (char*)(memory), (capacity), 0U, 0U}

 /**
  * Initialize the queue.
  * @see Test_Queue_init
  * @param queue Pointer to queue.
  * @param elem_size Size of an element.
  * @param memory Memory area of queue.
  * @param capacity Maximum number of elements on queue.
  */
extern void Queue_init(struct Queue* queue, unsigned int elem_size, void* memory, unsigned int capacity);

/**
 * Determine if queue is empty.
 * @see Test_Queue_is_empty
 * @param queue Pointer to queue.
 * @return Return true if queue is empty, otherwise return false.
 */
extern enum Queue_bool Queue_is_empty(struct Queue* queue);

/**
 * Determine if queue is full.
 * @see Test_Queue_is_full
 * @param queue Pointer to queue.
 * @return Return true if queue is full, otherwise return false.
 */
extern enum Queue_bool Queue_is_full(struct Queue* queue);

#endif /* QUEUE_H */
