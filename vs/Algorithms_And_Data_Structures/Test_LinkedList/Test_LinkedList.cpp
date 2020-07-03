#include "CppUnitTest.h"
#include "hippomocks.h"

extern "C" {
#include "LinkedList.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef int value_t;

namespace TestLinkedList
{
	TEST_CLASS(Test_LinkedList_create_destroy)
	{
	public:
		
		TEST_METHOD(normal)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(value_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(memory_allocation_error)
		{
			MockRepository mocks;
			mocks.ExpectCallFunc(LinkedListCell_create).Return(NULL);

			LinkedList* list = LinkedList_create(sizeof(value_t));

			Assert::AreEqual((void*)NULL, (void*)list);
		}
	};

	TEST_CLASS(Test_LinkedList_delete_all)
	{
	public:

		TEST_METHOD(there_is_a_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListCell* cell = LinkedListCell_create(NULL, NULL, 0U);
			LinkedListCell_set_next(list->head, cell);
			list->size = 1U;

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(value_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}
		
		TEST_METHOD(there_are_two_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListCell* cell1 = LinkedListCell_create(NULL, NULL, 0U);
			LinkedListCell* cell2 = LinkedListCell_create(NULL, NULL, 0U);
			LinkedListCell_set_next(list->head, cell1);
			LinkedListCell_set_next(cell1, cell2);
			list->size = 2U;

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(value_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(there_is_no_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreNotEqual((void*)NULL, (void*)list->head);
			Assert::AreEqual(sizeof(value_t), list->value_type_size);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}
	};

	TEST_CLASS(Test_LinkedList_begin)
	{
	public:

		TEST_METHOD(normal)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;

			LinkedList_begin(list, &iterator);

			Assert::AreEqual((void*)list->head, (void*)iterator.current);

			LinkedList_destroy(list);
		}
	};

	TEST_CLASS(Test_LinkedList_insert)
	{
	public:

		TEST_METHOD(insert_a_value_to_the_empty_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);

			value_t added_value = 1;
			LinkedListStatus status = LinkedList_insert(list, &iterator, &added_value);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status);
			Assert::AreNotEqual((void*)NULL, (void*)list->head->next);
			Assert::AreEqual(added_value, *(value_t*)list->head->next->value);
			Assert::AreEqual(1U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(insert_the_second_value_to_the_front_of_the_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);

			value_t added_value1 = 1;
			LinkedListStatus status1 = LinkedList_insert(list, &iterator, &added_value1);
			value_t added_value2 = 2;
			LinkedListStatus status2 = LinkedList_insert(list, &iterator, &added_value2);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status1);
			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status2);
			Assert::AreNotEqual((void*)NULL, (void*)list->head->next);
			Assert::AreNotEqual((void*)NULL, (void*)list->head->next->next);
			Assert::AreNotEqual((void*)list->head->next, (void*)list->head->next->next);
			Assert::AreEqual(added_value2, *(value_t*)list->head->next->value);
			Assert::AreEqual(added_value1, *(value_t*)list->head->next->next->value);
			Assert::AreEqual(2U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(insert_the_second_value_to_the_back_of_the_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);

			value_t added_value1 = 1;
			LinkedListStatus status1 = LinkedList_insert(list, &iterator, &added_value1);
			LinkedListIterator_next(&iterator);
			value_t added_value2 = 2;
			LinkedListStatus status2 = LinkedList_insert(list, &iterator, &added_value2);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status1);
			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status2);
			Assert::AreNotEqual((void*)NULL, (void*)list->head->next);
			Assert::AreNotEqual((void*)NULL, (void*)list->head->next->next);
			Assert::AreNotEqual((void*)list->head->next, (void*)list->head->next->next);
			Assert::AreEqual(added_value1, *(value_t*)list->head->next->value);
			Assert::AreEqual(added_value2, *(value_t*)list->head->next->next->value);
			Assert::AreEqual(2U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(memory_allocation_error)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);

			MockRepository mocks;
			mocks.ExpectCallFunc(LinkedListCell_create).Return(NULL);

			value_t added_value = 1;
			LinkedListStatus status = LinkedList_insert(list, &iterator, &added_value);

			Assert::AreEqual<int>(LINKED_LIST_FAILURE, status);

			LinkedList_destroy(list);
		}
	};

	TEST_CLASS(Test_LinkedList_remove)
	{
	public:

		TEST_METHOD(there_is_a_cell_in_the_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);
			value_t added_value = 1;
			LinkedList_insert(list, &iterator, &added_value);

			value_t removed_value = 0;
			LinkedListStatus status = LinkedList_remove(list, &iterator, &removed_value);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status);
			Assert::AreEqual(added_value, removed_value);
			Assert::AreEqual((void*)NULL, (void*)list->head->next);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(remove_front_there_are_two_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);
			value_t added_value2 = 2;
			LinkedList_insert(list, &iterator, &added_value2);
			value_t added_value1 = 1;
			LinkedList_insert(list, &iterator, &added_value1);

			value_t removed_value = 0;
			LinkedListStatus status = LinkedList_remove(list, &iterator, &removed_value);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status);
			Assert::AreEqual(added_value1, removed_value);
			Assert::AreEqual(added_value2, *(value_t*)list->head->next->value);
			Assert::AreEqual(1U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(remove_back_there_are_two_cell_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);
			value_t added_value2 = 2;
			LinkedList_insert(list, &iterator, &added_value2);
			value_t added_value1 = 1;
			LinkedList_insert(list, &iterator, &added_value1);

			LinkedListIterator_next(&iterator);
			value_t removed_value = 0;
			LinkedListStatus status = LinkedList_remove(list, &iterator, &removed_value);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status);
			Assert::AreEqual(added_value2, removed_value);
			Assert::AreEqual(added_value1, *(value_t*)list->head->next->value);
			Assert::AreEqual(1U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(next_cell_does_not_exist)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);

			value_t removed_value = 0;
			LinkedListStatus status = LinkedList_remove(list, &iterator, &removed_value);

			Assert::AreEqual<int>(LINKED_LIST_FAILURE, status);
			Assert::AreEqual(0, removed_value);
			Assert::AreEqual((void*)NULL, (void*)list->head->next);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(removed_value_is_discarded)
		{
			LinkedList* list = LinkedList_create(sizeof(value_t));
			LinkedListIterator iterator;
			LinkedList_begin(list, &iterator);
			value_t added_value = 1;
			LinkedList_insert(list, &iterator, &added_value);

			LinkedListStatus status = LinkedList_remove(list, &iterator, NULL);

			Assert::AreEqual<int>(LINKED_LIST_SUCCESS, status);
			Assert::AreEqual((void*)NULL, (void*)list->head->next);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}
	};
}
