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
			Assert::AreEqual(value, *(value_t*)cell->value);

			LinkedListCell_destroy(cell);
		}

		TEST_METHOD(set_the_next_pointer)
		{
			struct LinkedListCell next_cell;
			value_t value = 1;
			struct LinkedListCell* cell = LinkedListCell_create(&next_cell, &value, sizeof(value_t));

			Assert::AreEqual((void*)&next_cell, (void*)cell->next);
			Assert::AreEqual(value, *(value_t*)cell->value);

			LinkedListCell_destroy(cell);
		}
	};
}
