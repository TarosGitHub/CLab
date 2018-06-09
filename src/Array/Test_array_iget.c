/**
 * @file      Test_array_iget.c
 * @brief     Test for array_iget
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Array.h"


void test(int argc, char* argv[])
{
	/* Make the Array object */
	#define ARRAY_SIZE 5
	int memory[ARRAY_SIZE] = {4, 1, 3, 2, 0};
	Array array = new_Array(int, memory, ARRAY_SIZE);
	unsigned int index_array[ARRAY_SIZE] = {4, 1, 3, 2, 0};

	/* Call the set_index_array function */
	array.set_index_array(&array, index_array); 
	array_iprint(int, &array, "%d ", -1);

	/* Call the init_index_array function */
	array.init_index_array(&array);
	array_iprint(int, &array, "%d ", -1);

	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
