#include "CppUnitTest.h"
#include <stdlib.h>

extern "C" {
#include "Stack.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define MEMORY_SIZE 5

typedef int elem_t;

namespace TestStack
{
	TEST_CLASS(Test_Stack_new)
	{
	public:
		
		TEST_METHOD(normal)
		{
			elem_t memory[MEMORY_SIZE];
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);

			Assert::AreEqual(sizeof(elem_t), target.elem_size);
			Assert::AreEqual((void*)memory, (void*)target.memory);
			Assert::AreEqual((unsigned int)MEMORY_SIZE, target.capacity);
			Assert::AreEqual(0U, target.pointer);
		}
	};

	TEST_CLASS(Test_Stack_init)
	{
	public:

		TEST_METHOD(normal)
		{
			elem_t memory[MEMORY_SIZE];
			Stack target;
			
			Stack_init(&target, sizeof(elem_t), memory, MEMORY_SIZE);

			Assert::AreEqual(sizeof(elem_t), target.elem_size);
			Assert::AreEqual((void*)memory, (void*)target.memory);
			Assert::AreEqual((unsigned int)MEMORY_SIZE, target.capacity);
			Assert::AreEqual(0U, target.pointer);
		}
	};

	TEST_CLASS(Test_Stack_is_empty)
	{
	public:

		TEST_METHOD(stack_is_empty)
		{
			elem_t memory[MEMORY_SIZE];
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);

			enum Stack_bool is_empty = Stack_is_empty(&target);

			Assert::AreEqual<int>(STACK_TRUE, is_empty);
		}

		TEST_METHOD(stack_is_not_empty)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 1U;

			enum Stack_bool is_empty = Stack_is_empty(&target);

			Assert::AreEqual<int>(STACK_FALSE, is_empty);
		}
	};

	TEST_CLASS(Test_Stack_is_full)
	{
	public:

		TEST_METHOD(stack_is_full)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 5U;

			enum Stack_bool is_full = Stack_is_full(&target);

			Assert::AreEqual<int>(STACK_TRUE, is_full);
		}

		TEST_METHOD(stack_is_not_full)
		{
			elem_t memory[MEMORY_SIZE];
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);

			enum Stack_bool is_full = Stack_is_full(&target);

			Assert::AreEqual<int>(STACK_FALSE, is_full);
		}
	};

	TEST_CLASS(Test_Stack_size)
	{
	public:

		TEST_METHOD(normal)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 1U;

			unsigned int size = Stack_size(&target);

			Assert::AreEqual(1U, size);
		}
	};

	TEST_CLASS(Test_Stack_push)
	{
	public:

		TEST_METHOD(push_a_datum)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);

			elem_t pushed_elem = 1;
			enum Stack_status status = Stack_push(&target, &pushed_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(1U, target.pointer);
		}

		TEST_METHOD(push_data_to_full)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);

			elem_t pushed_elem = 1;
			enum Stack_status status1 = Stack_push(&target, &pushed_elem);
			pushed_elem = 2;
			enum Stack_status status2 = Stack_push(&target, &pushed_elem);
			pushed_elem = 3;
			enum Stack_status status3 = Stack_push(&target, &pushed_elem);
			pushed_elem = 4;
			enum Stack_status status4 = Stack_push(&target, &pushed_elem);
			pushed_elem = 5;
			enum Stack_status status5 = Stack_push(&target, &pushed_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status1);
			Assert::AreEqual<int>(STACK_SUCCESS, status2);
			Assert::AreEqual<int>(STACK_SUCCESS, status3);
			Assert::AreEqual<int>(STACK_SUCCESS, status4);
			Assert::AreEqual<int>(STACK_SUCCESS, status5);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(5U, target.pointer);
		}

		TEST_METHOD(overflow)
		{
			elem_t memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);

			elem_t pushed_elem = 1;
			enum Stack_status status1 = Stack_push(&target, &pushed_elem);
			pushed_elem = 2;
			enum Stack_status status2 = Stack_push(&target, &pushed_elem);
			pushed_elem = 3;
			enum Stack_status status3 = Stack_push(&target, &pushed_elem);
			pushed_elem = 4;
			enum Stack_status status4 = Stack_push(&target, &pushed_elem);
			pushed_elem = 5;
			enum Stack_status status5 = Stack_push(&target, &pushed_elem);
			pushed_elem = 6;
			enum Stack_status status6 = Stack_push(&target, &pushed_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status1);
			Assert::AreEqual<int>(STACK_SUCCESS, status2);
			Assert::AreEqual<int>(STACK_SUCCESS, status3);
			Assert::AreEqual<int>(STACK_SUCCESS, status4);
			Assert::AreEqual<int>(STACK_SUCCESS, status5);
			Assert::AreEqual<int>(STACK_FAILURE, status6);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(5U, target.pointer);
		}
	};

	TEST_CLASS(Test_Stack_pop)
	{
	public:

		TEST_METHOD(pop_a_datum)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 1U;

			elem_t poped_elem = 0;
			enum Stack_status status = Stack_pop(&target, &poped_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			Assert::AreEqual(1, poped_elem);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.pointer);
		}

		TEST_METHOD(pop_data_to_empty)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 5U;

			elem_t poped_elem5 = 0;
			enum Stack_status status5 = Stack_pop(&target, &poped_elem5);
			elem_t poped_elem4 = 0;
			enum Stack_status status4 = Stack_pop(&target, &poped_elem4);
			elem_t poped_elem3 = 0;
			enum Stack_status status3 = Stack_pop(&target, &poped_elem3);
			elem_t poped_elem2 = 0;
			enum Stack_status status2 = Stack_pop(&target, &poped_elem2);
			elem_t poped_elem1 = 0;
			enum Stack_status status1 = Stack_pop(&target, &poped_elem1);

			Assert::AreEqual<int>(STACK_SUCCESS, status5);
			Assert::AreEqual<int>(STACK_SUCCESS, status4);
			Assert::AreEqual<int>(STACK_SUCCESS, status3);
			Assert::AreEqual<int>(STACK_SUCCESS, status2);
			Assert::AreEqual<int>(STACK_SUCCESS, status1);
			Assert::AreEqual(5, poped_elem5);
			Assert::AreEqual(4, poped_elem4);
			Assert::AreEqual(3, poped_elem3);
			Assert::AreEqual(2, poped_elem2);
			Assert::AreEqual(1, poped_elem1);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.pointer);
		}

		TEST_METHOD(underflow)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 5U;

			elem_t poped_elem5 = 0;
			enum Stack_status status5 = Stack_pop(&target, &poped_elem5);
			elem_t poped_elem4 = 0;
			enum Stack_status status4 = Stack_pop(&target, &poped_elem4);
			elem_t poped_elem3 = 0;
			enum Stack_status status3 = Stack_pop(&target, &poped_elem3);
			elem_t poped_elem2 = 0;
			enum Stack_status status2 = Stack_pop(&target, &poped_elem2);
			elem_t poped_elem1 = 0;
			enum Stack_status status1 = Stack_pop(&target, &poped_elem1);
			elem_t poped_elem = 0;
			enum Stack_status status = Stack_pop(&target, &poped_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status5);
			Assert::AreEqual<int>(STACK_SUCCESS, status4);
			Assert::AreEqual<int>(STACK_SUCCESS, status3);
			Assert::AreEqual<int>(STACK_SUCCESS, status2);
			Assert::AreEqual<int>(STACK_SUCCESS, status1);
			Assert::AreEqual<int>(STACK_FAILURE, status);
			Assert::AreEqual(5, poped_elem5);
			Assert::AreEqual(4, poped_elem4);
			Assert::AreEqual(3, poped_elem3);
			Assert::AreEqual(2, poped_elem2);
			Assert::AreEqual(1, poped_elem1);
			Assert::AreEqual(0, poped_elem);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.pointer);
		}

		TEST_METHOD(argument_elem_is_NULL)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 1U;

			enum Stack_status status = Stack_pop(&target, NULL);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.pointer);
		}
	};
}
