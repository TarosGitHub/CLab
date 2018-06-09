/**
 * @file      Test_array_get_set.c
 * @brief     Test for array_get and array_set
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
	
	/* Test array_get */
	printf("[array_get]\n");
	int data = -1;
	data = *(int*) array_get(&array, 0);
	printf("array[0] = %d\n", data);
	
	/* Test array_set */
	printf("[array_set]\n");
	data = 34;
	array_set(&array, 0, &data);
	printf("array[0] <- %d\n", data);
	
	data = -1;
	data = *(int*) array_get(&array, 0);
	printf("array[0] = %d\n", data);
	
	/* Test array_set_all */
	printf("[array_set_all]\n");
	data = 78;
	array_set_all(&array, &data);
	
	int i;
	for (i = 0; i < array_max_size(&array); i++) {
		printf("array[%d] = %d\n", i, *(int*) array_get(&array, i));
	}
	
	return;
}

int main(int argc, char* argv[])
{
	printf("--- [Test start] ---\n");
	test(argc, argv);
	printf("--- [Test done ] ---\n");
	return 0;
}
