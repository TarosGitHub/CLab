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
			Assert::AreEqual(0U, target.rear);
			Assert::AreEqual<int>(QUEUE_TRUE, target.is_empty);
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
			Assert::AreEqual(0U, target.rear);
			Assert::AreEqual<int>(QUEUE_TRUE, target.is_empty);
		}
	};
}
