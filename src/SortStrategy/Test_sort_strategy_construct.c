/**
 * @file      Test_sort_strategy_construct.c
 * @brief     Test for sort_strategy_construct
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "SortStrategy.h"

void test_sort(void* sort_strtgy, void* const collection)
{
	printf("sort done.\n");
}

void test(int argc, char* argv[])
{
	SortStrategy sort_strtgy;
	
	sort_strategy_construct(&sort_strtgy, test_sort);
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
