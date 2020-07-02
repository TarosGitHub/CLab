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
			Cell* cell = (Cell*)malloc(sizeof(Cell));
			cell->next = (Cell*)NULL;
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
			Cell* cell = (Cell*)malloc(sizeof(Cell));
			cell->next = (Cell*)NULL;
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
	};

	TEST_CLASS(Test_LinkedList_add)
	{
	public:

		TEST_METHOD(normal)
		{
			LinkedList* list = LinkedList_create(sizeof(cell_t));
			list->value_type_size = sizeof(cell_t);
			list->head.next = NULL;
			list->head.value = NULL;
			list->tail = &list->head;
			list->size = 0U;

			MockRepository mocks;
			mocks.ExpectCallFunc(Cell_create).Return(NULL);

			cell_t added_value = 1;
			LinkedListStatus status = LinkedList_add(list, &added_value);

			Assert::AreEqual<int>(LINKED_LIST_FAILURE, status);

			LinkedList_destroy(list);
		}
	};
}
