/**
 * @file      Test_array_implement_sort_strategy.c
 * @brief     Test for array_implement_sort_strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Array.h"

/* The test sort function */
static void array_test_sort(void* sort_strtgy, void* const collection)
{
	/* DO NOTHING */
}

void test(int argc, char* argv[])
{
	/* Make the Array object */
	#define ARRAY_SIZE 5
	int memory[ARRAY_SIZE] = {0};
	Array array = new_Array(int, memory, ARRAY_SIZE);

	/* Make the SortStrategy object */
	SortStrategy sort_strtgy = new_SortStrategy(array_test_sort);

	/* Call the array_implement_sort_strategy function */
	array_implement_sort_strategy(&array, &sort_strtgy);
	printf("Construction completed.\n");

	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}


