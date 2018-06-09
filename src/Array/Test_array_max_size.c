/**
 * @file      Test_array_max_size.c
 * @brief     Test for array_max_size
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Array.h"


void test(int argc, char* argv[])
{
	#define ARRAY_SIZE 12
	int memory[ARRAY_SIZE] = {0};
	Array array;
	
	array_construct(&array, memory, ARRAY_SIZE, sizeof(int));
	
	/* Test of array_max_size */
	int max_size = -1;
	max_size = array_max_size(&array);
	printf("max_size = %d\n", max_size);
	
	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
