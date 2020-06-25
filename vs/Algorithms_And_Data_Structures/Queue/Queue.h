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
	unsigned int rear; /**< Pointer to rear of queue. */
	enum Queue_bool is_empty; /**< This flag is true if queue is empty. */
};

/**
 * Create a queue.
 * @see Test_Queue_new
 * @param elem_size Size of an element.
 * @param memory Memory area of queue.
 * @param capacity Maximum number of elements on queue.
 * @return Return a queue object.
 */
#define Queue_new(elem_size, memory, capacity) {sizeof(elem_size), (char*)(memory), (capacity), 0U, 0U, QUEUE_TRUE}

 /**
  * Initialize the queue.
  * @see Test_Queue_init
  * @param queue Pointer to queue.
  * @param elem_size Size of an element.
  * @param memory Memory area of queue.
  * @param capacity Maximum number of elements on queue.
  */
extern void Queue_init(struct Queue* queue, unsigned int elem_size, void* memory, unsigned int capacity);

#endif /* QUEUE_H */
