/**
 * @file      Test_min_strategy_construct.c
 * @brief     Test for min_strategy_construct
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "MinStrategy.h"

void* test_min(void* min_strtgy, void* const collection)
{
	printf("min done.\n");
	return (void*) 0;
}

void test(int argc, char* argv[])
{
	MinStrategy min_strtgy;
	
	min_strategy_construct(&min_strtgy, test_min);
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
