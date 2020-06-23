#include "CppUnitTest.h"

extern "C" {
#include "Stack.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define MEMORY_SIZE 5

typedef int elem_t;

namespace TestStack
{
	TEST_CLASS(Test_new_Stack)
	{
	public:
		
		TEST_METHOD(Test_normal)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = new_Stack(elem_t, memory, MEMORY_SIZE);

			Assert::AreEqual(sizeof(elem_t), target.elem_size);
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
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = new_Stack(elem_t, memory, MEMORY_SIZE);

			elem_t elem = 1;
			enum Stack_status status = Stack_push(&target, &elem);

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
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = new_Stack(elem_t, memory, MEMORY_SIZE);

			elem_t elem = 1;
			Stack_push(&target, &elem);

			elem_t poped_elem = 0;
			enum Stack_status status = Stack_pop(&target, &poped_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			Assert::AreEqual(1, poped_elem);
			Assert::AreEqual({ 0, 0, 0, 0, 0 }, memory);
			Assert::AreEqual(0U, target.size);
		}
	};
}
