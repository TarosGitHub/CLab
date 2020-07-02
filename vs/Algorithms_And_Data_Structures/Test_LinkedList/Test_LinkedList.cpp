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
		// TODO: LinkedList_createがNULLを返す場合の単体テストができていない
	public:
		
		TEST_METHOD(normal)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)NULL, (void*)list->head.value);
			Assert::AreEqual((void*)&list->head, (void*)list->tail);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(a_cell_is_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			LinkedListCell* cell = (LinkedListCell*)malloc(sizeof(LinkedListCell));
			cell->next = (LinkedListCell*)NULL;
			cell->value = (char*)NULL;
			list->head.next = cell;
			list->tail = cell;
			list->size = 1U;

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreNotEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)NULL, (void*)list->head.value);
			Assert::AreEqual((void*)cell, (void*)list->tail);
			Assert::AreEqual(1U, list->size);

			LinkedList_destroy(list);
		}
	};

	TEST_CLASS(Test_LinkedList_delete_all)
	{
	public:

		TEST_METHOD(a_cell_is_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			LinkedListCell* cell = (LinkedListCell*)malloc(sizeof(LinkedListCell));
			cell->next = (LinkedListCell*)NULL;
			cell->value = (char*)NULL;
			list->head.next = cell;
			list->tail = cell;
			list->size = 1U;

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)NULL, (void*)list->head.value);
			Assert::AreEqual((void*)&list->head, (void*)list->tail);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}

		TEST_METHOD(no_cell_is_in_the_linked_list)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));

			LinkedList_delete_all(list);

			Assert::AreNotEqual((void*)NULL, (void*)list);
			Assert::AreEqual(sizeof(cell_t), list->value_type_size);
			Assert::AreEqual((void*)NULL, (void*)list->head.next);
			Assert::AreEqual((void*)NULL, (void*)list->head.value);
			Assert::AreEqual((void*)&list->head, (void*)list->tail);
			Assert::AreEqual(0U, list->size);

			LinkedList_destroy(list);
		}
	};

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
#if 0
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
#endif
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
}
