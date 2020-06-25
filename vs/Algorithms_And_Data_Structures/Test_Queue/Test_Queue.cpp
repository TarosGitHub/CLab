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
}
