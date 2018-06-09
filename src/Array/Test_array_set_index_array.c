/**
 * @file      Test_array_set_index_array.c
 * @brief     Test for array_set_index_array
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Array.h"


void test(int argc, char* argv[])
{
	/* Make the Array object */
	#define ARRAY_SIZE 5
	int memory[ARRAY_SIZE] = {0};
	Array array = new_Array(int, memory, ARRAY_SIZE);
	int index_array[ARRAY_SIZE];

	/* Call the array_set_index_array function */
	array_set_index_array(&array, index_array); 
	printf("Setting completed.\n");

	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
