#include "CppUnitTest.h"
#include "hippomocks.h"

extern "C" {
#include "LinkedList.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef int cell_t;

namespace TestLinkedList
{
	TEST_CLASS(Test_LinkedList_create_destroy)
	{
	public:
		
		TEST_METHOD(normal)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(memory_allocation_error)
		{
			MockRepository mocks;
			mocks.ExpectCallFunc(LinkedListCell_create).Return(NULL);

			LinkedList* list = LinkedList_create(sizeof(cell_t));

			Assert::AreEqual((void*)NULL, (void*)list);
		}
	};

	TEST_CLASS(Test_LinkedList_delete_all)
	{
	public:

		TEST_METHOD(there_is_a_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			LinkedListCell* cell = LinkedListCell_create(NULL, NULL, 0U);
			LinkedListCell_set_next(list->head, cell);
			list->size = 1U;

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}
		
		TEST_METHOD(there_are_two_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			LinkedListCell* cell1 = LinkedListCell_create(NULL, NULL, 0U);
			LinkedListCell* cell2 = LinkedListCell_create(NULL, NULL, 0U);
			LinkedListCell_set_next(list->head, cell1);
			LinkedListCell_set_next(cell1, cell2);
			list->size = 2U;

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(there_is_no_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}
	};

	TEST_CLASS(Test_LinkedList_begin)
	{
	public:

		TEST_METHOD(normal)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			LinkedListIterator iterator;

			LinkedList_begin(list, &iterator);

			Assert::AreEqual((void*)list->head, (void*)iterator.current);

			LinkedList_destroy(list);
		}
	};

#if 0
	TEST_CLASS(Test_LinkedList_add)
	{
	public:

		TEST_METHOD(add_a_value_to_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));

			cell_t added_value = 1;
			LinkedListStatus status = LinkedList_add(list, &added_value);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status);
			Assert::AreNotEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)list->head.next, (void*)list->tail);
			Assert::AreEqual(added_value, *(cell_t*)list->head.next->value);
			Assert::AreEqual(1U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(add_two_values_to_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));

			cell_t added_value1 = 1;
			LinkedListStatus status1 = LinkedList_add(list, &added_value1);
			cell_t added_value2 = 2;
			LinkedListStatus status2 = LinkedList_add(list, &added_value2);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status1);
			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status2);
			Assert::AreNotEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)list->head.next->next, (void*)list->tail);
			Assert::AreEqual(added_value1, *(cell_t*)list->head.next->value);
			Assert::AreEqual(added_value2, *(cell_t*)list->head.next->next->value);
			Assert::AreEqual(2U, list->size);

			LinkedList_destroy(list);
		}

		// TODO: 追加に失敗した場合のテストができていない -> mallocをMockで置き換えられない
		TEST_METHOD(adding_fails)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));

			MockRepository mocks;
			mocks.ExpectCallFunc(LinkedListCell_create).Return(NULL);

			cell_t added_value = 1;
			LinkedListStatus status = LinkedList_add(list, &added_value);

			Assert::AreEqual<int>(LINKED_LIST_FAILURE, status);

			LinkedList_destroy(list);
		}
	};

	TEST_CLASS(Test_LinkedList_remove)
	{
	public:

		TEST_METHOD(a_cell_is_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			cell_t added_value1 = 1;
			LinkedListStatus status1 = LinkedList_add(list, &added_value1);

			LinkedList_remove(list);

			Assert::AreNotEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)&list->head, (void*)list->tail);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(two_cell_is_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			cell_t added_value1 = 1;
			LinkedListStatus status1 = LinkedList_add(list, &added_value1);
			cell_t added_value2 = 2;
			LinkedListStatus status2 = LinkedList_add(list, &added_value2);

			LinkedList_remove(list);

			Assert::AreNotEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)NULL, (void*)list->head.next->next);
			Assert::AreEqual((void*)list->head.next, (void*)list->tail);
			Assert::AreEqual(added_value1, *(cell_t*)list->head.next->value);
			Assert::AreEqual(1U, list->size);

			LinkedList_destroy(list);
		}
	};
#endif
}
