/**
 * @file      Test_array_range_min_strategy_min.c
 * @brief     Test for array_range_min_strategy_min
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "ArrayRangeMinStrategy.h"
#include "CompStrategy.h"
#include "Array.h"

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
	#define ARRAY_SIZE 10
	/*                       |0   |1   |2   |3   |4   |5   |6   |7   |8   |9   */
	int memory[ARRAY_SIZE] = { 141, 111,  31,   2,  10, -99,  -1,   0,   0,1090};
	Array array = new_Array(int, memory, ARRAY_SIZE);
	int min;

#if defined(TEST_COMP_ASCE)
	CompStrategy comp_strtgy = new_CompStrategy(test_comp_asce);
#else /* TEST_COMP_ASCE */
	CompStrategy comp_strtgy = new_CompStrategy(test_comp_desc);
#endif /* TEST_COMP_ASCE */
	array.implement_comp_strategy(&array, &comp_strtgy);
	ArrayRangeMinStrategy min_strtgy = new_ArrayRangeMinStrategy(2, 6);
	array.implement_min_strategy(&array, (MinStrategy*) &min_strtgy);

	/* Call min function */
	min = *(int*) array.min(array.min_strtgy, &array);
	printf("min=%d\n", min);

	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
