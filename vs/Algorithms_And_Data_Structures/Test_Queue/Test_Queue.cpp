#include "CppUnitTest.h"

extern "C" {
#include "Queue.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define MEMORY_SIZE 5U

typedef int elem_t;

namespace TestQueue
{
	TEST_CLASS(Test_Queue_new)
	{
	public:

		TEST_METHOD(normal)
		{
			elem_t memory[MEMORY_SIZE];
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);

			Assert::AreEqual(sizeof(elem_t), target.elem_size);
			Assert::AreEqual((void*)memory, (void*)target.memory);
			Assert::AreEqual(MEMORY_SIZE, target.capacity);
			Assert::AreEqual(0U, target.front);
			Assert::AreEqual(0U, target.size);
		}
	};

	TEST_CLASS(Test_Queue_init)
	{
	public:

		TEST_METHOD(normal)
		{
			elem_t memory[MEMORY_SIZE];
			Queue target;

			Queue_init(&target, sizeof(elem_t), memory, MEMORY_SIZE);

			Assert::AreEqual(sizeof(elem_t), target.elem_size);
			Assert::AreEqual((void*)memory, (void*)target.memory);
			Assert::AreEqual(MEMORY_SIZE, target.capacity);
			Assert::AreEqual(0U, target.front);
			Assert::AreEqual(0U, target.size);
		}
	};

	TEST_CLASS(Test_Queue_is_empty)
	{
	public:

		TEST_METHOD(queue_is_empty)
		{
			elem_t memory[MEMORY_SIZE];
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);

			Queue_bool is_empty = Queue_is_empty(&target);

			Assert::AreEqual<int>(QUEUE_TRUE, is_empty);
		}

		TEST_METHOD(queue_is_not_empty)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.size = 1U;

			Queue_bool is_empty = Queue_is_empty(&target);

			Assert::AreEqual<int>(QUEUE_FALSE, is_empty);
		}
	};

	TEST_CLASS(Test_Queue_is_full)
	{
	public:

		TEST_METHOD(queue_is_full)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.size = 5U;

			Queue_bool is_full = Queue_is_full(&target);

			Assert::AreEqual<int>(QUEUE_TRUE, is_full);
		}

		TEST_METHOD(queue_is_not_full)
		{
			elem_t memory[MEMORY_SIZE];
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);

			Queue_bool is_full = Queue_is_full(&target);

			Assert::AreEqual<int>(QUEUE_FALSE, is_full);
		}
	};

	TEST_CLASS(Test_Queue_size)
	{
	public:

		TEST_METHOD(normal)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.size = 1U;

			unsigned int size = Queue_size(&target);

			Assert::AreEqual(1U, size);
		}
	};

	TEST_CLASS(Test_Queue_dequeue)
	{
	public:

		TEST_METHOD(argument_elem_is_NULL)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.size = 1U;

			Queue_status status = Queue_dequeue(&target, NULL);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(1U, target.front);
			Assert::AreEqual(0U, target.size);
		}
	};

	TEST_CLASS(Test_Queue_enqueue_dequeue)
	{
	public:

		TEST_METHOD(enqueue_a_datum)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);

			elem_t enqueued_elem = 1;
			Queue_status status = Queue_enqueue(&target, &enqueued_elem);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.front);
			Assert::AreEqual(1U, target.size);
		}

		TEST_METHOD(enqueue_data_to_full)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);

			elem_t enqueued_elem = 1;
			Queue_status status1 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 2;
			Queue_status status2 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 3;
			Queue_status status3 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 4;
			Queue_status status4 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 5;
			Queue_status status5 = Queue_enqueue(&target, &enqueued_elem);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.front);
			Assert::AreEqual(5U, target.size);
		}

		TEST_METHOD(overflow)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);

			elem_t enqueued_elem = 1;
			Queue_status status1 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 2;
			Queue_status status2 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 3;
			Queue_status status3 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 4;
			Queue_status status4 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 5;
			Queue_status status5 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 6;
			Queue_status status6 = Queue_enqueue(&target, &enqueued_elem);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			Assert::AreEqual<int>(QUEUE_FAILURE, status6);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.front);
			Assert::AreEqual(5U, target.size);
		}

		TEST_METHOD(dequeue_a_datum)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.size = 1U;

			elem_t dequeued_elem = 0;
			Queue_status status = Queue_dequeue(&target, &dequeued_elem);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status);
			Assert::AreEqual(1, dequeued_elem);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(1U, target.front);
			Assert::AreEqual(0U, target.size);
		}

		TEST_METHOD(dequeue_data_to_empty)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.size = 5U;

			elem_t dequeued_elem1 = 0;
			Queue_status status1 = Queue_dequeue(&target, &dequeued_elem1);
			elem_t dequeued_elem2 = 0;
			Queue_status status2 = Queue_dequeue(&target, &dequeued_elem2);
			elem_t dequeued_elem3 = 0;
			Queue_status status3 = Queue_dequeue(&target, &dequeued_elem3);
			elem_t dequeued_elem4 = 0;
			Queue_status status4 = Queue_dequeue(&target, &dequeued_elem4);
			elem_t dequeued_elem5 = 0;
			Queue_status status5 = Queue_dequeue(&target, &dequeued_elem5);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			Assert::AreEqual(1, dequeued_elem1);
			Assert::AreEqual(2, dequeued_elem2);
			Assert::AreEqual(3, dequeued_elem3);
			Assert::AreEqual(4, dequeued_elem4);
			Assert::AreEqual(5, dequeued_elem5);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.front);
			Assert::AreEqual(0U, target.size);
		}

		TEST_METHOD(underflow)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.size = 5U;

			elem_t dequeued_elem1 = 0;
			Queue_status status1 = Queue_dequeue(&target, &dequeued_elem1);
			elem_t dequeued_elem2 = 0;
			Queue_status status2 = Queue_dequeue(&target, &dequeued_elem2);
			elem_t dequeued_elem3 = 0;
			Queue_status status3 = Queue_dequeue(&target, &dequeued_elem3);
			elem_t dequeued_elem4 = 0;
			Queue_status status4 = Queue_dequeue(&target, &dequeued_elem4);
			elem_t dequeued_elem5 = 0;
			Queue_status status5 = Queue_dequeue(&target, &dequeued_elem5);
			elem_t dequeued_elem6 = 0;
			Queue_status status6 = Queue_dequeue(&target, &dequeued_elem6);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			Assert::AreEqual<int>(QUEUE_FAILURE, status6);
			Assert::AreEqual(1, dequeued_elem1);
			Assert::AreEqual(2, dequeued_elem2);
			Assert::AreEqual(3, dequeued_elem3);
			Assert::AreEqual(4, dequeued_elem4);
			Assert::AreEqual(5, dequeued_elem5);
			Assert::AreEqual(0, dequeued_elem6);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.front);
			Assert::AreEqual(0U, target.size);
		}

		TEST_METHOD(enqueue_data_to_full_if_front_is_not_0)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.front = 2U;
			target.size = 0U;

			elem_t enqueued_elem = 1;
			Queue_status status1 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 2;
			Queue_status status2 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 3;
			Queue_status status3 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 4;
			Queue_status status4 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 5;
			Queue_status status5 = Queue_enqueue(&target, &enqueued_elem);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			elem_t expected_memory[MEMORY_SIZE] = { 4, 5, 1, 2, 3 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(2U, target.front);
			Assert::AreEqual(5U, target.size);
		}

		TEST_METHOD(overflow_if_front_is_not_0)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.front = 2U;
			target.size = 0U;

			elem_t enqueued_elem = 1;
			Queue_status status1 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 2;
			Queue_status status2 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 3;
			Queue_status status3 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 4;
			Queue_status status4 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 5;
			Queue_status status5 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 6;
			Queue_status status6 = Queue_enqueue(&target, &enqueued_elem);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			Assert::AreEqual<int>(QUEUE_FAILURE, status6);
			elem_t expected_memory[MEMORY_SIZE] = { 4, 5, 1, 2, 3 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(2U, target.front);
			Assert::AreEqual(5U, target.size);
		}

		TEST_METHOD(dequeue_data_to_empty_if_front_is_not_0)
		{
			elem_t memory[MEMORY_SIZE] = { 4, 5, 1, 2, 3 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.front = 2U;
			target.size = 5U;

			elem_t dequeued_elem1 = 0;
			Queue_status status1 = Queue_dequeue(&target, &dequeued_elem1);
			elem_t dequeued_elem2 = 0;
			Queue_status status2 = Queue_dequeue(&target, &dequeued_elem2);
			elem_t dequeued_elem3 = 0;
			Queue_status status3 = Queue_dequeue(&target, &dequeued_elem3);
			elem_t dequeued_elem4 = 0;
			Queue_status status4 = Queue_dequeue(&target, &dequeued_elem4);
			elem_t dequeued_elem5 = 0;
			Queue_status status5 = Queue_dequeue(&target, &dequeued_elem5);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			Assert::AreEqual(1, dequeued_elem1);
			Assert::AreEqual(2, dequeued_elem2);
			Assert::AreEqual(3, dequeued_elem3);
			Assert::AreEqual(4, dequeued_elem4);
			Assert::AreEqual(5, dequeued_elem5);
			elem_t expected_memory[MEMORY_SIZE] = { 4, 5, 1, 2, 3 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(2U, target.front);
			Assert::AreEqual(0U, target.size);
		}

		TEST_METHOD(underflow_if_front_is_not_0)
		{
			elem_t memory[MEMORY_SIZE] = { 4, 5, 1, 2, 3 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);
			target.front = 2U;
			target.size = 5U;

			elem_t dequeued_elem1 = 0;
			Queue_status status1 = Queue_dequeue(&target, &dequeued_elem1);
			elem_t dequeued_elem2 = 0;
			Queue_status status2 = Queue_dequeue(&target, &dequeued_elem2);
			elem_t dequeued_elem3 = 0;
			Queue_status status3 = Queue_dequeue(&target, &dequeued_elem3);
			elem_t dequeued_elem4 = 0;
			Queue_status status4 = Queue_dequeue(&target, &dequeued_elem4);
			elem_t dequeued_elem5 = 0;
			Queue_status status5 = Queue_dequeue(&target, &dequeued_elem5);
			elem_t dequeued_elem6 = 0;
			Queue_status status6 = Queue_dequeue(&target, &dequeued_elem6);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			Assert::AreEqual<int>(QUEUE_FAILURE, status6);
			Assert::AreEqual(1, dequeued_elem1);
			Assert::AreEqual(2, dequeued_elem2);
			Assert::AreEqual(3, dequeued_elem3);
			Assert::AreEqual(4, dequeued_elem4);
			Assert::AreEqual(5, dequeued_elem5);
			Assert::AreEqual(0, dequeued_elem6);
			elem_t expected_memory[MEMORY_SIZE] = { 4, 5, 1, 2, 3 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(2U, target.front);
			Assert::AreEqual(0U, target.size);
		}

		TEST_METHOD(compound_test)
		{
			// Test enqueue(e) and dequeue(d) in the following order:
			// e e d e e e d d d d e e d

			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Queue target = Queue_new(elem_t, memory, MEMORY_SIZE);

			elem_t enqueued_elem = 1;
			Queue_status status1 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 2;
			Queue_status status2 = Queue_enqueue(&target, &enqueued_elem);
			elem_t dequeued_elem1 = 0;
			Queue_status status3 = Queue_dequeue(&target, &dequeued_elem1);
			enqueued_elem = 3;
			Queue_status status4 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 4;
			Queue_status status5 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 5;
			Queue_status status6 = Queue_enqueue(&target, &enqueued_elem);
			elem_t dequeued_elem2 = 0;
			Queue_status status7 = Queue_dequeue(&target, &dequeued_elem2);
			elem_t dequeued_elem3 = 0;
			Queue_status status8 = Queue_dequeue(&target, &dequeued_elem3);
			elem_t dequeued_elem4 = 0;
			Queue_status status9 = Queue_dequeue(&target, &dequeued_elem4);
			elem_t dequeued_elem5 = 0;
			Queue_status status10 = Queue_dequeue(&target, &dequeued_elem5);
			enqueued_elem = 6;
			Queue_status status11 = Queue_enqueue(&target, &enqueued_elem);
			enqueued_elem = 7;
			Queue_status status12 = Queue_enqueue(&target, &enqueued_elem);
			elem_t dequeued_elem6 = 0;
			Queue_status status13 = Queue_dequeue(&target, &dequeued_elem6);

			Assert::AreEqual<int>(QUEUE_SUCCESS, status1);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status2);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status3);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status4);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status5);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status6);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status7);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status8);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status9);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status10);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status11);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status12);
			Assert::AreEqual<int>(QUEUE_SUCCESS, status13);
			Assert::AreEqual(1, dequeued_elem1);
			Assert::AreEqual(2, dequeued_elem2);
			Assert::AreEqual(3, dequeued_elem3);
			Assert::AreEqual(4, dequeued_elem4);
			Assert::AreEqual(5, dequeued_elem5);
			Assert::AreEqual(6, dequeued_elem6);
			elem_t expected_memory[MEMORY_SIZE] = { 6, 7, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(1U, target.front);
			Assert::AreEqual(1U, target.size);
		}
	};
}
