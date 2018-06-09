/**
 * @file      Test_sort_strategy_construct.c
 * @brief     Test for sort_strategy_construct
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "CompStrategy.h"

/* Test function of compare */
template_compare(int, test_compare);

void test(int argc, char* argv[])
{
	CompStrategy comp_strtgy;
	
	comp_strategy_construct(&comp_strtgy, test_compare);
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
