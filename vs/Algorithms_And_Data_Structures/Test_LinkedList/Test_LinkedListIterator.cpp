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
			LinkedListCell previous_cell;

			LinkedListIterator target = LinkedListIterator_new(&current_cell, &previous_cell);

			Assert::AreEqual((void*)&current_cell, (void*)target.current);
			Assert::AreEqual((void*)&previous_cell, (void*)target.previous);
		}
	};

	TEST_CLASS(Test_LinkedListIterator_init)
	{
	public:

		TEST_METHOD(normal)
		{
			LinkedListCell current_cell;
			LinkedListCell previous_cell;
			LinkedListIterator target;
			
			LinkedListIterator_init(&target, &current_cell, &previous_cell);

			Assert::AreEqual((void*)&current_cell, (void*)target.current);
			Assert::AreEqual((void*)&previous_cell, (void*)target.previous);
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
			LinkedListIterator target = LinkedListIterator_new(cell_has_next, NULL);

			Boolean has_next = LinkedListIterator_has_next(&target);

			Assert::AreEqual<int>(TRUE, has_next);
		}

		TEST_METHOD(does_not_have_next_pointer)
		{
			LinkedListIterator target = LinkedListIterator_new(cell_has_no_next, NULL);

			Boolean has_next = LinkedListIterator_has_next(&target);

			Assert::AreEqual<int>(FALSE, has_next);
		}
	};
}
