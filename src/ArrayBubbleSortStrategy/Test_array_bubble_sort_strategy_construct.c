/**
 * @file      Test_array_bubble_sort_strategy_construct.c
 * @brief     Test for array_bubble_sort_strategy_construct
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "ArrayBubbleSortStrategy.h"

void test(int argc, char* argv[])
{
	ArrayBubbleSortStrategy sort_strtgy;
	
	array_bubble_sort_strategy_construct(&sort_strtgy);
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
