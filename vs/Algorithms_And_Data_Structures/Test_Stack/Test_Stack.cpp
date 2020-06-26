#include "CppUnitTest.h"
#include <stdlib.h>

extern "C" {
#include "Stack.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define MEMORY_SIZE 5U
#define LARGE_MEMORY_SIZE 6U 
#define SMALE_MEMORY_SIZE 4U

typedef int elem_t;

struct AnyType {
	char a;
	int b;
};

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
			Assert::AreEqual(MEMORY_SIZE, target.capacity);
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
			Assert::AreEqual(MEMORY_SIZE, target.capacity);
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

			Stack_bool is_empty = Stack_is_empty(&target);

			Assert::AreEqual<int>(STACK_TRUE, is_empty);
		}

		TEST_METHOD(stack_is_not_empty)
		{
			elem_t memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);
			target.pointer = 1U;

			Stack_bool is_empty = Stack_is_empty(&target);

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

			Stack_bool is_full = Stack_is_full(&target);

			Assert::AreEqual<int>(STACK_TRUE, is_full);
		}

		TEST_METHOD(stack_is_not_full)
		{
			elem_t memory[MEMORY_SIZE];
			Stack target = Stack_new(elem_t, memory, MEMORY_SIZE);

			Stack_bool is_full = Stack_is_full(&target);

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
			Stack_status status = Stack_push(&target, &pushed_elem);

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
			Stack_status status1 = Stack_push(&target, &pushed_elem);
			pushed_elem = 2;
			Stack_status status2 = Stack_push(&target, &pushed_elem);
			pushed_elem = 3;
			Stack_status status3 = Stack_push(&target, &pushed_elem);
			pushed_elem = 4;
			Stack_status status4 = Stack_push(&target, &pushed_elem);
			pushed_elem = 5;
			Stack_status status5 = Stack_push(&target, &pushed_elem);

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
			Stack_status status1 = Stack_push(&target, &pushed_elem);
			pushed_elem = 2;
			Stack_status status2 = Stack_push(&target, &pushed_elem);
			pushed_elem = 3;
			Stack_status status3 = Stack_push(&target, &pushed_elem);
			pushed_elem = 4;
			Stack_status status4 = Stack_push(&target, &pushed_elem);
			pushed_elem = 5;
			Stack_status status5 = Stack_push(&target, &pushed_elem);
			pushed_elem = 6;
			Stack_status status6 = Stack_push(&target, &pushed_elem);

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

		TEST_METHOD(push_a_datum_of_AnyType)
		{
			AnyType memory[MEMORY_SIZE] = { {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0} };
			Stack target = Stack_new(AnyType, memory, MEMORY_SIZE);

			AnyType pushed_elem = { 'a', 1 };
			Stack_status status = Stack_push(&target, &pushed_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			AnyType expected_memory[MEMORY_SIZE] = { {'a', 1}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0} };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(1U, target.pointer);
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
			Stack_status status = Stack_pop(&target, &poped_elem);

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
			Stack_status status5 = Stack_pop(&target, &poped_elem5);
			elem_t poped_elem4 = 0;
			Stack_status status4 = Stack_pop(&target, &poped_elem4);
			elem_t poped_elem3 = 0;
			Stack_status status3 = Stack_pop(&target, &poped_elem3);
			elem_t poped_elem2 = 0;
			Stack_status status2 = Stack_pop(&target, &poped_elem2);
			elem_t poped_elem1 = 0;
			Stack_status status1 = Stack_pop(&target, &poped_elem1);

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
			Stack_status status5 = Stack_pop(&target, &poped_elem5);
			elem_t poped_elem4 = 0;
			Stack_status status4 = Stack_pop(&target, &poped_elem4);
			elem_t poped_elem3 = 0;
			Stack_status status3 = Stack_pop(&target, &poped_elem3);
			elem_t poped_elem2 = 0;
			Stack_status status2 = Stack_pop(&target, &poped_elem2);
			elem_t poped_elem1 = 0;
			Stack_status status1 = Stack_pop(&target, &poped_elem1);
			elem_t poped_elem = 0;
			Stack_status status = Stack_pop(&target, &poped_elem);

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

			Stack_status status = Stack_pop(&target, NULL);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			elem_t expected_memory[MEMORY_SIZE] = { 1, 0, 0, 0, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.pointer);
		}

		TEST_METHOD(pop_a_datum_of_AnyType)
		{
			AnyType memory[MEMORY_SIZE] = { {'a', 1}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0} };
			Stack target = Stack_new(AnyType, memory, MEMORY_SIZE);
			target.pointer = 1U;

			AnyType poped_elem;
			Stack_status status = Stack_pop(&target, &poped_elem);

			Assert::AreEqual<int>(STACK_SUCCESS, status);
			AnyType expected_elem = { 'a', 1 };
			Assert::AreEqual(0, memcmp(&expected_elem, &poped_elem, sizeof(poped_elem)));
			AnyType expected_memory[MEMORY_SIZE] = { {'a', 1}, {'\0', 0}, {'\0', 0}, {'\0', 0}, {'\0', 0} };
			Assert::AreEqual(0, memcmp(expected_memory, memory, sizeof(memory)));
			Assert::AreEqual(0U, target.pointer);
		}
	};

	TEST_CLASS(Test_Stack_copy)
	{
	public:

		TEST_METHOD(normal)
		{
			elem_t src_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Stack src = Stack_new(elem_t, src_memory, MEMORY_SIZE);
			src.pointer = 5U;
			elem_t dst_memory[MEMORY_SIZE] = { 0, 0, 0, 0, 0 };
			Stack dst = Stack_new(elem_t, dst_memory, MEMORY_SIZE);

			Stack_copy(&dst, &src);

			Assert::AreEqual(sizeof(elem_t), dst.elem_size);
			Assert::AreNotEqual(dst.memory, src.memory);
			Assert::AreEqual(0, memcmp(dst.memory, src.memory, sizeof(dst_memory)));
			Assert::AreEqual(MEMORY_SIZE, dst.capacity);
			Assert::AreEqual(5U, dst.pointer);
		}

		TEST_METHOD(the_size_of_destination_stack_memory_area_is_larger_than_the_pointer_of_source_stack)
		{
			elem_t src_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Stack src = Stack_new(elem_t, src_memory, MEMORY_SIZE);
			src.pointer = 5U;
			elem_t dst_memory[LARGE_MEMORY_SIZE] = { 0, 0, 0, 0, 0, 0 };
			Stack dst = Stack_new(elem_t, dst_memory, LARGE_MEMORY_SIZE);

			Stack_copy(&dst, &src);

			Assert::AreEqual(sizeof(elem_t), dst.elem_size);
			Assert::AreNotEqual(dst.memory, src.memory);
			elem_t expected_memory[LARGE_MEMORY_SIZE] = { 1, 2, 3, 4, 5, 0 };
			Assert::AreEqual(0, memcmp(expected_memory, dst.memory, sizeof(dst_memory)));
			Assert::AreEqual(LARGE_MEMORY_SIZE, dst.capacity);
			Assert::AreEqual(5U, dst.pointer);
		}

		TEST_METHOD(the_size_of_destination_stack_memory_area_is_smaler_than_the_pointer_of_source_stack)
		{
			elem_t src_memory[MEMORY_SIZE] = { 1, 2, 3, 4, 5 };
			Stack src = Stack_new(elem_t, src_memory, MEMORY_SIZE);
			src.pointer = 5U;
			elem_t dst_memory[SMALE_MEMORY_SIZE] = { 0, 0, 0, 0 };
			Stack dst = Stack_new(elem_t, dst_memory, SMALE_MEMORY_SIZE);

			Stack_copy(&dst, &src);

			Assert::AreEqual(sizeof(elem_t), dst.elem_size);
			Assert::AreNotEqual(dst.memory, src.memory);
			elem_t expected_memory[SMALE_MEMORY_SIZE] = { 1, 2, 3, 4 };
			Assert::AreEqual(0, memcmp(expected_memory, dst.memory, sizeof(dst_memory)));
			Assert::AreEqual(SMALE_MEMORY_SIZE, dst.capacity);
			Assert::AreEqual(4U, dst.pointer);
		}
	};
}
