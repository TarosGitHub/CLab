/**
 * @file      Test_array_copy.c
 * @brief     Test for array_copy
 * @author    Taro Hoshino
 * Copyright (C) 2017 Taro Hoshino. All Rights Reserved.
 */

#include <stdio.h>
#include "Array.h"
#include <limits.h>


void test(int argc, char* argv[])
{
	int i;
	
	printf("INT_MAX  = %10d\n", INT_MAX);
	printf("SHRT_MAX = %10d\n", SHRT_MAX);
	
	printf("---\n");
	/* Test array_copy */
	#define ARRAY_SIZE 5
	int memory0[ARRAY_SIZE] = {91, 2, 0, INT_MAX, -65};
	int memory1[ARRAY_SIZE] = {0};
	Array array0 = new_Array(int, memory0, ARRAY_SIZE);
	Array array1 = new_Array(int, memory1, ARRAY_SIZE);
	
	array_copy(&array0, &array1);
	
	for (i = 0; i < ARRAY_SIZE; i++) {
		printf("array[%d] = %d\n", i, *(int*) array_get(&array1, i));
	}
	
	printf("---\n");
	/* array_sizeが異なる場合 */
	#define ARRAY_SIZE2 7
	int memory2[ARRAY_SIZE2] = {0};
	Array array2 = new_Array(int, memory2, ARRAY_SIZE2);
	
	array_copy(&array0, &array2);
	
	for (i = 0; i < ARRAY_SIZE2; i++) {
		printf("array[%d] = %d\n", i, *(int*) array_get(&array2, i));
	}
	
	printf("---\n");
	/* elem_sizeが異なる場合 */
	short memory3[ARRAY_SIZE] = {0};
	Array array3 = new_Array(int, memory3, ARRAY_SIZE);
	
	array_copy(&array0, &array3);
	
	for (i = 0; i < ARRAY_SIZE; i++) {
		printf("array[%d] = %d\n", i, *(short*) array_get(&array3, i));
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
