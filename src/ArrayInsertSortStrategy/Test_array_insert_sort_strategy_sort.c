/**
 * @file      Test_array_insert_sort_strategy_sort.c
 * @brief     Test for array_insert_sort_strategy_sort
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "ArrayInsertSortStrategy.h"
#include "Array.h"
#include "CompStrategy.h"
#include "SortStrategy.h"

#if 1
#define TEST_COMP_ASCE
#endif

#if defined(TEST_COMP_ASCE)
static template_compare_asce(int, test_comp_asce);
#else /* TEST_COMP_ASCE */
static template_compare_desc(int, test_comp_desc);
#endif /* TEST_COMP_ASCE */

void test(int argc, char* argv[])
{
	#define ARRAY_SIZE 5
	int memory[ARRAY_SIZE] = {4, 1, 3, 2, 0};
	Array array = new_Array(int, memory, ARRAY_SIZE);
	unsigned int index_array[ARRAY_SIZE];

	array.set_index_array(&array, index_array);
	array.init_index_array(&array);

#if defined(TEST_COMP_ASCE)
	CompStrategy comp_strtgy = new_CompStrategy(test_comp_asce);
#else /* TEST_COMP_ASCE */
	CompStrategy comp_strtgy = new_CompStrategy(test_comp_desc);
#endif /* TEST_COMP_ASCE */
	array.implement_comp_strategy(&array, &comp_strtgy);
	ArrayInsertSortStrategy sort_strtgy = new_ArrayInsertSortStrategy();
	array.implement_sort_strategy(&array, (SortStrategy*) &sort_strtgy);

	/* Display the contents of the array before sorting. */
	printf("Before: ");
	array_iprint(int, &array, "%d ", -1);
	printf("\n");

	/* Call sort function */
	array.sort(array.sort_strtgy, &array);

	/* Display the contents of the array after sorting. */
	printf("After : ");
	array_iprint(int, &array, "%d ", -1);
	printf("\n");

	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
