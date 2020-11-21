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
}
