#include "CppUnitTest.h"

extern "C" {
#include "Stack.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define MEMORY_SIZE 5

typedef int data_t;

namespace TestStack
{
	TEST_CLASS(Test_new_Stack)
	{
	public:
		
		TEST_METHOD(Test_normal)
		{
			data_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = new_Stack(data_t, memory, MEMORY_SIZE);

			Assert::AreEqual(sizeof(data_t), target.data_size);
			Assert::AreEqual((void*)memory, (void*)target.memory);
			Assert::AreEqual((unsigned int)MEMORY_SIZE, target.capacity);
			Assert::AreEqual(0U, target.size);
		}
	};

	TEST_CLASS(Test_Stack_push)
	{
	public:

		TEST_METHOD(Test_push_a_datum)
		{
			data_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = new_Stack(data_t, memory, MEMORY_SIZE);

			data_t data = 1;
			enum Stack_status status = Stack_push(&target, &data);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			Assert::AreEqual({ 0, 0, 0, 0, 1 }, memory);
			Assert::AreEqual(1U, target.size);
		}
	};

	TEST_CLASS(Test_Stack_pop)
	{
	public:

		TEST_METHOD(Test_pop_a_datum)
		{
			data_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = new_Stack(data_t, memory, MEMORY_SIZE);

			data_t data = 1;
			Stack_push(&target, &data);

			data_t poped_data = 0;
			enum Stack_status status = Stack_pop(&target, &poped_data);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			Assert::AreEqual(1, poped_data);
			Assert::AreEqual({ 0, 0, 0, 0, 0 }, memory);
			Assert::AreEqual(0U, target.size);
		}
	};
}
