#include "CppUnitTest.h"

extern "C" {
#include "LinkedListIterator.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef int value_t;

namespace TestLinkedListIterator
{
	TEST_CLASS(Test_LinkedListIterator_new)
	{
	public:

		TEST_METHOD(normal)
		{
			LinkedListCell current_cell;

			LinkedListIterator target = LinkedListIterator_new(&current_cell);

			Assert::AreEqual((void*)&current_cell, (void*)target.current);
		}
	};

	TEST_CLASS(Test_LinkedListIterator_init)
	{
	public:

		TEST_METHOD(normal)
		{
			LinkedListCell current_cell;
			LinkedListIterator target;
			
			LinkedListIterator_init(&target, &current_cell);

			Assert::AreEqual((void*)&current_cell, (void*)target.current);
		}
	};

	TEST_CLASS(Test_LinkedListIterator_get_cell)
	{
	public:

		value_t value = 1;
		LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

		TEST_METHOD(normal)
		{
			LinkedListIterator target = LinkedListIterator_new(cell);

			LinkedListCell* getted_cell = LinkedListIterator_get_cell(&target);

			Assert::AreEqual((void*)cell, (void*)getted_cell);
		}
	};

	TEST_CLASS(Test_LinkedListIterator_has_next)
	{
	public:

		value_t value = 1;
		LinkedListCell next_cell;
		LinkedListCell* cell_has_next = LinkedListCell_create(&next_cell, &value, sizeof(value_t));
		LinkedListCell* cell_has_no_next = LinkedListCell_create(NULL, &value, sizeof(value_t));

		TEST_METHOD(has_next_pointer)
		{
			LinkedListIterator target = LinkedListIterator_new(cell_has_next);

			Boolean has_next = LinkedListIterator_has_next(&target);

			Assert::AreEqual<int>(TRUE, has_next);
		}

		TEST_METHOD(does_not_have_next_pointer)
		{
			LinkedListIterator target = LinkedListIterator_new(cell_has_no_next);

			Boolean has_next = LinkedListIterator_has_next(&target);

			Assert::AreEqual<int>(FALSE, has_next);
		}
	};

	TEST_CLASS(Test_LinkedListIterator_next)
	{
	public:

		value_t value = 1;
		LinkedListCell* last_cell = LinkedListCell_create(NULL, &value, sizeof(value_t));
		LinkedListCell* first_cell = LinkedListCell_create(last_cell, &value, sizeof(value_t));
		LinkedListCell* head_cell = LinkedListCell_create(first_cell, &value, sizeof(value_t));

		TEST_METHOD(move_next)
		{
			LinkedListIterator target = LinkedListIterator_new(first_cell);

			LinkedListIterator_next(&target);

			Assert::AreEqual((void*)last_cell, (void*)target.current);
		}

		TEST_METHOD(overrun)
		{
			LinkedListIterator target = LinkedListIterator_new(first_cell);

			LinkedListIterator_next(&target);
			LinkedListIterator_next(&target);

			Assert::AreEqual((void*)NULL, (void*)target.current);
		}
	};

	TEST_CLASS(Test_LinkedListIterator_get)
	{
	public:

		value_t value = 1;
		LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

		TEST_METHOD(normal)
		{
			LinkedListIterator target = LinkedListIterator_new(cell);

			value_t getted_value = 0;
			LinkedListIterator_get(&target, &getted_value);

			Assert::AreEqual(value, getted_value);
		}
	};

	TEST_CLASS(Test_LinkedListIterator_set)
	{
	public:

		value_t value = 1;
		LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

		TEST_METHOD(normal)
		{
			LinkedListIterator target = LinkedListIterator_new(cell);

			value_t setted_value = 2;
			LinkedListIterator_set(&target, &setted_value);

			value_t actual_value;
			LinkedListCell_get(cell, &actual_value);
			Assert::AreEqual(setted_value, actual_value);
		}
	};
}
