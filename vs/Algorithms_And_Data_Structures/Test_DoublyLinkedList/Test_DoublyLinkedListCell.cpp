#include "CppUnitTest.h"

extern "C" {
#include "DoublyLinkedListCell.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef int value_t;

namespace TestDoublyLinkedListCell
{
	TEST_CLASS(Test_DoublyLinkedListCell_create_destroy)
	{
		// TODO: DoublyLinkedListCell_create‚ªNULL‚ð•Ô‚·ƒeƒXƒg‚ª‚Å‚«‚Ä‚¢‚È‚¢
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			struct DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			Assert::AreEqual((void*)NULL, (void*)cell->prev);
			Assert::AreEqual((void*)NULL, (void*)cell->next);
			Assert::AreEqual(sizeof(value_t), cell->value_type_size);
			Assert::AreEqual(value, *(value_t*)cell->value);

			DoublyLinkedListCell_destroy(cell);
		}

		TEST_METHOD(sets_the_prev_and_next_pointers)
		{
			struct DoublyLinkedListCell prev_cell;
			struct DoublyLinkedListCell next_cell;
			value_t value = 1;
			struct DoublyLinkedListCell* cell = DoublyLinkedListCell_create(&prev_cell, &next_cell, &value, sizeof(value_t));

			Assert::AreEqual((void*)&prev_cell, (void*)cell->prev);
			Assert::AreEqual((void*)&next_cell, (void*)cell->next);
			Assert::AreEqual(sizeof(value_t), cell->value_type_size);
			Assert::AreEqual(value, *(value_t*)cell->value);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_has_prev)
	{
	public:

		TEST_METHOD(has_prev_pointer)
		{
			DoublyLinkedListCell prev_cell;
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(&prev_cell, NULL, &value, sizeof(value_t));

			Boolean it_has_prev = DoublyLinkedListCell_has_prev(cell);

			Assert::AreEqual<int>(TRUE, it_has_prev);

			DoublyLinkedListCell_destroy(cell);
		}

		TEST_METHOD(does_not_have_prev_pointer)
		{
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			Boolean it_has_prev = DoublyLinkedListCell_has_prev(cell);

			Assert::AreEqual<int>(FALSE, it_has_prev);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_has_next)
	{
	public:

		TEST_METHOD(has_next_pointer)
		{
			DoublyLinkedListCell next_cell;
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, &next_cell, &value, sizeof(value_t));

			Boolean it_has_next = DoublyLinkedListCell_has_next(cell);

			Assert::AreEqual<int>(TRUE, it_has_next);

			DoublyLinkedListCell_destroy(cell);
		}

		TEST_METHOD(does_not_have_next_pointer)
		{
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			Boolean it_has_next = DoublyLinkedListCell_has_next(cell);

			Assert::AreEqual<int>(FALSE, it_has_next);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_get_prev)
	{
	public:

		TEST_METHOD(has_prev_pointer)
		{
			DoublyLinkedListCell prev_cell;
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(&prev_cell, NULL, &value, sizeof(value_t));

			DoublyLinkedListCell* prev = DoublyLinkedListCell_get_prev(cell);

			Assert::AreEqual((void*)&prev_cell, (void*)prev);

			DoublyLinkedListCell_destroy(cell);
		}

		TEST_METHOD(does_not_have_prev_pointer)
		{
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			DoublyLinkedListCell* prev = DoublyLinkedListCell_get_prev(cell);

			Assert::AreEqual((void*)NULL, (void*)prev);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_get_next)
	{
	public:

		TEST_METHOD(has_next_pointer)
		{
			DoublyLinkedListCell next_cell;
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, &next_cell, &value, sizeof(value_t));

			DoublyLinkedListCell* next = DoublyLinkedListCell_get_next(cell);

			Assert::AreEqual((void*)&next_cell, (void*)next);

			DoublyLinkedListCell_destroy(cell);
		}

		TEST_METHOD(does_not_have_next_pointer)
		{
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			DoublyLinkedListCell* next = DoublyLinkedListCell_get_next(cell);

			Assert::AreEqual((void*)NULL, (void*)next);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_set_prev)
	{
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			DoublyLinkedListCell prev_cell;
			DoublyLinkedListCell_set_prev(cell, &prev_cell);

			Assert::AreEqual((void*)&prev_cell, (void*)cell->prev);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_set_next)
	{
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			DoublyLinkedListCell next_cell;
			DoublyLinkedListCell_set_next(cell, &next_cell);

			Assert::AreEqual((void*)&next_cell, (void*)cell->next);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_get)
	{
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			struct DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			value_t getted_value = 0;
			DoublyLinkedListCell_get(cell, &getted_value);

			Assert::AreEqual(value, getted_value);

			DoublyLinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_DoublyLinkedListCell_set)
	{
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			struct DoublyLinkedListCell* cell = DoublyLinkedListCell_create(NULL, NULL, &value, sizeof(value_t));

			value_t value_to_set = 2;
			DoublyLinkedListCell_set(cell, &value_to_set);

			Assert::AreEqual(value_to_set, *(value_t*)cell->value);

			DoublyLinkedListCell_destroy(cell);
		}
	};
}
