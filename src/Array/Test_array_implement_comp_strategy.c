/**
 * @file      Test_array_implement_comp_strategy.c
 * @brief     Test for array_implement_comp_strategy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Array.h"

static template_compare(int, array_test_compare);

void test(int argc, char* argv[])
{
	/* Make the Array object */
	#define ARRAY_SIZE 5
	int memory[ARRAY_SIZE] = {0};
	Array array = new_Array(int, memory, ARRAY_SIZE);

	/* Make the CompStrategy object */
	CompStrategy cmp_strtgy = new_CompStrategy(array_test_compare);

	/* Call the array_implement_comp_strategy function */
	array_implement_comp_strategy(&array, &cmp_strtgy); 
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
