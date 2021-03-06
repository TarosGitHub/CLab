#include "CppUnitTest.h"

extern "C" {
#include "LinkedListCell.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef int value_t;

namespace TestLinkedCell
{
	TEST_CLASS(Test_LinkedListCell_create_destroy)
	{
		// TODO: LinkedListCell_createがNULLを返すテストができていない
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			struct LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

			Assert::AreEqual((void*)NULL, (void*)cell->next);
			Assert::AreEqual(sizeof(value_t), cell->value_type_size);
			Assert::AreEqual(value, *(value_t*)cell->value);

			LinkedListCell_destroy(cell);
		}

		TEST_METHOD(set_the_next_pointer)
		{
			struct LinkedListCell next_cell;
			value_t value = 1;
			struct LinkedListCell* cell = LinkedListCell_create(&next_cell, &value, sizeof(value_t));

			Assert::AreEqual((void*)&next_cell, (void*)cell->next);
			Assert::AreEqual(sizeof(value_t), cell->value_type_size);
			Assert::AreEqual(value, *(value_t*)cell->value);

			LinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_LinkedListCell_has_next)
	{
	public:

		TEST_METHOD(has_next_pointer)
		{
			LinkedListCell next_cell;
			value_t value = 1;
			LinkedListCell* cell = LinkedListCell_create(&next_cell, &value, sizeof(value_t));

			Boolean it_has_next = LinkedListCell_has_next(cell);

			Assert::AreEqual<int>(TRUE, it_has_next);

			LinkedListCell_destroy(cell);
		}

		TEST_METHOD(does_not_have_next_pointer)
		{
			value_t value = 1;
			LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

			Boolean it_has_next = LinkedListCell_has_next(cell);

			Assert::AreEqual<int>(FALSE, it_has_next);

			LinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_LinkedListCell_get_next)
	{
	public:

		TEST_METHOD(has_next_pointer)
		{
			LinkedListCell next_cell;
			value_t value = 1;
			LinkedListCell* cell = LinkedListCell_create(&next_cell, &value, sizeof(value_t));

			LinkedListCell* next = LinkedListCell_get_next(cell);

			Assert::AreEqual((void*)&next_cell, (void*)next);

			LinkedListCell_destroy(cell);
		}

		TEST_METHOD(does_not_have_next_pointer)
		{
			value_t value = 1;
			LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

			LinkedListCell* next = LinkedListCell_get_next(cell);

			Assert::AreEqual((void*)NULL, (void*)next);

			LinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_LinkedListCell_set_next)
	{
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

			LinkedListCell next_cell;
			LinkedListCell_set_next(cell, &next_cell);

			Assert::AreEqual((void*)&next_cell, (void*)cell->next);

			LinkedListCell_destroy(cell);
		}
	};
	
	TEST_CLASS(Test_LinkedListCell_get)
	{
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			struct LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

			value_t getted_value = 0;
			LinkedListCell_get(cell, &getted_value);

			Assert::AreEqual(value, getted_value);

			LinkedListCell_destroy(cell);
		}
	};

	TEST_CLASS(Test_LinkedListCell_set)
	{
	public:

		TEST_METHOD(normal)
		{
			value_t value = 1;
			struct LinkedListCell* cell = LinkedListCell_create(NULL, &value, sizeof(value_t));

			value_t value_to_set = 2;
			LinkedListCell_set(cell, &value_to_set);

			Assert::AreEqual(value_to_set, *(value_t*)cell->value);

			LinkedListCell_destroy(cell);
		}
	};
}
